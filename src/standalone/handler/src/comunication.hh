#pragma once
#include "globals.hh"
#include "ver_env/checkerData.h"

inline void migrateTo(const ver_env::migrateGoalConstPtr &goal,
                      Server *as) {
    const std::lock_guard<std::mutex> lock(migrateMutex);
    // remove the checker from the scheduler
    std::vector<Checker *> chs;
    for (auto &chName : goal->checkers) {
        chs.push_back(chsAll.at(chName));
    }
    sched.removeCheckerRequest(chs);

    ver_env::migrateResult res;

    for (size_t i = 0; i < goal->stamp.size(); i++) {
        ver_env::checkerData cd;
        cd.checker = goal->checkers[i];
        cd.last_msg_ts =
            chsAll.at(goal->checkers[i])->migrateToHandleTS(goal->stamp[i]);
        res.cd.push_back(cd);
    }
    for (auto &cd : res.cd) {
        chsAll.at(cd.checker)->migrateToHandleData(cd);
    }
    std::unordered_set<std::string> chsToBeRemoved;
    for (auto &chName : goal->checkers) {
        chsToBeRemoved.insert(chName);
    }

    removeCheckerCallbacks(chsToBeRemoved);
    removeChecker(chsToBeRemoved);

    as->setSucceeded(res);
}
// function used by the coordinator to send a command to a node
inline void sendToNode(std::string pubName, int command, std::string node,
                       std::vector<std::string> &checkers) {

    ros::Publisher &pub = nameToPublisher.at(pubName);
    // wait that the receiving node is ready to receive the message
    while (ros::this_node::getName() != pubName &&
           pub.getNumSubscribers() == 0) {
        //        std::cout << ros::this_node::getName() << " waiting for " <<
        //        pubName << "\n";
        ros::Duration(0.1).sleep();
    }
    // prepare the message
    ver_env::command msg;
    msg.command = command;
    msg.header.stamp = ros::Time::now();
    msg.checkers=checkers;
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
inline void sendStatToCoordinator() {
    ros::Publisher &pub = nameToPublisher.at("ver_env/coo_stat");
    // wait that the receiving node is ready to receive the message
    while (ros::this_node::getName() != cooName &&
           pub.getNumSubscribers() == 0) {
        //        std::cout << ros::this_node::getName() << " waiting for " <<
        //        "coo_stat" << "\n";
        ros::Duration(0.1).sleep();
    }
    // prepare the message
    ver_env::stat msg;
    msg.header.stamp = ros::Time::now();
    msg.node = ros::this_node::getName();
    for (auto &tl : topicToLatency) {
        msg.topicList.push_back(tl.first);
        msg.topicLatency.push_back(tl.second);
    }
    for (auto &ch : chsActive) {
        msg.checkerList.push_back(ch.first);
        msg.checkerUsage.push_back(ch.second->_CPUusage);
        msg.eventsInBuffer.push_back(ch.second->_eventsInBuffer);
    }

    msg.wholeNodeUsage = wholeNodeUsage;
    msg.wholeMachineUsage = wholeMachineUsage;
    msg.availableUsage =
        thisMachineMaxUsage - wholeMachineUsage + wholeNodeUsage;
//    std::cout << thisMachineMaxUsage<<" - "<<wholeMachineUsage<<" + "<<wholeNodeUsage << "\n";
    msg.nAttachedTopics = attachedTopics.size();
    msg.machineCPUfreq = machineCPUfreq;
    msg.thisMachineMaxUsage=thisMachineMaxUsage;
    //  send the message
    //  n.b.  if the receiving now is in the same process of the coordinator,
    //  simply add the message to "msgs" instead of using a publisher
    if (ros::this_node::getName() == cooName) {
        stat_msgsMutex.lock();
        stat_msgs.push_back(msg);
        stat_msgsMutex.unlock();
    } else {
        pub.publish(msg);
    }
}

inline void sendAckToCoordinator() {
    ros::Publisher &pub = nameToPublisher.at("ver_env/coo_ack");
    // wait that the receiving node is ready to receive the message
    while (ros::this_node::getName() != cooName &&
           pub.getNumSubscribers() == 0) {
        //        std::cout << ros::this_node::getName() << " waiting for " <<
        //        "coo_stat" << "\n";
        ros::Duration(0.1).sleep();
    }
    // prepare the message
    ver_env::ack msg;
    msg.node = ros::this_node::getName();
    //  send the message
    //  n.b.  if the receiving now is in the same process of the coordinator,
    //  simply add the message to "msgs" instead of using a publisher
    if (ros::this_node::getName() == cooName) {
        acksMutex.lock();
        acks.push_back(msg.node);
        acksMutex.unlock();
    } else {
        pub.publish(msg);
    }
}

