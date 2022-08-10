#pragma once

#include "Atom.hh"
#include <string>
#include <vector>

namespace expression {

/// @brief BooleanVariable declaration.
/// This class represents a boolean variable.
template <typename T> class Variable_Base : public Atom<T> {
public:
  explicit Variable_Base(const std::string &name, VarType type = VarType::Bool,
                         uint8_t size = 64);

  void acceptVisitor(ExpVisitor &vis) override;

  const std::string &getName();

private:
  // the name of the variable
  std::string _name;
};

using BooleanVariable = Variable_Base<bool>;
using NumericVariable = Variable_Base<double>;
using LogicVariable = Variable_Base<Logic>;

struct enumItem {
  enumItem(const std::string &namedValue, int value)
      : _namedValue(namedValue), _value(value) {}
  std::string _namedValue;
  int _value;
};
class EnumVariable : public LogicVariable {
public:
  EnumVariable(const std::string &name, const std::vector<enumItem> &items);

  void acceptVisitor(ExpVisitor &vis) override;
  const std::vector<enumItem> &getItems();

private:
  const std::vector<enumItem> _items;
};
} // namespace expression

#include "Variable.i.hh"
