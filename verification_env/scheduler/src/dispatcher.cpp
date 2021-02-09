#include "dispatcher.hh"
#include <algorithm>
#include <cassert>
#include <iostream>

std::deque<Request *> Dispatcher::requests;
std::deque<Request *> Dispatcher::requestsLP;
std::queue<Request *> Dispatcher::sleepers;

std::mutex Dispatcher::requestsMutex;
std::mutex Dispatcher::workersMutex;
std::vector<Worker *> Dispatcher::allWorkers;
std::vector<std::thread *> Dispatcher::threads;
std::mutex Dispatcher::sleepersMutex;
std::thread *Dispatcher::sh;
bool Dispatcher::stopSH = false;

bool Dispatcher::init(size_t n_workers) {
	std::thread *t = nullptr;
	Worker *w = nullptr;
	std::cout << "Creating " << n_workers << " workers"
		  << "\n";
	for (size_t i = 0; i < n_workers; i++) {
		w = new Worker;
		allWorkers.push_back(w);
		t = new std::thread(&Worker::run, w);
		threads.push_back(t);
	}

	sh = new std::thread(&sleepersHandler);

	return true;
}
void Dispatcher::addRequest(Request *request) {
	if (request->getPriority() == 2) {
		requestsMutex.lock();
		requests.push_back(request);
		requestsMutex.unlock();
	} else if (request->getPriority() == 1) {
		requestsMutex.lock();
		requestsLP.push_back(request);
		requestsMutex.unlock();
	} else {
		assert(false);
	}
}
void Dispatcher::addSleeper(Request *request) {
	sleepersMutex.lock();
	sleepers.push(request);
	sleepersMutex.unlock();
}
bool Dispatcher::addWorker(Worker *worker) {
	requestsMutex.lock();
	if (requests.empty() && requestsLP.empty()) {
		requestsMutex.unlock();
		return false;
	}
	bool which_queu = (!requests.empty() && requestsLP.empty()) ||
			  (rand() % 9 && !requests.empty());

	if (which_queu) {
		worker->setRequest(requests.front());
		requests.pop_front();
	} else {
		worker->setRequest(requestsLP.front());
		requestsLP.pop_front();
	}
	std::condition_variable *cv;
	worker->getCondition(cv);
	cv->notify_one();
	requestsMutex.unlock();

	return true;
}
bool Dispatcher::stop() {
	stopSH = true;

	for (size_t i = 0; i < allWorkers.size(); i++) {
		allWorkers[i]->stop();
	}
	std::cout << "Stopped workers"
		  << "\n";

	for (size_t i = 0; i < threads.size(); i++) {
		threads[i]->join();
		delete threads[i];
	}
	for (size_t i = 0; i < allWorkers.size(); i++) {
		delete allWorkers[i];
	}
	sh->join();
	delete sh;
	std::cout << "Joined threads"
		  << "\n";

	size_t sum = 0;
	std::vector<Request *> allRequests;
	for (auto &i : requestsLP) {
		allRequests.push_back(i);
	}
	for (auto &i : requests) {
		allRequests.push_back(i);
	}
	while (!sleepers.empty()) {
		allRequests.push_back(sleepers.front());
		sleepers.pop();
	}
	for (auto &i : allRequests) {
		sum += i->_checker->_evaluations;
	}

	size_t HPsum = 0;
	size_t LPsum = 0;
	for (auto &i : allRequests) {
		if (i->getPriority() == 2) {
			HPsum += i->_checker->_evaluations;
		} else {
			LPsum += i->_checker->_evaluations;
		}
	}
	std::cout << "HP usage:" << (double)HPsum / (double)sum * 100.f << "\n";
	std::cout << "LP usage:" << (double)LPsum / (double)sum * 100.f << "\n";

	for (auto &i : allRequests) {
		delete i;
	}

	return true;
}
size_t Dispatcher::requestLeft() {
	size_t res;
	requestsMutex.lock();
	res = requests.size();
	requestsMutex.unlock();
	return res;
}
void Dispatcher::sleepersHandler() {
	while (!stopSH) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		sleepersMutex.lock();
		if(sleepers.empty()){ sleepersMutex.unlock(); continue;}

		/*
		 * all at once
		while (!sleepers.empty()) {
			addRequest(sleepers.front());
			sleepers.pop();
		}
		*/
		
		//one at a time
		addRequest(sleepers.front());
		sleepers.pop();

		sleepersMutex.unlock();
	}
}
