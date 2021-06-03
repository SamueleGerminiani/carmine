#pragma once
#include "ros/ros.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <mutex>
#include <vector>
#include "verification_env/initMigration.h"
#include "verification_env/sendBuffer.h"
#define REORDER_TH 10
class Checker {
       public:
	virtual bool eval() = 0;
	size_t getNvars() {
		return nVars;
	}

	enum Phase {active, //Checker is fully working
				pausing, //Checker is suspending: consuming messages until timestamp  
			    paused, //Checker suspended, waiting for a service call
                resumed //State between paused and active, checker resumed from pause
               };

	

	virtual ~Checker(){};


	virtual Phase getPhase() = 0;
	virtual bool needMigration() = 0;
	virtual bool initMigrationClient(std::string remoteHandlerName) = 0;
	virtual bool initMigrationServer(verification_env::initMigration::Request &req, verification_env::initMigration::Response &res) = 0;
	virtual bool sendBufferServer(verification_env::sendBuffer::Request &req, verification_env::sendBuffer::Response &res) = 0;
	virtual void notifyFailure() = 0;

	size_t _priority = 0;
	size_t _evaluationsHP=0;
	size_t _evaluationsLP=0;
       protected:
	Checker(size_t n,size_t priority) : nVars(n), _priority(priority),values_inside(64/nVars) {}

	size_t nVars;
	size_t values_inside;

	template <typename T>
	inline uint64_t readArg(size_t& shift, T arg) {
		return (arg << shift);
	}

	// The recursive case
	template <typename T, typename... R>
	inline uint64_t readArg(size_t& shift, T t, R... args) {
		return (t << shift) | readArg(++shift, args...);
	}

	template <typename T, typename... BooleanValue>
	inline void assign(uint64_t* buff, size_t index, BooleanValue... vi) {
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

	inline uint64_t get(uint64_t* buff, size_t index) {
		return buff[index / values_inside] >>
		       (nVars * (index % values_inside));
	}
};

