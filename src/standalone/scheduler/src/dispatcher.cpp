#include "dispatcher.hh"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
std::deque<Request *> Dispatcher::requests;
std::deque<Request *> Dispatcher::requestsLP;
std::queue<std::pair<
    Request *, std::chrono::time_point<std::chrono::high_resolution_clock>>>
    Dispatcher::sleepers;
std::condition_variable cv;
std::mutex mtx;

std::mutex Dispatcher::requestsMutex;
std::mutex Dispatcher::workersMutex;
std::vector<Worker *> Dispatcher::allWorkers;
std::vector<std::thread *> Dispatcher::threads;
std::mutex Dispatcher::sleepersMutex;
std::thread *Dispatcher::sh;
bool Dispatcher::stopSH = false;
size_t sleeperSpeed = 1;
size_t sleepTime = 100;
auto t1 = high_resolution_clock::now();
size_t rc=0;


bool Dispatcher::init(size_t n_workers) {
    std::thread *t = nullptr;
    Worker *w = nullptr;
    std::cout << "Creating " << n_workers << " workers"
              << "\n";
    for (size_t i = 0; i < n_workers; i++) {
        w = new Worker(i,cv, mtx);
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
//    rc++;
//    if (rc%100==0) {
//    auto t2 = high_resolution_clock::now();
//    auto ms_int = duration_cast<milliseconds>(t2 - t1);
//    std::cout << (double)rc/((double)ms_int.count() / 1000) << "\n";
        
    //}
    
    cv.notify_one();
}
void Dispatcher::addSleeper(Request *request) {
    sleepersMutex.lock();
    sleepers.push(std::make_pair(request, high_resolution_clock::now()));
    sleepersMutex.unlock();
}
bool Dispatcher::addWorker(Worker *worker) {
    requestsMutex.lock();
    if (requests.empty() && requestsLP.empty()) {
        requestsMutex.unlock();
        return false;
    }
    bool which_queu = !requests.empty();

    if (which_queu) {
        worker->setRequest(requests.front());
        requests.pop_front();
    } else {
        worker->setRequest(requestsLP.front());
        requestsLP.pop_front();
    }
    requestsMutex.unlock();

    return true;
}
bool Dispatcher::stop() {
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
    for (auto &i : requestsLP) {
        allRequests.push_back(i);
    }
    for (auto &i : requests) {
        allRequests.push_back(i);
    }
    while (!sleepers.empty()) {
        allRequests.push_back(sleepers.front().first);
        sleepers.pop();
    }

    size_t HPsum = 0;
    size_t LPsum = 0;

    for (auto &i : allRequests) {
        HPsum += i->_checker->_evaluationsHP;
        LPsum += i->_checker->_evaluationsLP;
    }
    size_t sum = HPsum + LPsum;
    std::cout << "HP usage:" << (double)HPsum / (double)sum * 100.f << "\n";
    std::cout << "LP usage:" << (double)LPsum / (double)sum * 100.f << "\n";

    if (allRequests.size() != 1) {
        std::cout << "Size:" << allRequests.size() << "\n";
        assert(0);
    }
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
