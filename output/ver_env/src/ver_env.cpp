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
std::string migrateTo = "handler1";


Scheduler sched(3, chs);



void sigint_handler(int signal) {
	ROS_INFO("Execution interrupted by the user!");
	ros::shutdown();
}


//Callback for topic V1
void callbackV0(const msg_gen::Num::Ptr& msg){
   for (const auto& e : chs) {
      auto checker = e.second;
      if(checker -> getPhase() != Checker::Phase::paused){
         if(dynamic_cast<CheckerT0*>(checker) != NULL){
            CheckerT0 *ch = dynamic_cast<CheckerT0*>(checker);
            ch->addEvent_var1(msg->header.stamp, msg->num);
         }
      }
   }
}
//Callback for topic V2
void callbackV1(const msg_gen::Num::Ptr& msg){
   for (const auto& e : chs) {
      auto checker = e.second;
      if(checker -> getPhase() != Checker::Phase::paused){
         if(dynamic_cast<CheckerT0*>(checker) != NULL){
            CheckerT0 *ch = dynamic_cast<CheckerT0*>(checker);
            ch->addEvent_var0(msg->header.stamp, msg->num);
         }
      }
   }
}




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

   ros::CallbackQueue *queue_0, *queue_1;
   ros::Subscriber *sub_0, *sub_1;
   std::thread *thread_0, *thread_1;
   ros::SingleThreadedSpinner *spinner_0, *spinner_1;

   queue_0 = new ros::CallbackQueue;
   n.setCallbackQueue(queue_0);
   sub_0 = new ros::Subscriber;
   *sub_0 = n.subscribe("V1", 1000, callbackV0, ros::TransportHints().tcpNoDelay());
   thread_0 = new std::thread([&queue_0, &spinner_0]() {
      spinner_0 = new ros::SingleThreadedSpinner;
      spinner_0->spin(queue_0);
   });

   queue_1 = new ros::CallbackQueue;
   n.setCallbackQueue(queue_1);
   sub_1 = new ros::Subscriber;
   *sub_1 = n.subscribe("V2", 1000, callbackV1, ros::TransportHints().tcpNoDelay());
   thread_1 = new std::thread([&queue_1, &spinner_1]() {
      spinner_1 = new ros::SingleThreadedSpinner;
      spinner_1->spin(queue_1);
   });



	// init checkers
	/*for (size_t i = 0; i < ch0Copies; i++) {
		chs.push_back(new Checker0(3,rand() % 2 + 1));
	}*/


	//Server
	//chs.push_back(new Checker0(3,rand() % 2 + 1,"handler1","checker0",true));
	//Client

   std::string handlerName = "handler0";
   chs["CheckerT0"] = new CheckerT0(2,rand() % 2 + 1,handlerName, "CheckerT0",false);


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

   thread_0->join();
   thread_1->join();
   keepPolling = false;

   delete thread_0;
   delete sub_0;
   delete spinner_0;
   delete queue_0;

   delete thread_1;
   delete sub_1;
   delete spinner_1;
   delete queue_1;




	 
	for (auto e : chs) {
		delete e.second;
	} 

	return 0;
}
