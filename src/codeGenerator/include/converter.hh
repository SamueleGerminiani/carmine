#pragma once
#include "types.hh"
namespace codeGenerator {
namespace converter {
SpotAutomata generateAutomata(const PSLformula &formula);
void generateChecker(const SpotAutomata& aut, const std::string checkerName, std::ofstream& outstream );
std::string formulaToString(const spot::formula f);
void addProcess(const SpotAutomata& aut, std::ofstream& outstream, const std::string className);
void addEval(const SpotAutomata& aut, std::ofstream& outstream, const std::string className);
void addCheckerVariables(const SpotAutomata& aut, std::ofstream& outstream);

}
} // namespace codeGenerator
