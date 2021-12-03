#pragma once
#include <unordered_set>
#include <utility>
#include <vector>
#include "globals.hh"
#include "ros/time.h"

$callbacks

// Utility functions <CheckerN,VK>-->add_event
$addVars


// Subscribe the specified topic
inline void attachCallback(const std::string &name) {
$attachCallbacks
}
inline void addCheckerCallbacks(const std::string &checkerName) {
    for (auto &topic : checkerToTopic.at(checkerName)) {
        addTopicFP(topic, checkerName);
        // attach a new your call back only if it's not already attached
        if (attachedTopics.count(topic)) {
            continue;
        }
        attachCallback(topic);
    }
}
inline void removeTopicFP(const std::string &topic,
                          const std::string &checker) {
$removeTopicFPs
}
inline void addTopicFP(const std::string &topic, const std::string &checker) {
$addTopicFPs
}
inline void ttlInsert(const std::string &topic, const ros::Time &stamp) {
    if (!topicToLatency.count(topic)) {
        topicToLatency[topic];
    }
    if (topicToLatencyWindow[topic].size() == windowMaxSize) {
        topicToLatencyWindow.at(topic).pop_back();
    }
    // debug
    //        topicToLatencyWindow.at(topic).push_front( (ros::Time::now() -
    //        stamp).toSec()+((double)(random()%100))/1000);
    topicToLatencyWindow.at(topic).push_front(
        (ros::Time::now() - stamp).toSec());
    topicToLatency.at(topic) =
        std::accumulate(topicToLatencyWindow.at(topic).begin(),
                        topicToLatencyWindow.at(topic).end(), 0.f) /
        (double)topicToLatencyWindow.at(topic).size();
}
inline void pingTopic(const std::string &topic) {
$pingTopics
}
inline void removeCheckerCallbacks(const std::string &checkerName) {
    std::unordered_set<std::string> usedTopics;
    // find the topics that are still necessary after removing the checker
    for (auto &ch : chsActive) {
        if (ch.first != checkerName) {
            for (auto &topic : checkerToTopic.at(ch.first)) {
                usedTopics.insert(topic);
            }
        }
    }
    // the callbacks are removed only if no other checker is using them
    for (auto &topic : checkerToTopic.at(checkerName)) {
        if (!usedTopics.count(topic) && attachedTopics.count(topic)) {
            attachedTopics.erase(topic);
        }
        removeTopicFP(topic, checkerName);
    }
}
inline void removeCheckerCallbacks(
    std::unordered_set<std::string> &chsToBeRemoved) {
    std::unordered_set<std::string> remainingCheckers;
    std::unordered_set<std::string> remainingTopics;
    std::unordered_set<std::string> topicsToBeErased;
    // find the topics that are still necessary after removing the checker
    // the callbacks are removed only if no other checker is using them

    for (auto &ch : chsActive) {
        if (!chsToBeRemoved.count(ch.first)) {
            remainingCheckers.insert(ch.first);
        }
    }

    for (auto &chName : remainingCheckers) {
        for (auto &t : checkerToTopic.at(chName)) {
            remainingTopics.insert(t);
        }
    }
    for (auto &t : attachedTopics) {
        if (!remainingTopics.count(t.first)) {
            topicsToBeErased.insert(t.first);
        }
    }

    for (auto &topic : topicsToBeErased) {
        attachedTopics.erase(topic);
        for (auto &checkerName : topicToChecker.at(topic)) {
            removeTopicFP(topic, checkerName);
        }
    }
}
inline void addPublisher(std::string nodeName) {
    if (nameToPublisher.count(nodeName)) {
        return;
    }
    nameToPublisher[nodeName] =
        n->advertise<ver_env::command>(nodeName, 100, 1);
}
// callback function to receive messages from starting nodes
inline void start_upCB(const ver_env::su &msg) {
    const std::lock_guard<std::mutex> lock1(addPublisherMutex);
    const std::lock_guard<std::mutex> lock2(nodesMutex);

    nodes.push_back(std::make_pair(msg.header.stamp, msg.name));
    if (ros::this_node::getName() != msg.name) {
        addPublisher(msg.name);
        addPublisher("ver_env/"+msg.name + "/latency");
    } else {
        nameToPublisher[msg.name];
    }
}
// callback function to receive messages for the node handler
inline void receiveNodeMSGS(const ver_env::command &msg) {
    const std::lock_guard<std::mutex> lock(msgsMutex);
    msgs.push_back(msg);
}
// callback function to receive messages for the coordinator
inline void receiveStatMSGS(const ver_env::stat &msg) {
    const std::lock_guard<std::mutex> lock(stat_msgsMutex);
    stat_msgs.push_back(msg);
}
inline void fillAllTopics() {
    for (auto &tl : checkerToTopic) {
        for (auto &t : tl.second) {
            allTopics.insert(t);
        }
    }
}
inline void fillAllCheckers() {
    for (auto &tl : checkerToTopic) {
        allCheckers.insert(tl.first);
    }
}
inline void acksCB(const ver_env::ack &msg) {
    const std::lock_guard<std::mutex> lock(acksMutex);
    acks.push_back(msg.node);
}
