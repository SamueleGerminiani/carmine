#include "request.hh"
#include "dispatcher.hh"

void Request::timer() {
	cv.wait_for(lock, std::chrono::milliseconds{1});
	sliceEnded = true;
}
void Request::start() {
	tt = new std::thread(&Request::timer, this);
}
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
	cv.notify_one();
	Dispatcher::addRequest(this);
	std::cout << "Slice ended!" << "\n";
} else {
	Dispatcher::addSleeper(this);
	_noData = false;
	 std::cout << "Ran out of data!" <<"\n";
}
	sliceEnded = false;
}
