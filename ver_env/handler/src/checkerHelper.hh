#pragma once
#include "globals.hh"
#include <unordered_set>

inline void initChecker(const std::string &name) {
    const std::lock_guard<std::mutex> lock(chsMutex);
    if (chsActive.count(name)) {
        return;
    }
    if (chsDeleted.count(name)) {
        chsActive[name] = chsDeleted.at(name);
        chsDeleted.erase(name);
        return;
    }

   if(name == "Checker1"){
      chsActive["Checker1"] = new Checker1(3,1,ros::this_node::getName(), "Checker1");
      chsAll["Checker1"] = chsActive.at("Checker1");
   }else if(name == "Checker2"){
      chsActive["Checker2"] = new Checker2(3,1,ros::this_node::getName(), "Checker2");
      chsAll["Checker2"] = chsActive.at("Checker2");
   }else if(name == "Checker3"){
      chsActive["Checker3"] = new Checker3(3,1,ros::this_node::getName(), "Checker3");
      chsAll["Checker3"] = chsActive.at("Checker3");
   }else if(name == "Checker1_r1"){
      chsActive["Checker1_r1"] = new Checker1_r1(3,1,ros::this_node::getName(), "Checker1_r1");
      chsAll["Checker1_r1"] = chsActive.at("Checker1_r1");
   }else if(name == "Checker2_r1"){
      chsActive["Checker2_r1"] = new Checker2_r1(3,1,ros::this_node::getName(), "Checker2_r1");
      chsAll["Checker2_r1"] = chsActive.at("Checker2_r1");
   }else if(name == "Checker3_r1"){
      chsActive["Checker3_r1"] = new Checker3_r1(3,1,ros::this_node::getName(), "Checker3_r1");
      chsAll["Checker3_r1"] = chsActive.at("Checker3_r1");
   }else if(name == "Checker1_r2"){
      chsActive["Checker1_r2"] = new Checker1_r2(3,1,ros::this_node::getName(), "Checker1_r2");
      chsAll["Checker1_r2"] = chsActive.at("Checker1_r2");
   }else if(name == "Checker2_r2"){
      chsActive["Checker2_r2"] = new Checker2_r2(3,1,ros::this_node::getName(), "Checker2_r2");
      chsAll["Checker2_r2"] = chsActive.at("Checker2_r2");
   }else if(name == "Checker3_r2"){
      chsActive["Checker3_r2"] = new Checker3_r2(3,1,ros::this_node::getName(), "Checker3_r2");
      chsAll["Checker3_r2"] = chsActive.at("Checker3_r2");
   }
}
inline void removeChecker(const std::string &name) {
    const std::lock_guard<std::mutex> lock(chsMutex);
    if (chsActive.count(name)) {
        chsDeleted[name] = chsActive.at(name);
        chsActive.erase(name);
        return;
    } else {
        assert(0);
        exit(1);
    }
}
inline void removeChecker(std::unordered_set<std::string> &chsToBeRemoved) {
    for (auto &ch : chsToBeRemoved) {
        removeChecker(ch);
    }
}

// this function should be called only when a checker is created for the first
// time
inline void execChecker(const std::string &checkerName) {
    initChecker(checkerName);
    addCheckerCallbacks(checkerName);
    sched.addCheckerRequest(chsActive.at(checkerName));
}
inline void initCheckerTopicRelation() {

   checkerToTopic["Checker1"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker1");
   checkerToTopic["Checker1_r1"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker1_r1");
   checkerToTopic["Checker1_r2"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker1_r2");
   checkerToTopic["Checker2"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker2");
   checkerToTopic["Checker2_r1"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker2_r1");
   checkerToTopic["Checker2_r2"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker2_r2");
   checkerToTopic["Checker3"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker3");
   checkerToTopic["Checker3_r1"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker3_r1");
   checkerToTopic["Checker3_r2"].emplace_back("T0");
   topicToChecker["T0"].emplace_back("Checker3_r2");

}
