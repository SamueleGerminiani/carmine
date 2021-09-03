#pragma once
#include <mutex>
#include <string>
#include <thread>

#include "Checker.hpp"
class Request {
   private:
    bool sliceEnded = false;
    bool _noData = false;
    std::mutex sliceMutex;
    std::mutex lockMutex;
    std::unique_lock<std::mutex> lock{lockMutex};
    std::thread* tt;
    void timer();

   public:
    Request(Checker* checker) : _checker(checker) {}
    void start();
    void process();
    void finish();
    size_t getPriority() const { return _checker->_priority; }
    Checker* _checker;
};
