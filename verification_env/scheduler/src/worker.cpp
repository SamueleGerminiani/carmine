#include "worker.hh"
#include "dispatcher.hh"
void Worker::getCondition(std::condition_variable *&cv) { cv = &(this->cv); }
void Worker::run() {


  while (running) {
    if (ready) {
      ready = false;
      request->start();
      request->process();
      request->finish();
    }
    if (Dispatcher::addWorker(this)) {
      while (!ready && running) {
        if (cv.wait_for(ulock, std::chrono::seconds(1)) ==
            std::cv_status::timeout) {
        }
      }
    }

  }
  
  //If the checker relative to the request was paused don't add the request again 
  if(request->_checker->getPhase()==Checker::Phase::active){
	 Dispatcher::addRequest(request);
  }

	else{

		delete request;
	}
  
 
  
}

