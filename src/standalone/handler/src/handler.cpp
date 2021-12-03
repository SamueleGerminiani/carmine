
#include <string>
#include <utility>
#include "callback.hh"
#include "checkerHelper.hh"
#include "commandLineParser.hh"
#include "comunication.hh"
#include "coordinator.hh"
#include "cpuUsageHelper.hh"
#include "globals.hh"
#include "nodeHandler.hh"
#include "statHandler.hh"
inline void sigint_handler(int signal) {
    std::cout << ros::this_node::getName() +
                     ": Execution interrupted by the user!"
              << "\n";
    ros::shutdown();
}

std::pair<int, char **> parseCommandLineArguments(int argc, char *argv[]) {
    std::vector<std::string> oargvs;
    for (size_t i = 0; i < argc; i++) {
        oargvs.push_back(argv[i]);
    }

    auto result = parse(argc, argv);
    std::vector<std::string> unusedArguments;
    std::unordered_set<std::string> usedArguments;

    if (result.count("milpUsageThreshold")) {
        milpUsageThreshold = result["milpUsageThreshold"].as<double>();
        usedArguments.insert("--milpUsageThreshold");
    }
    if (result.count("milpResponsivnessThreshold")) {
        milpResponsivnessThreshold= result["milpResponsivnessThreshold"].as<double>();
        usedArguments.insert("--milpResponsivnessThreshold");
    }
    if (result.count("topicPrefix")) {
        topicPrefix= result["topicPrefix"].as<std::string>();
        usedArguments.insert("--topicPrefix");
    }

    for (size_t i = 0; i < oargvs.size(); i++) {
        if (usedArguments.count(oargvs[i])) {
            i++;
        } else {
            unusedArguments.push_back(oargvs[i]);
        }
    }
    char **finalargv = nullptr;
    finalargv = new char *[unusedArguments.size()];

    for (size_t j = 0; j < unusedArguments.size(); j++) {
        auto &e = unusedArguments[j];
        finalargv[j] = new char[e.size()];
        e.push_back('\0');
        e.copy(finalargv[j], e.size());
    }

    return std::make_pair(unusedArguments.size(), finalargv);
}

int main(int argc, char **argv) {
    auto trimmedArgv = parseCommandLineArguments(argc, argv);
    

    signal(SIGINT, sigint_handler);
    ros::init(trimmedArgv.first, trimmedArgv.second, "handler",
              ros::init_options::NoSigintHandler);
    n = new ros::NodeHandle();
    ros::AsyncSpinner spinner(std::thread::hardware_concurrency());
    spinner.start();

    Server server(*n,"ver_env/"+ ros::this_node::getName() + "/migrate",
                  boost::bind(&migrateTo, _1, &server), false);
    server.start();

    // store which topic is used by each checker
    initCheckerTopicRelation();
    fillAllTopics();
    fillAllCheckers();

    initMaxFreq();

    // The following code is used to decide which node will contain the
    // coordinator
    // 1) broadcast to the network the existence of this
    // node and discover the existence of the other nodes: all the new nodes
    // will send their name to the "start_up" topic and
    // receive all the messages from the same topic
    ros::Publisher chatter_pub2 =
        n->advertise<ver_env::su>("ver_env/start_up", 1, 1);
    ver_env::su msg2;
    msg2.name = ros::this_node::getName();
    msg2.header.stamp = ros::Time::now();
    chatter_pub2.publish(msg2);

    ros::Subscriber sub_su = n->subscribe("ver_env/start_up", 100, start_upCB,
                                          ros::TransportHints().tcpNoDelay());
    // 2) wait for th seconds to receive the messages from the nodes
    double th = 1;
    ros::Duration(th).sleep();

    // find the node who sent the first message
    ros::Time min = ros::Time::now();
    std::string minName = "";
    nodesMutex.lock();
    for (auto &n : nodes) {
        if (n.first < min) {
            min = n.first;
            minName = n.second;
        }
    }
    // find the node that comes first in lexicographic order
    //  consider only the nodes that sent a message in the time window
    //  [timestamp -
    //  min]
    std::string maxName = "";
    for (auto &n : nodes) {
        if ((n.first - min).toSec() < (th * 0.7) && maxName < n.second) {
            maxName = n.second;
        }
    }
    nodesMutex.unlock();
    //    std::cout << ros::this_node::getName() << ": the coordinator is " <<
    //    maxName << "\n";
    cooName = maxName;

    boost::thread *ct = nullptr;
    boost::thread *nht = nullptr;
    boost::thread *sht = nullptr;

    ros::Subscriber sub_cc;
    ros::Subscriber sub_cs;
    ros::Subscriber sub_ack;

    if (cooName == ros::this_node::getName()) {
        // if this node is the chosen one, start the coordinator here
        //        std::cout << ros::this_node::getName() << ": Starting
        //        coordinator..." << "\n";
        sub_cs = n->subscribe("ver_env/coo_stat", 100, receiveStatMSGS,
                              ros::TransportHints().tcpNoDelay());
        sub_ack = n->subscribe("ver_env/coo_ack", 100, acksCB,
                               ros::TransportHints().tcpNoDelay());
        nameToPublisher["ver_env/coo_stat"];
        nameToPublisher["ver_env/coo_ack"];
        // independent thread containing the coordinator main loop
        ct = new boost::thread(coordinator);
    } else {
        nameToPublisher["ver_env/coo_stat"] =
            n->advertise<ver_env::stat>("ver_env/coo_stat", 100, 1);
        nameToPublisher["ver_env/coo_ack"] =
            n->advertise<ver_env::ack>("ver_env/coo_ack", 100, 1);
    }

    sub_cc = n->subscribe(ros::this_node::getName(), 100, receiveNodeMSGS,
                          ros::TransportHints().tcpNoDelay());

    // independent thread containing the node handle main loop
    nht = new boost::thread(nodeHandler);
    // independent thread containing the statistic handler main loop
    sht = new boost::thread(statHandler);

    sched.start();

    ros::waitForShutdown();

    sched.stop();




    // free memory
    for (auto &e : chsActive) {
        delete e.second;
    }
    for (auto &e : chsDeleted) {
        delete e.second;
    }

    if (cooName == ros::this_node::getName()) {
        ct->join();
        delete ct;
    }
    nht->join();
    sht->join();
    delete nht;
    delete sht;

    delete n;

    for (size_t i = 0; i < trimmedArgv.first; i++) {
        delete[] trimmedArgv.second;
    }

    return 0;
}
