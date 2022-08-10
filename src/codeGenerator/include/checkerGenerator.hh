#pragma once
#include "types.hh"
#include "utils_functions.hh"
#include "xmlUtils.hh"
using namespace expression;
namespace codeGenerator {

bool generateCheckerSource(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::pair<std::pair<std::string, std::string>, std::unordered_map<std::string, expression::Proposition *>> &parsedFormula,
    strChecker &checker, const std::vector<std::pair<size_t, size_t>> &timers);

// Generate header for checker class
bool generateCheckerHeader(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList, std::string &checkerName, std::pair<std::pair<std::string, std::string>, std::unordered_map<std::string, expression::Proposition *>> &parsedFormula) ;

std::pair<SpotAutomata, SpotAutomata>
generateAutomata(const PSLformula &formula, const PSLformula &ant);

void generateEvalFunction(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    const std::string checkerName, std::ofstream &outstream,
    std::unordered_map<std::string, expression::Proposition *> &phToProps) ;
std::string formulaToString(const spot::formula f,std::unordered_map<std::string, expression::Proposition *> &phToProps) ;
void addProcess(const SpotAutomata &aut, std::ofstream &outstream,
                const std::string className);
void addEval(const SpotAutomata &aut, std::ofstream &outstream,
             const std::string className);
void addCheckerVariables(const SpotAutomata &aut, std::ofstream &outstream);
}
