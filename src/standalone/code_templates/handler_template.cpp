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
#include "std_msgs/String.h"
#include "verification_env/command.h"
#include "verification_env/su.h"

#define EXEC 0
#define MIGRATE_TO 1
#define MIGRATE_FROM 2
#define SHUDOWN 3
struct CallbackData {
    CallbackData(const std::string &name, ros::CallbackQueue *queue = nullptr,
                 ros::Subscriber *sub = nullptr, std::thread *thread = nullptr,
                 ros::SingleThreadedSpinner *spinner = nullptr)
        : _name(name),
          _queue(queue),
          _sub(sub),
          _thread(thread),
          _spinner(spinner) {
        // not todo
    }
    std::string _name;
    ros::CallbackQueue *_queue;
    ros::Subscriber *_sub;
    std::thread *_thread;
    ros::SingleThreadedSpinner *_spinner;
};

std::map<std::string, Checker *> chs;
$callbacksMutex
ros::NodeHandle *n;

Scheduler sched(std::thread::hardware_concurrency() / 2);
std::vector<std::pair<ros::Time, std::string>> nodes;
std::unordered_map<std::string, std::vector<std::string>> checkerToTopic;
std::unordered_map<std::string, CallbackData> attachedTopics;

$callbacks




void pauseCallBacks() {
$pauseCallBacks
}
void resumeCallBacks() {
$resumeCallBacks
}

void attachCallback(CallbackData &cbd) {
    cbd._queue = new ros::CallbackQueue;
    n->setCallbackQueue(cbd._queue);
    cbd._sub = new ros::Subscriber;
$attachCallbacks

    cbd._thread = new std::thread([&cbd]() {
        cbd._spinner = new ros::SingleThreadedSpinner;
        cbd._spinner->spin(cbd._queue);
    });
}
void initChecker(const std::string &name) {
    pauseCallBacks();
$initChecker

    resumeCallBacks();
}
void detachCallback(CallbackData &cbd) {
    cbd._sub->shutdown();
    delete cbd._queue;
    delete cbd._sub;
    delete cbd._spinner;
    cbd._thread->join();
    delete cbd._thread;
}
void removeCheckerCallbacks(const std::string &name) {
    pauseCallBacks();
    std::unordered_set<std::string> usedTopics;
    for (auto &ch : chs) {
        if (ch.first != name) {
            for (auto &topic : checkerToTopic.at(ch.first)) {
                usedTopics.insert(topic);
            }
        }
    }
    resumeCallBacks();
    for (auto &topic : checkerToTopic.at(name)) {
        if (!usedTopics.count(topic) && attachedTopics.count(topic)) {
            detachCallback(attachedTopics.at(topic));
            attachedTopics.erase(topic);
        }
    }
}
void addCheckerCallbacks(const std::string &name) {
    for (auto &topic : checkerToTopic.at(name)) {
        if (attachedTopics.count(topic)) {
            continue;
        }
        attachedTopics.insert({{topic, CallbackData(topic)}});
        attachCallback(attachedTopics.at(topic));
    }
}
void addCheckerToScheduler(const std::string &name) {
    sched.addCheckerRequest(chs.at(name));
}
void execChecker(const std::string &name) {
    addCheckerCallbacks(name);
    initChecker(name);
    addCheckerToScheduler(name);
}
void start_upCB(const verification_env::su &msg) {
    nodes.push_back(std::make_pair(msg.header.stamp, msg.name));
}
void cooCommandsCB(const verification_env::command &msg) {
    switch (msg.command) {
        case EXEC:
            std::cout << ros::this_node::getName() << ": EXEC(" << msg.checker
                      << ")"
                      << "\n";
            execChecker(msg.checker);
            break;
        case MIGRATE_TO:
            break;
        case MIGRATE_FROM:
            break;
        case SHUDOWN:
            break;
    }
}
void sendToNode(int command, std::string node, std::string checker,
                std::string pubName, ros::Publisher &pub) {
    while (ros::this_node::getName() != pubName && pub.getNumSubscribers() == 0) {
        ros::Duration(0.1).sleep();
    }
    verification_env::command msg;
    msg.command = command;
    msg.header.stamp = ros::Time::now();
    msg.checker = checker;
    msg.node = node;
    if (ros::this_node::getName() == pubName) {
        cooCommandsCB(msg);
    } else {
        pub.publish(msg);
    }
}
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
#define OFF 0
#define RUNNING 1
#define MIGRATING 2
void coordinator() {
    // Wait for nodes to sync
    std::unordered_map<std::string, ros::Publisher> nameToPublisher;
    std::unordered_map<std::string, int> checkerToStatus;
    for (auto &ch : checkerToTopic) {
        checkerToStatus[ch.first] = 0;
    }
    std::cout << "c) Running..."
              << "\n";

    while (ros::ok()) {
        ros::Duration(0.2).sleep();

        // 1) add new nodes (if any) to the network
        for (auto nn : nodes) {
            if (!nameToPublisher.count(nn.second)) {
                cooAddPublisher(nn.second, nameToPublisher);
            }
        }

        // 2) gather the statistics from the nodes

        // 3) run the algorithm to find the best allocation

        // 4) coordinate the nodes
        for (auto &c : checkerToTopic) {
            for (auto &p : nameToPublisher) {
                if (checkerToStatus.at(c.first) == 0) {
                    std::cout << "c) EXEC(" << c.first << ") to node "
                              << p.first << "\n";
                    sendToNode(EXEC, "", c.first, p.first, p.second);
                    checkerToStatus[c.first] = 1;
                }
            }
        }
        ros::spinOnce();
    }
    ros::waitForShutdown();
}
void sigint_handler(int signal) {
    ROS_INFO("Execution interrupted by the user!");
    ros::shutdown();
}

int main(int argc, char **argv) {
    signal(SIGINT, sigint_handler);
    ros::init(argc, argv, "handler", ros::init_options::NoSigintHandler);
    n = new ros::NodeHandle();

$checkerToTopic

    ros::Publisher chatter_pub2 =
        n->advertise<verification_env::su>("start_up", 1, 1);
    verification_env::su msg2;
    msg2.name = ros::this_node::getName();
    msg2.header.stamp = ros::Time::now();
    chatter_pub2.publish(msg2);
    ros::spinOnce();

    ros::CallbackQueue *queue_su;
    ros::Subscriber *sub_su;
    std::thread *thread_su;
    ros::SingleThreadedSpinner *spinner_su;
    queue_su = new ros::CallbackQueue;
    n->setCallbackQueue(queue_su);
    sub_su = new ros::Subscriber;
    *sub_su = n->subscribe("start_up", 100, start_upCB,
                           ros::TransportHints().tcpNoDelay());
    thread_su = new std::thread([&queue_su, &spinner_su]() {
        spinner_su = new ros::SingleThreadedSpinner;
        spinner_su->spin(queue_su);
    });
    double th = 1;
    ros::Duration(th).sleep();

    ros::Time min = ros::Time::now();
    std::string minName = "";
    for (auto &n : nodes) {
        if (n.first < min) {
            min = n.first;
            minName = n.second;
        }
    }
    std::string maxName = "";
    for (auto &n : nodes) {
        if ((n.first - min).toSec() < (th * 0.7) && maxName < n.second) {
            maxName = n.second;
        }
    }
    std::cout << ros::this_node::getName() << ": the coordinator is " << maxName
              << "\n";

    sub_su->shutdown();

    std::thread *ct;
    ros::CallbackQueue *queue_cc;
    ros::Subscriber *sub_cc;
    std::thread *thread_cc;
    ros::SingleThreadedSpinner *spinner_cc;

    if (maxName == ros::this_node::getName()) {
        std::cout << ros::this_node::getName() << ": Starting coordinator..."
                  << "\n";
        ct = new std::thread(coordinator);
    } else {
        queue_cc = new ros::CallbackQueue;
        n->setCallbackQueue(queue_cc);
        sub_cc = new ros::Subscriber;
        *sub_cc = n->subscribe(ros::this_node::getName(), 100, cooCommandsCB,
                               ros::TransportHints().tcpNoDelay());
        thread_cc = new std::thread([&queue_cc, &spinner_cc]() {
            spinner_cc = new ros::SingleThreadedSpinner;
            spinner_cc->spin(queue_cc);
        });
    }

    sched.start();
    ros::waitForShutdown();
    sched.stop();


    for (auto &t : attachedTopics) {
        detachCallback(t.second);
    }

    for (auto e : chs) {
        delete e.second;
    }

    if (maxName == ros::this_node::getName()) {
        ct->join();
        delete ct;
    } else {
        delete queue_cc;
        delete sub_cc;
        delete spinner_cc;
        thread_cc->join();
        delete thread_cc;
    }
    delete queue_su;
    delete sub_su;
    delete spinner_su;
    thread_su->join();
    delete thread_su;

    delete n;
    return 0;
}
