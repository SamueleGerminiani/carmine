
#pragma once
#include "globals.hh"

inline void statHandler() {
    initCPU();
    initCPUTot();

    while (ros::ok()) {
        ros::Duration(0.1).sleep();

        for (auto &t : allTopics) {
            pingTopic(t);
        }

        wholeNodeUsage =
            getCurrentValue() * std::thread::hardware_concurrency();
        wholeMachineUsage =
            getCurrentValueTot() * std::thread::hardware_concurrency();

        sendStatToCoordinator();
    }
}
