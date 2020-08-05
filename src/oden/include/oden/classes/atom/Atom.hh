#pragma once

#include <cstddef>
#include <cstdint>

#include "oden/odenEnums.hh"

namespace oden {

// Forwards declaration of base class Visitor
class OdenVisitor;

/// @brief An Atom can represent either a Variable or a Constant.
/// It only provides the base methods evaluate and visit.
template <typename T> class Atom {
public:
  /// @brief Destructor.
  virtual ~Atom() = default;

  Atom(VarType type = VarType::Bool, uint8_t size = 64);

  /// @brief Accepts a visitor to visit the current object.
  /// @param vis The visitor.
  virtual void acceptVisitor(OdenVisitor &vis) = 0;

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

} // namespace oden

#include "Atom.i.hh"
