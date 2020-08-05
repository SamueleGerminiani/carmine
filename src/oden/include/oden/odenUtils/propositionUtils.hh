#pragma once

#include "oden/odenEnums.hh"
#include "oden/types.hh"
#include <string>
#include <unordered_map>

namespace oden {

/// @brief This method turns a proposition into a string.
/// @param prop The proposition
std::string prop2String(Proposition &prop);
std::vector<std::string> prop2Vars(Proposition &prop);
std::vector<std::pair<std::string,VarType>> prop2VarsWithType(Proposition &prop);

std::string logicExp2String(LogicExpression &le);

/// @brief This method turns a string into a Numeric
/// @param val A string representing a Numeric value
/// @return a Numeric
Numeric string2Numeric(const std::string &val);

/// @brief This method turns a string into a Logic
/// @param val A string representing a Logic value
/// @return a Logic
/*
Logic string2Logic(const std::string &val);

Logic string2Logic(const std::string &val,size_t size);
*/

std::pair<VarType, uint8_t>
applyCStandardConversion(const std::pair<VarType, uint8_t> &e1,
                         const std::pair<VarType, uint8_t> &e2);

template <typename T1> void addItems(T1 &base);

template <typename T1, typename T2, typename... T3>
void addItems(T1 &base, T2 arg1, T3... args);

/// @brief This method generates a new expression of type T1. All provided
/// sub-expressions are added in the generated expression by using its addItem
/// method.
/// @param args A list of sub-expressions.
/// @return A new expression combining the given sub-expressions by an operator.
template <typename T1, typename... T2> T1 *makeExpression(T2... args);

} // namespace oden

#include "propositionUtils.i.hh"
