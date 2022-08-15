#pragma once
#include "globals.hh"
#include <unordered_set>

inline void initMonitor(const std::string &name) {
    const std::lock_guard<std::mutex> lock(chsMutex);
    if (chsActive.count(name)) {
        return;
    }
    if (chsDeleted.count(name)) {
        chsActive[name] = chsDeleted.at(name);
        chsDeleted.erase(name);
        return;
    }

$initMonitors

}
inline void removeMonitor(const std::string &name) {
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
inline void removeMonitor(std::unordered_set<std::string> &chsToBeRemoved) {
    for (auto &ch : chsToBeRemoved) {
        removeMonitor(ch);
    }
}

// this function should be called only when a monitor is created for the first
// time
inline void execMonitor(const std::string &monitorName) {
    initMonitor(monitorName);
    addMonitorCallbacks(monitorName);
    sched.addMonitorRequest(chsActive.at(monitorName));
}
inline void initMonitorTopicRelation() {

$initMonitorTopicRelations

}
