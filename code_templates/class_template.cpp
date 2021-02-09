#include "$ClassName$.hh"
#include <thread>

void $ClassName$::notifyFailure(){
	std::cout<<"Checker "<<_checkerName<<" failed, resetting"<<std::endl;
}

//Call remote procedure on handler remoateHandlerName to start buffer migration
//Server responds sending first timestamp
bool $ClassName$::initMigrationClient(std::string remoteHandlerName){
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
bool $ClassName$::initMigrationServer(verification_env::initMigration::Request &req, verification_env::initMigration::Response &res){
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
bool $ClassName$::sendBufferClient(std::string remoteHandlerName){
	
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
bool $ClassName$::sendBufferServer(verification_env::sendBuffer::Request &req, verification_env::sendBuffer::Response &res){

	std::cout<<"Server: received buffer of size "<<req.buffer_p.size()<<std::endl;
	
    addEvent_mutex.lock();

	if(checkerPhase != active){
		
		for (int i = 0; i < req.buffer_p.size(); i++){
			auto val = (req.buffer_p)[i];
$setBuffer
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

bool $ClassName$::needMigration(){

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

bool $ClassName$::floatEquals(const float &d1, const float &d2){
	float epsilon = 0.01;
	return fabs(d1 - d2) <= epsilon;
}

bool $ClassName$::doubleEquals(const double &d1, const double &d2){
	double epsilon = 0.01;
	return fabs(d1 - d2) <= epsilon;
}

Checker::Phase $ClassName$::getPhase(){
	return checkerPhase;
}

$ClassName$::$ClassName$(size_t nVars,size_t priority, std::string handlerName, std::string checkerName, bool server) : Checker(nVars, priority) {
	// init buffers
	pbuff = new uint64_t[BUFF_SIZE * values_inside];
	order = new uint64_t[BUFF_SIZE * values_inside];
	evalIndex_p = 0;
	index_p = 0;
	eventsInBuffer = 0;
	

	NEXT_STATE = INIT_$ClassName$;
	_handlerName = handlerName;
	_checkerName = checkerName;

	

	if(server){
		checkerPhase = paused;
	}
	else{
		checkerPhase = active;
	}
}

$ClassName$::~$ClassName$() {
	//	std::cout <<(_priority==1?"Low: ":"High: ")<< evalIndex_p <<
	//"\n";
	delete[] pbuff;
	delete[] order;
}

$FSM



// function used in Request to eval a checker until the slice or available
// events end
bool $ClassName$::eval() {
	
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


$order_entry


	evalIndex_p = (evalIndex_p >= BUFF_SIZE - 1) ? 0 : evalIndex_p + 1;
	state_mutex.lock();

$call_eval
	state_mutex.unlock();
	return true;
}

// reorder using the timestamp
void $ClassName$::reorder(bool forceReorder) {
	if (vbuff.size() >= REORDER_TH || forceReorder) {
		std::sort(std::begin(vbuff), std::end(vbuff),
			[](const Event& e1, const Event& e2) {
				return e1._timeStamp < e2._timeStamp;
			});
		
$static_vars

		for (auto event : vbuff) {
			switch (event._type) {
$cases
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

$addEvent



