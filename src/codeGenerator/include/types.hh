#pragma once

#include "odenCore.hh"
#include "spot/tl/parse.hh"
#include "spot/twaalgos/hoa.hh"
#include "spot/twaalgos/translate.hh"
#include "spot/twa/bddprint.hh"
#include <limits>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>

namespace codeGenerator {
static std::string tab = "   ";
static std::string ident1 = tab;
static std::string ident2 = ident1 + tab;
static std::string ident3 = ident2 + tab;
static std::string ident4 = ident3 + tab;

using SpotAutomata = spot::twa_graph_ptr;
using PSLformula = std::string;

struct Assertion {};
//=================================================================================

inline bool isFinalState(spot::twa_graph_ptr graph, unsigned state) {
  return std::distance(graph->out(state).begin(), graph->out(state).end()) == 1;
}
inline size_t strToSizeCheckErrors(
    std::string val, std::string name = "value", size_t lBound = 0,
    size_t uBound = std::numeric_limits<unsigned long>::max()) {
  try {
    long long signedConverted = std::stoll(val);
    messageErrorIf(signedConverted < 0, name + " is negative!");
    size_t converted = signedConverted;
    messageErrorIf(converted < lBound || converted > uBound,
                   name + " = " + std::to_string(converted) +
                       " is out of bounds! it must be in [" +
                       std::to_string(lBound) + "," + std::to_string(uBound) +
                       "]");
    return converted;
  } catch (std::exception &e) {
    messageError(name + " conversion error!");
    exit(1);
  }
}
inline int strToIntCheckErrors(std::string val, std::string name = "value",
                               int lBound = std::numeric_limits<int>::min(),
                               int uBound = std::numeric_limits<int>::max()) {
  try {
    int signedConverted = std::stoi(val);
    messageErrorIf(signedConverted < lBound || signedConverted > uBound,
                   name + " = " + std::to_string(signedConverted) +
                       " is out of bounds! it must be in [" +
                       std::to_string(lBound) + "," + std::to_string(uBound) +
                       "]");
    return signedConverted;
  } catch (std::exception &e) {
    messageError(name + " conversion error!");
    exit(1);
  }
}
inline void removeSpacesBeforeAfter(std::string &str) {
  auto it1 = std::find_if_not(begin(str), end(str), [](char e) {
    return e == '\r' || e == '\n' || e == ' ' || e == '\t';
  });
  str.erase(begin(str), it1);
  auto it2 = std::find_if_not(rbegin(str), rend(str), [](char e) {
    return e == '\r' || e == '\n' || e == ' ' || e == '\t';
  });
  str.erase(it2.base(), end(str));
}

} // namespace codeGenerator
