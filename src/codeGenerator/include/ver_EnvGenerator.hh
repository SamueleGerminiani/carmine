#pragma once
#include "converter.hh"
#include "exp.hh"
#include "parserUtils.hh"
#include "types.hh"
#include "utils_functions.hh"
#include "xmlUtils.hh"
using namespace expression;

namespace codeGenerator {
bool generateCallbackHeader(std::vector<strMonitor> &monitors);
bool generateMonitorHelperHeader(std::vector<strMonitor> &monitors, int nPhs[]);
bool generateGlobalsHeader(std::vector<strMonitor> &monitors) ;
bool generateGlobalsSource(std::vector<strMonitor> &monitors) ;
}
