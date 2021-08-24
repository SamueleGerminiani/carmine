#pragma once
#include "converter.hh"
#include "odenCore.hh"
#include "parserUtils.hh"
#include "utils_functions.hpp"
#include "xmlUtils.hh"
using namespace oden;
namespace timer {
extern std::vector<std::pair<size_t, size_t>> timers;
}

bool generateCpp(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList,
    std::pair<std::pair<std::string, std::string>,
              std::unordered_map<std::string, oden::Proposition *>>
        &parsedFormula,
    std::string &checkerName);

// Generate header for checker class
bool generateHeader(
    std::pair<codeGenerator::SpotAutomata, codeGenerator::SpotAutomata> &fsms,
    std::vector<strVariable> &varList, std::string &checkerName);

// Generate handler code
bool generateHandler(std::vector<strChecker> &checkers, int nPhs[],
                     std::string handlerName, std::string migrateTo);

// Generate include header for handler class
bool generateHeaderHandler(std::vector<strChecker> &checkers);

