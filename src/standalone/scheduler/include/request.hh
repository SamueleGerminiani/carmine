#pragma once
#include <mutex>
#include <thread>
#include <condition_variable>
#include <string>

#include "Monitor.hpp"
class Request {
   private:
    bool sliceEnded = false;
    bool _noData = false;
    std::mutex sliceMutex;
    std::mutex lockMutex;
    std::unique_lock<std::mutex> lock{lockMutex};
    std::thread* tt;
    std::condition_variable reqNotifyAbruptEnd;
    std::mutex reqAbruptEndMutex;
    void timer();

   public:
    Request(Monitor* monitor) : _monitor(monitor) {}
    void start();
    void process();
    void finish();
    size_t getPriority() const { return _monitor->_priority; }
    Monitor* _monitor;
};
