
#include "handlerGenerator.hh"
#include "types.hh"
#include <cmath>
#include <cstdio>
#include <dirent.h>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <numeric>
#include <spot/tl/formula.hh>
#include <string>
#include <utility>
using namespace std::filesystem;

namespace codeGenerator {
bool generateCallbackHeader(std::vector<strChecker> &checkers) {
  std::ifstream src("src/standalone/code_templates/callback_template.hh");
  if (src.fail()) {
    std::cout << "Error: could not open callback_template.hh" << std::endl;
    return false;
  }

  create_directories("build/output/ver_env/src");
  std::ofstream dst("build/output/ver_env/src/callback.hh");

  if (dst.fail()) {
    std::cout << "Error: could not open output/ver_env/src/callback.hh"
              << std::endl;
    return false;
  }

  std::string line;

  int callbackNum = 0;
  std::map<std::string, std::string> callbackToTopic;
  std::map<std::string, std::string> callbackToEnTopic;
  std::map<std::string, std::string> enTopicToCallback;
  std::map<std::string, std::string> topicToCallback;
  std::map<std::string, std::string> topicToEnTopic;
  std::map<std::string, size_t> chNameToIndexInCheckers;
  std::map<std::pair<std::string, std::string>, std::set<std::string>>
      checkersMsg = groupCheckersByMsgTopic(checkers);
  std::map<std::pair<std::string, std::string>, std::pair<strVariable, size_t>>
      ch_enTp_ToVarEn;

  for (auto e : checkersMsg) {
    std::string callbackName = "callbackV" + std::to_string(callbackNum);
    auto topicName = e.first.second;
    callbackToTopic[callbackName] = topicName;
    topicToCallback[topicName] = callbackName;
    callbackToEnTopic[callbackName] = "V" + std::to_string(callbackNum);
    enTopicToCallback["V" + std::to_string(callbackNum)] = callbackName;
    topicToEnTopic[topicName] = "V" + std::to_string(callbackNum);
    callbackNum++;
  }
  for (size_t i = 0; i < checkers.size(); i++) {
    chNameToIndexInCheckers[checkers[i]._name] = i;
  }

  for (auto &cm : checkersMsg) {
    std::string topicName = cm.first.second;
    for (auto &chName : cm.second) {
      auto &vars = checkers[chNameToIndexInCheckers.at(chName)]._variables;
      auto it = std::find_if(vars.begin(), vars.end(), [&topicName](auto &e) {
        return e._rosTopic == topicName;
      });
      ch_enTp_ToVarEn[std::make_pair(chName, topicToEnTopic.at(topicName))] =
          std::make_pair(*it, std::distance(vars.begin(), it));
    }
  }

  // parse and substitute
  while (getline(src, line)) {
    if (line.compare("$callbacks") == 0) {
      line = "";
      for (auto e : checkersMsg) {
        auto checkerList = e.second;
        auto msgType = e.first.first;
        auto topicName = e.first.second;
        std::string callbackName = topicToCallback.at(topicName);

        line += "//Callback for topic " + topicName + "\n";
        line += "inline void " + callbackName + "(const ";
        line += msgType + "::Ptr& msg){\n";
        line += codeGenerator::ident1 + "const std::lock_guard<std::mutex> lock(" +
                toLowerCase(topicToEnTopic.at(topicName)) + "Mutex);\n\n";
        line += codeGenerator::ident1 + "for (auto& fp : " +
                toLowerCase(topicToEnTopic.at(topicName)) + "AddEvent) {\n";
        line +=
            codeGenerator::ident2 +
            "fp.second.second(fp.second.first, msg->header.stamp, msg->num);\n";
        line += codeGenerator::ident1 + "}\n";
        line += "}\n";
      }

    } else if (line.compare("$addVars") == 0) {
      line = "";
      for (auto &c_et_vl : ch_enTp_ToVarEn) {
        line += "//" + c_et_vl.second.first._name + "\n";
        line += "inline void addVar" + c_et_vl.first.first + "_" +
                c_et_vl.first.second + "(Checker *ch, ros::Time ts, " +
                c_et_vl.second.first._type + " val) {\n";
        line += codeGenerator::ident1 + "dynamic_cast<" + c_et_vl.first.first +
                " *>(ch)->addEvent_var" +
                std::to_string(c_et_vl.second.second) + "(ts, val);\n";
        line += "}\n";
      }

    } else if (line.compare("$attachCallbacks") == 0) {
      line = "";
      size_t i = 0;
      for (auto e : checkersMsg) {
        std::string callbackName = "callbackV" + std::to_string(i);
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "name == \"V" + std::to_string(i) + "\"){\n";
        line += codeGenerator::ident2 +
                "attachedTopics[name] = n->subscribe(\"" +
                callbackToTopic.at(callbackName) + "\", 10000, " +
                callbackName + ", ros::TransportHints().tcpNoDelay());\n";
        line += codeGenerator::ident1 + "}";
        i++;
      }
      line += "else{\n" + codeGenerator::ident2 + "assert(0);\n" +
              codeGenerator::ident1 + "}\n";

    } else if (line.compare("$removeTopicFPs") == 0) {
      line = "";
      size_t i = 0;
      for (auto e : checkersMsg) {
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "topic == \"V" + std::to_string(i) + "\"){\n";
        line += codeGenerator::ident2 +
                "const std::lock_guard<std::mutex> lock(v" + std::to_string(i) +
                "Mutex);\n";
        line += codeGenerator::ident2 + "v" + std::to_string(i) +
                "AddEvent.erase(checker);\n";
        line += codeGenerator::ident1 + "}";
        i++;
      }
      line += "else{\n" + codeGenerator::ident2 + "assert(0);\n" +
              codeGenerator::ident1 + "}\n";
    } else if (line.compare("$addTopicFPs") == 0) {
      line = "";
      size_t i = 0;
      for (auto e : checkersMsg) {
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "topic == \"V" + std::to_string(i) + "\"){\n";
        line += codeGenerator::ident2 +
                "const std::lock_guard<std::mutex> lock(v" + std::to_string(i) +
                "Mutex);\n";

        size_t j = 0;
        for (auto &ch : e.second) {
          line += (j == 0 ? codeGenerator::ident2 + "if(" : "else if(");
          line += "checker == \"" + ch + "\"){\n";
          line += codeGenerator::ident3 + "v" + std::to_string(i) +
                  "AddEvent[\"" + ch + "\"] = std::make_pair(chsAll.at(\"" +
                  ch + "\"), &addVar" + ch + "_V" + std::to_string(i) + ");\n";

          line += codeGenerator::ident2 + "}";
          j++;
        }
        line += "else{\n" + codeGenerator::ident3 + "assert(0);\n" +
                codeGenerator::ident2 + "}\n";
        line += codeGenerator::ident1 + "}";
        i++;
      }

      line += "else{\n" + codeGenerator::ident2 + "assert(0);\n" +
              codeGenerator::ident1 + "}\n";

    } else if (line.compare("$pingTopics") == 0) {
      line = "";
      size_t i = 0;
      for (auto e : checkersMsg) {
        auto msgType = e.first.first;
        std::string callbackName = "callbackV" + std::to_string(i);
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "topic == \"V" + std::to_string(i) + "\"){\n";
        line += codeGenerator::ident2 + "boost::shared_ptr<" + msgType +
                " const> msg = ros::topic::waitForMessage<" + msgType + ">(\"" +
                callbackToTopic.at(callbackName) + "\", *n);\n";
        line +=
            codeGenerator::ident2 + "ttlInsert(topic, msg->header.stamp);\n";
        line += codeGenerator::ident1 + "}";
        i++;
      }
      line += "else{\n" + codeGenerator::ident2 + "assert(0);\n" +
              codeGenerator::ident1 + "}\n";

    } else {
      line += "\n";
    }
    dst << line;
  }
  src.close();
  dst.close();
  return 1;
}

bool generateCheckerHelperHeader(std::vector<strChecker> &checkers,
                                 int nPhs[]) {
  std::ifstream src("src/standalone/code_templates/checkerHelper_template.hh");
  if (src.fail()) {
    std::cout << "Error: could not open checkerHelper_template.hh" << std::endl;
    return false;
  }

  create_directories("build/output/ver_env/src");
  std::ofstream dst("build/output/ver_env/src/checkerHelper.hh");

  if (dst.fail()) {
    std::cout << "Error: could not open output/ver_env/src/checkerHelper.hh"
              << std::endl;
    return false;
  }

  std::string line;

  int callbackNum = 0;
  std::map<std::string, std::string> callbackToTopic;
  std::map<std::string, std::string> callbackToEnTopic;
  std::map<std::string, std::string> enTopicToCallback;
  std::map<std::string, std::string> topicToCallback;
  std::map<std::string, std::string> topicToEnTopic;
  std::map<std::string, size_t> chNameToIndexInCheckers;
  std::map<std::pair<std::string, std::string>, std::set<std::string>>
      checkersMsg = groupCheckersByMsgTopic(checkers);
  std::map<std::pair<std::string, std::string>, std::pair<strVariable, size_t>>
      ch_enTp_ToVarEn;

  for (auto e : checkersMsg) {
    std::string callbackName = "callbackV" + std::to_string(callbackNum);
    auto topicName = e.first.second;
    callbackToTopic[callbackName] = topicName;
    topicToCallback[topicName] = callbackName;
    callbackToEnTopic[callbackName] = "V" + std::to_string(callbackNum);
    enTopicToCallback["V" + std::to_string(callbackNum)] = callbackName;
    topicToEnTopic[topicName] = "V" + std::to_string(callbackNum);
    callbackNum++;
  }
  for (size_t i = 0; i < checkers.size(); i++) {
    chNameToIndexInCheckers[checkers[i]._name] = i;
  }

  for (auto &cm : checkersMsg) {
    std::string topicName = cm.first.second;
    for (auto &chName : cm.second) {
      auto &vars = checkers[chNameToIndexInCheckers.at(chName)]._variables;
      auto it = std::find_if(vars.begin(), vars.end(), [&topicName](auto &e) {
        return e._rosTopic == topicName;
      });
      ch_enTp_ToVarEn[std::make_pair(chName, topicToEnTopic.at(topicName))] =
          std::make_pair(*it, std::distance(vars.begin(), it));
    }
  }

  // parse and substitute
  while (getline(src, line)) {
    if (line.compare("$initCheckers") == 0) {
      line = "";
      size_t i = 0;
      for (auto ch : checkers) {
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "name == \"" + ch._name + "\"){\n";
        line += codeGenerator::ident2 + "chsActive[\"" + ch._name +
                "\"] = new " + ch._name + "(" + std::to_string(nPhs[i]) + ",1,";
        line +=
            std::string("ros::this_node::getName(), ") + "\"" + ch._name + "\"";
        line += ");\n";
        line += codeGenerator::ident2 + "chsAll[\"" + ch._name +
                "\"] = chsActive.at(\"" + ch._name + "\");\n";
        line += codeGenerator::ident1 + "}";
        i++;
      }
    } else if (line.compare("$initCheckerTopicRelations") == 0) {
      line = "";
      for (auto e : checkersMsg) {
        for (auto &ch : e.second) {
          line += codeGenerator::ident1 + "checkerToTopic[\"" + ch +
                  "\"].emplace_back(\"" + topicToEnTopic.at(e.first.second) +
                  "\");\n";
          line += codeGenerator::ident1 + "topicToChecker[\"" +
                  topicToEnTopic.at(e.first.second) + "\"].emplace_back(\"" +
                  ch + "\");\n";
        }
      }
    } else {
      line += "\n";
    }
    dst << line;
  }
  src.close();
  dst.close();
  return 1;
}
bool generateGlobalsHeader(std::vector<strChecker> &checkers) {
  std::ifstream src("src/standalone/code_templates/globals_template.hh");
  if (src.fail()) {
    std::cout << "Error: could not open globals_template.hh" << std::endl;
    return false;
  }

  create_directories("build/output/ver_env/src");
  std::ofstream dst("build/output/ver_env/src/globals.hh");

  if (dst.fail()) {
    std::cout << "Error: could not open output/ver_env/src/globals.hh"
              << std::endl;
    return false;
  }

  std::string line;

  int callbackNum = 0;
  std::map<std::string, std::string> callbackToTopic;
  std::map<std::string, std::string> callbackToEnTopic;
  std::map<std::string, std::string> enTopicToCallback;
  std::map<std::string, std::string> enTopicVarType;
  std::map<std::string, std::string> topicToCallback;
  std::map<std::string, std::string> topicToEnTopic;
  std::map<std::string, size_t> chNameToIndexInCheckers;
  std::map<std::pair<std::string, std::string>, std::set<std::string>>
      checkersMsg = groupCheckersByMsgTopic(checkers);
  std::map<std::pair<std::string, std::string>, std::pair<strVariable, size_t>>
      ch_enTp_ToVarEn;

  for (auto e : checkersMsg) {
    std::string callbackName = "callbackV" + std::to_string(callbackNum);
    auto topicName = e.first.second;
    callbackToTopic[callbackName] = topicName;
    topicToCallback[topicName] = callbackName;
    callbackToEnTopic[callbackName] = "V" + std::to_string(callbackNum);
    enTopicToCallback["V" + std::to_string(callbackNum)] = callbackName;
    topicToEnTopic[topicName] = "V" + std::to_string(callbackNum);
    callbackNum++;
  }
  for (size_t i = 0; i < checkers.size(); i++) {
    chNameToIndexInCheckers[checkers[i]._name] = i;
  }

  for (auto &cm : checkersMsg) {
    std::string topicName = cm.first.second;
    for (auto &chName : cm.second) {
      auto &vars = checkers[chNameToIndexInCheckers.at(chName)]._variables;
      auto it = std::find_if(vars.begin(), vars.end(), [&topicName](auto &e) {
        return e._rosTopic == topicName;
      });
      ch_enTp_ToVarEn[std::make_pair(chName, topicToEnTopic.at(topicName))] =
          std::make_pair(*it, std::distance(vars.begin(), it));
    }
  }
  for (auto &c : ch_enTp_ToVarEn) {
      enTopicVarType[c.first.second]=c.second.first._type;
  }

  // parse and substitute
  while (getline(src, line)) {
    if (line.compare("$vMutexs") == 0) {
      line = "";
      for (size_t i = 0; i < checkersMsg.size(); i++) {
        line += "extern std::mutex v" + std::to_string(i) + "Mutex;\n";
      }
    } else if (line.compare("$vAddEvents") == 0) {
      line = "";
      for (auto &et_vt : enTopicVarType) {
          line+="extern std::unordered_map<std::string,std::pair<Checker*,void (*)(Checker*, ros::Time, "+et_vt.second+")>> "+toLowerCase(et_vt.first)+"AddEvent;\n";
      }
    } else {
      line += "\n";
    }
    dst << line;
  }
  src.close();
  dst.close();
  return 1;
}
bool generateGlobalsSource(std::vector<strChecker> &checkers) {
  std::ifstream src("src/standalone/code_templates/globals_template.cpp");
  if (src.fail()) {
    std::cout << "Error: could not open globals_template.cpp" << std::endl;
    return false;
  }

  create_directories("build/output/ver_env/src");
  std::ofstream dst("build/output/ver_env/src/globals.cpp");

  if (dst.fail()) {
    std::cout << "Error: could not open output/ver_env/src/globals.cpp"
              << std::endl;
    return false;
  }

  std::string line;

  int callbackNum = 0;
  std::map<std::string, std::string> callbackToTopic;
  std::map<std::string, std::string> callbackToEnTopic;
  std::map<std::string, std::string> enTopicToCallback;
  std::map<std::string, std::string> enTopicVarType;
  std::map<std::string, std::string> topicToCallback;
  std::map<std::string, std::string> topicToEnTopic;
  std::map<std::string, size_t> chNameToIndexInCheckers;
  std::map<std::pair<std::string, std::string>, std::set<std::string>>
      checkersMsg = groupCheckersByMsgTopic(checkers);
  std::map<std::pair<std::string, std::string>, std::pair<strVariable, size_t>>
      ch_enTp_ToVarEn;

  for (auto e : checkersMsg) {
    std::string callbackName = "callbackV" + std::to_string(callbackNum);
    auto topicName = e.first.second;
    callbackToTopic[callbackName] = topicName;
    topicToCallback[topicName] = callbackName;
    callbackToEnTopic[callbackName] = "V" + std::to_string(callbackNum);
    enTopicToCallback["V" + std::to_string(callbackNum)] = callbackName;
    topicToEnTopic[topicName] = "V" + std::to_string(callbackNum);
    callbackNum++;
  }
  for (size_t i = 0; i < checkers.size(); i++) {
    chNameToIndexInCheckers[checkers[i]._name] = i;
  }

  for (auto &cm : checkersMsg) {
    std::string topicName = cm.first.second;
    for (auto &chName : cm.second) {
      auto &vars = checkers[chNameToIndexInCheckers.at(chName)]._variables;
      auto it = std::find_if(vars.begin(), vars.end(), [&topicName](auto &e) {
        return e._rosTopic == topicName;
      });
      ch_enTp_ToVarEn[std::make_pair(chName, topicToEnTopic.at(topicName))] =
          std::make_pair(*it, std::distance(vars.begin(), it));
    }
  }
  for (auto &c : ch_enTp_ToVarEn) {
      enTopicVarType[c.first.second]=c.second.first._type;
  }

  // parse and substitute
  while (getline(src, line)) {
    if (line.compare("$vMutexs") == 0) {
      line = "";
      for (size_t i = 0; i < checkersMsg.size(); i++) {
        line += "std::mutex v" + std::to_string(i) + "Mutex;\n";
      }
    } else if (line.compare("$vAddEvents") == 0) {
      line = "";
      for (auto &et_vt : enTopicVarType) {
          line+="std::unordered_map<std::string,std::pair<Checker*,void (*)(Checker*, ros::Time, "+et_vt.second+")>> "+toLowerCase(et_vt.first)+"AddEvent;\n";
      }
    } else {
      line += "\n";
    }
    dst << line;
  }
  src.close();
  dst.close();
  return 1;
}
}
