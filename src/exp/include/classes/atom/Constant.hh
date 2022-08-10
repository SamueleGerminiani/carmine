#pragma once

#include "Atom.hh"

namespace expression {

/// @brief Constant declaration.
/// This class represents a constant value.
template <typename T> class Constant : public Atom<T> {

public:
  /// @brief Constructor.
  /// @param value a constant value.
  /// @param max_time the largest simulation time that can be provided to
  /// the method evaluate.
  explicit Constant(T value, VarType type = VarType::Bool, uint8_t size = 64);

  /// @brief copy Constructor.
  /// @param other The other constant to be copied.
  Constant(const Constant &other);

  /// @brief Destructor.
  ~Constant() = default;

  /// @brief Assignment operator
  /// @param other The other variable to be copied.
  Constant &operator=(const Constant &other);

  /// @brief Accepts a visitor to visit the current object.
  /// @param vis The visitor.
  void acceptVisitor(ExpVisitor &vis) override;

  T _getValue() { return _value; }

  ///  @brief Stores the constant value
  T _value;
};

using BooleanConstant = Constant<bool>;
using NumericConstant = Constant<Numeric>;
using LogicConstant = Constant<Logic>;

template <typename T> class NamedConstant : public Constant<T> {
public:
  explicit NamedConstant(std::string name, T value,
                         VarType type = VarType::Bool, uint8_t size = 64);
  void acceptVisitor(ExpVisitor &vis) override;
  std::string _getNamedValue() { return _name; }

private:
  std::string _name;
};

using NamedLogicConstant = NamedConstant<Logic>;

} // namespace expression

#include "Constant.i.hh"
