
#include "coordinator.hh"
#include <algorithm>
#include <boost/functional/hash.hpp>
#include <chrono>
#include <cmath>
#include <deque>
#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include "comunication.hh"
#include "globals.hh"
#include "z3++.h"
#include "z3.h"
#define printStat 1
#define dumpStats 1

std::unordered_map<std::string, std::unordered_map<std::string, double>>
    nodeToTopicLatency;
std::unordered_map<std::string, std::unordered_map<std::string, double>>
    nodeToCheckerUsage;
std::unordered_map<std::string, size_t> checkerToATCF;
std::unordered_map<std::string, std::unordered_map<std::string, double>>
    nodeToTopicUsage;
std::unordered_map<std::string, double> nodeToAvailable;
std::unordered_map<std::string, double> nodeToWholeNodeUsage;
std::unordered_map<std::string, double> nodeToWholeMachineUsage;
std::unordered_map<std::string, double> nodeToThisMachineMaxUsage;
std::unordered_map<std::string, double> nodeToCPUfreq;
std::unordered_map<std::string, std::string> currAlloc;
std::unordered_map<std::string, std::string> findBestAllocation();
void gatherStats();
void startCheckers();
void freeStats();
bool haveLatForAllNodes();
bool haveUsageForAllCheckers();
void printStatistics();
std::vector<std::pair<std::string, std::string>> findMigrationOrder();
bool ackReceived(const std::string &node);
std::chrono::steady_clock::time_point lastChange =
    std::chrono::steady_clock::now();

int getDelay(std::unordered_map<std::string, std::string> &alloc) {
    size_t curr_delay = 0;
    std::unordered_map<std::string, std::vector<std::string>>
        currCheckersInMachine;
    for (auto &c_m : alloc) {
        currCheckersInMachine[c_m.second].push_back(c_m.first);
    }
    for (auto &m_cc : currCheckersInMachine) {
        std::unordered_set<std::string> reqTopics;
        for (auto &c : m_cc.second) {
            for (auto &t : checkerToTopic.at(c)) {
                reqTopics.insert(t);
            }
        }
        for (auto &t : reqTopics) {
            curr_delay +=
                (int)(nodeToTopicLatency.at(m_cc.first).at(t) * 1000.f);
        }
    }
    return curr_delay;
}
std::unordered_map<std::pair<std::string, std::string>,
                   std::vector<std::string>,
                   boost::hash<std::pair<std::string, std::string>>>
findMigrationOrder(std::unordered_map<std::string, std::string> &ba) {
    std::unordered_map<std::pair<std::string, std::string>,
                       std::vector<std::string>,
                       boost::hash<std::pair<std::string, std::string>>>
        mmToCh;
    for (auto &c_m : ba) {
        if (currAlloc.at(c_m.first) != c_m.second) {
            mmToCh[std::make_pair(currAlloc.at(c_m.first), c_m.second)]
                .push_back(c_m.first);
        }
    }

    return mmToCh;
}

bool ackReceived(const std::string &node) {
    const std::lock_guard<std::mutex> lock(acksMutex);
    for (size_t i = 0; i < acks.size(); i++) {
        if (node == acks[i]) {
            acks.erase(acks.begin() + i);
            return 1;
        }
    }

    return 0;
}

#if dumpStats
static std::ofstream statOut("stat.csv");
std::unordered_map<std::string, std::tuple<double, double,double,size_t>> nextDump;
#endif

// the coordinator main loop
void coordinator() {
    static size_t count = 0;
    static const size_t rateMILP = 10;
    static const size_t rateStat = 10;
    static const size_t ratePrint = 10;
    //    std::cout << "c) Running..." << "\n";

//    ros::Duration(5).sleep();
    startCheckers();
    while (ros::ok()) {
        ros::Duration(0.1).sleep();
        count++;

        // 1) gather the statistics from the nodes
        if ((count % rateStat == 0)) {
            gatherStats();
        }

#if printStat
        if (count % ratePrint == 0) {
            printStatistics();
        }
#endif

        if (std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - lastChange)
                    .count() >= 0 &&
            nodes.size() > 1 && (count % rateMILP == 0) &&
            haveLatForAllNodes() && haveUsageForAllCheckers() &&
            !disableMigration) {
            // 3) run the algorithm to find the best allocation
            auto bestAlloc = findBestAllocation();

            // 4) coordinate the nodes
            auto migOrder = findMigrationOrder(bestAlloc);
            if (!migOrder.empty()) {
                lastChange = std::chrono::steady_clock::now();
            }
            for (auto &mm_cc : migOrder) {
                sendToNode(mm_cc.first.second, MIGRATE_FROM, mm_cc.first.first,
                           mm_cc.second);
                while (!ackReceived(mm_cc.first.second)) {
                    ros::Duration(0.01).sleep();
                }
                for (auto &c : mm_cc.second) {
                    currAlloc.at(c) = mm_cc.first.second;
                }
            }
        }
    }
}

bool haveLatForAllNodes() {
    const std::lock_guard<std::mutex> lock(nodesMutex);
    for (auto &n : nodes) {
        if (!nodeToTopicLatency.count(n.second)) {
            return 0;
        }
    }
    return 1;
}
bool haveUsageForAllCheckers() {
    for (auto &c : allCheckers) {
        for (auto &n_cu : nodeToCheckerUsage) {
            if (n_cu.second.count(c)) {
                goto foundChecker;
            }
        }
        return 0;
    foundChecker:;
    }
    return 1;
}
void startCheckers() {
    while (!haveLatForAllNodes()) {
        ros::Duration(0.1).sleep();
        gatherStats();
    }
    nodesMutex.lock();
    std::string firstNode = nodes.begin()->second;
    nodesMutex.unlock();

#if dumpStats
    statOut << "time; ";
    nodesMutex.lock();
    for (auto &c : nodes) {
        nextDump[c.second];
    }
    nodesMutex.unlock();
    for (auto &c : nextDump) {
        statOut << " available_"+c.first+"; checker_"+c.first+"; topic_"+c.first+";  nChs_"+c.first+"; ";
    }
    statOut<<"nFailures; ";
    statOut << "\n";
#endif

    for (auto &c : allCheckers) {
        nodeToCheckerUsage[firstNode][c] = 0.0f;
    }

    {
        const std::lock_guard<std::mutex> lock(nodesMutex);
        for (auto &n : nodes) {
            nodeToAvailable[n.second]=0.0f;
            //avoid z3 bug
            for (auto &tl : nodeToTopicLatency[n.second]) {
                tl.second+=0.001f;
            }
        }
    }
    std::unordered_map<std::string, std::string> ba = findBestAllocation();

    std::unordered_map<std::string, std::vector<std::string>> mToExeCheckers;
    for (auto &c_n : ba) {
        mToExeCheckers[c_n.second].push_back(c_n.first);
    }
    for (auto &m_cc : mToExeCheckers) {
        sendToNode(m_cc.first, EXEC, "", m_cc.second);
        while (!ackReceived(m_cc.first)) {
            ros::Duration(0.01).sleep();
        }
        for (auto &c : m_cc.second) {
            currAlloc[c] = m_cc.first;
        }
    }
}

void freeStats() {
    nodeToTopicLatency.clear();
    nodeToCheckerUsage.clear();
    nodeToTopicUsage.clear();
    nodeToAvailable.clear();
    nodeToCPUfreq.clear();
    stat_msgsMutex.lock();
    stat_msgs.clear();
    stat_msgsMutex.unlock();
}
void gatherStats() {
    stat_msgsMutex.lock();
    if (stat_msgs.empty()) {
        stat_msgsMutex.unlock();
        return;
    }
    while (!stat_msgs.empty()) {
        // retrieve the next message
        ver_env::stat msg = stat_msgs.front();
        stat_msgs.pop_front();

        double sumCheckerUsage = 0.f;
        //checker
        nodeToCheckerUsage[msg.node].clear();
        for (size_t i = 0; i < msg.checkerList.size(); i++) {
            auto checkerName = msg.checkerList[i];
            double usage = msg.checkerUsage[i];
            if (currAlloc.at(checkerName)==msg.node) {
                //only if msg is updated to curr allocation
                nodeToCheckerUsage[msg.node][checkerName] = usage;
                sumCheckerUsage += usage;
            }
            checkerToATCF[checkerName]=msg.checkerATCF[i];
        }


        //topics
        nodeToTopicLatency[msg.node].clear();
        nodeToTopicUsage[msg.node].clear();
        std::unordered_set<std::string> attachedTopics;
        for (auto &at : msg.attachedTopics) {
            attachedTopics.insert(at);
        }
        size_t nAttachedTopics=msg.attachedTopics.size();
        for (size_t i = 0; i < msg.topicList.size(); i++) {
            auto topicName = msg.topicList[i];
            auto latency = msg.topicLatency[i];
            //latency
            nodeToTopicLatency[msg.node][topicName] = latency<0.f?0.f:latency;

            // usage
            double val =(nAttachedTopics==0 || (msg.wholeNodeUsage - sumCheckerUsage) < 0.f)?0.f: ((msg.wholeNodeUsage - sumCheckerUsage) / nAttachedTopics);

            if (attachedTopics.count(topicName)) {
                nodeToTopicUsage[msg.node][topicName] =val;
            }
        }

        nodeToWholeNodeUsage[msg.node] = msg.wholeNodeUsage<0.f?0.f:msg.wholeNodeUsage;
        nodeToWholeMachineUsage[msg.node] = msg.wholeMachineUsage<0.f?0.f:msg.wholeMachineUsage;
        nodeToCPUfreq[msg.node] = msg.machineCPUfreq<0.f?0.f:msg.machineCPUfreq;
        nodeToAvailable[msg.node] = msg.availableUsage<0.f?0.f:msg.availableUsage;
        nodeToThisMachineMaxUsage[msg.node] = msg.thisMachineMaxUsage<0.f?0.f:msg.thisMachineMaxUsage;
    }
    stat_msgsMutex.unlock();
}

void printStatistics() {
    std::cout << "-----------------STAT---------------------"
              << "\n";
    std::cout << "[Topics Latency]"
              << "\n";
    for (auto &nll : nodeToTopicLatency) {
        std::cout << nll.first << "\n";
        for (auto &nl : nll.second) {
            std::cout << "\t\t" << nl.first << ": " << (int)(nl.second * 1000.f)
                      << "ms\n";
        }
    }
    std::cout << "[Usage]"
              << "\n";
    for (auto checkerUsage : nodeToCheckerUsage) {
        double sumccpu=0.f;
        double sumtcpu=0.f;
        std::cout << checkerUsage.first << "\n";
        for (auto &cu : checkerUsage.second) {
            sumccpu+=cu.second;
            //        std::cout << "\t\t" << cu.first << ": " << cu.second //
            //        << "\n";
        }
        for (auto &tu : nodeToTopicUsage.at(checkerUsage.first)) {
            sumtcpu+=tu.second;
            //std::cout << "\t\t" << tu.first << ": " << tu.second << "\n";
        }
        //        std::cout << "CPU freq: " <<
        //        nodeToCPUfreq.at(checkerUsage.first) << "\n";
        std::cout << "Checker usage: " << sumccpu                  << "\n";
        std::cout << "Topic usage: " << sumtcpu                  << "\n";
        std::cout << "Available CPU: " << nodeToAvailable.at(checkerUsage.first)
                  << "\n";
        std::cout << "Whole node CPU: "
                  << nodeToWholeNodeUsage.at(checkerUsage.first) << "\n";
#if dumpStats
            nextDump[checkerUsage.first] = std::make_tuple(nodeToAvailable.at(checkerUsage.first),sumccpu,sumtcpu,0);
#endif
    }

    std::cout << "[NCheckers]"
              << "\n";
    std::unordered_map<std::string, size_t> nodeToNC;
    for (auto &a : currAlloc) {
        nodeToNC[a.second]++;
    }
    for (auto &na : nodeToNC) {
        std::cout << na.first << ": " << na.second << "\n";
#if dumpStats
        std::get<3>(nextDump.at(na.first)) = na.second;
#endif
    }
    std::cout << "--------------------------------------"
              << "\n";

#if dumpStats
    size_t totATCF=0;
    for (auto &atcf : checkerToATCF) {
        totATCF+=atcf.second;
    }
#endif

#if dumpStats
    statOut << ros::Time::now() << "; ";
        for (auto &d : nextDump) {
            statOut << std::get<0>(d.second) << "; ";
            statOut << std::get<1>(d.second) << "; ";
            statOut << std::get<2>(d.second) << "; ";
            statOut << std::get<3>(d.second) << "; ";
        }
        statOut <<totATCF<<"; ";
        statOut << "\n";
        statOut.flush();
#endif
}

using namespace z3;
std::unordered_map<std::string, std::string> findBestAllocation() {
    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    {
            //avoid z3 bug
        const std::lock_guard<std::mutex> lock(nodesMutex);
        for (auto &n : nodes) {
            for (auto &tl : nodeToTopicLatency[n.second]) {
                tl.second+=0.001f;
            }
        }
    }

    // checker -> node
    std::unordered_map<std::string, std::string> ret;
    // init optimizer
    z3::context ctx;
    z3::optimize opt(ctx);
    z3::params p(ctx);
    opt.set(p);

    // enum type
    std::vector<std::string> enum_names;
    std::unordered_map<std::string, std::string> enumToNode;
    std::unordered_map<std::string, std::string> nodeToEnum;
    size_t i = 0;
    for (auto &node : nodeToCPUfreq) {
        enum_names.push_back("m" + std::to_string(i));
        enumToNode[enum_names[i]] = node.first;
        nodeToEnum[node.first] = enum_names[i];
        i++;
    }

    // debug
    // std::cout << i<<" "<<enumToNode.size()<<" "<<nodeToEnum.size() <<
    // "\n";
    // for (size_t i = 0; i < nodeToCPUfreq.size(); i++) {
    //     std::cout << enum_names[i]<< " -> "<<enumToNode[enum_names[i]]
    //     <<" ->
    //     "<<nodeToEnum[enumToNode[enum_names[i]]] << "\n";
    // }

    func_decl_vector enum_consts(ctx);
    func_decl_vector enum_testers(ctx);
    const char *enum_namesC[nodeToCPUfreq.size()];
    for (size_t i = 0; i < nodeToCPUfreq.size(); i++) {
        enum_namesC[i] = enum_names[i].c_str();
    }

    sort s = ctx.enumeration_sort("M", nodeToCPUfreq.size(), enum_namesC,
                                  enum_consts, enum_testers);
    std::unordered_map<std::string, expr> enumNameToz3Exp;
    for (size_t j = 0; j < nodeToCPUfreq.size(); j++) {
        enumNameToz3Exp.insert({{enum_names[j], enum_consts[j]()}});
    }

    // ch constants of enum type

    // find all checkers
    std::unordered_set<std::string> checkers;
    for (auto &cu_list : nodeToCheckerUsage) {
        for (auto &c : cu_list.second) {
            checkers.insert(c.first);
        }
    }

    // checkers mappings
    std::unordered_map<std::string, std::string> z3NameToChecker;
    std::unordered_map<std::string, std::string> checkerToz3Name;
    size_t j = 0;
    for (auto &checker : checkers) {
        z3NameToChecker["ch" + std::to_string(j)] = checker;
        checkerToz3Name[checker] = "ch" + std::to_string(j);
        j++;
    }

    // debug
    //    j=0;
    //    for (auto &checker : checkers) {
    //        std::cout << "ch" + std::to_string(j)<< " ->
    //        "<<z3NameToChecker["ch" + std::to_string(j)] <<" ->
    //        "<<checkerToz3Name[z3NameToChecker["ch" + std::to_string(j)]]
    //        <<
    //        "\n";
    //        j++;
    //    }
    //    exit(1);

    std::unordered_map<std::string, expr> chToz3Const;
    for (auto &c : z3NameToChecker) {
        chToz3Const.insert({{c.first, ctx.constant(c.first.c_str(), s)}});
    }

    // estimate the ch usage for all machine
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        nodeToCheckerUsageScaled;
    for (auto node_ul : nodeToCheckerUsage) {
        for (auto ch_u : node_ul.second) {
            for (auto &n_f : nodeToCPUfreq) {
                nodeToCheckerUsageScaled[n_f.first][ch_u.first] =
                    (nodeToCPUfreq.at(node_ul.first) / n_f.second) *
                    ch_u.second;
  //              std::cout << nodeToCPUfreq.at(node_ul.first)<<" / "<<n_f.second<<") * "<<      ch_u.second << "\n";
                //                    debug
                //                    std::cout
                //                    <<"("<<nodeToCPUfreq.at(node_ul.first)<<"\\"<<n_f.second<<")"<<ch_u.second
                //                    << "\n";
            }
        }
    }
    //                    debug
    //    for (auto node_ul : nodeToCheckerUsageScaled) {
    //        std::cout << node_ul.first << "\n";
    //        for (auto c_u : node_ul.second) {
    //            std::cout << "c_u.second:" << c_u.second << "\n";
    //        }
    //    }

    std::unordered_map<std::string, expr> mj_cpu;
    // ch_mj_cpu
    for (auto &c : z3NameToChecker) {
        for (auto &en : enum_names) {
            if (!mj_cpu.count(en)) {
                mj_cpu.insert({{en, ctx.int_val((int)0)}});
            }
            expr cond = chToz3Const.at(c.first) == enumNameToz3Exp.at(en);
            expr t =
                ctx.int_val((int)(nodeToCheckerUsageScaled.at(enumToNode.at(en))
                                      .at(c.second) *
                                  100.f));
            expr f = ctx.int_val((int)0);
            mj_cpu.at(en) =
                mj_cpu.at(en) + to_expr(ctx, Z3_mk_ite(ctx, cond, t, f));
        }
    }

    // estimate the topic usage for all machine
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        nodeToTopicUsageScaled;
    for (auto node_ul : nodeToTopicUsage) {
        for (auto t_u : node_ul.second) {
            if (t_u.second > 0.f &&
                t_u.second < std::numeric_limits<float>::max()) {
                for (auto &n_f : nodeToCPUfreq) {
                    nodeToTopicUsageScaled[n_f.first][t_u.first] =
                        (nodeToCPUfreq.at(node_ul.first) / n_f.second) *
                        t_u.second;
                    //                    debug
                    //                    std::cout << node_ul.first <<
                    //                    "\n";
                    //                    std::cout <<
                    //                    "nodeToCPUfreq.at(node_ul.first):"<<nodeToCPUfreq.at(node_ul.first)
                    //                    << "\n";
                    //                    std::cout <<
                    //                    "n_f.second:"<<n_f.second
                    //                    << "\n";
                    //                    std::cout <<
                    //                    "t_u.second:"<<t_u.second
                    //                    << "\n";
                    //                    std::cout
                    //                    <<"---------------------->"<<
                    //                    (nodeToCPUfreq.at(node_ul.first) /
                    //                    n_f.second) * t_u.second << "\n";
                }
            }
        }
    }
    //                    debug
    //    for (auto node_ul : nodeToTopicUsageScaled) {
    //        std::cout << node_ul.first << "\n";
    //        for (auto t_u : node_ul.second) {
    //                    std::cout << "t_u.second:"<<t_u.second << "\n";
    //        }
    //    }

    std::unordered_map<std::string, std::string> topicNameToz3Name;
    size_t k = 0;
    for (auto &t : allTopics) {
        topicNameToz3Name[t] = "topic" + std::to_string(k);
    }
    // topic_mj_cpu
    for (auto &topic : topicNameToz3Name) {
        for (auto &en : enum_names) {
            expr orCond = ctx.bool_val(false);
            for (auto &ct : checkerToTopic) {
                orCond = orCond ||
                         chToz3Const.at(checkerToz3Name.at(ct.first)) ==
                             enumNameToz3Exp.at(en);
            }
            expr t = ctx.int_val(
                (int)(nodeToTopicUsageScaled[enumToNode.at(en)][topic.first] *
                      100.f));
            expr f = ctx.int_val((int)0);
            mj_cpu.at(en) =
                mj_cpu.at(en) + to_expr(ctx, Z3_mk_ite(ctx, orCond, t, f));
        }
    }

    // chi_mj_delay
    std::unordered_map<std::string, expr> mj_delay;

    // estimate the ch delay for all machine
    for (auto &node_tl : nodeToTopicLatency) {
        if (!mj_delay.count(nodeToEnum.at(node_tl.first))) {
            mj_delay.insert(
                {{nodeToEnum.at(node_tl.first), ctx.int_val((int)0)}});
        }
        for (auto &t_v : node_tl.second) {
            expr orCond = ctx.bool_val(false);
            for (auto &c : topicToChecker.at(t_v.first)) {
                orCond = orCond ||
                         chToz3Const.at(checkerToz3Name.at(c)) ==
                             enumNameToz3Exp.at(nodeToEnum.at(node_tl.first));
            }
            expr t = ctx.int_val((int)(t_v.second * 1000.f));
            expr f = ctx.int_val((int)0);
            mj_delay.at(nodeToEnum.at(node_tl.first)) =
                mj_delay.at(nodeToEnum.at(node_tl.first)) +
                to_expr(ctx, Z3_mk_ite(ctx, orCond, t, f));
        }
    }

    // mi_avail_cpu
    std::unordered_map<std::string, expr> mi_avail_cpu;
    for (auto e : nodeToAvailable) {
        double av = (e.second -
                     nodeToThisMachineMaxUsage.at(e.first) *
                         (1.f - milpUsageThreshold)) *
                    100.f;

        mi_avail_cpu.insert({{nodeToEnum.at(e.first),
                              ctx.int_val((int)(av >= 0.f ? av : 0.f))}});
    }

    // assert cpu saturation
    for (auto &u : mj_cpu) {
        opt.add(u.second <= mi_avail_cpu.at(u.first));
    }
    // opt function
    z3::expr_vector goal(ctx);
    for (auto &d : mj_delay) {
        goal.push_back(d.second);
    }

    // launch z3
    opt.minimize(sum(goal));


    if (z3::sat != opt.check()) {
        // Unsat: do nothing
                       std::cout << "Unsat or Uknown!"                   << "\n";
//            std::cout << opt << "\n";
 //               assert(0);
 //               exit(1);
        ret = currAlloc;
        return ret;
    }

#if printStat
    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    std::cout << "MILP time = "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       begin)
                     .count()
              << "[ms]" << std::endl;
// debug
//   std::cout << opt << "\n";
#endif

    z3::model model = opt.get_model();

    for (size_t j = 0; j < model.size(); j++) {
        std::string chName = model[j].name().str();
        std::string chVal = model.get_const_interp(model[j]).to_string();
        ret[z3NameToChecker.at(chName)] = enumToNode.at(chVal);
    }

    if (!currAlloc.empty()) {
        z3::expr_vector sol(ctx);
        for (auto &c_m : currAlloc) {
            sol.push_back(chToz3Const.at(checkerToz3Name.at(c_m.first)) ==
                    enumNameToz3Exp.at(nodeToEnum.at(c_m.second)));
        }
        bool mustMove = 0;
        for (auto e : nodeToAvailable) {
            if (nodeToThisMachineMaxUsage.at(e.first) *
                    milpUsageThreshold <=
                    nodeToWholeMachineUsage.at(e.first)) {
                mustMove = 1;
                std::cout << "\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << "\n";
                break;
            }
        }
        if (!mustMove) {
            int currDelay = getDelay(currAlloc);
            int newDelay = getDelay(ret);
            //    debug
            //    std::cout << " ====================currDelay:" <<
            //    currDelay <<
            //    "\n";
            //    std::cout << " ====================newDelay:" <<
            //    newDelay
            //    <<
            //    "\n";
            //    std::cout << "''''''''''''''''''''''''''''''''''''" <<
            //    "\n";
            //    std::cout << "< "<<(int)(std::abs(currDelay -
            //    newDelay) <
            //    milpResponsivnessThreshold) << "\n";

            if (std::abs(currDelay - newDelay) <=
                    milpResponsivnessThreshold) {
                ret = currAlloc;
                return ret;
            }
        }
    }

    //std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||"
    //          << "\n";
    //std::cout << "Best allocation:"
    //          << "\n";
    //for (auto cm : ret) {
    //    std::cout << cm.first << " " << cm.second << "\n";
    //}



    return ret;
}
