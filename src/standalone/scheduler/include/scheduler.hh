#include <chrono>
#include <csignal>
#include <iostream>
#include <string>
#include <thread>
#include "dispatcher.hh"
#include "request.hh"
#include "Checker.hpp"
class Scheduler {
       public:
	Scheduler(size_t nWorkers, std::map<std::string,Checker*> &checkers)
	    : _nWorkers(nWorkers), _checkers(checkers) {
		// not todo
	}
	void stop() {
		_stop = true;
		Dispatcher::stop();
		std::cout << "Scheduler stopped!"
			  << "\n";
	}
	void start() {
		Dispatcher::init(_nWorkers);
		std::cout << "Init"
			  << "\n";
		Request *rq = nullptr;
		for (auto kv: _checkers) {
			rq = new Request(kv.second->_priority,kv.second);
			Dispatcher::addRequest(rq);
		}
	}

	void addCheckerRequest(Checker* ch){
		Request *rq = new Request(ch->_priority,ch);
		Dispatcher::addRequest(rq);
	}

       private:
	bool _stop = false;
	size_t _nWorkers;
	std::map<std::string,Checker*> &_checkers;
};
