#pragma once
#include "converter.hh"
#include "odenCore.hh"
#include "parserUtils.hh"
#include "types.hh"
#include "utils_functions.hpp"
#include "xmlUtils.hh"
using namespace oden;

namespace codeGenerator {
bool generateCallbackHeader(std::vector<strChecker> &checkers);
bool generateCheckerHelperHeader(std::vector<strChecker> &checkers, int nPhs[]);
bool generateGlobalsHeader(std::vector<strChecker> &checkers) ;
bool generateGlobalsSource(std::vector<strChecker> &checkers) ;
}
