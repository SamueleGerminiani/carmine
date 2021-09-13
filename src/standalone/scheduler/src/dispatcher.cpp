#include "dispatcher.hh"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

std::deque<Request *> Dispatcher::requests;
std::queue<std::pair<
    Request *, std::chrono::time_point<std::chrono::high_resolution_clock>>>
    Dispatcher::sleepers;

std::condition_variable Dispatcher::workerNotifyNewRequest;
std::mutex Dispatcher::workerMutexNewRequest;

std::condition_variable Dispatcher::notifyRequestKilled;
std::mutex Dispatcher::toKillMutex;

std::mutex Dispatcher::requestsMutex;
std::mutex Dispatcher::workersMutex;
std::vector<Worker *> Dispatcher::allWorkers;
std::vector<std::thread *> Dispatcher::threads;
std::mutex Dispatcher::sleepersMutex;
std::thread *Dispatcher::sh;
bool Dispatcher::stopSH = false;
size_t sleeperSpeed = 1;
size_t sleepTime = 100;

void Dispatcher::init(size_t n_workers) {
    std::thread *t = nullptr;
    Worker *w = nullptr;
    std::cout << "Scheduler: using " << n_workers << " threads"
              << "\n";
    for (size_t i = 0; i < n_workers; i++) {
        w = new Worker(i, workerNotifyNewRequest, workerMutexNewRequest);
        allWorkers.push_back(w);
        t = new std::thread(&Worker::run, w);
        threads.push_back(t);
    }

    sh = new std::thread(&sleepersHandler);
}
void Dispatcher::addRequest(Request *request) {
    if (request->_checker->_toKill) {
        delete request;
        notifyRequestKilled.notify_all();
        return;
    }

    requestsMutex.lock();
    requests.push_back(request);
    requestsMutex.unlock();

    workerNotifyNewRequest.notify_one();
}
void Dispatcher::addSleeper(Request *request) {
    sleepersMutex.lock();
    sleepers.push(std::make_pair(request, high_resolution_clock::now()));
    sleepersMutex.unlock();
}
bool Dispatcher::addWorker(Worker *worker) {
    requestsMutex.lock();
    if (requests.empty()) {
        requestsMutex.unlock();
        return false;
    }
    if (requests.front()->_checker->_toKill) {
        Request *r = requests.front();
        requests.pop_front();
        delete r;
        notifyRequestKilled.notify_all();
        if (requests.empty()) {
            requestsMutex.unlock();
            return false;
        }
    }
    worker->setRequest(requests.front());
    requests.pop_front();
    requestsMutex.unlock();
    return true;
}
void Dispatcher::stop() {
    stopSH = true;
    sh->join();
    delete sh;

    for (size_t i = 0; i < allWorkers.size(); i++) {
        allWorkers[i]->stop();
    }
    std::cout << "Stopped workers"
              << "\n";

    for (size_t i = 0; i < threads.size(); i++) {
        threads[i]->join();
        delete threads[i];
    }
    std::cout << "Joined threads"
              << "\n";
    for (size_t i = 0; i < allWorkers.size(); i++) {
        delete allWorkers[i];
    }

    std::vector<Request *> allRequests;
    for (auto &i : requests) {
        allRequests.push_back(i);
    }
    while (!sleepers.empty()) {
        allRequests.push_back(sleepers.front().first);
        sleepers.pop();
    }

    for (auto &i : allRequests) {
        delete i;
    }
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
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeperSpeed));
        sleepersMutex.lock();

        while (!sleepers.empty() &&
               duration_cast<milliseconds>(high_resolution_clock::now() -
                                           sleepers.front().second)
                       .count() > sleepTime) {
            addRequest(sleepers.front().first);
            sleepers.pop();
        }

        sleepersMutex.unlock();
    }
}
void Dispatcher::killRequest(Checker *ch) {
    std::unique_lock<std::mutex> ulock(Dispatcher::toKillMutex);

    ch->_toKill = 1;
    Dispatcher::notifyRequestKilled.wait(ulock);
}
