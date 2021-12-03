#pragma once
#include <ros/callback_queue.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstdarg>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <vector>
#include "Checker.hpp"
$msgHeaders

class $ClassName$ : public Checker {
   public:
    $ClassName$(size_t nVars, size_t priority, std::string handlerName,
              std::string checkerName);

    ~$ClassName$() override;
    bool eval() override;
    void notifyFailure() override;
    void clearData() override;
$addEvent

   private:

$eval
    void reorder(bool forceReorder = false);
    void addTimerValue(size_t timerID);
    bool getTimerValue(size_t timerID, size_t timerInstance, bool isAss);
    void popTimerInst(size_t timerID, size_t nToErase);
    void resetChecker();

    ros::Time migrateFromHandleTSbefore() override;
    void migrateFromHandleTSAfter(const ros::Time &ts) override;
    void migrateFromHandleData(ver_env::checkerData &res) override;
    ros::Time migrateToHandleTS(const ros::Time &ts) override;
    void migrateToHandleData(ver_env::checkerData &res) override;

    union Value {
$value
    };
    // used to have a common data type for all variables <timestamp,var>
    // that can be stored in a 'vector'
    struct Event {
        Event(ros::Time timeStamp, Value value, size_t type)
            : _timeStamp(timeStamp), _value(value), _type(type) {
            // not todo
        }
        ros::Time _timeStamp;
        size_t _type;
        Value _value;
    };

    std::vector<Event> _vbuff;
    size_t _currAss[$nStatesAss$];
    size_t _nextAss[$nStatesAss$];
    size_t _currAnt[$nStatesAnt$];
    size_t _nextAnt[$nStatesAnt$];
$init_p
};
