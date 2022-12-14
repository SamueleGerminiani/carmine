
#include "coordinator.hh"
#include <algorithm>
#include <boost/functional/hash.hpp>
#include <chrono>
#include <cmath>
#include <deque>
#include <fstream>
#include <sstream>
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
    nodeToMonitorUsage;
std::unordered_map<std::string, size_t> monitorToATCF;
std::unordered_map<std::string, std::unordered_map<std::string, double>>
    nodeToTopicUsage;
std::unordered_map<std::string, double> nodeToAvailable;
std::unordered_map<std::string, double> nodeToWholeNodeUsage;
std::unordered_map<std::string, double> nodeToWholeMachineUsage;
std::unordered_map<std::string, double> nodeToThisMachineMaxUsage;
std::unordered_map<std::string, double> nodeToCPUfreq;
std::unordered_map<std::string, double> nodeToMilpUsageTh;
std::unordered_map<std::string, std::string> currAlloc;
std::unordered_map<std::string, std::string> findBestAllocation();
void gatherStats();
void startMonitors();
void freeStats();
bool haveLatForAllNodes();
bool haveUsageForAllMonitors();
void printStatistics();
std::vector<std::pair<std::string, std::string>> findMigrationOrder();
bool ackReceived(const std::string &node);
std::chrono::steady_clock::time_point lastChange =
    std::chrono::steady_clock::now();

int getDelay(std::unordered_map<std::string, std::string> &alloc) {
    size_t curr_delay = 0;
    std::unordered_map<std::string, std::vector<std::string>>
        currMonitorsInMachine;
    for (auto &c_m : alloc) {
        currMonitorsInMachine[c_m.second].push_back(c_m.first);
    }
    for (auto &m_cc : currMonitorsInMachine) {
        std::unordered_set<std::string> reqTopics;
        for (auto &c : m_cc.second) {
            for (auto &t : monitorToTopic.at(c)) {
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
static std::string dumpFile = "stat.csv";
static std::ofstream statOut;
static auto prevDumpTime = std::chrono::steady_clock::now();
static size_t currDumpTime = 0;
static size_t prevDumpSize = 0;
std::unordered_map<std::string, std::tuple<double, double, double, size_t>>
    nextDump;

void printHeader() {
    std::stringstream ss;
    ss << "time; ";
    ss << "|||; ";
    nodesMutex.lock();
    for (auto &c : nodes) {
        nextDump[c.second];
    }
    nodesMutex.unlock();
    for (auto &c : nextDump) {
        ss << " available_" + c.first + "; monitor_" + c.first + "; topic_" +
                  c.first + ";  nChs_" + c.first + "; ";
        ss << "|||; ";
    }
    ss << "nFailures; ";
    ss << "\n";
    statOut << ss.str();
}
#endif

// the coordinator main loop
void coordinator() {
    static size_t count = 0;
    static const size_t rateMILP = 10;
    static const size_t rateStat = 10;
    static const size_t ratePrint = 10;
    if (system(("rm "+ dumpFile).c_str())) {
        std::cout << "Can not remove "<<dumpFile << "\n";
    }
    if (system(("touch " + dumpFile).c_str())) {
        std::cout << "Can not create "<<dumpFile << "\n";
    }
    statOut.open(dumpFile,std::ios_base::app);

    //    debug
    //    ros::Duration(5).sleep();
    startMonitors();
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
            haveLatForAllNodes() && haveUsageForAllMonitors() &&
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
bool haveUsageForAllMonitors() {
    for (auto &c : allMonitors) {
        for (auto &n_cu : nodeToMonitorUsage) {
            if (n_cu.second.count(c)) {
                goto foundMonitor;
            }
        }
        return 0;
    foundMonitor:;
    }
    return 1;
}
void startMonitors() {
    while (!haveLatForAllNodes()) {
        ros::Duration(0.1).sleep();
        gatherStats();
    }
    nodesMutex.lock();
    std::string firstNode = nodes.begin()->second;
    nodesMutex.unlock();

    for (auto &c : allMonitors) {
        nodeToMonitorUsage[firstNode][c] = 0.0f;
    }

    {
        const std::lock_guard<std::mutex> lock(nodesMutex);
        for (auto &n : nodes) {
            nodeToAvailable[n.second] = 0.0f;
            // avoid z3 bug
            for (auto &tl : nodeToTopicLatency[n.second]) {
                tl.second += 0.001f;
            }
        }
    }
    std::unordered_map<std::string, std::string> ba = findBestAllocation();

    std::unordered_map<std::string, std::vector<std::string>> mToExeMonitors;
    for (auto &c_n : ba) {
        mToExeMonitors[c_n.second].push_back(c_n.first);
    }
    for (auto &m_cc : mToExeMonitors) {
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
    nodeToMonitorUsage.clear();
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

        double sumMonitorUsage = 0.f;
        // monitor
        nodeToMonitorUsage[msg.node].clear();
        for (size_t i = 0; i < msg.monitorList.size(); i++) {
            auto monitorName = msg.monitorList[i];
            double usage = msg.monitorUsage[i];
            if (currAlloc.at(monitorName) == msg.node) {
                // only if msg is updated to curr allocation
                nodeToMonitorUsage[msg.node][monitorName] = usage;
                sumMonitorUsage += usage;
            }
            monitorToATCF[monitorName] = msg.monitorATCF[i];
        }

        // topics
        nodeToTopicLatency[msg.node].clear();
        nodeToTopicUsage[msg.node].clear();
        std::unordered_set<std::string> attachedTopics;
        for (auto &at : msg.attachedTopics) {
            attachedTopics.insert(at);
        }
        size_t nAttachedTopics = msg.attachedTopics.size();
        for (size_t i = 0; i < msg.topicList.size(); i++) {
            auto topicName = msg.topicList[i];
            auto latency = msg.topicLatency[i];
            // latency
            nodeToTopicLatency[msg.node][topicName] =
                latency < 0.f ? 0.f : latency;
//            if (msg.node=="/edge1") {
            nodeToTopicLatency[msg.node][topicName] =0.f;
 //           }

            // usage
            double val = (nAttachedTopics == 0 ||
                          (msg.wholeNodeUsage - sumMonitorUsage) < 0.f)
                             ? 0.f
                             : ((msg.wholeNodeUsage - sumMonitorUsage) /
                                nAttachedTopics);

            if (attachedTopics.count(topicName)) {
                nodeToTopicUsage[msg.node][topicName] = val;
            }
        }

        nodeToWholeNodeUsage[msg.node] =
            msg.wholeNodeUsage < 0.f ? 0.f : msg.wholeNodeUsage;
        nodeToWholeMachineUsage[msg.node] =
            msg.wholeMachineUsage < 0.f ? 0.f : msg.wholeMachineUsage;
        nodeToCPUfreq[msg.node] =
            msg.machineCPUfreq < 0.f ? 0.f : msg.machineCPUfreq;
        nodeToAvailable[msg.node] =
            msg.availableUsage < 0.f ? 0.f : msg.availableUsage;
        nodeToThisMachineMaxUsage[msg.node] =
            msg.thisMachineMaxUsage < 0.f ? 0.f : msg.thisMachineMaxUsage;
        nodeToMilpUsageTh[msg.node] = msg.milpUsageThreshold;
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
    for (auto monitorUsage : nodeToMonitorUsage) {
        double sumccpu = 0.f;
        double sumtcpu = 0.f;
        std::cout << monitorUsage.first << "\n";
        for (auto &cu : monitorUsage.second) {
            sumccpu += cu.second;
            //        std::cout << "\t\t" << cu.first << ": " << cu.second //
            //        << "\n";
        }
        for (auto &tu : nodeToTopicUsage.at(monitorUsage.first)) {
            sumtcpu += tu.second;
            // std::cout << "\t\t" << tu.first << ": " << tu.second << "\n";
        }
        //        std::cout << "CPU freq: " <<
        //        nodeToCPUfreq.at(monitorUsage.first) << "\n";
        std::cout << "Monitor usage: " << sumccpu << "\n";
        std::cout << "Topic usage: " << sumtcpu << "\n";
        std::cout << "Available CPU: " << nodeToAvailable.at(monitorUsage.first)
                  << "\n";
        std::cout << "Whole node CPU: "
                  << nodeToWholeNodeUsage.at(monitorUsage.first) << "\n";
#if dumpStats
        nextDump[monitorUsage.first] = std::make_tuple(
            nodeToAvailable.at(monitorUsage.first), sumccpu, sumtcpu, 0);
#endif
    }

    std::cout << "[NMonitors]"
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
    size_t totATCF = 0;
    for (auto &atcf : monitorToATCF) {
        totATCF += atcf.second;
    }
#endif

#if dumpStats
    if (!nextDump.empty()) {
        if (prevDumpSize != nextDump.size()) {
            prevDumpSize = nextDump.size();
            printHeader();
        }

        std::stringstream ss;

        // dump time
        currDumpTime += std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::steady_clock::now() - prevDumpTime)
                            .count();
        prevDumpTime = std::chrono::steady_clock::now();
        ss << currDumpTime << "; ";

        ss << "|||; ";
        for (auto &d : nextDump) {
            ss << std::get<0>(d.second) << "; ";
            ss << std::get<1>(d.second) << "; ";
            ss << std::get<2>(d.second) << "; ";
            ss << std::get<3>(d.second) << "; ";
            ss << "|||; ";
        }
        ss << totATCF << "; ";
        ss << "\n";
        statOut << ss.str();
        statOut.flush();
    }
#endif
}

using namespace z3;
std::unordered_map<std::string, std::string> findBestAllocation() {
    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    {
        // avoid z3 bug
        const std::lock_guard<std::mutex> lock(nodesMutex);
        for (auto &n : nodes) {
            for (auto &tl : nodeToTopicLatency[n.second]) {
                tl.second += 0.001f;
            }
        }
    }

    // monitor -> node
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

    // find all monitors
    std::unordered_set<std::string> monitors;
    for (auto &cu_list : nodeToMonitorUsage) {
        for (auto &c : cu_list.second) {
            monitors.insert(c.first);
        }
    }

    // monitors mappings
    std::unordered_map<std::string, std::string> z3NameToMonitor;
    std::unordered_map<std::string, std::string> monitorToz3Name;
    size_t j = 0;
    for (auto &monitor : monitors) {
        z3NameToMonitor["ch" + std::to_string(j)] = monitor;
        monitorToz3Name[monitor] = "ch" + std::to_string(j);
        j++;
    }

    // debug
    //    j=0;
    //    for (auto &monitor : monitors) {
    //        std::cout << "ch" + std::to_string(j)<< " ->
    //        "<<z3NameToMonitor["ch" + std::to_string(j)] <<" ->
    //        "<<monitorToz3Name[z3NameToMonitor["ch" + std::to_string(j)]]
    //        <<
    //        "\n";
    //        j++;
    //    }
    //    exit(1);

    std::unordered_map<std::string, expr> chToz3Const;
    for (auto &c : z3NameToMonitor) {
        chToz3Const.insert({{c.first, ctx.constant(c.first.c_str(), s)}});
    }

    // estimate the ch usage for all machine
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        nodeToMonitorUsageScaled;
    for (auto node_ul : nodeToMonitorUsage) {
        for (auto ch_u : node_ul.second) {
            for (auto &n_f : nodeToCPUfreq) {
                nodeToMonitorUsageScaled[n_f.first][ch_u.first] =
                    (nodeToCPUfreq.at(node_ul.first) / n_f.second) *
                    ch_u.second;
                //              std::cout << nodeToCPUfreq.at(node_ul.first)<<"
                //              / "<<n_f.second<<") * "<<      ch_u.second <<
                //              "\n";
                //                    debug
                //                    std::cout
                //                    <<"("<<nodeToCPUfreq.at(node_ul.first)<<"\\"<<n_f.second<<")"<<ch_u.second
                //                    << "\n";
            }
        }
    }
    //                    debug
    //    for (auto node_ul : nodeToMonitorUsageScaled) {
    //        std::cout << node_ul.first << "\n";
    //        for (auto c_u : node_ul.second) {
    //            std::cout << "c_u.second:" << c_u.second << "\n";
    //        }
    //    }

    std::unordered_map<std::string, expr> mj_cpu;
    // ch_mj_cpu
    for (auto &c : z3NameToMonitor) {
        for (auto &en : enum_names) {
            if (!mj_cpu.count(en)) {
                mj_cpu.insert({{en, ctx.int_val((int)0)}});
            }
            expr cond = chToz3Const.at(c.first) == enumNameToz3Exp.at(en);
            expr t =
                ctx.int_val((int)(nodeToMonitorUsageScaled.at(enumToNode.at(en))
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
            for (auto &ct : monitorToTopic) {
                orCond =
                    orCond || chToz3Const.at(monitorToz3Name.at(ct.first)) ==
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
            for (auto &c : topicToMonitor.at(t_v.first)) {
                orCond = orCond ||
                         chToz3Const.at(monitorToz3Name.at(c)) ==
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
        // MAXUsage * TH - TaskUsage(Max-Avail)
        double av = ((nodeToThisMachineMaxUsage.at(e.first) *
                      nodeToMilpUsageTh.at(e.first)) -
                     (nodeToThisMachineMaxUsage.at(e.first) - e.second)) *
                    100.f;
        //        debug
        //        std::cout << "------------------->" << e.first << ": " <<
        //        av/100 << "\n";

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

    opt.minimize(sum(goal));

    // run z3
    auto milpRes = opt.check();

    if (milpRes != z3::sat) {
        // do nothing: do not know how to proceed
#if printStat
        if (milpRes == z3::unknown) {
            std::cout << "Uknown!"
                      << "\n";
        } else {
            std::cout << "Unsat!"
                      << "\n";
            //            debug
            //            std::cout << opt << "\n";
        }
#endif
        return currAlloc;
    } else {
#if printStat
        //        debug
//        std::cout << "Sat!" << "\n";
#endif
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
    // convert the z3 model to an allocation
    for (size_t j = 0; j < model.size(); j++) {
        std::string chName = model[j].name().str();
        std::string chVal = model.get_const_interp(model[j]).to_string();
        ret[z3NameToMonitor.at(chName)] = enumToNode.at(chVal);
    }

    // only if we already have a previous optimal allocation
    if (!currAlloc.empty()) {
        z3::expr_vector sol(ctx);
        for (auto &c_m : currAlloc) {
            sol.push_back(chToz3Const.at(monitorToz3Name.at(c_m.first)) ==
                          enumNameToz3Exp.at(nodeToEnum.at(c_m.second)));
        }
        bool mustMove = 0;
        for (auto e : nodeToAvailable) {
            if (nodeToThisMachineMaxUsage.at(e.first) *
                        nodeToMilpUsageTh.at(e.first) <=
                    nodeToWholeMachineUsage.at(e.first) &&
                !nodeToMonitorUsage.at(e.first).empty()) {
                // must move! at least a cpu is saturated
                mustMove = 1;
#if printStat
                std::cout
                    << "\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++\n";
                std::cout << "\t\t\t\t\t|            Must move from: " +
                                 e.first + "\n";
                std::cout
                    << "\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++\n";
#endif
                break;
            }
        }
        if (!mustMove && std::abs(getDelay(currAlloc) - getDelay(ret)) <=
                             milpResponsivnessThreshold) {
            // not worth migrating
            return currAlloc;
        }
    }

    // std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||"
    //          << "\n";
    // std::cout << "Best allocation:"
    //          << "\n";
    // for (auto cm : ret) {
    //    std::cout << cm.first << " " << cm.second << "\n";
    //}

    return ret;
}
