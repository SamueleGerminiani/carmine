
#include "monitorGenerator.hh"
#include "converter.hh"
#include "exp.hh"
#include "globals.hh"
#include "parserUtils.hh"
#include <chrono>
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

bool isConst(const std::string &n) { return n[0] == 'c'; }

std::string formulaToString(
    const spot::formula f,
    std::unordered_map<std::string, expression::Proposition *> &phToProps) {

  // And
  if (f.is(spot::op::And)) {
    std::string ret = "";
    ret = "(" + formulaToString(f[0], phToProps);
    for (size_t i = 1; i < f.size(); i++) {
      ret += " && " + formulaToString(f[i], phToProps);
    }
    ret += ")";
    return ret;
  }

  // Or
  if (f.is(spot::op::Or)) {
    std::string ret = "";
    ret = "(" + formulaToString(f[0], phToProps);
    for (size_t i = 1; i < f.size(); i++) {
      ret += " || " + formulaToString(f[i], phToProps);
    }
    ret += ")";
    return ret;
  }

  // Not
  if (f.is(spot::op::Not)) {
    return "!" + formulaToString(f[0], phToProps);
  }

  // Atomic proposition
  if (f.is(spot::op::ap)) {
    if (f.is_tt() || f.ap_name().find("start", 0) != std::string::npos) {
      return "1";
    }
    if (isConst(f.ap_name())) {
      return expression::prop2String(*phToProps.at(f.ap_name()));
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

// Generate code for monitor class
bool generateMonitorSource(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::pair<std::pair<std::string, std::string>,
              std::unordered_map<std::string, expression::Proposition *>>
        &parsedFormula,
    strMonitor &monitor, const std::vector<std::pair<size_t, size_t>> &timers) {

  //monitor -> list of variables
  std::map<std::string, std::vector<strVariable>> bindings;
  auto autAss = fsms.first;
  auto autAnt = fsms.second;
  auto &phToProps = parsedFormula.second;
  auto monitorName = monitor._name;
  auto varList = monitor._variables;

  std::ifstream src("src/standalone/code_templates/monitor_template.cpp");

  if (src.fail()) {
    std::cout << "Error: could not open "
              << "src/standalone/code_templates/monitor_template.cpp"
              << std::endl;
    return false;
  }

  std::ofstream dst("build/output/monitors/src/" + monitorName + ".cpp");

  if (dst.fail()) {
    std::cout << "Error: could not open build/output/monitors/src/"
              << monitorName << ".cpp" << std::endl;
    return false;
  }

  // Read template file, and on each line replace $ClassName$
  // or generate code
  std::string line;

  while (getline(src, line)) {
    while (replace(line, "$ClassName$", monitorName))
      ; // To handle multiple occurences
    while (replace(line, "$nStatesAss$", std::to_string(autAss->num_states())))
      ;
    while (replace(line, "$nStatesAnt$", std::to_string(autAnt->num_states())))
      ;

    // Code for retrieving placeholder's values
    if (line.compare("$order_entry") == 0) {
      line = "";
      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += codeGenerator::ident1 + "if (order_entry & (1ULL << " +
                std::to_string(i) + ")) {\n";
        line += codeGenerator::ident2 + "_last_p" + std::to_string(i) +
                "= pbuff_entry & (1ULL << " + std::to_string(i) + ");\n";
        line += codeGenerator::ident1 + "}\n";
        i++;
      }
    } else if (line.compare("$clearData") == 0) {
      line = "";
      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line +=
            codeGenerator::ident1 + "_last_p" + std::to_string(i++) + " = 0;\n";
      } // Code for calling eval() and resetting monitor
    } else if (line.compare("$overhead") == 0) {
      line = "";
      if (monitor._overhead != "none") {
        // genenerate overhead
        line += codeGenerator::ident1 +
                "static std::chrono::steady_clock::time_point ohstart = "
                "std::chrono::steady_clock::now();\n";

        line += codeGenerator::ident1 + "while (1) {\n";
        line += codeGenerator::ident2 +
                "if (std::chrono::duration_cast<std::chrono::microseconds>( "
                "std::chrono::steady_clock::now() - ohstart).count() >= " +
                monitor._overhead + ") {\n";
        line += codeGenerator::ident2 +
                "ohstart = std::chrono::steady_clock::now();\n";
        line += codeGenerator::ident2 + "break;\n";
        line += codeGenerator::ident2 + "}\n";
        line += codeGenerator::ident1 + "}\n";
      }
    } else if (line.compare("$call_eval") == 0) {
      line = "";
      line += codeGenerator::ident1 + "if (!eval_" + monitorName + "(";

      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += "_last_p" + std::to_string(i++) + ", ";
      }
      line += "0)){\n";
      line += codeGenerator::ident2 + "notifyFailure();\n";
      line += codeGenerator::ident2 + "eval_" + monitorName + "(";
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += "0, ";
      }
      line += "1);\n";
      line += codeGenerator::ident1 + "}\n";

    }

    // Monitor FSM
    else if (line.compare("$FSM") == 0) {
      line = "";
      generateEvalFunction(fsms, monitorName, dst, phToProps);
    } else if (line.compare("$initTimers$") == 0) {
      line = "";
      for (size_t i = 0; i < timers.size(); i++) {
        line += codeGenerator::ident1 + "_timerInstances[" + std::to_string(i) +
                "];\n";
        line +=
            codeGenerator::ident1 + "_timerCache[" + std::to_string(i) + "];\n";
        line += codeGenerator::ident1 + "_timeouts.push_back(" +
                std::to_string(timers[i].second) + ");\n";
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
      size_t j = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += codeGenerator::ident3 + "bool p" + std::to_string(j) +
                " = val & (1ULL << " + std::to_string(j) + ");\n";
        placeholders += " , p" + std::to_string(j);
        j++;
      }

      line += codeGenerator::ident3 + "assign<bool>(_pbuff, _index_p" +
              placeholders + ");\n";
      line += codeGenerator::ident3 + "val = (res.buffer_o)[i];\n";

      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += codeGenerator::ident3 + ph.first + " = val & (1ULL << " +
                std::to_string(i) + ");\n";
        i++;
      }

      line += codeGenerator::ident3 + "assign<bool>(_order, _index_p" +
              placeholders + ");\n";

    } else if (line.compare("$setInit_p_MF") == 0) {
      line = "";
      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += codeGenerator::ident1 + "_last_p" + std::to_string(i) +
                " = res.last_p[" + std::to_string(i) + "];\n";
        i++;
      }

    } else if (line.compare("$setInit_p_MT") == 0) {
      line = "";
      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += codeGenerator::ident1 + "res.last_p.push_back(" + "_last_p" +
                std::to_string(i++) + ");\n";
      }

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
                expression::prop2String(*(phToProps[placeholder]));

            line += expression + ";\n";
          }
        }

        // count n of consts
        size_t nConstants = 0;
        for (auto &ph : phToProps) {
          if (isConst(ph.first)) {
            nConstants++;
          }
        }

        // Alphabetically sort placeholders, e.g. p1,p2,p0 => p0,p1,p2
        std::sort(usedPlaceholders.begin(), usedPlaceholders.end());

        line += codeGenerator::ident6 + "assign<bool>(_pbuff, _index_p";
        line +=
            getPbuffEntries(usedPlaceholders, phToProps.size() - nConstants);
        line += ");\n";

        line += codeGenerator::ident6 + "assign<bool>(_order, _index_p";
        line +=
            getOrderEntries(usedPlaceholders, phToProps.size() - nConstants);
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
          monitorName, std::vector<strVariable>()));

      for (auto v : varList) {

        bindings[monitorName].push_back(v);

        line +=
            "void " + monitorName + "::addEvent_" + v._name + "(ros::Time ts, ";
        line += v._type + " value){\n";
        line += codeGenerator::ident2 + "_addEvent_mutex.lock();\n";
        line += codeGenerator::ident2 + "_last_msg_ts = ts;\n";
        line += codeGenerator::ident2 + "_numberOfAddEvent++;\n";
        line += codeGenerator::ident2 +
                "_vbuff.push_back(Event(ts, Value(value, " + std::to_string(i) +
                "),";
        line += std::to_string(i) + "));\n";
        line += codeGenerator::ident2 + "_addEvent_mutex.unlock();\n";
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

// Generate header for monitor class
bool generateMonitorHeader(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList, std::string &monitorName,
    std::pair<std::pair<std::string, std::string>,
              std::unordered_map<std::string, expression::Proposition *>>
        &parsedFormula) {

  auto autAss = fsms.first;
  auto autAnt = fsms.second;
  auto &phToProps = parsedFormula.second;

  // Copy templates in new files replacing the tokens
  std::ifstream src("src/standalone/code_templates/monitor_template.hh");
  if (src.fail()) {
    std::cout << "Error: could not open monitor_template.hh" << std::endl;
    return false;
  }

  std::ofstream dst("build/output/monitors/include/" + monitorName + ".hh");

  if (dst.fail()) {
    std::cout << "Error: could not open build/output/monitors/include/"
              << monitorName << ".hh" << std::endl;
    return false;
  }

  std::string line;

  while (getline(src, line)) {

    while (replace(line, "$ClassName$", monitorName))
      ;
    while (replace(line, "$nStatesAss$", std::to_string(autAss->num_states())))
      ;
    while (replace(line, "$nStatesAnt$", std::to_string(autAnt->num_states())))
      ;

    // Code for placeholders initialization
    if (line.compare("$init_p") == 0) {
      line = "";
      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += codeGenerator::ident1 + "bool _last_p" + std::to_string(i++) +
                " = false;\n";
      }
    }

    // Code for defining the eval function
    else if (line.compare("$eval") == 0) {
      line = "";
      line = codeGenerator::ident1 + "bool eval_" + monitorName + "(";
      size_t i = 0;
      for (auto &ph : phToProps) {
        if (isConst(ph.first))
          continue;

        line += "bool p" + std::to_string(i++) + ",";
      }
      line += "bool reset = false);\n";
    }

    // Code for defining the Value union based on monitor's variables
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

    // Code for including ROS message headers and for defining the monitor's
    // initial state
    else if (line.compare("$msgHeaders") == 0) {
      line = "";
      std::unordered_set<std::string> alreadyIncluded;
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

    }

    else if (line.compare("$addEvent") == 0) {
      line = "";
      for (auto v : varList) {
        line += codeGenerator::ident1 + "void addEvent_" + v._name +
                "(ros::Time ts, ";
        line += v._type + " value);\n";
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
    const std::string monitorName, std::ofstream &outstream,
    std::unordered_map<std::string, expression::Proposition *> &phToProps) {

  std::string initState = "INIT_" + monitorName;
  outstream << "//Return true if monitor did not fail" << std::endl;
  outstream << "inline bool " + monitorName + "::eval_" + monitorName + "(";
  auto autAss = fsms.first;
  auto autAnt = fsms.second;

  // Add all input variables (atomic propositions and placeholders)
  for (auto f : autAss->ap()) {
    if (f.ap_name().find("start", 0) != std::string::npos ||
        f.ap_name().find("stop", 0) != std::string::npos) {
      continue;
    }
    if (f.ap_name()[0] != 'c') {
      outstream << "bool " << f << ", ";
    }
  }

  outstream << "bool const reset";

  outstream << "){" << std::endl;

  outstream << codeGenerator::ident1 << "if(reset){\n"
            << codeGenerator::ident2 << "resetMonitor();" << std::endl
            << codeGenerator::ident2 << "return 1;" << std::endl
            << codeGenerator::ident1 << "}" << std::endl;

  const spot::bdd_dict_ptr &dict = autAss->get_dict();
  unsigned num_states = autAss->num_states();

  outstream << codeGenerator::ident1 << " _currAss["
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

    // gather stop clauses
    std::set<size_t> timers;
    for (auto &edge : autAss->out(state)) {
      spot::formula f =
          spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
      formulaToGetTimers(f, timers);
    }

    if (!timers.empty()) {

      outstream << codeGenerator::ident1 << " for (size_t i = 0; i < "
                << "_currAss[" << state << "]; i++) {\n";

      for (auto t : timers) {
        outstream << codeGenerator::ident2 << "bool stop" << t
                  << " = getTimerValue(" << t << ", i, 1);\n";
      }

      bool firstEdge = true;
      for (auto &edge : autAss->out(state)) {
        spot::formula f =
            spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
        // Convert formula to string format
        std::string stringF = formulaToString(f, phToProps);
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
                outstream << codeGenerator::ident3 << "popTimerInst(" << t
                          << ","
                          << "1);" << std::endl;
              }
            }

            outstream << codeGenerator::ident3 << "_endIns++;" << std::endl;
            // outstream << codeGenerator::ident3 << "endIns+="
            //          << "currAss[" << state << "];" << std::endl;
            // outstream << codeGenerator::ident3 << "break;" << std::endl;
          } else {
            outstream << codeGenerator::ident3 << "return 0;" << std::endl;
          }
        } else {
          // non terminal
          for (size_t i = 0; i < timers.size(); i++) {
            if (tokenExists(f, "start" + std::to_string(i)) &&
                tokenExists(f, "stop" + std::to_string(i))) {
              outstream << codeGenerator::ident3 << "addTimerValue(" << i
                        << ");" << std::endl;
            }
          }

          outstream << codeGenerator::ident3 << " _nextAss[" << edge.dst
                    << "]++;\n";
        }
        delete it;
        outstream << codeGenerator::ident2 << "}\n";
      }
      outstream << codeGenerator::ident1 << "}\n";
    } else { // timer empty

      bool firstEdge = true;
      for (auto &edge : autAss->out(state)) {
        spot::formula f =
            spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
        // Convert formula to string format
        std::string stringF = formulaToString(f, phToProps);
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

            outstream << codeGenerator::ident3 << "_endIns+="
                      << "_currAss[" << state << "];" << std::endl;
            // outstream << codeGenerator::ident3 << "endIns+="
            //          << "currAss[" << state << "];" << std::endl;
            // outstream << codeGenerator::ident3 << "break;" << std::endl;
          } else {
            outstream << codeGenerator::ident3 << "return 0;" << std::endl;
          }
        } else {
          // non terminal

          outstream << codeGenerator::ident3 << " _nextAss[" << edge.dst
                    << "]+="
                    << "_currAss[" << state << "];\n";
        }
        delete it;
        outstream << codeGenerator::ident2 << "}\n";
      }
    }
    outstream << codeGenerator::ident1 << " _currAss[" << state << "]=0;\n";
  }
  outstream << codeGenerator::ident1 << "for (size_t i = 0; i <"
            << autAss->num_states() << "; i++) {\n";
  outstream << codeGenerator::ident2 << "    _currAss[i] = _nextAss[i];\n";
  outstream << codeGenerator::ident2 << "    _nextAss[i] = 0;\n";
  outstream << codeGenerator::ident1 << "}\n";

  // ant
  outstream << "\n\n// ---------ANT-------------\n\n\n";
  outstream << codeGenerator::ident1 << " _currAnt["
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

    // gather stop clauses
    std::set<size_t> timersID;
    for (auto &edge : autAnt->out(state)) {
      spot::formula f =
          spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
      formulaToGetTimers(f, timersID);
    }

    if (!timersID.empty()) {
      outstream << codeGenerator::ident1 << " for (size_t i = 0; i < "
                << "_currAnt[" << state << "]; i++) {\n";
      for (auto t : timersID) {
        outstream << codeGenerator::ident2 << "bool stop" << t
                  << " = getTimerValue(" << t << ", i, 0);\n";
      }

      bool firstEdge = true;
      for (auto &edge : autAnt->out(state)) {
        spot::formula f =
            spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
        // Convert formula to string format
        std::string stringF = formulaToString(f, phToProps);
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

            outstream << codeGenerator::ident3 << "_conIns++;" << std::endl;
          } else {

            outstream << codeGenerator::ident3 << "_endIns--;" << std::endl;
          }
        } else {
          // non terminal

          outstream << codeGenerator::ident3 << " _nextAnt[" << edge.dst
                    << "]++;\n";
        }
        delete it;
        outstream << codeGenerator::ident2 << "}\n";
      }
      outstream << codeGenerator::ident1 << "}\n";
    } else { // ant timers empty

      bool firstEdge = true;
      for (auto &edge : autAnt->out(state)) {
        spot::formula f =
            spot::parse_formula(spot::bdd_format_formula(dict, edge.cond));
        // Convert formula to string format
        std::string stringF = formulaToString(f, phToProps);
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

            outstream << codeGenerator::ident3 << "_conIns+="
                      << "_currAnt[" << state << "];" << std::endl;
          } else {

            outstream << codeGenerator::ident3 << "_endIns-="
                      << "_currAnt[" << state << "];" << std::endl;
          }
        } else {
          // non terminal

          outstream << codeGenerator::ident3 << " _nextAnt[" << edge.dst
                    << "]+="
                    << "_currAnt[" << state << "];\n";
        }
        delete it;
        outstream << codeGenerator::ident2 << "}\n";
      }
    }

    outstream << codeGenerator::ident1 << " _currAnt[" << state << "]=0;\n";
  }
  outstream << codeGenerator::ident1 << "for (size_t i = 0; i <"
            << autAnt->num_states() << "; i++) {\n";
  outstream << codeGenerator::ident2 << "    _currAnt[i] = _nextAnt[i];\n";
  outstream << codeGenerator::ident2 << "    _nextAnt[i] = 0;\n";
  outstream << codeGenerator::ident1 << "}\n";

  outstream << codeGenerator::ident1 << "if (_conIns - _endIns > 0) {\n";
  outstream << codeGenerator::ident2 << "_priority = 2;\n";
  outstream << codeGenerator::ident1
            << "} else if (_conIns - _endIns <= 0) {\n";
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

// Add variables used by the monitor in a .h file
// void addMonitorVariables(const SpotAutomata& aut, std::ofstream& outstream){
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

  // Declare monitor variables
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
} // namespace codeGenerator
