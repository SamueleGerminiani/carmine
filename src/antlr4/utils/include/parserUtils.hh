#pragma once

#include "oden/odenUtils/odenUtils.hh"
#include <unordered_set>

namespace oden {

using Name = std::string;
using Type = std::string;
using VarDeclaration = std::pair<Name, Type>;

enum class expectedToken { TypeP1 = 0, TypeP2, TypeP3, Name };

std::pair<VarType, uint8_t> string2VarTypes(std::string type);
void addTypeToProposition(std::string &formula,
                          const std::vector<VarDeclaration> &varDeclaration);

Proposition *parseProposition(std::string &formula, const std::string &decls) ;
Proposition *parsePropositionAlreadyTyped(const std::string &formula);

std::pair<std::pair<std::string, std::string>, std::unordered_map<std::string, Proposition *>>
parseLTLformula(std::string &formula, const std::string &decls,
                std::vector<std::pair<size_t, size_t>> &timers) ;

std::unordered_map<std::string, std::string> &getDebugVars();
bool exists(const std::string &varName);
} // namespace oden
