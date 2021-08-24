#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <types.hh>
namespace codeGenerator {
namespace timer {
extern std::vector<std::pair<size_t, size_t>> timers;
}
extern std::map<std::string, std::vector<strVariable>> bindings;
}
