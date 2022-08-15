#pragma once
#include <actionlib/server/simple_action_server.h>
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
#include "scheduler.hh"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/times.h"
#include "sys/vtimes.h"
#include "ver_env/ack.h"
#include "ver_env/command.h"
#include "ver_env/stat.h"
#include "ver_env/su.h"
#include "Monitor.hpp"
$includeMonitors
$msgHeaders

#define EXEC 0
#define REMOVE 1
#define MIGRATE_FROM 2

typedef actionlib::SimpleActionServer<ver_env::migrateAction> Server;
// this function is called by the client Ros service (migrateFrom)
// it contains the monitors currently executed by this node
extern std::unordered_map<std::string, Monitor *> chsActive;
// it contains the monitors deleted by this node
extern std::unordered_map<std::string, Monitor *> chsDeleted;
extern std::unordered_map<std::string, Monitor *> chsAll;

extern ros::NodeHandle *n;
extern std::string cooName;

extern Scheduler sched;
extern std::unordered_map<std::string, double> topicToLatency;
extern std::unordered_map<std::string, std::deque<double>> topicToLatencyWindow;

// the nodes currently executing in the network
extern std::vector<std::pair<ros::Time, std::string>> nodes;

extern std::vector<std::string> acks;
extern std::unordered_map<std::string, std::vector<std::string>> monitorToTopic;
extern std::unordered_map<std::string, std::vector<std::string>> topicToMonitor;
extern std::unordered_map<std::string, ros::Subscriber> attachedTopics;
extern std::unordered_map<std::string, ros::Publisher> nameToPublisher;
extern std::unordered_set<std::string> allTopics;
extern std::unordered_set<std::string> allMonitors;
// messages sent by the coordinator to the node
extern std::deque<ver_env::command> msgs;
// mutex to protect the messages' container
// avoid concurrency between migrateTo and migrateFrom
// messages sent by the coordinator to the node
extern std::deque<ver_env::stat> stat_msgs;
// mutex to protect the messages' container

extern std::mutex cbMutex;
extern std::mutex migrateMutex;
extern std::mutex msgsMutex;
extern std::mutex stat_msgsMutex;
extern std::mutex nodesMutex;
extern std::mutex chsMutex;
extern std::mutex addPublisherMutex;
extern std::mutex acksMutex;

$vMutexs

$vAddEvents

extern double wholeNodeUsage;
extern double wholeMachineUsage;
extern int machineCPUfreq;
extern double thisMachineMaxUsage;
extern double milpUsageThreshold;
extern double milpResponsivnessThreshold;
extern bool disableMigration;
extern bool disableNotifications;
extern std::string topicPrefix;
extern size_t windowMaxSize;

void nodeHandler();

void statHandler();

// callback
void addPublisher(std::string nodeName);
void attachCallback(const std::string &name);
void addMonitorCallbacks(const std::string &monitorName);
void removeMonitorCallbacks(const std::string &monitorName);
void removeMonitorCallbacks(std::unordered_set<std::string> &chsToBeRemoved) ;
void addTopicFP(const std::string &topic, const std::string &monitor) ;
void removeTopicFP(const std::string &topic, const std::string &monitor) ;
void start_upCB(const ver_env::su &msg);
void receiveNodeMSGS(const ver_env::command &msg);
void receiveStatMSGS(const ver_env::stat &msg);
void acksCB(const ver_env::ack &msg);

// monitorhelp
void fillAllTopics();
void initMonitorTopicRelation();
void initMonitor(const std::string &name);
void removeMonitor(const std::string &name);
void removeMonitor(std::unordered_set<std::string> &chsToBeRemoved) ;
void execMonitor(const std::string &monitorName);

// communication
void sendToNode(std::string pubName, int command, std::string node,
                std::string monitor);
void sendStatToCoordinator();
void pingTopic(const std::string &topic);
void migrateTo(const ver_env::migrateGoalConstPtr &goal, Server *as);
void sendAckToCoordinator() ;

// cpuUsage
void initCPU();
double getCurrentValue();
void initCPUTot();
double getCurrentValueTot();
