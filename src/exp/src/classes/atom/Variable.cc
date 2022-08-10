#include "classes/atom/Variable.hh"
#include "visitors/ExpVisitor.hh"
#include "message.hh"

namespace expression {

template <> void BooleanVariable::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}

template <> void NumericVariable::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}

template <> void LogicVariable::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}

EnumVariable::EnumVariable(const std::string &name,
                           const std::vector<enumItem> &items)
    : LogicVariable(name, VarType::SLogic, 32), _items(items) {}
const std::vector<enumItem> &EnumVariable::getItems() { return _items; }
void EnumVariable::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
} // namespace expression
