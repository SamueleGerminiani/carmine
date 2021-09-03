#include "request.hh"
#include "dispatcher.hh"

void Request::timer() {
     std::this_thread::sleep_for(std::chrono::milliseconds{1});
    sliceEnded = true;
}
void Request::start() { tt = new std::thread(&Request::timer, this); }
void Request::process() {
    while (!sliceEnded) {
        if (!_checker->eval()) {
            _noData = true;
            break;
        }
    }
}
void Request::finish() {
    tt->join();
    delete tt;

    if (!_noData) {
        Dispatcher::addRequest(this);
    } else {
        Dispatcher::addSleeper(this);
        _noData = false;
    }
    sliceEnded = false;
}
