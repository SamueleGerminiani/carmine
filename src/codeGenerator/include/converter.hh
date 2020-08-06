#pragma once
#include "types.hh"
namespace codeGenerator {
namespace converter {
SpotAutomata generateAutomata(const PSLformula &formula);
void generateChecker(const std::string& inputFormula,const std::unordered_map<std::string,std::string>& map);
std::string formulaToString(const spot::formula f, const std::unordered_map<std::string,std::string>& map);
void insertPlaceholders(std::string& inputFormula, const char delimiter, std::unordered_map<std::string,std::string>& map);
}
} // namespace codeGenerator
