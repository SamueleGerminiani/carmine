#pragma once
#include <actionlib/client/simple_action_client.h>
#include <verification_env/migrateAction.h>
#include "ros/ros.h"

#include <algorithm>
#include <boost/chrono.hpp>
#include <boost/chrono/duration.hpp>
#include <cassert>
#include <chrono>
#include <deque>
#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>
#include <vector>
#define REORDER_TH 10
#define BUFF_SIZE 1'000'000
typedef actionlib::SimpleActionClient<verification_env::migrateAction> Client;
class Checker {
   public:
    virtual bool eval() = 0;

    virtual ~Checker(){};

    virtual void notifyFailure() = 0;
    virtual void clearData() = 0;
    virtual ros::Time migrateFromHandleTSbefore() = 0;
    virtual void migrateFromHandleTSAfter(const ros::Time &ts) = 0;
    virtual void migrateFromHandleData(verification_env::checkerData &res) = 0;
    virtual ros::Time migrateToHandleTS(const ros::Time &ts)=0;
    virtual void migrateToHandleData(verification_env::checkerData &res)=0;

    size_t getNvars() { return nVars; }

    size_t _priority = 0;
    bool _toKill = false;
    std::string _handlerName, _checkerName;
    size_t _evalSpeed = 0;
    size_t _numberOfAddEvent = 0;
    size_t _topicSpeed = 0;
    double _CPUusage = 0;
    std::deque<double> _evalSpeedWindow;
    std::deque<double> _topicSpeedWindow;
    std::deque<double> _cpuUsageWindow;
    const size_t _windowMaxSize = 5;

   protected:
    ros::Time _last_msg_ts = ros::Time(0);
    size_t _evalIndex_p = 0;
    size_t _index_p = 0;
    uint64_t *_order = nullptr;
    uint64_t *_pbuff = nullptr;
    std::map<size_t, std::deque<double>> _timerInstances;
    std::map<size_t, std::deque<bool>> _timerCache;
    std::vector<size_t> _timeouts;
    int _conIns = 0;
    int _endIns = 0;
    size_t _eventsInBuffer = 0;
    std::mutex _buff_mutex;
    std::mutex _addEvent_mutex;

   protected:
    Checker(size_t n, size_t priority)
        : nVars(n), _priority(priority), values_inside(64 / nVars) {}

    size_t nVars;
    size_t values_inside;

    template <typename T>
    inline uint64_t readArg(size_t &shift, T arg) {
        return (arg << shift);
    }

    // The recursive case
    template <typename T, typename... R>
    inline uint64_t readArg(size_t &shift, T t, R... args) {
        return (t << shift) | readArg(++shift, args...);
    }

    template <typename T, typename... BooleanValue>
    inline void assign(uint64_t *buff, size_t index, BooleanValue... vi) {
        size_t tPos = index / values_inside;
        size_t shift = nVars * (index % values_inside);
        size_t intShift = 0;
        uint64_t value = readArg(intShift, vi...);

        value = value << shift;

        // delete value
        buff[tPos] = buff[tPos] & ~(((1ULL << nVars) - 1) << shift);

        // set new value
        buff[tPos] = buff[tPos] | value;
    }

    inline uint64_t get(uint64_t *buff, size_t index) {
        return buff[index / values_inside] >> (nVars * (index % values_inside));
    }
};

