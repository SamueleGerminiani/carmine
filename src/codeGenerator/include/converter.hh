#pragma once
#include "types.hh"
#include <spot/twaalgos/isdet.hh>
#include <spot/twaalgos/minimize.hh>
#include <spot/twaalgos/powerset.hh>
namespace timer {
extern std::vector<std::pair<size_t, size_t>> timers;
}
namespace codeGenerator {
namespace converter {
inline std::pair<SpotAutomata, SpotAutomata> generateAutomata(const PSLformula &formula, const PSLformula &ant) {
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
}
} // namespace codeGenerator
