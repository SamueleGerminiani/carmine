
#include <actionlib/server/simple_action_server.h>
#include <deque>
#include <ros/callback_queue.h>
#include <cassert>
#include <chrono>
#include <csignal>
#include <iostream>
#include <mutex>
#include <string>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <utility>

#include <ver_env/migrateAction.h>
#include <unordered_set>
#include "ros/ros.h"
#include "globals.hh"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/times.h"
#include "sys/vtimes.h"
#include "ver_env/command.h"
#include "ver_env/stat.h"
#include "ver_env/su.h"


// this function is called by the client Ros service (migrateFrom)
// it contains the checkers currently executed by this node
std::unordered_map<std::string, Checker *> chsActive;
// it contains the checkers deleted by this node
std::unordered_map<std::string, Checker *> chsDeleted;
std::unordered_map<std::string, Checker *> chsAll;


ros::NodeHandle *n;
std::string cooName;
std::string thisHandlerName="";

Scheduler sched(std::thread::hardware_concurrency());
std::unordered_map<std::string, ros::Duration> nodeToLatency;
std::unordered_map<std::string, double> topicToLatency;
std::unordered_map<std::string, std::deque<double>> topicToLatencyWindow;

// the nodes currently executing in the network
std::vector<std::pair<ros::Time, std::string>> nodes;
std::vector<std::string> acks;

std::unordered_map<std::string, std::vector<std::string>> checkerToTopic;
std::unordered_map<std::string, std::vector<std::string>> topicToChecker;
std::unordered_map<std::string, ros::Subscriber> attachedTopics;
std::unordered_map<std::string, ros::Publisher> nameToPublisher;
std::unordered_set<std::string> allTopics;
std::unordered_set<std::string> allCheckers;
// messages sent by the coordinator to the node
std::deque<ver_env::command> msgs;
// mutex to protect the messages' container
// avoid concurrency between migrateTo and migrateFrom
// messages sent by the coordinator to the node
std::deque<ver_env::stat> stat_msgs;
// mutex to protect the messages' container

std::mutex cbMutex;
std::mutex migrateMutex;
std::mutex msgsMutex;
std::mutex acksMutex;
std::mutex stat_msgsMutex;
std::mutex nodesMutex;
std::mutex chsMutex;
std::mutex addPublisherMutex;

$vMutexs

$vAddEvents
double thisMachineMaxUsage = ((double)std::thread::hardware_concurrency()) * 100.0f;
double wholeNodeUsage=0.f;
double wholeMachineUsage=0.f;
int machineCPUfreq=0;
double milpUsageThreshold=1;
double milpResponsivnessThreshold=0;
bool disableMigration=0;
bool disableNotifications=0;
std::string topicPrefix;
size_t windowMaxSize=5;
