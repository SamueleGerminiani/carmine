#pragma once

#include <deque>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "request.hh"
#include "semaphore.hh"
#include "worker.hh"

class Dispatcher {
   public:
    static void init(size_t n_workers);
    static void stop();
    static void addRequest(Request *request);
    static bool addWorker(Worker *worker);
    static void addSleeper(Request *request);
    static size_t requestLeft();
    static void sleepersHandler();
    static void killRequest(std::vector<Monitor*> &chs);

   private:
    static std::deque<Request *> requests;
    static std::mutex requestsMutex;
    static std::mutex workersMutex;
    static std::mutex sleepersMutex;
    static std::vector<Worker *> allWorkers;
    static std::vector<std::thread *> threads;

    static std::condition_variable workerNotifyNewRequest;
    static std::mutex workerMutexNewRequest;

    static Semaphore* killSema;

    static size_t HPsum;
    static size_t LPsum;

    static std::queue<std::pair<
        Request *, std::chrono::time_point<std::chrono::high_resolution_clock>>>
        sleepers;
    static std::thread *sh;
    static bool stopSH;
};
