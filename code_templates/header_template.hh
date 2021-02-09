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
$msgHeaders
#define BUFF_SIZE 1'000'000
#define MIGRATION_TH 10
class $ClassName$ : public Checker {
public:

	$ClassName$(size_t nVars,size_t priority, std::string handlerName, std::string checkerName, bool server);

	

	bool eval() override;

	~$ClassName$() override;

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

$addEvent

	union Value{
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

	std::vector<Event> vbuff;

$eval
	
	
	
	
	Checker::Phase checkerPhase;
	ros::Time timestampToReach;
	int NEXT_STATE;	

	std::string _handlerName, _checkerName,_remoteHandlerName;
	
	
	size_t evalIndex_p = 0;
	size_t index_p = 0;

$init
	
	uint64_t* order;
	uint64_t* pbuff;
	size_t eventsInBuffer = 0;
	std::mutex buff_mutex;
	std::mutex addEvent_mutex;
	std::mutex notify_mutex;
	std::mutex state_mutex;
};
