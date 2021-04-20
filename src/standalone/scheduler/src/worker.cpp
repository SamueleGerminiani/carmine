#include "worker.hh"
#include "dispatcher.hh"
#include <chrono>
void Worker::run() {



  while (running) {
    if (!Dispatcher::addWorker(this)) {
        std::unique_lock<std::mutex> ulock(_mtx);
        _cv.wait_for(ulock,std::chrono::milliseconds(500));
    }
    
    if (ready) {
      ready = false;
      request->start();
      request->process();
      request->finish();
    }
  }
  
  //If the checker relative to the request was paused don't add the request again 
//  if(request->_checker->getPhase()!=Checker::Phase::active){
//		delete request;
//	}
  
  
 
  
}

