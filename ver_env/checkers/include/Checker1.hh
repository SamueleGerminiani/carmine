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
#include "sensor_msgs/JointState.h"


class Checker1 : public Checker {
   public:
    Checker1(size_t nVars, size_t priority, std::string handlerName,
              std::string checkerName);

    ~Checker1() override;
    bool eval() override;
    void notifyFailure() override;
    void clearData() override;
   void addEvent_ef12(ros::Time ts, double value);
   void addEvent_ef13(ros::Time ts, double value);


   private:

   bool eval_Checker1(bool p0,bool p1,bool reset = false);

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
      Value(const double var, size_t id){
         switch (id) {
            case 0:
               _ef12 = var;
               break;
            case 1:
               _ef13 = var;
               break;
            }
         }
      double _ef12;
      double _ef13;

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
    size_t _currAss[5];
    size_t _nextAss[5];
    size_t _currAnt[3];
    size_t _nextAnt[3];
   bool _last_p0 = false;
   bool _last_p1 = false;

};
