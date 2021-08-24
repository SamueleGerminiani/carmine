#pragma once

#include "odenCore.hh"
#include "spot/tl/parse.hh"
#include "spot/twa/bddprint.hh"
#include "spot/twaalgos/hoa.hh"
#include "spot/twaalgos/isdet.hh"
#include "spot/twaalgos/translate.hh"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

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

struct strVariable {
  strVariable(std::string decl, std::string name, std::string type,
              std::string rosTopic, std::string msgType, std::string msgField)
      : _decl(decl), _name(name), _type(type), _rosTopic(rosTopic),
        _msgType(msgType), _msgField(msgField) {
    // not todo
  }
  strVariable() {}
  std::string _decl;
  std::string _name;
  std::string _type;
  std::string _rosTopic;
  std::string _msgType;
  std::string _msgField;
};
struct strChecker {
  strChecker(std::string name, std::string description, std::string LTLformula,
             std::vector<strVariable> variables)
      : _name(name), _description(description), _LTLformula(LTLformula),
        _variables(variables) {
    // not todo
  }
  strChecker() {}
  std::string _name;
  std::string _description;
  std::string _LTLformula;
  std::vector<strVariable> _variables;
};
struct strHandler {
  strHandler(std::string name, std::string migrateTo,
             std::vector<strChecker> checkers)
      : _name(name), _migrateTo(migrateTo), _checkers(checkers) {
    // not todo
  }
  strHandler() {}
  std::string _name;
  std::string _migrateTo;
  std::vector<strChecker> _checkers;
};

} // namespace codeGenerator
