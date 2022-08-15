#include <chrono>
#include <chrono>
#include <csignal>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include "Monitor.hpp"
#include "dispatcher.hh"
#include "request.hh"
class Scheduler {
   public:
    Scheduler(size_t nWorkers) : _nWorkers(nWorkers) {
        // not todo
    }
    void stop() {
        _stop = true;
        Dispatcher::stop();
        std::cout << "Scheduler stopped!"
                  << "\n";
    }
    void start() { Dispatcher::init(_nWorkers); }

    void addMonitorRequest(Monitor* ch) {
        Request* rq = new Request(ch);
        Dispatcher::addRequest(rq);
    }
    void removeMonitorRequest(std::vector<Monitor*> &ch) {
        const std::lock_guard<std::mutex> lock(_removeMonitorRequestMutex);
        Dispatcher::killRequest(ch);
    }

   private:
    bool _stop = false;
    size_t _nWorkers;
    std::mutex _removeMonitorRequestMutex;
};
