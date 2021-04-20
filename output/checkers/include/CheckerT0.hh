#pragma once
#include <ros/callback_queue.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <mutex>
#include <thread>
#include <cstdarg>
#include <vector>
#include "Checker.hpp"
#include <chrono>
#include <map>
#include <deque>
#include "msg_gen/Num.h"
#include "msg_gen/Num.h"
#define INIT_CheckerT0 0

#define BUFF_SIZE 1'000'000
#define MIGRATION_TH 10
class CheckerT0 : public Checker {
public:

	CheckerT0(size_t nVars,size_t priority, std::string handlerName, std::string checkerName, bool server);

	

	bool eval() override;

	~CheckerT0() override;

	Phase getPhase() override;

	

	bool initMigrationClient(std::string remoteHandlerName) override;
	bool initMigrationServer(verification_env::initMigration::Request &req, verification_env::initMigration::Response &res) override;

	bool sendBufferClient(std::string remoteHandlerName);
	bool sendBufferServer(verification_env::sendBuffer::Request &req, verification_env::sendBuffer::Response &res) override;


	bool floatEquals(const float &d1, const float &d2);
	bool doubleEquals(const double &d1, const double &d2);
	
	bool needMigration() override;

	void reorder(bool forceReorder = false);

	void notifyFailure() override;

   void addEvent_var0(ros::Time ts, bool value);
   void addEvent_var1(ros::Time ts, bool value);


	union Value{
      Value(const bool var, size_t id){
         switch (id) {
            case 0:
               _v1 = var;
               break;
            case 1:
               _v2 = var;
               break;
            }
         }
      bool _v1;
      bool _v2;

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

	std::vector<Event> vbuff;

   bool eval_CheckerT0(bool p0,bool p1,bool reset = false);

	
	
    void addTimerValue(size_t timerID) {
        _timerInstances[timerID].push_back(ros::Time::now().toSec() * 1000);
    }
    void popTimerInst(size_t timerID, size_t nToErase) {
        if (_timerInstances.at(timerID).empty()) {
            return;
        }
        _timerInstances.at(timerID).erase(
            begin(_timerInstances.at(timerID)),
            begin(_timerInstances.at(timerID)) + nToErase);
    }
    bool getTimerValue(size_t timerID, size_t timerInstance, bool isAss) {
        if (isAss) {
            if (_timerInstances.at(timerID).empty()) {
                _timerCache[timerID].push_back(0);
                return 0;
            }
            double now = ros::Time::now().toSec() * 1000;
            bool val = (now - _timerInstances.at(timerID)[timerInstance]) >
                       _timeouts[timerID];
            _timerCache[timerID].push_back(val);
            return val;
        } else {
            bool val = _timerCache.at(timerID).front();
            _timerCache.at(timerID).pop_front();
            return val;
        }
    }
    void resetChecker() {
        for (size_t j = 0; j < 4; j++) {
            currAss[j] = 0;
            nextAss[j] = 0;
        }
        for (size_t j = 0; j < 3; j++) {
            currAnt[j] = 0;
            nextAnt[j] = 0;
        }
        for (auto &e : _timerInstances) {
            e.second.clear();
        }
        for (auto &e : _timerCache) {
            e.second.clear();
        }
        printOnce1 = 1;
        printOnce2 = 1;
        conIns = 0;
        endIns = 0;
    }
	
	
	Checker::Phase checkerPhase;
	ros::Time timestampToReach;
	int NEXT_STATE;	

	std::string _handlerName, _checkerName,_remoteHandlerName;
	
	
	size_t evalIndex_p = 0;
	size_t index_p = 0;

   bool last_p0 = false;
   bool last_p1 = false;

	
	uint64_t* order;
	uint64_t* pbuff;
    std::map<size_t, std::deque<double>> _timerInstances;
    std::map<size_t, std::deque<bool>> _timerCache;
    std::vector<size_t> _timeouts;
    size_t currAss[4];
    size_t nextAss[4];
    size_t currAnt[3];
    size_t nextAnt[3];
    bool printOnce1 = 1;
    bool printOnce2 = 1;
    int conIns = 0;
    int endIns = 0;
	size_t eventsInBuffer = 0;
	std::mutex buff_mutex;
	std::mutex addEvent_mutex;
	std::mutex notify_mutex;
	std::mutex state_mutex;
};
