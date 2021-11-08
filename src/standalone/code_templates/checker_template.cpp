#include "$ClassName$.hh"
#include "ros/time.h"
#include "verification_env/checkerData.h"

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
    _toKill = 0;
    _CPUusage = 0.f;
    _evalSpeed = 0.f;
    resetChecker();
}

// function used in Request to eval a checker until the slice or available
// events end
bool $ClassName$::eval() {
    // stat declarations
    static boost::chrono::thread_clock::time_point oneEvalStart;
    static std::chrono::steady_clock::time_point oneSecondStart =
        std::chrono::steady_clock::now();
    static double cumulativeEvalTime = 0;
    static size_t numberOfEvals = 0;
    oneEvalStart = boost::chrono::thread_clock::now();

    _addEvent_mutex.lock();
    reorder();
    _addEvent_mutex.unlock();

    if (_eventsInBuffer == 0) {
        // finished the available data
        return false;
    }

    _eventsInBuffer--;
    // stat
    numberOfEvals++;

    /*We eval one event at a time
    //ex. If we have v0 in the buffer as next element, the evaluation uses
    the new v0 and the old values for v1 and v2.*/
    uint64_t order_entry = get(_order, _evalIndex_p);
    uint64_t pbuff_entry = get(_pbuff, _evalIndex_p);


$order_entry

    _evalIndex_p = (_evalIndex_p >= BUFF_SIZE - 1) ? 0 : _evalIndex_p + 1;

$call_eval

    // stat
    cumulativeEvalTime +=
        boost::chrono::duration_cast<boost::chrono::nanoseconds>(
            boost::chrono::thread_clock::now() - oneEvalStart)
            .count();
    if (std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::steady_clock::now() - oneSecondStart)
            .count() >= 1e9) {
        _evalSpeedWindow.push_front(numberOfEvals);
        _topicSpeedWindow.push_front(_numberOfAddEvent);
        _cpuUsageWindow.push_front(
            (((double)cumulativeEvalTime) /
             std::chrono::duration_cast<std::chrono::nanoseconds>(
                 std::chrono::steady_clock::now() - oneSecondStart)
                 .count()) *
            100);
        if (_evalSpeedWindow.size() == _windowMaxSize) {
            _evalSpeedWindow.pop_back();
            _topicSpeedWindow.pop_back();
            _cpuUsageWindow.pop_back();
        }
        _evalSpeed = std::accumulate(_evalSpeedWindow.begin(),
                                     _evalSpeedWindow.end(), 0) /
                     (double)_evalSpeedWindow.size();
        _topicSpeed = std::accumulate(_topicSpeedWindow.begin(),
                                      _topicSpeedWindow.end(), 0) /
                      (double)_topicSpeedWindow.size();
        _CPUusage = std::accumulate(_cpuUsageWindow.begin(),
                                    _cpuUsageWindow.end(), 0.f) /
                    (double)_cpuUsageWindow.size();
        // debug
            //    std::cout << "eval speed: " << numberOfEvals << " e/s\n";
             //   std::cout << "topic speed: " << _topicSpeed << " e/s\n";
//        std::cout << "\t\t\t\t\t" << _handlerName << "," << _checkerName << " buffer: " << std::setprecision(4) << ((double)_eventsInBuffer / BUFF_SIZE) * 100 << "%\n";
        //        std::cout << "cpu: " << _CPUusage << "\n";
        _numberOfAddEvent = 0;
        numberOfEvals = 0;
        cumulativeEvalTime = 0;
        oneSecondStart = std::chrono::steady_clock::now();
    }

    return true;
}

$FSM

// reorder using the timestamp
void $ClassName$::reorder(bool forceReorder) {
    if (_vbuff.size() >= REORDER_TH || forceReorder) {
        std::sort(std::begin(_vbuff), std::end(_vbuff),
                  [](const Event &e1, const Event &e2) {
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
            assert(
                !(_index_p < _evalIndex_p && (_index_p + 1 == _evalIndex_p)));

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

ros::Time $ClassName$::migrateFromHandleTSbefore() {
    while (_last_msg_ts == ros::Time(0)) {
        ros::Duration(0.01).sleep();
    }
    return _last_msg_ts;
}
void $ClassName$::migrateFromHandleTSAfter(const ros::Time &ts) {
    while (ts > _last_msg_ts) {
        ros::Duration(0.01).sleep();
    }
}
void $ClassName$::migrateFromHandleData(verification_env::checkerData &res) {
    // buff

    _addEvent_mutex.lock();
    std::sort(std::begin(_vbuff), std::end(_vbuff),
              [](const Event &e1, const Event &e2) {
                  return e1._timeStamp < e2._timeStamp;
              });
    auto ts = res.last_msg_ts;
    auto it = std::find_if(_vbuff.begin(), _vbuff.end(), [&ts](const Event &v) {
        return v._timeStamp >= ts;
    });
    assert(it != _vbuff.end());
    _last_msg_ts = it->_timeStamp;
    _vbuff.erase(_vbuff.begin(), it + 1);

    // debug
    // std::cout << res.last_msg_ts << " --> " << _last_msg_ts << "\n";
    // std::cout << "Buff size: " << res.buffer_p.size() << "\n";

    for (int i = 0; i < res.buffer_p.size(); i++) {
        auto val = (res.buffer_p)[i];
        
$setBuffer

        _index_p = (_index_p >= BUFF_SIZE - 1) ? 0 : _index_p + 1;
        _eventsInBuffer++;
    }
    _addEvent_mutex.unlock();

    // timers
    size_t lastB = 0;
    for (size_t i = 0; i < _timeouts.size(); i++) {
        for (size_t j = lastB; j < res.timerBounds[i]; j++) {
            _timerInstances.at(i).push_back(res.timerInstances[j]);
        }
        for (size_t j = lastB; j < res.timerBounds[i]; j++) {
            _timerCache.at(i).push_back(res.timerCache[j]);
        }
        assert(_timerInstances.at(i).size() == _timerCache.at(i).size());
        lastB = res.timerBounds[i];
    }

    // state
    int assSize = sizeof(_currAss) / sizeof(_currAss[0]);
    for (size_t i = 0; i < assSize; i++) {
        _currAss[i] = res.currAss[i];
        _nextAss[i] = res.nextAss[i];
    }

    int antSize = sizeof(_currAnt) / sizeof(_currAnt[0]);
    for (size_t i = 0; i < antSize; i++) {
        _currAnt[i] = res.currAnt[i];
        _nextAnt[i] = res.nextAnt[i];
    }

    _conIns = res.conIns;
    _endIns = res.endIns;
$setInit_p_MF

    //    if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    //    {
    //        ROS_INFO("-------------------------------------MIGRATION
    //        SUCCEEDED");
    //    } else {
    //        ROS_INFO("------------------------------------------MIGRATION
    //        FAILED");
    //    }
}
ros::Time $ClassName$::migrateToHandleTS(const ros::Time &ts) {
    while (_last_msg_ts < ts) {
        ros::Duration(0.01).sleep();
    }
    _addEvent_mutex.lock();
    reorder(1);
    auto lmts = _last_msg_ts;
    _addEvent_mutex.unlock();
    return lmts;
}
void $ClassName$::migrateToHandleData(verification_env::checkerData &res) {
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
}

