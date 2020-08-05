#pragma once

#include <iostream>
#include <string>

namespace oden {

enum class VarType { Bool = 0, ULogic, SLogic, Numeric };

inline std::ostream &operator<<(std::ostream &o, const oden::VarType &vt) {
  switch (vt) {
  case oden::VarType::Bool:
    o << "Bool";
    break;
  case oden::VarType::ULogic:
    o << "ULogic";
    break;
  case oden::VarType::SLogic:
    o << "SLogic";
    break;
  case oden::VarType::Numeric:
    o << "Numeric";
    break;
  }
  return o;
}

enum class BinaryOperator {
  // Boolean operators
  AND = 1,
  OR = 2,
  XOR = 3,
  // Arithmetic operators
  SUM = 4,
  SUB = 5,
  MUL = 6,
  DIV = 7,
  // Bitwise operators
  BAND = 8,
  BOR = 9,
  BXOR = 10,
  NOT = 11,
  // Relational operators
  EQ = 12,
  NEQ = 13,
  LT = 14,
  LE = 15,
  GT = 16,
  GE = 17,
  LS = 18,
  RS = 19
};

} // namespace oden
