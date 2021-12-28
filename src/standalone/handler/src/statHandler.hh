
#pragma once
#include <deque>
#include "globals.hh"

#define WINDOW(var, value, type, wsize)                                         \
    {                                                                          \
        static std::deque<type> var_window;                                    \
        var_window.push_front(value);                                          \
        if (var_window.size() > wsize) {                                       \
            var_window.pop_back();                                             \
        }                                                                      \
        var = std::accumulate(var_window.begin(), var_window.end(), (type)0) / \
              (type)var_window.size();                                         \
    }


inline void statHandler() {
    initCPU();
    initCPUTot();

    while (ros::ok()) {

        WINDOW(wholeNodeUsage,
               getCurrentValue() * std::thread::hardware_concurrency(), double,
               10);

        WINDOW(wholeMachineUsage,
               getCurrentValueTot() * std::thread::hardware_concurrency(),
               double, 10);

        

        for (auto &t : allTopics) {
            pingTopic(t);
        }

        machineCPUfreq=getThiscpuFreq();


        sendStatToCoordinator();

        ros::Duration(0.1).sleep();
    }
}
