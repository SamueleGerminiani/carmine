#pragma once
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>

#include "Checker.hpp"
#define TO_PROCESS 1000000
typedef void (*logfunction)(std::string text);
class Request {
       private:
	int value;
	// size_t toProcess=TO_PROCESS;
	size_t priority = 1;
	logfunction outFnc;
	bool sliceEnded = false;
	bool _noData = false;
	std::mutex sliceMutex;
	std::mutex lockMutex;
	std::unique_lock<std::mutex> lock{lockMutex};
	void timer();
	std::thread *tt;
	std::condition_variable cv;

       public:
	Request(size_t pri,Checker* checker) : priority(pri), _checker(checker) {}
	void setValue(int value) { this->value = value; }
	void setOutput(logfunction fn) { outFnc = fn; }
	void start();
	void process();
	void finish();
	size_t getPriority() const { return priority; }
	Checker* _checker;
};
