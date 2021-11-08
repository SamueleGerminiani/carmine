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

$initCheckers

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

$initCheckerTopicRelations

}
