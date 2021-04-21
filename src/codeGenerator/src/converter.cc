#include "converter.hh"
#include "types.hh"
#include <spot/twaalgos/isdet.hh>
#include <spot/twaalgos/minimize.hh>
#include <spot/twaalgos/powerset.hh>
#include <string>
#include <utility>

namespace codeGenerator {

namespace converter {
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

std::pair<SpotAutomata, SpotAutomata>
generateAutomata(const PSLformula &formula, const PSLformula &ant) {
  spot::parsed_formula pf = spot::parse_infix_psl(formula);
  spot::parsed_formula pant = spot::parse_infix_psl(ant);
  messageErrorIf(pf.format_errors(std::cerr),
                 "SpotLTL: Syntax errors in assertion:\n" + formula);

  spot::translator trans;
  trans.set_pref(spot::postprocessor::Deterministic);

  auto res = trans.run(pf.f);
  auto resAnt = trans.run(pant.f);
  spot::postprocessor post;
  post.set_pref(spot::postprocessor::Complete);
  res = post.run(res);
  resAnt = post.run(resAnt);

  //    DEBUG
  // print_hoa(std::cout, res) << '\n';

  // Check if automata is deterministic

  if (!(spot::is_deterministic(res)) || !(spot::is_deterministic(resAnt))) {
    std::cout
        << "Error: could not generate deterministic automata for formula "
        << formula << std::endl;
    exit(1);
  }

  return std::make_pair(res, resAnt);
}

// Generate and print checker
void generateChecker(
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
              //outstream << codeGenerator::ident3 << "popTimerInst(" << t << "," << "currAss[" << state << "]);" << std::endl;
              outstream << codeGenerator::ident3 << "popTimerInst(" << t << "," << "1);" << std::endl;
            }
          }

          outstream << codeGenerator::ident3 << "endIns++;"<< std::endl;
          //outstream << codeGenerator::ident3 << "endIns+="
          //          << "currAss[" << state << "];" << std::endl;
          //outstream << codeGenerator::ident3 << "break;" << std::endl;
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
          outstream << codeGenerator::ident3 << "conIns++;"<< std::endl;
        } else {
          //outstream << codeGenerator::ident3 << "endIns-="
          //          << "currAnt[" << state << "];" << std::endl;
          //outstream << codeGenerator::ident3 << "break;" << std::endl;

          outstream << codeGenerator::ident3 << "endIns--;"<< std::endl;
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

} // namespace Converter
} // namespace codeGenerator
