#include <ros/callback_queue.h>
#include <cassert>
#include <chrono>
#include <csignal>
#include <iostream>
#include <mutex>
#include <string>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <utility>

#include <unordered_set>
#include "include_checkers.hh"
#include "ros/ros.h"
#include "scheduler.hh"
#include "verification_env/command.h"
#include "verification_env/su.h"

// command types sent by the coordinator to the nodes
#define EXEC 0
#define MIGRATE_FROM 1
// this function is called by the client Ros service (migrateFrom)
bool migrateTo(verification_env::migrate::Request &req,
               verification_env::migrate::Response &res);
// it contains the checkers currently executed by this node
std::map<std::string, Checker *> chs;
// it contains the checkers deleted by this node
std::map<std::string, Checker *> chsDeleted;

ros::NodeHandle *n;

Scheduler sched(1);

// the nodes currently executing in the network
std::vector<std::pair<ros::Time, std::string>> nodes;

std::unordered_map<std::string, std::vector<std::string>> checkerToTopic;
std::unordered_map<std::string, ros::ServiceServer> checkerToSS;
std::unordered_map<std::string, ros::Subscriber> attachedTopics;
std::unordered_map<std::string, ros::Publisher> nameToPublisher;

$callbacks


void attachCallback(const std::string &name) {
$attachCallbacks
}
void initChecker(const std::string &name) {
    if (chsDeleted.count(name)) {
        chs[name] = chsDeleted.at(name);
        chsDeleted.erase(name);
        return;
    }
$initChecker
}
void pubService(const std::string &name) {
    if (checkerToSS.count(name)) {
        return;
    }
$pubService
}
void removeService(const std::string &name) { checkerToSS.erase(name); }
void removeChecker(const std::string &name) {
    if (chs.count(name)) {
        chsDeleted[name] = chs.at(name);
        chs.erase(name);
        return;
    } else {
        assert(0);
        exit(1);
    }
}

void removeCheckerCallbacks(const std::string &checkerName) {
    std::unordered_set<std::string> usedTopics;
    // find the topics that are still necessary after removing the checker
    for (auto &ch : chs) {
        if (ch.first != checkerName) {
            for (auto &topic : checkerToTopic.at(ch.first)) {
                usedTopics.insert(topic);
            }
        }
    }
    // the callbacks are removed only if no other checker is using them
    for (auto &topic : checkerToTopic.at(checkerName)) {
        if (!usedTopics.count(topic) && attachedTopics.count(topic)) {
            //            attachedTopics.erase(topic);
        }
    }
}
void addCheckerCallbacks(const std::string &checkerName) {
    for (auto &topic : checkerToTopic.at(checkerName)) {
        if (attachedTopics.count(topic)) {
            continue;
        }
        attachCallback(topic);
    }
}
// this function should be called only when a checker is created for the first
// time
void execChecker(const std::string &checkerName) {
    initChecker(checkerName);
    addCheckerCallbacks(checkerName);
    sched.addCheckerRequest(chs.at(checkerName));
    pubService(checkerName);
}
// callback function to receive messages from starting nodes
void start_upCB(const verification_env::su &msg) {
    nodes.push_back(std::make_pair(msg.header.stamp, msg.name));
}
// messages sent by the coordinator to the node
std::deque<verification_env::command> msgs;
// mutex to protect the messages' container
std::mutex msgsMutex;
//avoid concurrency between migrateTo and migrateFrom
std::mutex migrateMutex;

// callback function to receive messages from the coordinator
void receiveCooMSGS(const verification_env::command &msg) {
    msgsMutex.lock();
    msgs.push_back(msg);
    msgsMutex.unlock();
}
// the main loop function of a node
void nodeHandler() {
    while (ros::ok()) {
        // 1) periodically checks if there are new messages to be served
        ros::Duration(0.01).sleep();
        msgsMutex.lock();
        if (!msgs.empty()) {
            // 2) retrieve the next message
            verification_env::command msg = msgs.front();
            msgs.pop_front();
            msgsMutex.unlock();
            // 3) serve the corresponding command
            switch (msg.command) {
                Checker *ch;
                case EXEC:
                    // execute a checker: only for the first time
                    std::cout << ros::this_node::getName() << ": EXEC("
                              << msg.checker << ")"
                              << "\n";
                    execChecker(msg.checker);
                    break;
                case MIGRATE_FROM:
                    const std::lock_guard<std::mutex> lock(migrateMutex);
                    // migrate a checker: this command is served by the node
                    // receiving the checker
                    std::cout << ros::this_node::getName() << ": MIGRATE_FROM("
                              << msg.checker << ", " << msg.node << ")"
                              << "\n";

                    initChecker(msg.checker);
                    addCheckerCallbacks(msg.checker);
                    ch = chs.at(msg.checker);
                    // execute the migration
                    ch->migrateFrom(msg.node, n);
                    // put the checker on the scheduler
                    sched.addCheckerRequest(ch);
                    // publish the migration service on this node
                    pubService(msg.checker);
                    std::cout << ros::this_node::getName() << " MF_ended"
                              << "\n";
                    break;
            }
        } else {
            msgsMutex.unlock();
        }
    }
}
bool migrateTo(verification_env::migrate::Request &req,
               verification_env::migrate::Response &res) {
    const std::lock_guard<std::mutex> lock(migrateMutex);
    std::cout << ros::this_node::getName() << ": MIGRATE_TO(" << req.checkerName
              << ")"
              << "\n";
    Checker *ch = chs.at(req.checkerName);
    // remove the checker from the scheduler
    sched.removeCheckerRequest(ch);
    // call the function implementing the migration logic in the checker
    ch->migrateTo(req, res);
    removeCheckerCallbacks(req.checkerName);
    removeChecker(req.checkerName);
    std::cout << ros::this_node::getName() << " MT_ended"
              << "\n";
    return 1;
}
// function used by the coordinator to send a command to a node
void sendToNode(std::string pubName, int command, std::string node,
                std::string checker) {
    ros::Publisher &pub = nameToPublisher.at(pubName);
    // wait that the receiving node is ready to receive the message
    while (ros::this_node::getName() != pubName &&
           pub.getNumSubscribers() == 0) {
        ros::Duration(0.1).sleep();
    }
    // prepare the message
    verification_env::command msg;
    msg.command = command;
    msg.header.stamp = ros::Time::now();
    msg.checker = checker;
    msg.node = node;
    //  send the message
    //  n.b.  if the receiving now is in the same process of the coordinator,
    //  simply add the message to "msgs" instead of using a publisher
    if (ros::this_node::getName() == pubName) {
        msgsMutex.lock();
        msgs.push_back(msg);
        msgsMutex.unlock();
    } else {
        pub.publish(msg);
    }
}
// used by the coordinator to create a new publisher
void cooAddPublisher(
    std::string nodeName,
    std::unordered_map<std::string, ros::Publisher> &nameToPublisher) {
    if (ros::this_node::getName() == nodeName) {
        nameToPublisher[nodeName];
    } else {
        std::cout << "c) Pub to " << nodeName << "\n";
        nameToPublisher[nodeName] =
            n->advertise<verification_env::command>(nodeName, 100, 1);
    }
}
// the coordinator main loop
void coordinator() {
    std::cout << "c) Running..."
              << "\n";

    while (ros::ok()) {
        ros::Duration(0.01).sleep();

        // 1) add new nodes (if any) to the network
        for (auto nn : nodes) {
            if (!nameToPublisher.count(nn.second)) {
                cooAddPublisher(nn.second, nameToPublisher);
            }
        }

        // 2) gather the statistics from the nodes

        // 3) run the algorithm to find the best allocation

        // 4) coordinate the nodes
        //======================================================================
        // this is just an example to check if all works correctly
        //======================================================================
        //           std::cout << "c) EXEC(" << "CheckerT0" << ") to node " <<
        //           "/my_node1" << "\n";
        sendToNode("/my_node1", EXEC, "", "CheckerT0");
        sendToNode("/my_node1", EXEC, "", "CheckerT1");
        while (1) {
            ros::Duration(3).sleep();
            sendToNode("/my_node2", MIGRATE_FROM, "/my_node1", "CheckerT0");
            std::cout << "c) 1->2"
                      << "\n";

            std::cout << "c) ok!"
                      << "\n";
            ros::Duration(3).sleep();
            sendToNode("/my_node3", MIGRATE_FROM, "/my_node2", "CheckerT0");
            std::cout << "c) 2->1"
                      << "\n";

            std::cout << "c) ok!"
                      << "\n";
            ros::Duration(3).sleep();
            sendToNode("/my_node1", MIGRATE_FROM, "/my_node3", "CheckerT0");
            std::cout << "c) 3->1"
                      << "\n";
            std::cout << "c) ok!"
                      << "\n";

            std::cout << "----------------------"
                      << "\n";
        }
        ros::waitForShutdown();
    }
}
void sigint_handler(int signal) {
    std::cout << ros::this_node::getName() +
                     ": Execution interrupted by the user!"
              << "\n";
    ros::shutdown();
}

int main(int argc, char **argv) {
    signal(SIGINT, sigint_handler);
    ros::init(argc, argv, "handler", ros::init_options::NoSigintHandler);
    n = new ros::NodeHandle();
    ros::AsyncSpinner spinner(1);
    spinner.start();

    // store which topic is used by each checker
$checkerToTopic

    // The following code is used to decide which node will contain the
    // coordinator
    // 1) broadcast to the network the existence of this
    // node and discover the existence of the other nodes: all the new nodes
    // will send their name to the "start_up" topic and
    // receive all the messages from the same topic
    ros::Publisher chatter_pub2 =
        n->advertise<verification_env::su>("start_up", 1, 1);
    verification_env::su msg2;
    msg2.name = ros::this_node::getName();
    msg2.header.stamp = ros::Time::now();
    chatter_pub2.publish(msg2);

    ros::Subscriber sub_su = n->subscribe("start_up", 100, start_upCB,
                                          ros::TransportHints().tcpNoDelay());
    // 2) wait for th seconds to receive the messages from the nodes
    double th = 1;
    ros::Duration(th).sleep();

    // find the node who sent the first message
    ros::Time min = ros::Time::now();
    std::string minName = "";
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
    std::cout << ros::this_node::getName() << ": the coordinator is " << maxName
              << "\n";

    sub_su.shutdown();
    std::thread *ct = nullptr;
    std::thread *nht = nullptr;

    ros::Subscriber sub_cc;

    if (maxName == ros::this_node::getName()) {
        // if this node is the chosen one, start the coordinator here
        std::cout << ros::this_node::getName() << ": Starting coordinator..."
                  << "\n";
        // independent thread containing the coordinator main loop
        ct = new std::thread(coordinator);
    } else {
        // otherwise, initialise the infrastructure used to receiving messages
        // from the coordinator
        // queue_cc = new ros::CallbackQueue;
        // n->setCallbackQueue(queue_cc);
        sub_cc = n->subscribe(ros::this_node::getName(), 100, receiveCooMSGS,
                              ros::TransportHints().tcpNoDelay());
    }

    // independent thread containing the node main loop
    nht = new std::thread(nodeHandler);

    spinner.stop();
    sched.start();

    ros::spin();

    sched.stop();

    // free memory

    for (auto e : chs) {
        delete e.second;
    }

    if (maxName == ros::this_node::getName()) {
        ct->join();
        delete ct;
    } else {
        sub_cc.shutdown();
    }
    nht->join();
    delete nht;

    delete n;
    return 0;
}
