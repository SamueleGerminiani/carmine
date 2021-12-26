
#pragma once
#include <deque>
#include "globals.hh"

#define WINDOW(var, value, type, wsize)                                         \
    {                                                                          \
        static std::deque<type> var_window;                                    \
        var_window.push_front(value);                                          \
        if (var_window.size() == wsize) {                                       \
            var_window.pop_back();                                             \
        }                                                                      \
        var = std::accumulate(var_window.begin(), var_window.end(), (type)0) / \
              (type)var_window.size();                                         \
    }

inline void statHandler() {
    initCPU();
    initCPUTot();

    while (ros::ok()) {
        for (size_t i = 0; i < 5; i++) {
        WINDOW(wholeNodeUsage,
               getCurrentValue() * std::thread::hardware_concurrency(), double,
               20);
        WINDOW(wholeMachineUsage,
               getCurrentValueTot() * std::thread::hardware_concurrency(),
               double, 20);
        ros::Duration(0.02).sleep();
        }
        

        for (auto &t : allTopics) {
            pingTopic(t);
        }

        machineCPUfreq=getThiscpuFreq();


        sendStatToCoordinator();
    }
}
