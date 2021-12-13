#pragma once
#include <unordered_set>
#include <utility>
#include <vector>
#include "globals.hh"
#include "ros/time.h"

//Callback for topic joint_states
inline void callbackT0(const sensor_msgs::JointState::Ptr& msg){
   const std::lock_guard<std::mutex> lock(t0Mutex);

   for (auto& fp : t0AddEvent) {
      fp.second.second(fp.second.first, msg->header.stamp, msg);
   }
}

// Utility functions <CheckerN,VK>-->add_event
inline void addVarChecker1_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_ef12(10,0);
window_ef12.pop_front(); window_ef12.push_back(msg->effort[12]);
   dynamic_cast<Checker1 *>(ch)->addEvent_ef12(ts,std::accumulate(window_ef12.begin(), window_ef12.end(), (double)0)/window_ef12.size());
static std::deque<double> window_ef13(10,0);
window_ef13.pop_front(); window_ef13.push_back(msg->effort[13]);
   dynamic_cast<Checker1 *>(ch)->addEvent_ef13(ts,std::accumulate(window_ef13.begin(), window_ef13.end(), (double)0)/window_ef13.size());
}
inline void addVarChecker1_r1_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_ef12(10,0);
window_ef12.pop_front(); window_ef12.push_back(msg->effort[12]);
   dynamic_cast<Checker1_r1 *>(ch)->addEvent_ef12(ts,std::accumulate(window_ef12.begin(), window_ef12.end(), (double)0)/window_ef12.size());
static std::deque<double> window_ef13(10,0);
window_ef13.pop_front(); window_ef13.push_back(msg->effort[13]);
   dynamic_cast<Checker1_r1 *>(ch)->addEvent_ef13(ts,std::accumulate(window_ef13.begin(), window_ef13.end(), (double)0)/window_ef13.size());
}
inline void addVarChecker1_r2_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_ef12(10,0);
window_ef12.pop_front(); window_ef12.push_back(msg->effort[12]);
   dynamic_cast<Checker1_r2 *>(ch)->addEvent_ef12(ts,std::accumulate(window_ef12.begin(), window_ef12.end(), (double)0)/window_ef12.size());
static std::deque<double> window_ef13(10,0);
window_ef13.pop_front(); window_ef13.push_back(msg->effort[13]);
   dynamic_cast<Checker1_r2 *>(ch)->addEvent_ef13(ts,std::accumulate(window_ef13.begin(), window_ef13.end(), (double)0)/window_ef13.size());
}
inline void addVarChecker2_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_vel0(10,0);
window_vel0.pop_front(); window_vel0.push_back(msg->velocity[0]);
   dynamic_cast<Checker2 *>(ch)->addEvent_vel0(ts,std::accumulate(window_vel0.begin(), window_vel0.end(), (double)0)/window_vel0.size());
}
inline void addVarChecker2_r1_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_vel0(10,0);
window_vel0.pop_front(); window_vel0.push_back(msg->velocity[0]);
   dynamic_cast<Checker2_r1 *>(ch)->addEvent_vel0(ts,std::accumulate(window_vel0.begin(), window_vel0.end(), (double)0)/window_vel0.size());
}
inline void addVarChecker2_r2_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_vel0(10,0);
window_vel0.pop_front(); window_vel0.push_back(msg->velocity[0]);
   dynamic_cast<Checker2_r2 *>(ch)->addEvent_vel0(ts,std::accumulate(window_vel0.begin(), window_vel0.end(), (double)0)/window_vel0.size());
}
inline void addVarChecker3_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_pos0(10,0);
window_pos0.pop_front(); window_pos0.push_back(msg->position[0]);
   dynamic_cast<Checker3 *>(ch)->addEvent_pos0(ts,std::accumulate(window_pos0.begin(), window_pos0.end(), (double)0)/window_pos0.size());
}
inline void addVarChecker3_r1_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_pos0(10,0);
window_pos0.pop_front(); window_pos0.push_back(msg->position[0]);
   dynamic_cast<Checker3_r1 *>(ch)->addEvent_pos0(ts,std::accumulate(window_pos0.begin(), window_pos0.end(), (double)0)/window_pos0.size());
}
inline void addVarChecker3_r2_T0(Checker *ch, ros::Time ts, const sensor_msgs::JointState::Ptr& msg) {
static std::deque<double> window_pos0(10,0);
window_pos0.pop_front(); window_pos0.push_back(msg->position[0]);
   dynamic_cast<Checker3_r2 *>(ch)->addEvent_pos0(ts,std::accumulate(window_pos0.begin(), window_pos0.end(), (double)0)/window_pos0.size());
}


// Subscribe the specified topic
inline void attachCallback(const std::string &name) {
   if(name == "T0"){
      attachedTopics[name] = n->subscribe(topicPrefix + "joint_states", 10000, callbackT0, ros::TransportHints().tcpNoDelay()); 
    }else{
      assert(0);
   }
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
   if(topic == "T0"){
      const std::lock_guard<std::mutex> lock(t0Mutex);
      t0AddEvent.erase(checker);
   }else{
      assert(0);
   }
}
inline void addTopicFP(const std::string &topic, const std::string &checker) {
   if(topic == "T0"){
      const std::lock_guard<std::mutex> lock(t0Mutex);
      if(checker == "Checker1"){
         t0AddEvent["Checker1"] = std::make_pair(chsAll.at("Checker1"), &addVarChecker1_T0);
      }else if(checker == "Checker1_r1"){
         t0AddEvent["Checker1_r1"] = std::make_pair(chsAll.at("Checker1_r1"), &addVarChecker1_r1_T0);
      }else if(checker == "Checker1_r2"){
         t0AddEvent["Checker1_r2"] = std::make_pair(chsAll.at("Checker1_r2"), &addVarChecker1_r2_T0);
      }else if(checker == "Checker2"){
         t0AddEvent["Checker2"] = std::make_pair(chsAll.at("Checker2"), &addVarChecker2_T0);
      }else if(checker == "Checker2_r1"){
         t0AddEvent["Checker2_r1"] = std::make_pair(chsAll.at("Checker2_r1"), &addVarChecker2_r1_T0);
      }else if(checker == "Checker2_r2"){
         t0AddEvent["Checker2_r2"] = std::make_pair(chsAll.at("Checker2_r2"), &addVarChecker2_r2_T0);
      }else if(checker == "Checker3"){
         t0AddEvent["Checker3"] = std::make_pair(chsAll.at("Checker3"), &addVarChecker3_T0);
      }else if(checker == "Checker3_r1"){
         t0AddEvent["Checker3_r1"] = std::make_pair(chsAll.at("Checker3_r1"), &addVarChecker3_r1_T0);
      }else if(checker == "Checker3_r2"){
         t0AddEvent["Checker3_r2"] = std::make_pair(chsAll.at("Checker3_r2"), &addVarChecker3_r2_T0);
      }else{
         assert(0);
      }
   }else{
      assert(0);
   }
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
   if(topic == "T0"){
      boost::shared_ptr<sensor_msgs::JointState const> msg = ros::topic::waitForMessage<sensor_msgs::JointState>(topicPrefix + "joint_states", *n);
      ttlInsert(topic, msg->header.stamp);
   }else{
      assert(0);
   }
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
