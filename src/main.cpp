#include "codeGenerator.hh"
#include "commandLineParser.hh"
#include "odenCore.hh"
#include "parserUtils.hh"
#include "utils_functions.hpp"
#include "xmlUtils.hh"
#include <cmath>
#include <cstdio>
#include <dirent.h>
#include <experimental/filesystem>
#include <fstream>
#include <numeric>

std::map<std::string,std::vector<checkerVar>> bindings;
/*static void parseCommandLineArguments(int argc, char *args[],
                                      std::vector<std::string> &files,
                                      std::string &outDirectory);*/

// Generate code for checker class
bool generateCpp(
    codeGenerator::SpotAutomata &fsm, std::vector<checkerVar> &varList,
    std::pair<std::string, std::unordered_map<std::string, oden::Proposition *>>
        &parsedFormula,
    std::string &checkerName) {

  std::ifstream src("code_templates/class_template.cpp");

  if (src.fail()) {
    std::cout << "Error: could not open class_template.cpp" << std::endl;
    return false;
  }

  std::ofstream dst("output/checkers/src/" + checkerName + ".cpp");

  if (dst.fail()) {
    std::cout << "Error: could not open output/checkers/src/" << checkerName
              << ".cpp" << std::endl;
    return false;
  }

  std::string line;
  std::string toReplace = "$ClassName$";
  size_t len = toReplace.length();

  // Read template file, and on each line replace $ClassName$
  // or generate code

  std::map<std::string, std::vector<checkerVar>> parsedVars;
  groupVariablesByMsgType(parsedVars, varList);

  while (getline(src, line)) {
    while (true) { // To handle multiple occurences
      size_t pos = line.find(toReplace);
      if (pos != std::string::npos)
        line.replace(pos, len, checkerName);
      else
        break;
    }

    // Code for retrieving placeholder's values
    if (line.compare("$order_entry") == 0) {
      line = "";
      for (unsigned int i = 0; i < fsm->ap().size(); i++) {
        line += codeGenerator::ident1 + "if (order_entry & (1ULL << " +
                std::to_string(i) + ")) {\n";
        line += codeGenerator::ident2 + "last_" + (fsm->ap()[i]).ap_name() +
                "= pbuff_entry & (1ULL << " + std::to_string(i) + ");\n";
        line += codeGenerator::ident1 + "}\n";
      }
    }

    // Code for calling eval() and resetting checker
    else if (line.compare("$call_eval") == 0) {
      line = "";
      line += codeGenerator::ident1 + "if (!eval_" + checkerName + "(last_" +
              (fsm->ap()[0]).ap_name();
      for (unsigned int i = 1; i < fsm->ap().size(); i++) {
        line += ",last_" + (fsm->ap()[i]).ap_name();
      }
      line += ")){\n";
      line += codeGenerator::ident2 + "notify_mutex.lock();\n";
      line += codeGenerator::ident2 + "notifyFailure();\n";
      line += codeGenerator::ident2 + "notify_mutex.unlock();\n";
      line += codeGenerator::ident2 + "eval_" + checkerName + "(";
      for (unsigned int i = 0; i < fsm->ap().size(); i++) {
        line += "0,";
      }
      line += "1);\n";
      line += codeGenerator::ident1 + "}\n";

    }

    // Checker FSM
    else if (line.compare("$FSM") == 0) {
      line = "";
      codeGenerator::converter::generateChecker(fsm, checkerName, dst);
    }

    // Declare static vars inside reorder()
    else if (line.compare("$static_vars") == 0) {
      line = "";
      for (auto v : varList) {
        line += codeGenerator::ident1 + "static " + v.type + " " + v.varName +
                ";\n";
      }
    }
    // Set buffer received during the migration
    else if (line.compare("$setBuffer") == 0) {
      line = "";
      std::string placeholders = "";
      for (unsigned int i = 0; i < fsm->ap().size(); i++) {
        line += codeGenerator::ident3 + "bool p" + std::to_string(i) +
                " = val & (1ULL << " + std::to_string(i) + ");\n";
        placeholders += " ,p" + std::to_string(i);
      }

      line += codeGenerator::ident3 + "assign<bool>(pbuff, index_p" +
              placeholders + ");\n";
      line += codeGenerator::ident3 + "val = (req.buffer_o)[i];\n";

      for (unsigned int i = 0; i < fsm->ap().size(); i++) {
        line += codeGenerator::ident3 + "p" + std::to_string(i) +
                " = val & (1ULL << " + std::to_string(i) + ");\n";
      }

      line += codeGenerator::ident3 + "assign<bool>(order, index_p" +
              placeholders + ");\n";

    }

    // Code for generating boolean values for placeholders
    else if (line.compare("$cases") == 0) {
      line = "";
      std::map<std::string, std::vector<std::string>> map;
      groupVariablesByPlaceholders(parsedFormula, map);

      int count = 0;
      std::vector<std::string> usedPlaceholders;
      for (auto v : varList) {
        usedPlaceholders.clear();
        line +=
            codeGenerator::ident5 + "case " + std::to_string(count) + ":{\n";
        // auto varsFromMsgType = v.second;
        // Assign the message's value to the related static variables
        /*for(auto var : varsFromMsgType){
          line+=codeGenerator::ident6+var.varName+" =
        "+"e._value._"+var.varName+";\n";
        }*/

        line += codeGenerator::ident6 + v.varName + " = " + "event._value._" +
                v.varName + ";\n";

        for (auto varPH : map) {

          // Check if a variable is in the expression replaced by the
          // placeholder
          if (std::find(varPH.second.begin(), varPH.second.end(), v.varName) !=
              varPH.second.end()) {
            auto placeholder = varPH.first;
            usedPlaceholders.push_back(placeholder);
            line += codeGenerator::ident6 + "const bool " + placeholder + " = ";

            std::string expression =
                oden::prop2String(*(parsedFormula.second[placeholder]));

            // If the expression is of type float == var use the floatEquals
            // method
            /*if((v.type).compare("float") == 0 && expression.find("==") !=
            std::string::npos){
              int p = expression.find_first_of("==");
              line+="floatEquals"+expression.replace(p,2,",")+";\n";
            }
            else{*/
            line += expression + ";\n";
            //}
          }
        }

        // Alphabetically sort placeholders, e.g. p1,p2,p0 => p0,p1,p2
        std::sort(usedPlaceholders.begin(), usedPlaceholders.end());

        line += codeGenerator::ident6 + "assign<bool>(pbuff, index_p";
        line += getPbuffEntries(usedPlaceholders, parsedFormula.second.size());
        line += ");\n";

        line += codeGenerator::ident6 + "assign<bool>(order, index_p";
        line += getOrderEntries(usedPlaceholders, parsedFormula.second.size());
        line += ");\n";

        line +=
            codeGenerator::ident5 + "}\n" + codeGenerator::ident5 + "break;\n";
        count++;
      }

    }

    else if (line.compare("$addEvent") == 0) {
      line = "";
      int i = 0;
      bindings.insert(std::pair<std::string, std::vector<checkerVar>>(
          checkerName, std::vector<checkerVar>()));

      for (auto v : varList) {

        bindings[checkerName].push_back(v);

        line += "void " + checkerName + "::addEvent_var" + std::to_string(i) +
                "(ros::Time ts, ";
        line += v.type + " value){\n";
        line += codeGenerator::ident1 +
                "if(checkerPhase == pausing && ts > timestampToReach){\n";
        line +=
            codeGenerator::ident2 + "sendBufferClient(_remoteHandlerName);\n";
        line += codeGenerator::ident2 + "checkerPhase = paused;\n";
        line += codeGenerator::ident1 + "}\n";
        line += codeGenerator::ident1 + "else{\n";
        line += codeGenerator::ident2 + "addEvent_mutex.lock();\n";
        line += codeGenerator::ident2 +
                "vbuff.push_back(Event(ts, Value(value, " + std::to_string(i) +
                "),";
        line += std::to_string(i) + "));\n";
        line += codeGenerator::ident2 + "reorder();\n";
        line += codeGenerator::ident2 + "addEvent_mutex.unlock();\n";
        line += codeGenerator::ident1 + "}\n";
        line += "}\n";
        i++;
      }
    }

    dst << line << '\n';
  }

  src.close();
  dst.close();
  return true;
}

// Generate header for checker class
bool generateHeader(codeGenerator::SpotAutomata &fsm,
                    std::vector<checkerVar> &varList,
                    std::string &checkerName) {
  // Copy templates in new files replacing generic names
  std::ifstream src("code_templates/header_template.hh");
  if (src.fail()) {
    std::cout << "Error: could not open header_template.hh" << std::endl;
    return false;
  }

  std::ofstream dst("output/checkers/include/" + checkerName + ".hh");

  if (dst.fail()) {
    std::cout << "Error: could not open output/checkers/include/" << checkerName
              << ".hh" << std::endl;
    return false;
  }

  std::map<std::string, std::vector<checkerVar>> parsedVars;
  groupVariablesByMsgType(parsedVars, varList);

  std::string line;
  std::string toReplace = "$ClassName$";
  size_t len = toReplace.length();

  // Read template file, and on each line replace $ClassName$
  // or generate code

  while (getline(src, line)) {
    while (true) { // To handle multiple occurences
      size_t pos = line.find(toReplace);
      if (pos != std::string::npos)
        line.replace(pos, len, checkerName);
      else
        break;
    }

    // Code for placeholders initialization
    if (line.compare("$init") == 0) {
      line = "";
      for (auto prop : fsm->ap()) {
        line += codeGenerator::ident1 + "bool last_" + prop.ap_name() +
                " = false;\n";
      }
    }
    // Code for defining the eval function
    else if (line.compare("$eval") == 0) {
      line = "";
      line = codeGenerator::ident1 + "bool eval_" + checkerName + "(";
      for (auto ap : fsm->ap()) {
        line += "bool " + ap.ap_name() + ",";
      }
      line += "bool reset = false);\n";
    }

    // Code for defining the Value union based on checker's variables
    else if (line.compare("$value") == 0) {
      line = "";
      std::map<std::string, int> count = countVarTypes(varList);

      // Keep track of used vars
      std::set<std::string> usedVars;

      // Keep track of used types
      std::set<std::string> usedTypes;

      for (size_t i = 0; i < varList.size(); i++) {
        auto var = varList[i];
        if (usedTypes.find(var.type) == usedTypes.end()) {
          line += codeGenerator::ident2 + "Value(const " + var.type +
                  " var, size_t id)";
        }

        // There are at least 2 variables of the same type and the current
        // variable has not already been used
        if (count[var.type] > 1 &&
            usedTypes.find(var.type) == usedTypes.end()) {
          line += "{\n";
          line += codeGenerator::ident3 + "switch (id) {\n";
          for (size_t j = i; j < varList.size(); j++) {
            auto var2 = varList[j];
            if ((var2.type).compare(var.type) == 0) {
              line +=
                  codeGenerator::ident4 + "case " + std::to_string(j) + ":\n";
              line += codeGenerator::ident5 + "_" + var2.varName + " = var;\n";
              line += codeGenerator::ident5 + "break;\n";
            }
          }
          line += codeGenerator::ident4 + "}\n";
          line += codeGenerator::ident3 + "}\n";
          usedTypes.insert(var.type);
        } else if (count[var.type] == 1) {

          line += ": _" + var.varName + "(var){}\n";
        }
      }
      for (auto var : varList) {
        line += codeGenerator::ident2 + var.type + " _" + var.varName + ";\n";
      }

    }

    // Code for including ROS message headers and for defining the checker's
    // initial state
    else if (line.compare("$msgHeaders") == 0) {
      line = "";
      for (auto var : varList) {
        line += "#include \"";
        auto msgType = var.msgType;
        auto p = msgType.find_first_of(":");
        msgType.replace(p, 2, "/");
        line += msgType + ".h\"\n";
      }

      line += "#define INIT_" + checkerName + " " +
              std::to_string(fsm->get_init_state_number()) + "\n";

    }

    else if (line.compare("$addEvent") == 0) {
      line = "";
      int i = 0;
      for (auto v : varList) {
        line += codeGenerator::ident1 + "void addEvent_var" +
                std::to_string(i) + "(ros::Time ts, ";
        line += v.type + " value);\n";
        i++;
      }
    }

    dst << line << '\n';
  }

  src.close();
  dst.close();
  return true;
}

// Generate handler code
bool generateHandler(rapidxml::XmlNodeList &checkers, int nVars[],
                     std::string handlerName, std::string migrateTo) {
  std::ifstream src("code_templates/handler_template.cpp");
  if (src.fail()) {
    std::cout << "Error: could not open handler_template.cpp" << std::endl;
    return false;
  }

  std::ofstream dst("output/ver_env/src/ver_env.cpp");

  if (dst.fail()) {
    std::cout << "Error: could not open output/ver_env/src/ver_env.cpp"
              << std::endl;
    return false;
  }

  std::string line;

  int callbackNum = 0;
  std::map<std::string, std::string> callbackTopic;
  while (getline(src, line)) {
    // Allocate checker instances
    if (line.compare("$addCheckers") == 0) {
      line = "";
      line += codeGenerator::ident1 + "std::string handlerName = " + "\"" +
              handlerName + "\"" + ";\n";

      int i = 0;
      for (auto ch : checkers) {
        bool paused = false;
        auto checkerName = rapidxml::getAttributeValue(ch, "name", "");
        line += codeGenerator::ident1;
        line += "chs[\"" + checkerName + "\"] = new " + checkerName + "(" +
                std::to_string(nVars[i]) + ",rand() % 2 + 1,";
        line += std::string("handlerName, ") + "\"" + checkerName + "\"" + ",";
        line += paused ? "true" : "false";
        line += ");\n";
      }

    }

    // Generate callback functions
    else if (line.compare("$callbacks") == 0) {
      line = "";
      auto checkersMsg = groupCheckersByMsgTopic(checkers);

      for (auto e : checkersMsg) {

        std::string callbackName = "callbackV" + std::to_string(callbackNum);
        auto checkerList = e.second;
        auto msgType = e.first.first;
        auto topicName = e.first.second;

        callbackTopic[callbackName] = topicName;
        line += "//Callback for topic " + topicName + "\n";
        line += "void " + callbackName + "(const ";

        line += msgType + "::Ptr& msg){\n";
        line += codeGenerator::ident1 + "for (const auto& e : chs) {\n";
        line += codeGenerator::ident2 + "auto checker = e.second;\n";
        line += codeGenerator::ident2 +
                "if(checker -> getPhase() != Checker::Phase::paused){\n";

        for (auto ch : checkerList) {
          int i = 0;
          line += codeGenerator::ident3 + "if(dynamic_cast<" + ch +
                  "*>(checker) != NULL){\n";
          line += codeGenerator::ident4 + ch + " *ch = dynamic_cast<" + ch +
                  "*>(checker);\n";

          auto vars = bindings[ch];
          std::string msgField = "";
          for (auto v : vars) {
            if (msgType.compare(v.msgType) == 0 &&
                topicName.compare(v.topicName) == 0) {
              msgField = v.msgField;
              line += codeGenerator::ident4 + "ch->addEvent_var" +
                      std::to_string(i) + "(msg->header.stamp, msg->" +
                      msgField + ");\n";
            }
            i++;
          }
          line += codeGenerator::ident3 + "}\n";
        }

        line += codeGenerator::ident2 + "}\n";
        line += codeGenerator::ident1 + "}\n";
        line += "}\n";
        callbackNum++;
      }

    }

    // Declare a spinner thread and a queue for each callback
    else if (line.compare("$declareSpinners") == 0) {
      line = "";

      line += codeGenerator::ident1 + "ros::CallbackQueue *queue_0";
      for (int i = 1; i < callbackNum; i++) {
        line += ", *queue_" + std::to_string(i);
      }
      line += ";\n";

      line += codeGenerator::ident1 + "ros::Subscriber *sub_0";
      for (int i = 1; i < callbackNum; i++) {
        line += ", *sub_" + std::to_string(i);
      }
      line += ";\n";

      line += codeGenerator::ident1 + "std::thread *thread_0";
      for (int i = 1; i < callbackNum; i++) {
        line += ", *thread_" + std::to_string(i);
      }
      line += ";\n";

      line += codeGenerator::ident1 + "ros::SingleThreadedSpinner *spinner_0";
      for (int i = 1; i < callbackNum; i++) {
        line += ", *spinner_" + std::to_string(i);
      }
      line += ";\n";

    }

    else if (line.compare("$initQueues") == 0) {
      line = "";

      for (int i = 0; i < callbackNum; i++) {
        std::string n = std::to_string(i);
        std::string callbackName = "callbackV" + n;
        line += codeGenerator::ident1 + "queue_" + n +
                " = new ros::CallbackQueue;\n";
        line +=
            codeGenerator::ident1 + "n.setCallbackQueue(queue_" + n + ");\n";
        line +=
            codeGenerator::ident1 + "sub_" + n + " = new ros::Subscriber;\n";
        line += codeGenerator::ident1 + "*sub_" + n + " = n.subscribe(" + "\"" +
                callbackTopic[callbackName] + "\", ";
        line += std::string("1000, ") + callbackName +
                ", ros::TransportHints().tcpNoDelay());\n";
        line += codeGenerator::ident1 + "thread_" + n +
                " = new std::thread([&queue_" + n + ", &spinner_" + n +
                "]() {\n";
        line += codeGenerator::ident2 + "spinner_" + n +
                " = new ros::SingleThreadedSpinner;\n";
        line += codeGenerator::ident2 + "spinner_" + n + "->spin(queue_" + n +
                ");\n";
        line += codeGenerator::ident1 + "});\n\n";
      }
    }

    else if (line.compare("$deleteAll") == 0) {
      line = "";
      for (int i = 0; i < callbackNum; i++) {
        line += codeGenerator::ident1 + "thread_" + std::to_string(i) +
                "->join();\n";
      }
      line += codeGenerator::ident1 + "keepPolling = false;\n\n";

      for (int i = 0; i < callbackNum; i++) {
        line += codeGenerator::ident1 + "delete thread_" + std::to_string(i) +
                ";\n";
        line +=
            codeGenerator::ident1 + "delete sub_" + std::to_string(i) + ";\n";
        line += codeGenerator::ident1 + "delete spinner_" + std::to_string(i) +
                ";\n";
        line += codeGenerator::ident1 + "delete queue_" + std::to_string(i) +
                ";\n\n";
      }

    }

    else if (line.compare("$migrateTo") == 0) {
      line = "";
      line += "std::string migrateTo = \"" + migrateTo + "\";\n";
    }

    dst << line << '\n';
  }

  src.close();
  dst.close();
  return true;
}

// Generate include header for handler class
bool generateHeaderHandler(rapidxml::XmlNodeList &checkers) {
  std::ofstream dst("output/checkers/include/include_checkers.hh");

  if (dst.fail()) {
    std::cout
        << "Error: could not open output/checkers/include/include_checkers.hh"
        << std::endl;
    return false;
  }

  for (auto ch : checkers) {
    auto checkerName = rapidxml::getAttributeValue(ch, "name", "");
    dst << "#include \"" << checkerName << ".hh\"\n";
  }

  dst.close();
  return true;
}

int main(int argc, char *args[]) {

  if (argc < 2) {
    std::cout << "Missing XML specification file, call as ./carmine "
                 "<specification.xml>"
              << std::endl;
    return 0;
  }
  // Parse xml specification
  rapidxml::file<> *_xmlFile;

  rapidxml::xml_document<> *_doc;

  // find root node
  try {
    _xmlFile = new rapidxml::file<>(args[1]);
    _doc = new rapidxml::xml_document<>();
    _doc->parse<0>(_xmlFile->data());
  } catch (rapidxml::parse_error &e) {
    std::stringstream ss;
    ss << "Parsing error in " << /*configFile <<*/ " "
       << "\n"
       << e.m_what << " at line " << e.m_lineNumber << std::endl;
    if (!reinterpret_cast<char *>(e.m_where)[0]) {
      ss << "Hint: you probably forgot to close a tag\n";
    }
  }

  auto root = _doc->first_node("handler");
  std::string handlerName = "";
  std::string migrateTo = "";
  handlerName = rapidxml::getAttributeValue(root, "name", "");
  migrateTo = rapidxml::getAttributeValue(root, "migrateTo", "");
  rapidxml::XmlNodeList checkers;

  rapidxml::getNodesFromName(root, "checker", checkers);

  // Each item in the array is the number o placeholders generated for each
  // checker formula
  int* nVars;
  nVars= new int[checkers.size()];
  int i = 0;
  std::vector<checkerVar> varList;
  // Parse each checker and generate code
  for (auto ch : checkers) {
    std::string formula = rapidxml::getAttributeValue(ch, "LTLformula", "");
    rapidxml::XmlNodeList variables;
    rapidxml::getNodesFromName(ch, "variable", variables);
    std::string declarations = "";

    for (auto v : variables) {
      declarations += rapidxml::getAttributeValue(v, "decl", "") + ";";
    }

    auto parsedFormula = oden::parseLTLformula(formula, declarations);

    nVars[i] = parsedFormula.second.size();

    varList.clear();
    parseVariables(varList, variables);

    auto fsm = codeGenerator::converter::generateAutomata(parsedFormula.first);
    auto checkerName = rapidxml::getAttributeValue(ch, "name", "");

    if (generateCpp(fsm, varList, parsedFormula, checkerName) &&
        generateHeader(fsm, varList, checkerName)) {
      std::cout << "Successfully generated files for checker " << checkerName
                << std::endl;
    } else {
      std::cout << "Could not generate files for checker " << checkerName
                << std::endl;
      return 1;
    }

    i++;
  }

  if (!generateHeaderHandler(checkers)) {
    std::cout << "Could not generate header file for handler node" << std::endl;
    return 1;
  }
  if (!generateHandler(checkers, nVars, handlerName, migrateTo)) {
  delete []nVars;
    std::cout << "Could not generate handler node" << std::endl;
    return 1;
  }

  delete []nVars;
  return 0;
}

void parseCommandLineArguments(int argc, char *args[],
                               std::vector<std::string> &files,
                               std::string &outDirectory) {

  auto result = parse(argc, args);

  if (result.count("f")) {
    files = result["f"].as<std::vector<std::string>>();
  }
  if (result.count("o")) {
    outDirectory = result["o"].as<std::string>();
  }
  if (result.count("d")) {
    std::cout << "Adding files from directory: "
              << result["d"].as<std::string>() << "\n";
    for (const auto &entry : std::experimental::filesystem::directory_iterator(
             result["d"].as<std::string>())) {
      if (entry.path().extension() == ".xml") {
        files.push_back(entry.path().u8string());
      }
    }
  }
  messageErrorIf(files.empty(), "No files found!");
}
