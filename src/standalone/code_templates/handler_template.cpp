#include <ros/callback_queue.h>
#include <cassert>
#include <chrono>
#include <csignal>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

#include "include_checkers.hh"
#include "ros/ros.h"
#include "scheduler.hh"

bool keepPolling = true;

//All the checkers managed by this handler are put in this std::map
//The key is the unique checker's name and the value is the checker's instance 
std::map<std::string,Checker*> chs;
$migrateTo

Scheduler sched(std::thread::hardware_concurrency()/2, chs);



void sigint_handler(int signal) {
	ROS_INFO("Execution interrupted by the user!");
	ros::shutdown();
}


$callbacks



//Function used to poll checkers and start the migration if needed, and delete paused checkers
void pollCheckers(){

	while(keepPolling){
		for(const auto& e : chs){
			//Migrate checker
			if( e.second->needMigration() ){
				e.second-> initMigrationClient(migrateTo);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

//Mettere mutex per gestire chiamate multiple ?
bool initMigrationServer(verification_env::initMigration::Request &req, verification_env::initMigration::Response &res){
	auto checkerToMigrate = req.checkerName;

	if(chs[checkerToMigrate]-> getPhase() != Checker::Phase::paused){
		std::cout<<"Error, checker "<<checkerToMigrate<<" not paused in this machine"<<std::endl;
		return false;
	}
	sched.addCheckerRequest(chs[checkerToMigrate]);
	chs[checkerToMigrate]->initMigrationServer(req, res);
	return true;
}

bool sendBufferServer(verification_env::sendBuffer::Request &req, verification_env::sendBuffer::Response &res){
	auto checkerToMigrate = req.checkerName;
	chs[checkerToMigrate]->sendBufferServer(req,res);
	return true;
}

int main(int argc, char** argv) {
	signal(SIGINT, sigint_handler);

	ros::init(argc, argv, "handler0", ros::init_options::NoSigintHandler);
	ros::NodeHandle n;

$declareSpinners
$initQueues

	// init checkers
	/*for (size_t i = 0; i < ch0Copies; i++) {
		chs.push_back(new Checker0(3,rand() % 2 + 1));
	}*/


	//Server
	//chs.push_back(new Checker0(3,rand() % 2 + 1,"handler1","checker0",true));
	//Client

$addCheckers

	//Services

	//Checker0
	
	ros::ServiceServer serviceBuffer = n.advertiseService(handlerName+"/sendBuffer", sendBufferServer);
	ros::ServiceServer serviceInit = n.advertiseService(handlerName+"/initMigration", initMigrationServer);

	
	/*ros::ServiceServer serviceBuffer = n.advertiseService("/handler0/sendBuffer", &Checker0::sendBufferServer,ch0);
	ros::ServiceServer serviceInit = n.advertiseService("/handler0/initMigration", &Checker0::initMigrationServer,ch0);*/

	//std::thread pollingThread(pollCheckers);

	
	sched.start();
	std::cout << "Running..." << "\n";
	ros::waitForShutdown();

	sched.stop();

$deleteAll


	 
	for (auto e : chs) {
		delete e.second;
	} 

	return 0;
}
