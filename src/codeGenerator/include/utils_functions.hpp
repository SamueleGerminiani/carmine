#pragma once
#include "oden/oden.hh"
#include "types.hh"
#include "xmlUtils.hh"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

// Map used to store the binding between the addEvent_varx function of the
// checkers
// and the variable it refers to
// Key = checker's name
// Value = vector of strVariable
// If vector[0] = "msg.a" then the function addEvent_var0 of the checker
// will take msg.a as a parameter

namespace codeGenerator {

extern std::map<std::string, std::vector<strVariable>> bindings;
// Trim string
inline std::string trim(const std::string &s) {
  auto wsfront = std::find_if_not(s.begin(), s.end(),
                                  [](int c) { return std::isspace(c); });
  auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) {
                  return std::isspace(c);
                }).base();
  return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

// Given a variable declaration split its type and its name
// eg int a gets splitted into "int" and "a"
inline void splitNameType(std::string &name, std::string &type,
                          std::string &decl) {
  decl = trim(decl);
  auto p = decl.find_last_of(" ");
  type = decl.substr(0, p);
  name = decl.substr(p + 1);
}

// Return a map with a type as key and as value the number of variables of that
// type
inline std::map<std::string, int>
countVarTypes(std::vector<strVariable> &varList) {
  std::map<std::string, int> res;

  for (auto v : varList) {
    if (res.count(v._type) == 0) {
      res.insert(std::pair<std::string, int>(v._type, 1));
    } else {
      res[v._type] += 1;
    }
  }
  return res;
}

// Given a XmlNodeList of variable nodes return a map having the msgType as key
// and as value a vector of strVariable representing the variables that are
// updated from that topic
inline void groupVariablesByMsgType(
    std::map<std::string, std::vector<strVariable>> &parsedVars,
    std::vector<strVariable> &varList) {

  for (auto var : varList) {

    if (parsedVars.count(var._msgType) == 0) {
      parsedVars.insert(std::pair<std::string, std::vector<strVariable>>(
          var._msgType, std::vector<strVariable>()));
    }

    parsedVars[var._msgType].push_back(var);
  }
}

// Return a map with a placeholder as key and a vector of variables names as
// value
inline void groupVariablesByPlaceholders(
    std::pair<std::pair<std::string, std::string>,
              std::unordered_map<std::string, oden::Proposition *>>
        &parsedFormula,
    std::map<std::string, std::vector<std::string>> &varsPH) {
  for (auto p : parsedFormula.second) {

    // Get variables of the expression replaced by the placeholder
    auto vars = oden::prop2Vars(*p.second);
    varsPH[p.first] = vars;
  }
}

// Get parameters to pass to assign<bool>(order, index_p,...) in reorder()
// E.g if we have p0,p1,p2 and p0,p2 are updated then getOrderEntries will
// return 1,0,1
inline std::string getOrderEntries(std::vector<std::string> &placeholders,
                                   int totPlaceholders) {
  std::string ret = "";
  size_t indexVector = 0;
  for (int i = 0; i < totPlaceholders; i++) {
    if (indexVector < placeholders.size() &&
        placeholders[indexVector].compare("p" + std::to_string(i)) == 0) {
      ret += ", 1";
      indexVector++;
    } else {
      ret += ", 0";
    }
  }
  return ret;
}

// Get parameters to pass to assign<bool>(pbuff, index_p,...) in reorder()
inline std::string getPbuffEntries(std::vector<std::string> &placeholders,
                                   int totPlaceholders) {
  std::string ret = "";
  size_t indexVector = 0;
  for (int i = 0; i < totPlaceholders; i++) {
    if (indexVector < placeholders.size() &&
        placeholders[indexVector].compare("p" + std::to_string(i)) == 0) {
      ret += ", " + placeholders[indexVector];
      indexVector++;
    } else {
      ret += ", 0";
    }
  }
  return ret;
}

// Return a map having a pair <message type,topic> as key and as value a vector
// of the checkers that
// listen to that type and topic
inline std::map<std::pair<std::string, std::string>, std::set<std::string>>
groupCheckersByMsgTopic(std::vector<strChecker> &checkers) {
  std::map<std::pair<std::string, std::string>, std::set<std::string>> output;

  for (auto ch : checkers) {
    std::string name = ch._name;

    for (auto v : ch._variables) {

      std::string msgType = v._msgType;
      std::string rosTopic = v._rosTopic;

      // If the msg type is not already in the map instert it as key and create
      // a new vector as value
      if (!output.count(make_pair(msgType, rosTopic))) {
        output.insert(std::pair<std::pair<std::string, std::string>,
                                std::set<std::string>>(
            make_pair(msgType, rosTopic), std::set<std::string>()));
      }

      // Add checker's name to the vector
      output[make_pair(msgType, rosTopic)].insert(name);
    }
  }

  return output;
}
}
