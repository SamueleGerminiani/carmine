#pragma once
#include "types.hh"
namespace timer {
extern std::vector<std::pair<size_t, size_t>> timers;
}
namespace codeGenerator {
namespace converter {
std::pair<SpotAutomata, SpotAutomata>
generateAutomata(const PSLformula &formula, const PSLformula &ant);
void generateChecker(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    const std::string checkerName, std::ofstream &outstream);
std::string formulaToString(const spot::formula f);
void addProcess(const SpotAutomata &aut, std::ofstream &outstream,
                const std::string className);
void addEval(const SpotAutomata &aut, std::ofstream &outstream,
             const std::string className);
void addCheckerVariables(const SpotAutomata &aut, std::ofstream &outstream);
}
} // namespace codeGenerator
