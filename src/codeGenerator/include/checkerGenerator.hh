#pragma once
#include "types.hh"
#include "utils_functions.hpp"
#include "xmlUtils.hh"
using namespace oden;
namespace codeGenerator {

bool generateCheckerSource(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList,
    std::pair<std::pair<std::string, std::string>,
              std::unordered_map<std::string, oden::Proposition *>>
        &parsedFormula,
    std::string &checkerName);

// Generate header for checker class
bool generateCheckerHeader(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList, std::string &checkerName, std::pair<std::pair<std::string, std::string>, std::unordered_map<std::string, oden::Proposition *>> &parsedFormula) ;

std::pair<SpotAutomata, SpotAutomata>
generateAutomata(const PSLformula &formula, const PSLformula &ant);

void generateEvalFunction(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    const std::string checkerName, std::ofstream &outstream,
    std::unordered_map<std::string, oden::Proposition *> &phToProps) ;
std::string formulaToString(const spot::formula f,std::unordered_map<std::string, oden::Proposition *> &phToProps) ;
void addProcess(const SpotAutomata &aut, std::ofstream &outstream,
                const std::string className);
void addEval(const SpotAutomata &aut, std::ofstream &outstream,
             const std::string className);
void addCheckerVariables(const SpotAutomata &aut, std::ofstream &outstream);
}
