
#include "checkerGenerator.hh"
#include "converter.hh"
#include "odenCore.hh"
#include "parserUtils.hh"
#include "globals.hh"
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

std::string formulaToString(const spot::formula f) {

  // And
  if (f.is(spot::op::And)) {
    std::string ret = "";
    ret = "(" + formulaToString(f[0]);
    for (size_t i = 1; i < f.size(); i++) {
      ret += " && " + formulaToString(f[i]);
    }
    ret += ")";
    return ret;
  }

  // Or
  if (f.is(spot::op::Or)) {
    std::string ret = "";
    ret = "(" + formulaToString(f[0]);
    for (size_t i = 1; i < f.size(); i++) {
      ret += " || " + formulaToString(f[i]);
    }
    ret += ")";
    return ret;
  }

  // Not
  if (f.is(spot::op::Not)) {
    return "!" + formulaToString(f[0]);
  }

  // Atomic proposition
  if (f.is(spot::op::ap)) {
    if (f.is_tt() || f.ap_name().find("start", 0) != std::string::npos) {
      return "1";
    }
    return f.ap_name();
  }

  if (f.is_tt()) {
    return "1";
  }
  return "";
}

bool tokenExists(const spot::formula f, const std::string &token) {

  bool ret = 0;
  for (size_t i = 0; i < f.size(); i++) {
    ret = ret || tokenExists(f[i], token);
  }
  if (f.is(spot::op::ap)) {
    auto tok = f.ap_name();
    return tok == token;
  }

  return ret;
}

void formulaToGetTimers(const spot::formula f, std::set<size_t> &timers) {

  for (size_t i = 0; i < f.size(); i++) {
    formulaToGetTimers(f[i], timers);
  }

  // Atomic proposition
  if (f.is(spot::op::ap)) {
    auto token = f.ap_name();
    if (token.find("stop", 0) != std::string::npos) {
      timers.insert(std::stoul(token.substr(4, token.size() - 4)));
    }
  }
}

static bool replace(std::string &str, const std::string &from,
                    const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
  return true;
}

// Generate code for checker class
bool generateCheckerSource(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList,
    std::pair<std::pair<std::string, std::string>,
              std::unordered_map<std::string, oden::Proposition *>>
        &parsedFormula,
    std::string &checkerName) {

  std::vector<spot::formula> aps;
  auto autAss = fsms.first;
  auto autAnt = fsms.second;
  auto &phToProps = parsedFormula.second;

  // gather all the placeholders in the formula
  //'start' and 'stop' variables are used only to handle timers, we must
  // discard them from the list of placeholders
  for (auto ap : autAss->ap()) {
    if (ap.ap_name().find("start", 0) != std::string::npos ||
        ap.ap_name().find("stop", 0) != std::string::npos) {
      continue;
    }
    aps.push_back(ap);
  }

  std::ifstream src("src/standalone/code_templates/checker_template.cpp");

  remove_all(path("build/output"));
  create_directories("build/output/checkers/src");
  create_directories("build/output/checkers/include");

  if (src.fail()) {
    std::cout << "Error: could not open checker_template.cpp" << std::endl;
    return false;
  }

  std::ofstream dst("build/output/checkers/src/" + checkerName + ".cpp");

  if (dst.fail()) {
    std::cout << "Error: could not open build/output/checkers/src/"
              << checkerName << ".cpp" << std::endl;
    return false;
  }

  // Read template file, and on each line replace $ClassName$
  // or generate code

  std::map<std::string, std::vector<strVariable>> parsedVars;
  groupVariablesByMsgType(parsedVars, varList);
  std::string line;

  while (getline(src, line)) {
    while (replace(line, "$ClassName$", checkerName))
      ; // To handle multiple occurences

    // Code for retrieving placeholder's values
    if (line.compare("$order_entry") == 0) {
      line = "";
      for (unsigned int i = 0; i < aps.size(); i++) {
        line += codeGenerator::ident1 + "if (order_entry & (1ULL << " +
                std::to_string(i) + ")) {\n";
        line += codeGenerator::ident2 + "last_" + (aps[i]).ap_name() +
                "= pbuff_entry & (1ULL << " + std::to_string(i) + ");\n";
        line += codeGenerator::ident1 + "}\n";
      }
    }

    // Code for calling eval() and resetting checker
    else if (line.compare("$call_eval") == 0) {
      line = "";
      line += codeGenerator::ident1 + "if (!eval_" + checkerName + "(last_" +
              (aps[0]).ap_name();
      for (unsigned int i = 1; i < aps.size(); i++) {
        line += ",last_" + (aps[i]).ap_name();
      }
      line += ")){\n";
      line += codeGenerator::ident2 + "notify_mutex.lock();\n";
      line += codeGenerator::ident2 + "notifyFailure();\n";
      line += codeGenerator::ident2 + "notify_mutex.unlock();\n";
      line += codeGenerator::ident2 + "eval_" + checkerName + "(";
      for (unsigned int i = 0; i < aps.size(); i++) {
        line += "0,";
      }
      line += "1);\n";
      line += codeGenerator::ident1 + "}\n";

    }

    // Checker FSM
    else if (line.compare("$FSM") == 0) {
      line = "";
      generateEvalFunction(fsms, checkerName, dst);
    } else if (line.compare("$initTimers$") == 0) {
      line = "";
      for (size_t i = 0; i < timer::timers.size(); i++) {
        line += codeGenerator::ident1 + "_timerInstances[" + std::to_string(i) +
                "];\n";
        line +=
            codeGenerator::ident1 + "_timerCache[" + std::to_string(i) + "];\n";
        line += codeGenerator::ident1 + "_timeouts.push_back(" +
                std::to_string(timer::timers[i].second) + ");\n";
      }
    }

    // Declare static vars inside reorder()
    else if (line.compare("$static_vars") == 0) {
      line = "";
      for (auto v : varList) {
        line +=
            codeGenerator::ident1 + "static " + v._type + " " + v._name + ";\n";
      }
    }
    // Set buffer received during the migration
    else if (line.compare("$setBuffer") == 0) {
      line = "";
      std::string placeholders = "";
      for (unsigned int i = 0; i < aps.size(); i++) {
        line += codeGenerator::ident3 + "bool p" + std::to_string(i) +
                " = val & (1ULL << " + std::to_string(i) + ");\n";
        placeholders += " ,p" + std::to_string(i);
      }

      line += codeGenerator::ident3 + "assign<bool>(pbuff, index_p" +
              placeholders + ");\n";
      line += codeGenerator::ident3 + "val = (req.buffer_o)[i];\n";

      for (unsigned int i = 0; i < aps.size(); i++) {
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

        line += codeGenerator::ident6 + v._name + " = " + "event._value._" +
                v._name + ";\n";

        for (auto varPH : map) {

          // Check if a variable is in the expression replaced by the
          // placeholder
          if (std::find(varPH.second.begin(), varPH.second.end(), v._name) !=
              varPH.second.end()) {
            auto placeholder = varPH.first;
            usedPlaceholders.push_back(placeholder);
            line += codeGenerator::ident6 + "const bool " + placeholder + " = ";

            std::string expression =
                oden::prop2String(*(phToProps[placeholder]));

            line += expression + ";\n";
          }
        }

        // Alphabetically sort placeholders, e.g. p1,p2,p0 => p0,p1,p2
        std::sort(usedPlaceholders.begin(), usedPlaceholders.end());

        line += codeGenerator::ident6 + "assign<bool>(pbuff, index_p";
        line += getPbuffEntries(usedPlaceholders, phToProps.size());
        line += ");\n";

        line += codeGenerator::ident6 + "assign<bool>(order, index_p";
        line += getOrderEntries(usedPlaceholders, phToProps.size());
        line += ");\n";

        line +=
            codeGenerator::ident5 + "}\n" + codeGenerator::ident5 + "break;\n";
        count++;
      }

    }

    else if (line.compare("$addEvent") == 0) {
      line = "";
      int i = 0;
      bindings.insert(std::pair<std::string, std::vector<strVariable>>(
          checkerName, std::vector<strVariable>()));

      for (auto v : varList) {

        bindings[checkerName].push_back(v);

        line += "void " + checkerName + "::addEvent_var" + std::to_string(i) +
                "(ros::Time ts, ";
        line += v._type + " value){\n";
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
bool generateCheckerHeader(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList, std::string &checkerName) {
  auto autAss = fsms.first;
  auto autAnt = fsms.second;

  // Copy templates in new files replacing the tokens
  std::ifstream src("src/standalone/code_templates/checker_template.hh");
  if (src.fail()) {
    std::cout << "Error: could not open checker_template.hh" << std::endl;
    return false;
  }

  std::ofstream dst("build/output/checkers/include/" + checkerName + ".hh");

  if (dst.fail()) {
    std::cout << "Error: could not open build/output/checkers/include/"
              << checkerName << ".hh" << std::endl;
    return false;
  }

  std::map<std::string, std::vector<strVariable>> parsedVars;
  groupVariablesByMsgType(parsedVars, varList);

  std::string line;
  std::vector<spot::formula> aps;

  for (auto ap : autAss->ap()) {
    if (ap.ap_name().find("start", 0) != std::string::npos ||
        ap.ap_name().find("stop", 0) != std::string::npos) {
      continue;
    }
    aps.push_back(ap);
  }

  while (getline(src, line)) {

    while (replace(line, "$ClassName$", checkerName))
      ;
    while (replace(line, "$nStatesAss$", std::to_string(autAss->num_states())))
      ;
    while (replace(line, "$nStatesAnt$", std::to_string(autAnt->num_states())))
      ;

    // Code for placeholders initialization
    if (line.compare("$init") == 0) {
      line = "";
      for (auto prop : aps) {
        line += codeGenerator::ident1 + "bool last_" + prop.ap_name() +
                " = false;\n";
      }
    }

    // Code for defining the eval function
    else if (line.compare("$eval") == 0) {
      line = "";
      line = codeGenerator::ident1 + "bool eval_" + checkerName + "(";
      for (auto ap : aps) {
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
        if (usedTypes.find(var._type) == usedTypes.end()) {
          line += codeGenerator::ident2 + "Value(const " + var._type +
                  " var, size_t id)";
        }

        // There are at least 2 variables of the same type and the current
        // variable has not already been used
        if (count[var._type] > 1 &&
            usedTypes.find(var._type) == usedTypes.end()) {
          line += "{\n";
          line += codeGenerator::ident3 + "switch (id) {\n";
          for (size_t j = i; j < varList.size(); j++) {
            auto var2 = varList[j];
            if ((var2._type).compare(var._type) == 0) {
              line +=
                  codeGenerator::ident4 + "case " + std::to_string(j) + ":\n";
              line += codeGenerator::ident5 + "_" + var2._name + " = var;\n";
              line += codeGenerator::ident5 + "break;\n";
            }
          }
          line += codeGenerator::ident4 + "}\n";
          line += codeGenerator::ident3 + "}\n";
          usedTypes.insert(var._type);
        } else if (count[var._type] == 1) {

          line += ": _" + var._name + "(var){}\n";
        }
      }
      for (auto var : varList) {
        line += codeGenerator::ident2 + var._type + " _" + var._name + ";\n";
      }

    }

    // Code for including ROS message headers and for defining the checker's
    // initial state
    else if (line.compare("$msgHeaders") == 0) {
      line = "";
      for (auto var : varList) {
        line += "#include \"";
        auto msgType = var._msgType;
        auto p = msgType.find_first_of(":");
        msgType.replace(p, 2, "/");
        line += msgType + ".h\"\n";
      }

      line += "#define INIT_" + checkerName + " " +
              std::to_string(autAss->get_init_state_number()) + "\n";

    }

    else if (line.compare("$addEvent") == 0) {
      line = "";
      int i = 0;
      for (auto v : varList) {
        line += codeGenerator::ident1 + "void addEvent_var" +
                std::to_string(i) + "(ros::Time ts, ";
        line += v._type + " value);\n";
        i++;
      }
    }

    dst << line << '\n';
  }

  src.close();
  dst.close();
  return true;
}

void generateEvalFunction(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    const std::string checkerName, std::ofstream &outstream) {

  std::string initState = "INIT_" + checkerName;
  outstream << "//Return true if checker did not fail" << std::endl;
  outstream << "inline bool " + checkerName + "::eval_" + checkerName + "(";
  auto autAss = fsms.first;
  auto autAnt = fsms.second;

  // Add all input variables (atomic propositions and placeholders)
  for (auto f : autAss->ap()) {
    if (f.ap_name().find("start", 0) != std::string::npos ||
        f.ap_name().find("stop", 0) != std::string::npos) {
      continue;
    }
    outstream << "bool " << f << ", ";
  }

  outstream << "bool const reset";

  outstream << "){" << std::endl;

  outstream << codeGenerator::ident1 << "if(reset){\n"
            << codeGenerator::ident2 << "resetChecker();" << std::endl
            << codeGenerator::ident2 << "return 1;" << std::endl
            << codeGenerator::ident1 << "}" << std::endl;

  const spot::bdd_dict_ptr &dict = autAss->get_dict();
  unsigned num_states = autAss->num_states();

  outstream << codeGenerator::ident1 << " currAss["
            << autAss->get_init_state_number() << "]++;\n";
  // ass
  for (unsigned state = 0; state < num_states; state++) {

    auto currState = autAss->state_from_number(state);

    // skip term states
    auto it = autAss->succ_iter(currState);
    if (it->first() && (it->dst()->hash() == currState->hash()) &&
        !it->next()) {
      delete it;
      continue;
    }
    delete it;

    outstream << codeGenerator::ident1 << " for (size_t i = 0; i < "
              << "currAss[" << state << "]; i++) {\n";

    // gather stop clauses
    std::set<size_t> timers;
    for (auto &edge : autAss->out(state)) {
      spot::formula f =
          spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
      formulaToGetTimers(f, timers);
    }
    for (auto t : timers) {
      outstream << codeGenerator::ident2 << "bool stop" << t
                << " = getTimerValue(" << t << ", i, 1);\n";
    }

    bool firstEdge = true;
    for (auto &edge : autAss->out(state)) {
      spot::formula f =
          spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
      // Convert formula to string format
      std::string stringF = formulaToString(f);
      if (firstEdge) {
        outstream << codeGenerator::ident2 << "if(" << stringF << "){\n";
        firstEdge = 0;
      } else {
        outstream << codeGenerator::ident2 << "else if(" << stringF << "){\n";
      }

      // term edges
      auto nextState = autAss->state_from_number(edge.dst);
      auto it = autAss->succ_iter(nextState);
      if (it->first() && (it->dst()->hash() == nextState->hash()) &&
          !it->next()) {
        if (autAss->state_is_accepting(nextState)) {
          for (auto t : timers) {
            if (!tokenExists(f, "start" + std::to_string(t))) {
              // outstream << codeGenerator::ident3 << "popTimerInst(" << t <<
              // "," << "currAss[" << state << "]);" << std::endl;
              outstream << codeGenerator::ident3 << "popTimerInst(" << t << ","
                        << "1);" << std::endl;
            }
          }

          outstream << codeGenerator::ident3 << "endIns++;" << std::endl;
          // outstream << codeGenerator::ident3 << "endIns+="
          //          << "currAss[" << state << "];" << std::endl;
          // outstream << codeGenerator::ident3 << "break;" << std::endl;
        } else {
          outstream << codeGenerator::ident3 << "return 0;" << std::endl;
        }
      } else {
        // non terminal
        for (size_t i = 0; i < timer::timers.size(); i++) {
          if (tokenExists(f, "start" + std::to_string(i)) &&
              tokenExists(f, "stop" + std::to_string(i))) {
            outstream << codeGenerator::ident3 << "addTimerValue(" << i << ");"
                      << std::endl;
          }
        }

        outstream << codeGenerator::ident3 << " nextAss[" << edge.dst
                  << "]++;\n";
      }
      delete it;
      outstream << codeGenerator::ident2 << "}\n";
    }
    outstream << codeGenerator::ident1 << "}\n";
    outstream << codeGenerator::ident1 << " currAss[" << state << "]=0;\n";
  }
  outstream << codeGenerator::ident1 << "for (size_t i = 0; i <"
            << autAss->num_states() << "; i++) {\n";
  outstream << codeGenerator::ident2 << "    currAss[i] = nextAss[i];\n";
  outstream << codeGenerator::ident2 << "    nextAss[i] = 0;\n";
  outstream << codeGenerator::ident1 << "}\n";

  // ant

  outstream << codeGenerator::ident1 << " currAnt["
            << autAnt->get_init_state_number() << "]++;\n";
  num_states = autAnt->num_states();
  for (unsigned state = 0; state < num_states; state++) {

    auto currState = autAnt->state_from_number(state);

    // skip term states
    auto it = autAnt->succ_iter(currState);
    if (it->first() && (it->dst()->hash() == currState->hash()) &&
        !it->next()) {
      delete it;
      continue;
    }
    delete it;

    outstream << codeGenerator::ident1 << " for (size_t i = 0; i < "
              << "currAnt[" << state << "]; i++) {\n";

    // gather stop clauses
    std::set<size_t> timers;
    for (auto &edge : autAnt->out(state)) {
      spot::formula f =
          spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
      formulaToGetTimers(f, timers);
    }
    for (auto t : timers) {
      outstream << codeGenerator::ident2 << "bool stop" << t
                << " = getTimerValue(" << t << ", i, 0);\n";
    }

    bool firstEdge = true;
    for (auto &edge : autAnt->out(state)) {
      spot::formula f =
          spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
      // Convert formula to string format
      std::string stringF = formulaToString(f);
      if (firstEdge) {
        outstream << codeGenerator::ident2 << "if(" << stringF << "){\n";
        firstEdge = 0;
      } else {
        outstream << codeGenerator::ident2 << "else if(" << stringF << "){\n";
      }

      // term edges
      auto nextState = autAnt->state_from_number(edge.dst);
      auto it = autAnt->succ_iter(nextState);
      if (it->first() && (it->dst()->hash() == nextState->hash()) &&
          !it->next()) {
        if (autAnt->state_is_accepting(nextState)) {

          //  outstream << codeGenerator::ident3 << "conIns+="
          //            << "currAnt[" << state << "];" << std::endl;
          //  outstream << codeGenerator::ident3 << "break;" << std::endl;
          outstream << codeGenerator::ident3 << "conIns++;" << std::endl;
        } else {
          // outstream << codeGenerator::ident3 << "endIns-="
          //          << "currAnt[" << state << "];" << std::endl;
          // outstream << codeGenerator::ident3 << "break;" << std::endl;

          outstream << codeGenerator::ident3 << "endIns--;" << std::endl;
        }
      } else {
        // non terminal

        outstream << codeGenerator::ident3 << " nextAnt[" << edge.dst
                  << "]++;\n";
      }
      delete it;
      outstream << codeGenerator::ident2 << "}\n";
    }
    outstream << codeGenerator::ident1 << "}\n";
    outstream << codeGenerator::ident1 << " currAnt[" << state << "]=0;\n";
  }
  outstream << codeGenerator::ident1 << "for (size_t i = 0; i <"
            << autAnt->num_states() << "; i++) {\n";
  outstream << codeGenerator::ident2 << "    currAnt[i] = nextAnt[i];\n";
  outstream << codeGenerator::ident2 << "    nextAnt[i] = 0;\n";
  outstream << codeGenerator::ident1 << "}\n";

  outstream << codeGenerator::ident1 << "if (conIns - endIns > 0) {\n";
  outstream << codeGenerator::ident2 << "_priority = 2;\n";
  outstream << codeGenerator::ident1 << "} else if (conIns - endIns <= 0) {\n";
  outstream << codeGenerator::ident2 << "_priority = 1;\n";
  outstream << codeGenerator::ident1 << "}\n";

  outstream << "\n" << codeGenerator::ident1 << "return true;" << std::endl;
  outstream << "}" << std::endl; // close function
}

// Create a specific request, inheriting from the base request class
void createRequestClass(const SpotAutomata &aut, std::ofstream &outstream,
                        const std::string className) {
  outstream << "class " << className << " : request{" << std::endl;

  addEval(aut, outstream, className);
  addProcess(aut, outstream, className);

  outstream << "}" << std::endl;
}

// Add variables used by the checker in a .h file
// void addCheckerVariables(const SpotAutomata& aut, std::ofstream& outstream){
//}

// Add eval method to the request class created earlier
void addEval(const SpotAutomata &aut, std::ofstream &outstream,
             const std::string className) {

  outstream << "bool" << className << "::eval"
            << "(";
  // Add all input variables (atomic propositions and placeholders)
  size_t count = 1;
  for (auto f : aut->ap()) {
    outstream << "bool &" << f;
    if (count < aut->ap().size()) {
      outstream << ", ";
    }
    count++;
  }

  outstream << "){" << std::endl;

  outstream << "}" << std::endl;
}

// Add process method to the request class created earlier
void addProcess(const SpotAutomata &aut, std::ofstream &outstream,
                const std::string className) {
  outstream << "void" << className << "::process"
            << "(){" << std::endl;

  // Declare checker variables
  for (auto f : aut->ap()) {
    outstream << "bool " << f << std::endl;
  }

  outstream << "while (!sliceEnded) {" << std::endl;
  outstream << codeGenerator::ident1 << "if( eval(";
  size_t count = 1;
  for (auto f : aut->ap()) {
    outstream << f;
    if (count < aut->ap().size()) {
      outstream << ", ";
    }
    count++;
  }
  outstream << ")){" << std::endl;

  outstream << "}" << std::endl;
}
}
