#include "CheckerT0.hh"
#include <thread>

void CheckerT0::notifyFailure(){
	std::cout<<"Checker "<<_checkerName<<" failed, resetting"<<std::endl;
}

//Call remote procedure on handler remoateHandlerName to start buffer migration
//Server responds sending first timestamp
bool CheckerT0::initMigrationClient(std::string remoteHandlerName){
	_remoteHandlerName = remoteHandlerName;

	std::cout<<"Client: initiated migration"<<std::endl;
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<verification_env::initMigration>(remoteHandlerName+"/initMigration");
	verification_env::initMigration srv;
	srv.request.handlerName = _handlerName;
	srv.request.checkerName = _checkerName;
	
	if(! client.call(srv)){
		ROS_INFO("Client: failed to call initMigrationServer on remote node");
		return false;
	}


	//Checker will consume messages until this timestamp is reached, then stop
	timestampToReach = srv.response.stamp;
	checkerPhase = pausing;
	return true;
	
}

//Serve remote procedure to start buffer migration: get the first timestamp send it to the client, enable callbacks 
//Here the checker on the server should be in paused state
bool CheckerT0::initMigrationServer(verification_env::initMigration::Request &req, verification_env::initMigration::Response &res){
	std::cout<<"Server: received migration request"<<std::endl;
    checkerPhase = resumed;

    bool empty = true;

    //Wait until there is at least a message in the buffer and send its timestamp as response

    while(empty){
    	addEvent_mutex.lock();
    	empty = vbuff.size() == 0;
    	if(! empty){
    		std::sort(std::begin(vbuff), std::end(vbuff),
			  [](const Event& e1, const Event& e2) {
				  return e1._timeStamp < e2._timeStamp;
			  });
    		res.stamp = vbuff[0]._timeStamp;
    	}
    	addEvent_mutex.unlock();
    }

	return true;
}

//send data to handler remoteHandlerName
bool CheckerT0::sendBufferClient(std::string remoteHandlerName){
	
	addEvent_mutex.lock();
	checkerPhase = paused;
	
	ros::NodeHandle n;
 	ros::ServiceClient client = n.serviceClient<verification_env::sendBuffer>(remoteHandlerName+"/sendBuffer");
 	verification_env::sendBuffer srv;

 	srv.request.handlerName = _handlerName;
 	srv.request.checkerName = _checkerName;


	if(evalIndex_p <= index_p){
		for(int i = evalIndex_p; i< index_p;i++){
			srv.request.buffer_p.push_back(get(pbuff,i));
			srv.request.buffer_o.push_back(get(order,i));
		}
	}
	

	//If evalIndex_p > index_p the end of the circular buffer has been reached 
	//new values are insterted at the beginning of the buffer
	//Send values accordingly 
	else{
		srv.request.buffer_p.assign(pbuff + evalIndex_p, pbuff + BUFF_SIZE * values_inside);
		srv.request.buffer_o.assign(order + evalIndex_p, order + BUFF_SIZE * values_inside);
		for (int i = 0; i <= index_p; i++){
			srv.request.buffer_p.push_back(pbuff[i]);
			srv.request.buffer_o.push_back(order[i]);
		}
	}

	
	state_mutex.lock();
	srv.request.state = NEXT_STATE;
	state_mutex.unlock();


    if(! client.call(srv)){
		ROS_INFO("Client failed to call sendBuffer");
		return false;
	}

	std::cout<<"Client: migrated buffer of size "<<srv.request.buffer_p.size()<<std::endl;

	
	vbuff.clear();
	memset(order,0,BUFF_SIZE * values_inside);
	memset(pbuff,0,BUFF_SIZE * values_inside);
	evalIndex_p = 0;
	index_p = 0;
	eventsInBuffer = 0;
	
	addEvent_mutex.unlock();
	return true;
}

//Receive and set data, set checker state back to active
bool CheckerT0::sendBufferServer(verification_env::sendBuffer::Request &req, verification_env::sendBuffer::Response &res){

	std::cout<<"Server: received buffer of size "<<req.buffer_p.size()<<std::endl;
	
    addEvent_mutex.lock();

	if(checkerPhase != active){
		
		for (int i = 0; i < req.buffer_p.size(); i++){
			auto val = (req.buffer_p)[i];
         bool p0 = val & (1ULL << 0);
         bool p1 = val & (1ULL << 1);
         bool p2 = val & (1ULL << 2);
         bool p3 = val & (1ULL << 3);
         assign<bool>(pbuff, index_p ,p0 ,p1 ,p2 ,p3);
         val = (req.buffer_o)[i];
         p0 = val & (1ULL << 0);
         p1 = val & (1ULL << 1);
         p2 = val & (1ULL << 2);
         p3 = val & (1ULL << 3);
         assign<bool>(order, index_p ,p0 ,p1 ,p2 ,p3);

			index_p = (index_p >= BUFF_SIZE - 1) ? 0 : index_p + 1;
			buff_mutex.lock();
			eventsInBuffer++;
			buff_mutex.unlock();
		}

		NEXT_STATE = req.state;
		res.response = true;
		addEvent_mutex.unlock();
		checkerPhase = active;
	}
	
	return true;
}

bool CheckerT0::needMigration(){

	if(checkerPhase!=active){
		return false;
	}
	else{
		buff_mutex.lock();
		bool res = eventsInBuffer > MIGRATION_TH;
		buff_mutex.unlock();
		return res;
	}
}

bool CheckerT0::floatEquals(const float &d1, const float &d2){
	float epsilon = 0.01;
	return fabs(d1 - d2) <= epsilon;
}

bool CheckerT0::doubleEquals(const double &d1, const double &d2){
	double epsilon = 0.01;
	return fabs(d1 - d2) <= epsilon;
}

Checker::Phase CheckerT0::getPhase(){
	return checkerPhase;
}

CheckerT0::CheckerT0(size_t nVars,size_t priority, std::string handlerName, std::string checkerName, bool server) : Checker(nVars, priority) {
	// init buffers
	pbuff = new uint64_t[BUFF_SIZE * values_inside];
	order = new uint64_t[BUFF_SIZE * values_inside];
	evalIndex_p = 0;
	index_p = 0;
	eventsInBuffer = 0;
	

	NEXT_STATE = INIT_CheckerT0;
	_handlerName = handlerName;
	_checkerName = checkerName;

	

	if(server){
		checkerPhase = paused;
	}
	else{
		checkerPhase = active;
	}
}

CheckerT0::~CheckerT0() {
	//	std::cout <<(_priority==1?"Low: ":"High: ")<< evalIndex_p <<
	//"\n";
	delete[] pbuff;
	delete[] order;
}

//Return true if checker did not fail
inline bool CheckerT0::eval_CheckerT0(bool p0, bool p1, bool p2, bool p3, bool const reset){
   if(reset){
      NEXT_STATE = INIT_CheckerT0;
    }
   switch(NEXT_STATE){

      case 0:
         if((!p0 || (p1 && p3))){
            NEXT_STATE = 1;
         }
         if((p0 && p1)){
            NEXT_STATE = 2;
         }
         if(((p0 && !p1) || (p0 && !p2))){
            return false;
         }
         break;

      case 1:
         if(){
            NEXT_STATE = 1;
         }
         break;

      case 2:
         if(p3){
            NEXT_STATE = 1;
         }
         if((p2 && !p3)){
            NEXT_STATE = 2;
         }
         if((!p2 && !p3)){
            return false;
         }
         break;
   }

   return true;
}




// function used in Request to eval a checker until the slice or available
// events end
bool CheckerT0::eval() {
	
	// eval and the callbacks both use 'eventsInbuffer' in parallel

	buff_mutex.lock();

	if (eventsInBuffer == 0) {
		//		ROS_INFO("No more events to evaluate!");
		// finished the available data
		buff_mutex.unlock();
		return false;
	}
	_evaluations++;
	eventsInBuffer--;
	buff_mutex.unlock();

	/*We eval one event at a time
	//ex. If we have v0 in the buffer as next element, the evaluation uses
	the new v0 and the old values for v1 and v2.*/
	uint64_t order_entry = get(order, evalIndex_p);
	uint64_t pbuff_entry = get(pbuff, evalIndex_p);


   if (order_entry & (1ULL << 0)) {
      last_p0= pbuff_entry & (1ULL << 0);
   }
   if (order_entry & (1ULL << 1)) {
      last_p1= pbuff_entry & (1ULL << 1);
   }
   if (order_entry & (1ULL << 2)) {
      last_p2= pbuff_entry & (1ULL << 2);
   }
   if (order_entry & (1ULL << 3)) {
      last_p3= pbuff_entry & (1ULL << 3);
   }



	evalIndex_p = (evalIndex_p >= BUFF_SIZE - 1) ? 0 : evalIndex_p + 1;
	state_mutex.lock();

   if (!eval_CheckerT0(last_p0,last_p1,last_p2,last_p3)){
      notify_mutex.lock();
      notifyFailure();
      notify_mutex.unlock();
      eval_CheckerT0(0,0,0,0,1);
   }

	state_mutex.unlock();
	return true;
}

// reorder using the timestamp
void CheckerT0::reorder(bool forceReorder) {
	if (vbuff.size() >= REORDER_TH || forceReorder) {
		std::sort(std::begin(vbuff), std::end(vbuff),
			[](const Event& e1, const Event& e2) {
				return e1._timeStamp < e2._timeStamp;
			});
		
   static bool start0;
   static bool end0;
   static bool v0;
   static bool v1;


		for (auto event : vbuff) {
			switch (event._type) {
               case 0:{
                  start0 = event._value._start0;
                  const bool p1 = start0;
                  assign<bool>(pbuff, index_p, 0, p1, 0, 0);
                  assign<bool>(order, index_p, 0, 1, 0, 0);
               }
               break;
               case 1:{
                  end0 = event._value._end0;
                  const bool p2 = !end0;
                  assign<bool>(pbuff, index_p, 0, 0, p2, 0);
                  assign<bool>(order, index_p, 0, 0, 1, 0);
               }
               break;
               case 2:{
                  v0 = event._value._v0;
                  const bool p0 = v0;
                  assign<bool>(pbuff, index_p, p0, 0, 0, 0);
                  assign<bool>(order, index_p, 1, 0, 0, 0);
               }
               break;
               case 3:{
                  v1 = event._value._v1;
                  const bool p3 = v1;
                  assign<bool>(pbuff, index_p, 0, 0, 0, p3);
                  assign<bool>(order, index_p, 0, 0, 0, 1);
               }
               break;

				default:
				assert(false);
			}
			// fails if there are more than BUFF_SIZE unevaluated
			// events
			assert(!(index_p < evalIndex_p && (index_p + 1 == evalIndex_p)));

			index_p = (index_p >= BUFF_SIZE - 1) ? 0 : index_p + 1;

			//'eventInbuffer' is used in eval in parallel
			buff_mutex.lock();
			eventsInBuffer++;
			buff_mutex.unlock();
		}
		vbuff.clear();
	}
}

void CheckerT0::addEvent_var0(ros::Time ts, bool value){
   if(checkerPhase == pausing && ts > timestampToReach){
      sendBufferClient(_remoteHandlerName);
      checkerPhase = paused;
   }
   else{
      addEvent_mutex.lock();
      vbuff.push_back(Event(ts, Value(value, 0),0));
      reorder();
      addEvent_mutex.unlock();
   }
}
void CheckerT0::addEvent_var1(ros::Time ts, bool value){
   if(checkerPhase == pausing && ts > timestampToReach){
      sendBufferClient(_remoteHandlerName);
      checkerPhase = paused;
   }
   else{
      addEvent_mutex.lock();
      vbuff.push_back(Event(ts, Value(value, 1),1));
      reorder();
      addEvent_mutex.unlock();
   }
}
void CheckerT0::addEvent_var2(ros::Time ts, bool value){
   if(checkerPhase == pausing && ts > timestampToReach){
      sendBufferClient(_remoteHandlerName);
      checkerPhase = paused;
   }
   else{
      addEvent_mutex.lock();
      vbuff.push_back(Event(ts, Value(value, 2),2));
      reorder();
      addEvent_mutex.unlock();
   }
}
void CheckerT0::addEvent_var3(ros::Time ts, bool value){
   if(checkerPhase == pausing && ts > timestampToReach){
      sendBufferClient(_remoteHandlerName);
      checkerPhase = paused;
   }
   else{
      addEvent_mutex.lock();
      vbuff.push_back(Event(ts, Value(value, 3),3));
      reorder();
      addEvent_mutex.unlock();
   }
}




