#pragma once
#include "request.hh"
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
typedef void (*logfunction)(std::string text);
class Worker {
private:
  std::condition_variable &_newRequestNotify;
  std::mutex &_newRequestMutex;
  Request *request;
  bool running;
  bool ready;
  size_t _id;

public:
  Worker(size_t id,std::condition_variable &cv,std::mutex &mtx) : _id(id),_newRequestNotify(cv), _newRequestMutex(mtx),running(true), ready(false) {
  }
  void run();
  void stop() { running = false; }
  void setRequest(Request *request) { this->request = request; ready = true; }
};
