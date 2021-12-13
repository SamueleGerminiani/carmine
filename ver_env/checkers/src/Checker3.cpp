#include "Checker3.hh"
#include "ros/time.h"
#include "ver_env/checkerData.h"

void Checker3::notifyFailure() {
    std::cout << ros::this_node::getName() << ": Checker " << _checkerName
              << " failed, resetting" << std::endl;
}

Checker3::Checker3(size_t nVars, size_t priority, std::string handlerName,
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

   _timerInstances[0];
   _timerCache[0];
   _timeouts.push_back(10000);


    resetChecker();
}

Checker3::~Checker3() {
    delete[] _pbuff;
    delete[] _order;
}

void Checker3::clearData() {
    _vbuff.clear();
    _evalIndex_p = 0;
    _index_p = 0;
    _eventsInBuffer = 0;

   _last_p0 = 0;
   _last_p1 = 0;


    _last_msg_ts = ros::Time(0);
    _toKill = 0;
    _CPUusage = 0.f;
    _evalSpeed = 0.f;
    resetChecker();
}

// function used in Request to eval a checker until the slice or available
// events end
bool Checker3::eval() {
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


   if (order_entry & (1ULL << 0)) {
      _last_p0= pbuff_entry & (1ULL << 0);
   }
   if (order_entry & (1ULL << 1)) {
      _last_p1= pbuff_entry & (1ULL << 1);
   }


    _evalIndex_p = (_evalIndex_p >= BUFF_SIZE - 1) ? 0 : _evalIndex_p + 1;

   static std::chrono::steady_clock::time_point ohstart = std::chrono::steady_clock::now();
   while (1) {
      if (std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::steady_clock::now() - ohstart).count() >= 10000) {
      ohstart = std::chrono::steady_clock::now();
      break;
      }
   }


   if (!eval_Checker3(_last_p0, _last_p1, 0)){
      notifyFailure();
      eval_Checker3(0, 0, 1);
   }


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

//Return true if checker did not fail
inline bool Checker3::eval_Checker3(bool p0, bool p1, bool const reset){
   if(reset){
      resetChecker();
      return 1;
   }
    _currAss[3]++;
    for (size_t i = 0; i < _currAss[0]; i++) {
      bool stop0 = getTimerValue(0, i, 1);
      if((!p1 && !stop0)){
          _nextAss[0]++;
      }
      else if(p1){
         popTimerInst(0,1);
         _endIns++;
      }
      else if((!p1 && stop0)){
         return 0;
      }
   }
    _currAss[0]=0;
    for (size_t i = 0; i < _currAss[1]; i++) {
      bool stop0 = getTimerValue(0, i, 1);
      if((!p1 && 1 && !stop0)){
         addTimerValue(0);
          _nextAss[0]++;
      }
      else if((p1 && 1)){
         _endIns++;
      }
      else if((!1 || (!p1 && stop0))){
         return 0;
      }
   }
    _currAss[1]=0;
      if((1 && p0)){
          _nextAss[1]+=_currAss[3];
      }
      else if((!1 && p0)){
         _endIns+=_currAss[3];
      }
      else if(!p0){
          _nextAss[3]+=_currAss[3];
      }
    _currAss[3]=0;
   for (size_t i = 0; i <5; i++) {
          _currAss[i] = _nextAss[i];
          _nextAss[i] = 0;
   }


// ---------ANT-------------


    _currAnt[1]++;
      if((1 && p0)){
         _conIns+=_currAnt[1];
      }
      else if(!p0){
          _nextAnt[1]+=_currAnt[1];
      }
      else if((!1 && p0)){
         _endIns-=_currAnt[1];
      }
    _currAnt[1]=0;
   for (size_t i = 0; i <3; i++) {
          _currAnt[i] = _nextAnt[i];
          _nextAnt[i] = 0;
   }
   if (_conIns - _endIns > 0) {
      _priority = 2;
   } else if (_conIns - _endIns <= 0) {
      _priority = 1;
   }

   return true;
}


// reorder using the timestamp
void Checker3::reorder(bool forceReorder) {
    if (_vbuff.size() >= REORDER_TH || forceReorder) {
        std::sort(std::begin(_vbuff), std::end(_vbuff),
                  [](const Event &e1, const Event &e2) {
                      return e1._timeStamp < e2._timeStamp;
                  });

   static double pos0;


        for (auto event : _vbuff) {
            switch (event._type) {
               case 0:{
                  pos0 = event._value._pos0;
                  const bool p0 = (pos0 != 0);
                  const bool p1 = (pos0 >= 0);
                  assign<bool>(_pbuff, _index_p, p0, p1);
                  assign<bool>(_order, _index_p, 1, 1);
               }
               break;

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

void Checker3::addEvent_pos0(ros::Time ts, double value){
      _addEvent_mutex.lock();
      _last_msg_ts = ts;
      _numberOfAddEvent++;
      _vbuff.push_back(Event(ts, Value(value, 0),0));
      _addEvent_mutex.unlock();
}


void Checker3::addTimerValue(size_t timerID) {
    _timerInstances[timerID].push_back(ros::Time::now().toSec() * 1000);
}
void Checker3::popTimerInst(size_t timerID, size_t nToErase) {
    if (_timerInstances.at(timerID).empty()) {
        return;
    }
    _timerInstances.at(timerID).erase(
        begin(_timerInstances.at(timerID)),
        begin(_timerInstances.at(timerID)) + nToErase);
}
bool Checker3::getTimerValue(size_t timerID, size_t timerInstance,
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

void Checker3::resetChecker() {
    for (size_t j = 0; j < 5; j++) {
        _currAss[j] = 0;
        _nextAss[j] = 0;
    }
    for (size_t j = 0; j < 3; j++) {
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

ros::Time Checker3::migrateFromHandleTSbefore() {
    while (_last_msg_ts == ros::Time(0)) {
        ros::Duration(0.01).sleep();
    }
    return _last_msg_ts;
}
void Checker3::migrateFromHandleTSAfter(const ros::Time &ts) {
    while (ts > _last_msg_ts) {
        ros::Duration(0.01).sleep();
    }
}
void Checker3::migrateFromHandleData(ver_env::checkerData &res) {
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
        
         bool p0 = val & (1ULL << 0);
         bool p1 = val & (1ULL << 1);
         assign<bool>(_pbuff, _index_p , p0 , p1);
         val = (res.buffer_o)[i];
         p1 = val & (1ULL << 0);
         p0 = val & (1ULL << 1);
         assign<bool>(_order, _index_p , p0 , p1);


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
   _last_p0 = res.last_p[0];
   _last_p1 = res.last_p[1];


    //    if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    //    {
    //        ROS_INFO("-------------------------------------MIGRATION
    //        SUCCEEDED");
    //    } else {
    //        ROS_INFO("------------------------------------------MIGRATION
    //        FAILED");
    //    }
}
ros::Time Checker3::migrateToHandleTS(const ros::Time &ts) {
    while (_last_msg_ts < ts) {
        ros::Duration(0.01).sleep();
    }
    _addEvent_mutex.lock();
    reorder(1);
    auto lmts = _last_msg_ts;
    _addEvent_mutex.unlock();
    return lmts;
}
void Checker3::migrateToHandleData(ver_env::checkerData &res) {
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
   res.last_p.push_back(_last_p0);
   res.last_p.push_back(_last_p1);


    clearData();
}

