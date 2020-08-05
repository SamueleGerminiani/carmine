#include "converter.hh"

namespace codeGenerator {

namespace converter {
SpotAutomata generateAutomata(const PSLformula &formula) {
  spot::parsed_formula pf = spot::parse_infix_psl(formula);
  messageErrorIf(pf.format_errors(std::cerr),
                 "SpotLTL: Syntax errors in assertion:\n" +
                     formula);


  spot::translator trans;
  trans.set_pref(spot::postprocessor::Complete);

  auto res = trans.run(pf.f);

  //    DEBUG
  // print_hoa(std::cout, res) << '\n';

  return res;
}
} // namespace Converter
} // namespace codeGenerator
