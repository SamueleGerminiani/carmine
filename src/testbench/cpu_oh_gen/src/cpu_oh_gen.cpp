#include <cassert>
#include <chrono>
#include <thread>
#include <vector>
#include <csignal>
#include <set>
#include <unordered_set>
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "commandLineParser.hh"
std::string targetNode="current";
inline void sigint_handler(int signal) {
    std::cout << ros::this_node::getName() +
                     ": Execution interrupted by the user!"
              << "\n";
    ros::shutdown();
}
std::pair<int, char **> parseCommandLineArguments(int argc, char *argv[]) {
    std::vector<std::string> oargvs;
    for (size_t i = 0; i < argc; i++) {
        oargvs.push_back(argv[i]);
    }
    targetNode=oargvs[2];

    auto result = parse(argc, argv);
    std::vector<std::string> unusedArguments;
    std::unordered_set<std::string> usedArguments;

    if (result.count("targetNode")) {
        targetNode= result["targetNode"].as<std::string>();
        usedArguments.insert("--targetNode");
    }

    for (size_t i = 0; i < oargvs.size(); i++) {
        if (usedArguments.count(oargvs[i])) {
            i++;
        } else {
            unusedArguments.push_back(oargvs[i]);
        }
    }
    char **finalargv = nullptr;
    finalargv = new char *[unusedArguments.size()];

    for (size_t j = 0; j < unusedArguments.size(); j++) {
        auto &e = unusedArguments[j];
        finalargv[j] = new char[e.size()];
        e.push_back('\0');
        e.copy(finalargv[j], e.size());
    }

    return std::make_pair(unusedArguments.size(), finalargv);
}
static void consumeCPU(int percentage, bool &stop) {
    assert(percentage <= 100 && percentage >= 0);
    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    while (!stop) {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - begin)
                .count() > percentage) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(100 - percentage));
            begin = std::chrono::steady_clock::now();
        }
    }
}

inline void overheadCB(const std_msgs::Float64 &msg) {
    static bool stop = false;
    static std::vector<std::thread> ths;

    stop = 1;
    for (auto &th : ths) {
        th.join();
    }
    ths.clear();
    stop = 0;
    size_t nCPUs = (size_t)msg.data / 100.f;
    size_t pCPU = msg.data - nCPUs * 100.f;
    for (size_t i = 0; i < nCPUs; i++) {
        ths.emplace_back(&consumeCPU, 100, std::ref(stop));
    }
    if (pCPU >= 1) {
        ths.emplace_back(&consumeCPU, pCPU, std::ref(stop));
    }
}

int main(int argc, char **argv) {
    auto trimmedArgv = parseCommandLineArguments(argc, argv);
    signal(SIGINT, sigint_handler);
    ros::init(trimmedArgv.first, trimmedArgv.second, "oh_"+targetNode,
              ros::init_options::NoSigintHandler);
    ros::NodeHandle n;

    ros::Subscriber sub_su = n.subscribe("ver_env/overhead/"+targetNode, 100, overheadCB,
                                          ros::TransportHints().tcpNoDelay());

    ros::spin();
    return 0;
}

