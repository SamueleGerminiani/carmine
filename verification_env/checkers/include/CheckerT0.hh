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
#include "nav_msgs/Odometry.h"
#include "nav_msgs/Odometry.h"
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

   void addEvent_var0(ros::Time ts, unsigned int value);
   void addEvent_var1(ros::Time ts, float value);


	union Value{
      Value(const unsigned int var, size_t id): _x(var){}
      Value(const float var, size_t id): _y(var){}
      unsigned int _x;
      float _y;

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
	size_t eventsInBuffer = 0;
	std::mutex buff_mutex;
	std::mutex addEvent_mutex;
	std::mutex notify_mutex;
	std::mutex state_mutex;
};
