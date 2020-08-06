#pragma once
#include "types.hh"
namespace codeGenerator {
namespace converter {
SpotAutomata generateAutomata(const PSLformula &formula);
void generateChecker(const SpotAutomata& aut, std::ofstream& outstream );
std::string formulaToString(const spot::formula f);
}
} // namespace codeGenerator
