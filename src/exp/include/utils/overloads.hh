#pragma once

#include <iostream>
#include <string>
#include "VarType.hh"

namespace expression {


inline std::ostream &operator<<(std::ostream &o, const expression::VarType &vt) {
  switch (vt) {
  case expression::VarType::Bool:
    o << "Bool";
    break;
  case expression::VarType::ULogic:
    o << "ULogic";
    break;
  case expression::VarType::SLogic:
    o << "SLogic";
    break;
  case expression::VarType::Numeric:
    o << "Numeric";
    break;
  }
  return o;
}


} // namespace expression
