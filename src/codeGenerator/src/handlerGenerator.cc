#include "handlerGenerator.hh"
#include "types.hh"
#include <cmath>
#include <cstdio>
#include <dirent.h>
#include <filesystem>
#include <fstream>
#include <numeric>
#include <spot/tl/formula.hh>
#include <string>
using namespace std::filesystem;

namespace codeGenerator {
// Generate handler code
bool generateHandlerSource(std::vector<strChecker> &checkers, int nPhs[]) {
  std::ifstream src("src/standalone/code_templates/handler_template.cpp");
  if (src.fail()) {
    std::cout << "Error: could not open handler_template.cpp" << std::endl;
    return false;
  }

  create_directories("build/output/ver_env/src");
  std::ofstream dst("build/output/ver_env/src/handler.cpp");

  if (dst.fail()) {
    std::cout << "Error: could not open output/ver_env/src/handler.cpp"
              << std::endl;
    return false;
  }

  std::string line;

  int callbackNum = 0;
  std::map<std::string, std::string> callbackTopic;
  std::map<std::string, std::string> topicEnTopic;

  while (getline(src, line)) {
    // Allocate checker instances
    if (line.compare("$checkerToTopic") == 0) {
      line = "";
      auto checkersMsg = groupCheckersByMsgTopic(checkers);

      for (auto chm : checkersMsg) {
        for (auto c : chm.second) {
          line += "checkerToTopic[\"" + c + "\"].emplace_back(\"" +
                  topicEnTopic.at(chm.first.second) + "\");\n";
        }
      }

    }

    else if (line.compare("$callbacksMutex") == 0) {
      line = "";
      auto checkersMsg = groupCheckersByMsgTopic(checkers);
      for (size_t i = 0; i < checkersMsg.size(); i++) {
        line += "std::mutex v" + std::to_string(i) + "Mutex;\n";
      }
    } else if (line.compare("$pauseCallBacks") == 0) {
      line = "";
      auto checkersMsg = groupCheckersByMsgTopic(checkers);
      for (size_t i = 0; i < checkersMsg.size(); i++) {
        line += "v" + std::to_string(i) + "Mutex.lock();\n";
      }
    } else if (line.compare("$resumeCallBacks") == 0) {
      line = "";
      auto checkersMsg = groupCheckersByMsgTopic(checkers);
      for (size_t i = 0; i < checkersMsg.size(); i++) {
        line += "v" + std::to_string(i) + "Mutex.unlock();\n";
      }
    } else if (line.compare("$callbacks") == 0) {
      line = "";
      auto checkersMsg = groupCheckersByMsgTopic(checkers);

      for (auto e : checkersMsg) {

        std::string callbackName = "callbackV" + std::to_string(callbackNum);
        auto checkerList = e.second;
        auto msgType = e.first.first;
        auto topicName = e.first.second;

        callbackTopic[callbackName] = topicName;
        topicEnTopic[topicName] = "V" + std::to_string(callbackNum);
        line += "//Callback for topic " + topicName + "\n";
        line += "void " + callbackName + "(const ";

        line += msgType + "::Ptr& msg){\n";
//        line += codeGenerator::ident1 + "std::lock_guard<std::mutex> lock{v" + std::to_string(callbackNum) + "Mutex};\n\n";
        line += codeGenerator::ident1 + "for (const auto& e : chs) {\n";
        line += codeGenerator::ident2 + "auto checker = e.second;\n";

        for (auto ch : checkerList) {
          int i = 0;
          line += codeGenerator::ident2 + "if(dynamic_cast<" + ch +
                  "*>(checker) != nullptr){\n";
          line += codeGenerator::ident3 + ch + " *ch = dynamic_cast<" + ch +
                  "*>(checker);\n";

          auto vars = bindings[ch];
          std::string msgField = "";
          for (auto v : vars) {
            if (msgType.compare(v._msgType) == 0 &&
                topicName.compare(v._rosTopic) == 0) {
              msgField = v._msgField;
              line += codeGenerator::ident3 + "ch->addEvent_var" +
                      std::to_string(i) + "(msg->header.stamp, msg->" +
                      msgField + ");\n";
            }
            i++;
          }
          line += codeGenerator::ident2 + "}\n";
        }

        line += codeGenerator::ident1 + "}\n";
        line += "}\n";
        callbackNum++;
      }

    } else if (line.compare("$attachCallbacks") == 0) {
      line = "";
      auto checkersMsg = groupCheckersByMsgTopic(checkers);

      size_t i = 0;
      for (auto e : checkersMsg) {
        std::string callbackName = "callbackV" + std::to_string(i);
        line += codeGenerator::ident1 + (i == 0 ? "if(" : "else if(");
        line += "name == \"V" + std::to_string(i) + "\"){\n";
        line += codeGenerator::ident2 + "attachedTopics[name] = n->subscribe(\"" +
                callbackTopic.at(callbackName) + "\", 1000, " + callbackName +
                ", ros::TransportHints().tcpNoDelay());\n";
        line += codeGenerator::ident1 + "}\n";
        i++;
      }
        line += codeGenerator::ident1 + "else{\n"+codeGenerator::ident1+" assert(0);}\n";

    } else if (line.compare("$initCheckers") == 0) {
      line = "";
      size_t i = 0;
      for (auto ch : checkers) {
        line += codeGenerator::ident1 + (i == 0 ? "if(" : "else if(");
        line += "name == \"" + ch._name + "\"){\n";
        line += codeGenerator::ident2 + "chs[\"" + ch._name + "\"] = new " +
                ch._name + "(" + std::to_string(nPhs[i]) + ",1,";
        line += std::string("ros::this_node::getName(), ") + "\"" + ch._name +
                "\"";
        line += ");\n";
        line += codeGenerator::ident1 + "}\n";
        i++;
      }
    } else if (line.compare("$pubService") == 0) {
      line = "";
      size_t i = 0;
      for (auto ch : checkers) {
        line += codeGenerator::ident1 + (i == 0 ? "if(" : "else if(");
        line += "name == \"" + ch._name + "\"){\n";
        line += codeGenerator::ident2 + "checkerToSS[\"" + ch._name + "\"] = n->advertiseService( ros::this_node::getName() + \"/migrate/\" + \""+ch._name+"\", migrateTo);\n";
        line += codeGenerator::ident1 + "}\n";
        i++;
      }
    }else{
        line+="\n";
    }
    dst<<line;
  }

  src.close();
  dst.close();
  return true;
}

// Generate include header for handler class
bool generateHandlerHeader(std::vector<strChecker> &checkers) {
  std::ofstream dst("build/output/checkers/include/include_checkers.hh");

  if (dst.fail()) {
    std::cout << "Error: could not open "
                 "build/output/checkers/include/include_checkers.hh"
              << std::endl;
    return false;
  }

  for (auto ch : checkers) {
    dst << "#include \"" << ch._name << ".hh\"\n";
  }

  dst.close();
  return true;
}
}
