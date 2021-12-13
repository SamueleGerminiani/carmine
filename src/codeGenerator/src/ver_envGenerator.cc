
#include "types.hh"
#include "ver_EnvGenerator.hh"
#include <cmath>
#include <cstdio>
#include <dirent.h>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <numeric>
#include <spot/tl/formula.hh>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std::filesystem;

namespace codeGenerator {

std::unordered_map<std::string, std::vector<std::string>>
get_topicToCheckers(std::vector<strChecker> &checkers) {
  std::unordered_map<std::string, std::vector<std::string>> ret;
  for (auto &ch : checkers) {
    for (auto &var : ch._variables) {
      ret[var._rosTopic].push_back(ch._name);
    }
  }

  for (auto &t_cc : ret) {
    auto &vec = t_cc.second;
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  }
  return ret;
}

std::unordered_map<std::string, std::string>
get_topicToEnTopic(std::vector<strChecker> &checkers) {

  std::vector<std::string> topics;
  for (auto &ch : checkers) {
    for (auto &var : ch._variables) {
      topics.push_back(var._rosTopic);
    }
  }

  std::sort(topics.begin(), topics.end());
  topics.erase(std::unique(topics.begin(), topics.end()), topics.end());
  std::unordered_map<std::string, std::string> ret;
  for (size_t i = 0; i < topics.size(); i++) {
    ret[topics[i]] = "T" + std::to_string(i);
  }

  return ret;
}
std::unordered_map<std::string, std::string>
get_enTopicToTopic(std::vector<strChecker> &checkers) {

  std::vector<std::string> topics;
  for (auto &ch : checkers) {
    for (auto &var : ch._variables) {
      topics.push_back(var._rosTopic);
    }
  }

  std::sort(topics.begin(), topics.end());
  topics.erase(std::unique(topics.begin(), topics.end()), topics.end());
  std::unordered_map<std::string, std::string> ret;
  for (size_t i = 0; i < topics.size(); i++) {
    ret["T" + std::to_string(i)] = topics[i];
  }

  return ret;
}
std::unordered_map<std::string, std::string>
get_topicToMsgType(std::vector<strChecker> &checkers) {

  std::unordered_map<std::string, std::string> ret;
  for (auto &ch : checkers) {
    for (auto &var : ch._variables) {
      ret[var._rosTopic] = var._msgType;
    }
  }

  return ret;
}
std::map<std::pair<std::string, std::string>,
         std::vector<std::tuple<std::string, std::string, std::string,
                                std::pair<std::string, std::string>>>>
get_CheckerTopicToVarFieldTypeFilter(std::vector<strChecker> &checkers) {

  std::map<std::pair<std::string, std::string>,
           std::vector<std::tuple<std::string, std::string, std::string,
                                  std::pair<std::string, std::string>>>>
      ret;

  for (auto &ch : checkers) {
    for (auto &var : ch._variables) {
      ret[std::make_pair(ch._name, var._rosTopic)].push_back(std::make_tuple(
          var._name, var._msgField, var._type,
          std::make_pair(var._filter.first, var._filter.second)));
    }
  }

  return ret;
}
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

  auto topicToEnTopic = get_topicToEnTopic(checkers);
  auto topicToCheckers = get_topicToCheckers(checkers);
  auto topicToMsgType = get_topicToMsgType(checkers);
  auto checkerTopicToVarField = get_CheckerTopicToVarFieldTypeFilter(checkers);

  // parse and substitute
  while (getline(src, line)) {
    if (line.compare("$callbacks") == 0) {
      line = "";
      for (auto &t_et : topicToEnTopic) {
        auto msgType = topicToMsgType.at(t_et.first);
        auto topicName = t_et.first;
        std::string callbackName = "callback" + t_et.second;

        line += "//Callback for topic " + topicName + "\n";
        line += "inline void " + callbackName + "(const ";
        line += msgType + "::Ptr& msg){\n";
        line += codeGenerator::ident1 +
                "const std::lock_guard<std::mutex> lock(" +
                toLowerCase(topicToEnTopic.at(topicName)) + "Mutex);\n\n";
        line += codeGenerator::ident1 + "for (auto& fp : " +
                toLowerCase(topicToEnTopic.at(topicName)) + "AddEvent) {\n";
        line += codeGenerator::ident2 +
                "fp.second.second(fp.second.first, msg->header.stamp, msg);\n";
        line += codeGenerator::ident1 + "}\n";
        line += "}\n";
      }

    } else if (line.compare("$addVars") == 0) {
      line = "";
      for (auto &ct_vf : checkerTopicToVarField) {
        line += "inline void addVar" + ct_vf.first.first + "_" +
                topicToEnTopic.at(ct_vf.first.second) +
                "(Checker *ch, ros::Time ts, const " +
                topicToMsgType.at(ct_vf.first.second) + "::Ptr& msg) {\n";
        for (auto &vff : ct_vf.second) {

          if (std::get<3>(vff).first != "none") {

            if (std::get<3>(vff).first == "ma") {
              line += "static std::deque<" + std::get<2>(vff) + "> window_"+std::get<0>(vff)+"(" +
                      std::get<3>(vff).second + ",0);\n";
              line += "window_"+std::get<0>(vff)+".pop_front(); window_"+std::get<0>(vff)+".push_back(msg->" +
                      std::get<1>(vff) + ");\n";
              line += codeGenerator::ident1 + "dynamic_cast<" +
                      ct_vf.first.first + " *>(ch)->addEvent_" +
                      std::get<0>(vff) + "(ts,std::accumulate(window_"+std::get<0>(vff)+".begin(), window_"+std::get<0>(vff)+".end(), ("+std::get<2>(vff)+")0)/window_"+std::get<0>(vff)+".size());\n";
            }
          } else {
            line += codeGenerator::ident1 + "dynamic_cast<" +
                    ct_vf.first.first + " *>(ch)->addEvent_" +
                    std::get<0>(vff) + "(ts, msg->" + std::get<1>(vff) + ");\n";
          }
        }
        line += "}\n";
      }

    } else if (line.compare("$attachCallbacks") == 0) {
      line = "";
      size_t i = 0;
      for (auto t_cc : topicToCheckers) {
        std::string callbackName = "callback" + topicToEnTopic.at(t_cc.first);
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "name == \"" + topicToEnTopic.at(t_cc.first) + "\"){\n";
        line += codeGenerator::ident2 +
                "attachedTopics[name] = n->subscribe(topicPrefix + \"" +
                t_cc.first + "\", 10000, " + callbackName +
                ", ros::TransportHints().tcpNoDelay()); \n ";
        line += codeGenerator::ident1 + "}";
        i++;
      }
      line += "else{\n" + codeGenerator::ident2 + "assert(0);\n" +
              codeGenerator::ident1 + "}\n";

    } else if (line.compare("$removeTopicFPs") == 0) {
      line = "";
      for (size_t i = 0; i < topicToCheckers.size(); i++) {

        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "topic == \"T" + std::to_string(i) + "\"){\n";
        line += codeGenerator::ident2 +
                "const std::lock_guard<std::mutex> lock(t" + std::to_string(i) +
                "Mutex);\n";
        line += codeGenerator::ident2 + "t" + std::to_string(i) +
                "AddEvent.erase(checker);\n";
        line += codeGenerator::ident1 + "}";
      }
      line += "else{\n" + codeGenerator::ident2 + "assert(0);\n" +
              codeGenerator::ident1 + "}\n";
    } else if (line.compare("$addTopicFPs") == 0) {
      line = "";
      size_t i = 0;
      for (auto e : topicToCheckers) {
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "topic == \"" + topicToEnTopic.at(e.first) + "\"){\n";
        line += codeGenerator::ident2 +
                "const std::lock_guard<std::mutex> lock(" +
                toLowerCase(topicToEnTopic.at(e.first)) + "Mutex);\n";

        size_t j = 0;
        for (auto &ch : e.second) {
          line += (j == 0 ? codeGenerator::ident2 + "if(" : "else if(");
          line += "checker == \"" + ch + "\"){\n";
          line += codeGenerator::ident3 +
                  toLowerCase(topicToEnTopic.at(e.first)) + "AddEvent[\"" + ch +
                  "\"] = std::make_pair(chsAll.at(\"" + ch + "\"), &addVar" +
                  ch + "_" + topicToEnTopic.at(e.first) + ");\n";

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
      for (auto e : topicToCheckers) {
        auto msgType = topicToMsgType.at(e.first);
        std::string callbackName = "callback" + topicToEnTopic.at(e.first);
        line += (i == 0 ? codeGenerator::ident1 + "if(" : "else if(");
        line += "topic == \"" + topicToEnTopic.at(e.first) + "\"){\n";
        line += codeGenerator::ident2 + "boost::shared_ptr<" + msgType +
                " const> msg = ros::topic::waitForMessage<" + msgType + ">(" +
                "topicPrefix + \"" + e.first + "\", *n);\n";
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
  auto topicToEnTopic = get_topicToEnTopic(checkers);
  auto topicToCheckers = get_topicToCheckers(checkers);
  auto topicToMsgType = get_topicToMsgType(checkers);

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
      for (auto e : topicToCheckers) {
        for (auto &ch : e.second) {
          line += codeGenerator::ident1 + "checkerToTopic[\"" + ch +
                  "\"].emplace_back(\"" + topicToEnTopic.at(e.first) + "\");\n";
          line += codeGenerator::ident1 + "topicToChecker[\"" +
                  topicToEnTopic.at(e.first) + "\"].emplace_back(\"" + ch +
                  "\");\n";
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
  auto topicToEnTopic = get_topicToEnTopic(checkers);
  auto topicToCheckers = get_topicToCheckers(checkers);
  auto topicToMsgType = get_topicToMsgType(checkers);

  // parse and substitute
  while (getline(src, line)) {
    if (line.compare("$vMutexs") == 0) {
      line = "";
      for (size_t i = 0; i < topicToCheckers.size(); i++) {
        line += "extern std::mutex t" + std::to_string(i) + "Mutex;\n";
      }
    } else if (line.compare("$includeCheckers") == 0) {
      line = "";
      for (auto &ch : checkers) {
        line += "#include \"" + ch._name + ".hh\"\n";
      }
    } else if (line.compare("$msgHeaders") == 0) {
      line = "";
      std::unordered_set<std::string> alreadyIncluded;
      std::vector<strVariable> varList;
      for (auto &ch : checkers) {
        for (auto v : ch._variables) {
          varList.push_back(v);
        }
      }
      for (auto var : varList) {
        std::string toInclude = "";
        toInclude += "#include \"";
        auto msgType = var._msgType;
        auto p = msgType.find_first_of(":");
        msgType.replace(p, 2, "/");
        toInclude += msgType + ".h\"\n";
        if (alreadyIncluded.count(toInclude)) {
          continue;
        }
        alreadyIncluded.insert(toInclude);
        line += toInclude;
      }

    } else if (line.compare("$vAddEvents") == 0) {
      line = "";
      for (auto &t_m : topicToMsgType) {
        line += "extern std::unordered_map<std::string,std::pair<Checker*,void "
                "(*)(Checker*, ros::Time, const " +
                topicToMsgType.at(t_m.first) + "::Ptr&)>> " +
                toLowerCase(topicToEnTopic.at(t_m.first)) + "AddEvent;\n";
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
  auto topicToEnTopic = get_topicToEnTopic(checkers);
  auto topicToCheckers = get_topicToCheckers(checkers);
  auto topicToMsgType = get_topicToMsgType(checkers);

  // parse and substitute
  while (getline(src, line)) {
    if (line.compare("$vMutexs") == 0) {
      line = "";
      for (size_t i = 0; i < topicToCheckers.size(); i++) {
        line += "std::mutex t" + std::to_string(i) + "Mutex;\n";
      }
    } else if (line.compare("$vAddEvents") == 0) {
      line = "";
      for (auto &t_m : topicToMsgType) {
        line += "std::unordered_map<std::string,std::pair<Checker*,void "
                "(*)(Checker*, ros::Time, const " +
                topicToMsgType.at(t_m.first) + "::Ptr&)>> " +
                toLowerCase(topicToEnTopic.at(t_m.first)) + "AddEvent;\n";
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
