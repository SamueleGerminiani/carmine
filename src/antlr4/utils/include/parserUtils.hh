#pragma once


#include "oden/odenUtils/odenUtils.hh"
#include <unordered_set>

namespace oden {

    using Name = std::string;
    using Type = std::string;
    using VarDeclaration = std::pair<Name, Type>;
    using EnumValues = std::vector<std::pair<Name, int>>;
    using EnumMap = std::unordered_map<Name, EnumValues>;

enum class expectedToken { TypeP1 = 0, TypeP2, TypeP3, Name };

std::pair<VarType,uint8_t> string2VarTypes(std::string type);
void addTypeToProposition(std::string &formula,
                          const std::vector<VarDeclaration> &varDeclaration,
                          const EnumMap &enums);

Proposition *parseProposition(std::string &formula,
                              const std::string &localDecls,
                              std::string propLocation="unknown location",std::string locDecLocation="unknown location");

std::unordered_map<std::string,std::string>& getDebugVars();
bool exists(const std::string &varName) ;
}  // namespace oden    
