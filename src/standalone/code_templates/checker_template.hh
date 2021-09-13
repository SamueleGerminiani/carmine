#pragma once
#include "Checker.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstdarg>
#include <iostream>
#include <map>
#include <mutex>
#include <ros/callback_queue.h>
#include <thread>
#include <vector>
$msgHeaders
#define BUFF_SIZE 1'000'000
#define MIGRATION_TH 10

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

  void migrateFrom(const std::string &toHandler, ros::NodeHandle *n) override;
  void migrateTo(verification_env::migrate::Request &req,
                 verification_env::migrate::Response &res) override;

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
