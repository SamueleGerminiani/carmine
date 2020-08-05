#pragma once

#include "oden/classes/atom/Atom.hh"
#include "oden/classes/atom/Constant.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

/// @brief TypeCast declaration.
/// This class represents the bit selector operator
template <typename ET, typename RT> class TypeCast : public RT {

public:
  using ReturnType =
      typename std::conditional<std::is_same<RT, LogicExpression>::value, Logic,
                                bool>::type;

  TypeCast(ET *e, VarType type = VarType::Bool, uint8_t size = 8);

  /// @brief Copy constructor.
  TypeCast(const TypeCast &other) = delete;

  /// @brief Destructor.
  virtual ~TypeCast();

  /// @brief Accepts a visitor to visit the current object.
  /// @param vis The visitor.
  void acceptVisitor(OdenVisitor &vis) override;

  /// @brief Return the expression of the next operator
  /// @return A reference to the expression.
  ET &getItem();

  /// @brief Assing operator
  TypeCast &operator=(const TypeCast &other) = delete;

private:
  ET *_e;
};
using LogicToNumeric = TypeCast<LogicExpression, NumericExpression>;
using LogicToBool = TypeCast<LogicExpression, Proposition>;
using NumericToBool = TypeCast<NumericExpression, Proposition>;

} // namespace oden

#include "TypeCast.i.hh"
