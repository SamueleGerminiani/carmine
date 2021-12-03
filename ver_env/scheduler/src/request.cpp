#include "request.hh"
#include "dispatcher.hh"

void Request::timer() {
    std::unique_lock<std::mutex> ulock(reqAbruptEndMutex);
    reqNotifyAbruptEnd.wait_for(ulock, std::chrono::milliseconds(1));
    sliceEnded = true;
}
void Request::start() {
    _noData = false;
    sliceEnded = false;
    tt = new std::thread(&Request::timer, this);
}
void Request::process() {
    while (!sliceEnded && !_checker->_toKill) {
        if (!_checker->eval()) {
            _noData = true;
            break;
        }
    }
}
void Request::finish() {
    // end timer
    reqNotifyAbruptEnd.notify_one();
    tt->join();
    delete tt;

    if (!_noData) {
//        std::cout << "-----------------------------------------------------Ran out of data!" << "\n";
        Dispatcher::addRequest(this);
    } else {
        Dispatcher::addSleeper(this);
    }
}
