#pragma once
#include "converter.hh"
#include "odenCore.hh"
#include "parserUtils.hh"
#include "types.hh"
#include "utils_functions.hpp"
#include "xmlUtils.hh"
using namespace oden;
namespace timer {
extern std::vector<std::pair<size_t, size_t>> timers;
}

namespace codeGenerator {
// Generate handler code
bool generateHandlerSource(std::vector<strChecker> &checkers, int nPhs[]);

// Generate include header for handler class
bool generateHandlerHeader(std::vector<strChecker> &checkers);

}
