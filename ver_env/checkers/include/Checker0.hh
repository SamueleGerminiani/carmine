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
#include "msg_gen/Num.h"


class Checker0 : public Checker {
   public:
    Checker0(size_t nVars, size_t priority, std::string handlerName,
              std::string checkerName);

    ~Checker0() override;
    bool eval() override;
    void notifyFailure() override;
    void clearData() override;
   void addEvent_v1(ros::Time ts, bool value);
   void addEvent_v2(ros::Time ts, bool value);
   void addEvent_v3(ros::Time ts, bool value);


   private:

   bool eval_Checker0(bool p0,bool p1,bool p2,bool reset = false);

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
      Value(const bool var, size_t id){
         switch (id) {
            case 0:
               _v1 = var;
               break;
            case 1:
               _v2 = var;
               break;
            case 2:
               _v3 = var;
               break;
            }
         }
      bool _v1;
      bool _v2;
      bool _v3;

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
    size_t _currAss[6];
    size_t _nextAss[6];
    size_t _currAnt[4];
    size_t _nextAnt[4];
   bool _last_p0 = false;
   bool _last_p1 = false;
   bool _last_p2 = false;

};
