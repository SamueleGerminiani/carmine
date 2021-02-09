#pragma once
#include "request.hh"
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
typedef void (*logfunction)(std::string text);
class Worker {
private:
  std::condition_variable cv;
  std::mutex mtx;
  Request *request;
  bool running;
  bool ready;
  std::unique_lock<std::mutex> ulock;

public:
  Worker()
      : running(true), ready(false), ulock(std::unique_lock<std::mutex>(mtx)) {
  }
  void run();
  void stop() { running = false; }
  void setRequest(Request *request) { this->request = request; ready = true; }
  void getCondition(std::condition_variable *&cv);
};
