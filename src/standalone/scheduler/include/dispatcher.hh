#pragma once

#include "request.hh"
#include "worker.hh"
#include <mutex>
#include <thread>
#include <vector>
#include <queue>
#include <deque>
class Dispatcher {

public:
  static bool init(size_t n_workers);
  static bool stop();
  static void addRequest(Request *request);
  static bool addWorker(Worker *worker);
  static void addSleeper(Request *request);
  static size_t requestLeft() ;
  static void sleepersHandler();

private:
  static std::deque<Request *> requests;
  static std::deque<Request *> requestsLP;
  static std::mutex requestsMutex;
  static std::mutex workersMutex;
  static std::mutex sleepersMutex;
  static std::vector<Worker *> allWorkers;
  static std::vector<std::thread*> threads;

static std::queue<std::pair<Request *,std::chrono::time_point<std::chrono::high_resolution_clock>>> sleepers;
  static std::thread* sh;
  static bool stopSH;
};
