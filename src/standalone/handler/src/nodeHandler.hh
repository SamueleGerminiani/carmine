#include "globals.hh"
#include "ros/time.h"
#include "ver_env/migrateActionResult.h"
#include "ver_env/migrateGoal.h"
// the main loop function of a node
inline void nodeHandler() {
    while (ros::ok()) {
        // 1) periodically checks if there are new messages to be served
        ros::Duration(0.01).sleep();
        msgsMutex.lock();
        if (!msgs.empty()) {
            // 2) retrieve the next message
            ver_env::command msg = msgs.front();
            msgs.pop_front();
            msgsMutex.unlock();
            // 3) serve the corresponding command
            switch (msg.command) {
                case EXEC:
                    // execute a checker: only for the first time
                    for (auto &chName : msg.checkers) {
                        execChecker(chName);
                        std::cout << ros::this_node::getName() << ": EXEC("
                                  << chName << ")"
                                  << "\n";
                    }
                    sendAckToCoordinator();
                    break;
                case REMOVE:
                    //                    ch = chsAll.at(msg.checker);
                    //                    // remove the checker from the
                    //                    scheduler
                    //                    sched.removeCheckerRequest(ch);
                    //                    // call the function implementing the
                    //                    migration logic in the
                    //                    // checker
                    //                    removeCheckerCallbacks(msg.checker);
                    //                    removeChecker(msg.checker);
                    //                    ch->clearData();
                    //                    std::cout << ros::this_node::getName()
                    //                    << ": REMOVE("
                    //                              << msg.checker << ")"
                    //                              << "\n";
                    //                    sendAckToCoordinator();
                    break;
                case MIGRATE_FROM:
                    const std::lock_guard<std::mutex> lock(migrateMutex);
                    // migrate a checker: this command is served by the node
                    // receiving the checker
                    //                    std::cout << ros::this_node::getName()
                    //                    << ": MIGRATE_FROM(" << msg.checker <<
                    //                    ", " << msg.node << ")" << "\n";

                    for (auto &chName : msg.checkers) {
                        initChecker(chName);
                    }

                    for (auto &chName : msg.checkers) {
                        chsAll.at(chName)->clearData();
                        addCheckerCallbacks(chName);
                    }

                    ver_env::migrateGoal goal;
                    for (auto &chName : msg.checkers) {
                        goal.checkers.push_back(chName);
                        goal.stamp.push_back(
                            chsAll.at(chName)->migrateFromHandleTSbefore());
                    }
                    // execute the migration
                    Client client("ver_env/"+msg.node + "/migrate", 0);
                    client.waitForServer();

                    // Fill in goal here
                    client.sendGoal(goal);
                    client.waitForResult(ros::Duration(5.0));

                    auto chDataList = client.getResult()->cd;
                    for (auto &chData : chDataList) {
                        chsAll.at(chData.checker)
                            ->migrateFromHandleTSAfter(chData.last_msg_ts);
                    }
                    for (auto &chData : chDataList) {
                        chsAll.at(chData.checker)
                            ->migrateFromHandleData(chData);
                    }
                    // put the checker on the scheduler
                    for (auto &chName : msg.checkers) {
                        sched.addCheckerRequest(chsAll.at(chName));
                    }

                    sendAckToCoordinator();
                    if (client.getState() ==
                        actionlib::SimpleClientGoalState::SUCCEEDED) {
                        ROS_INFO(
                            "-------------------------------------MIGRATION "
                            "SUCCEEDED");
                    } else {
                        ROS_INFO(
                            "------------------------------------------"
                            "MIGRATION FAILED");
                    }
                    // publish the migration service on this node
                    //                    std::cout << ros::this_node::getName()
                    //                    << " MF_ended" << "\n";
                    break;
            }
        } else {
            msgsMutex.unlock();
        }
    }
}
