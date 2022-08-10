#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include "utils/VarType.hh"



namespace expression {

// Forwards declaration of base class Visitor
class ExpVisitor;

/// @brief An Atom can represent either a Variable or a Constant.
/// It only provides the base methods evaluate and visit.
template <typename T> class Atom {
public:
  /// @brief Destructor.
  virtual ~Atom() = default;

  Atom(VarType type = VarType::Bool, uint8_t size = 64);

  /// @brief Accepts a visitor to visit the current object.
  /// @param vis The visitor.
  virtual void acceptVisitor(ExpVisitor &vis) = 0;

  void setParams(VarType type, uint8_t size) {
    _type = type;
    _size = size;
  }

  uint8_t getSize() { return _size; }

  VarType getType() { return _type; }

protected:
  VarType _type;
  uint8_t _size;
};

using Numeric = double;
using Logic = uint64_t;

using NumericExpression = Atom<Numeric>;
using LogicExpression = Atom<Logic>;
using Proposition = Atom<bool>;

} // namespace expression

#include "Atom.i.hh"
