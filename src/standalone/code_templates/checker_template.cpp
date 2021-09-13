#include "$ClassName$.hh"
#include <thread>

void $ClassName$::notifyFailure() {
    std::cout << ros::this_node::getName() << ": Checker " << _checkerName
              << " failed, resetting" << std::endl;
}

$ClassName$::$ClassName$(size_t nVars, size_t priority, std::string handlerName,
                     std::string checkerName)
    : Checker(nVars, priority) {
    // init buffers
    _pbuff = new uint64_t[BUFF_SIZE * values_inside];
    _order = new uint64_t[BUFF_SIZE * values_inside];
    _evalIndex_p = 0;
    _index_p = 0;
    _eventsInBuffer = 0;

    _handlerName = handlerName;
    _checkerName = checkerName;

$initTimers$
    resetChecker();
}

$ClassName$::~$ClassName$() {
	delete[] _pbuff;
	delete[] _order;
}


void $ClassName$::clearData() {
    _vbuff.clear();
    _evalIndex_p = 0;
    _index_p = 0;
    _eventsInBuffer = 0;
$clearData
    _last_msg_ts = ros::Time(0);
    _toKill=0;
    resetChecker();
}


// function used in Request to eval a checker until the slice or available
// events end
bool $ClassName$::eval() {
	
    _addEvent_mutex.lock();
    reorder();
    _addEvent_mutex.unlock();

    if (_eventsInBuffer == 0) {
        // finished the available data
        return false;
    }

    _eventsInBuffer--;

    /*We eval one event at a time
    //ex. If we have v0 in the buffer as next element, the evaluation uses
    the new v0 and the old values for v1 and v2.*/
    uint64_t order_entry = get(_order, _evalIndex_p);
    uint64_t pbuff_entry = get(_pbuff, _evalIndex_p);

$order_entry


	_evalIndex_p = (_evalIndex_p >= BUFF_SIZE - 1) ? 0 : _evalIndex_p + 1;

$call_eval
	return true;
}

$FSM

// reorder using the timestamp
void $ClassName$::reorder(bool forceReorder) {
	if (_vbuff.size() >= REORDER_TH || forceReorder) {
		std::sort(std::begin(_vbuff), std::end(_vbuff),
			[](const Event& e1, const Event& e2) {
				return e1._timeStamp < e2._timeStamp;
			});
		
$static_vars

		for (auto event : _vbuff) {
			switch (event._type) {
$cases
				default:
				assert(false);
			}
			// fails if there are more than BUFF_SIZE unevaluated
			// events
			assert(!(_index_p < _evalIndex_p && (_index_p + 1 == _evalIndex_p)));

			_index_p = (_index_p >= BUFF_SIZE - 1) ? 0 : _index_p + 1;

			//'eventInbuffer' is used in eval in parallel
			_eventsInBuffer++;
		}
		_vbuff.clear();
	}
}


$addEvent

void $ClassName$::addTimerValue(size_t timerID) {
    _timerInstances[timerID].push_back(ros::Time::now().toSec() * 1000);
}
void $ClassName$::popTimerInst(size_t timerID, size_t nToErase) {
    if (_timerInstances.at(timerID).empty()) {
        return;
    }
    _timerInstances.at(timerID).erase(
        begin(_timerInstances.at(timerID)),
        begin(_timerInstances.at(timerID)) + nToErase);
}
bool $ClassName$::getTimerValue(size_t timerID, size_t timerInstance,
                              bool isAss) {
    if (isAss) {
        if (timerInstance >= _timerInstances.at(timerID).size()) {
            _timerCache[timerID].push_back(0);
            return 0;
        }
        double now = ros::Time::now().toSec() * 1000;
        bool val = (now - _timerInstances.at(timerID)[timerInstance]) >
                   _timeouts[timerID];
        _timerCache[timerID].push_back(val);
        return val;
    } else {
        assert(!_timerCache.at(timerID).empty());
        bool val = _timerCache.at(timerID).front();
        _timerCache.at(timerID).pop_front();
        return val;
    }
}

void $ClassName$::resetChecker() {
        for (size_t j = 0; j < $nStatesAss$; j++) {
            _currAss[j] = 0;
            _nextAss[j] = 0;
        }
        for (size_t j = 0; j < $nStatesAnt$; j++) {
            _currAnt[j] = 0;
            _nextAnt[j] = 0;
        }
        for (auto &e : _timerInstances) {
            e.second.clear();
        }
        for (auto &e : _timerCache) {
            e.second.clear();
        }
        _conIns = 0;
        _endIns = 0;

}

void $ClassName$::migrateFrom(const std::string &toHandler, ros::NodeHandle *n) {
    std::cout << "Client: initiated migration from "
              << toHandler + "/migrate/" + _checkerName << std::endl;
    ros::ServiceClient client = n->serviceClient<verification_env::migrate>(
        toHandler + "/migrate/" + _checkerName);
    verification_env::migrate srv;
    srv.request.checkerName = _checkerName;
    while (_last_msg_ts == ros::Time(0)) {
        ros::Duration(0.01).sleep();
    }
    _addEvent_mutex.lock();
    srv.request.stamp = _last_msg_ts;
    _addEvent_mutex.unlock();

    if (!client.call(srv)) {
        ROS_INFO("Client: failed to call migrate on remote node");
        assert(0);
        exit(1);
    }
    while (srv.response.last_msg_ts > _last_msg_ts) {
        ros::Duration(0.01).sleep();
    }

    // buff

    _addEvent_mutex.lock();
    std::sort(std::begin(_vbuff), std::end(_vbuff),
              [](const Event &e1, const Event &e2) {
                  return e1._timeStamp < e2._timeStamp;
              });
    auto ts = srv.response.last_msg_ts;
    auto it = std::find_if(_vbuff.begin(), _vbuff.end(), [&ts](const Event &v) {
        return v._timeStamp >= ts;
    });
    assert(it != _vbuff.end());
    _last_msg_ts = it->_timeStamp;
    _vbuff.erase(_vbuff.begin(), it + 1);
    std::cout << srv.response.last_msg_ts << " --> " << _last_msg_ts << "\n";

    std::cout << "Buff size: " << srv.response.buffer_p.size() << "\n";

    for (int i = 0; i < srv.response.buffer_p.size(); i++) {
        auto val = (srv.response.buffer_p)[i];
$setBuffer
        _index_p = (_index_p >= BUFF_SIZE - 1) ? 0 : _index_p + 1;
        _eventsInBuffer++;
    }
    _addEvent_mutex.unlock();

    // timers
    size_t lastB = 0;
    for (size_t i = 0; i < _timeouts.size(); i++) {
        for (size_t j = lastB; j < srv.response.timerBounds[i]; j++) {
            _timerInstances.at(i).push_back(srv.response.timerInstances[j]);
        }
        for (size_t j = lastB; j < srv.response.timerBounds[i]; j++) {
            _timerCache.at(i).push_back(srv.response.timerCache[j]);
        }
        assert(_timerInstances.at(i).size() == _timerCache.at(i).size());
        lastB = srv.response.timerBounds[i];
    }

    // state
    int assSize = sizeof(_currAss) / sizeof(_currAss[0]);
    for (size_t i = 0; i < assSize; i++) {
        _currAss[i] = srv.response.currAss[i];
        _nextAss[i] = srv.response.nextAss[i];
    }

    int antSize = sizeof(_currAnt) / sizeof(_currAnt[0]);
    for (size_t i = 0; i < antSize; i++) {
        _currAnt[i] = srv.response.currAnt[i];
        _nextAnt[i] = srv.response.nextAnt[i];
    }

    _conIns = srv.response.conIns;
    _endIns = srv.response.endIns;
$setInit_p_MF

    if (srv.response.response) {
        ROS_INFO("Success!");
    } else {
        ROS_INFO("Failed!");
    }

}
void $ClassName$::migrateTo(verification_env::migrate::Request &req,
                          verification_env::migrate::Response &res) {
    std::cout << "Server: timestamp " << req.stamp << "\n";
    while (_last_msg_ts < req.stamp) {
        ros::Duration(0.01).sleep();
    }

    _addEvent_mutex.lock();
    res.last_msg_ts = _last_msg_ts;
    reorder(1);
    // buffers
    if (_evalIndex_p <= _index_p) {
        for (int i = _evalIndex_p; i < _index_p; i++) {
            res.buffer_p.push_back(get(_pbuff, i));
            res.buffer_o.push_back(get(_order, i));
        }
    } else {
        res.buffer_p.assign(_pbuff + _evalIndex_p,
                            _pbuff + BUFF_SIZE * values_inside);
        res.buffer_o.assign(_order + _evalIndex_p,
                            _order + BUFF_SIZE * values_inside);
        for (int i = 0; i <= _index_p; i++) {
            res.buffer_p.push_back(_pbuff[i]);
            res.buffer_o.push_back(_order[i]);
        }
    }
    _addEvent_mutex.unlock();

    // timers
    for (size_t i = 0; i < _timeouts.size(); i++) {
        res.timerBounds.push_back(_timerInstances.at(i).size());
        for (auto &f : _timerInstances.at(i)) {
            res.timerInstances.push_back(f);
        }
        for (auto &f : _timerCache.at(i)) {
            res.timerCache.push_back(f);
        }
    }

    // state
    int assSize = sizeof(_currAss) / sizeof(_currAss[0]);
    for (size_t i = 0; i < assSize; i++) {
        res.currAss.push_back(_currAss[i]);
        res.nextAss.push_back(_nextAss[i]);
    }

    int antSize = sizeof(_currAnt) / sizeof(_currAnt[0]);
    for (size_t i = 0; i < antSize; i++) {
        res.currAnt.push_back(_currAnt[i]);
        res.nextAnt.push_back(_nextAnt[i]);
    }

    res.conIns = _conIns;
    res.endIns = _endIns;
$setInit_p_MT

    clearData();
    res.response = 1;
}



