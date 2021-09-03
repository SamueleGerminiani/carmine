#include "worker.hh"
#include "dispatcher.hh"
#include <chrono>
void Worker::run() {

  while (running) {
    if (!Dispatcher::addWorker(this)) {
        std::unique_lock<std::mutex> ulock(_newRequestMutex);
        _newRequestNotify.wait_for(ulock,std::chrono::milliseconds(500));
    }
    
    if (ready) {
      ready = false;
      request->start();
      request->process();
      request->finish();
    }
  }
  
}

