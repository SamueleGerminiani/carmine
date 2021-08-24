#pragma once

#include "odenCore.hh"
#include "spot/tl/parse.hh"
#include "spot/twaalgos/hoa.hh"
#include "spot/twaalgos/translate.hh"
#include "spot/twa/bddprint.hh"
#include "spot/twaalgos/isdet.hh"
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
static std::string ident5 = ident4 + tab;
static std::string ident6 = ident5 + tab;

using SpotAutomata = spot::twa_graph_ptr;
using PSLformula = std::string;


} // namespace codeGenerator
