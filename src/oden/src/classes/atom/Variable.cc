#include "oden/classes/atom/Variable.hh"
#include "oden/OdenVisitor.hh"
#include "oden/odenUtils/applicationUtils.hh"

namespace oden {

template <> void BooleanVariable::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

template <> void NumericVariable::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

template <> void LogicVariable::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

EnumVariable::EnumVariable(const std::string &name,
                           const std::vector<enumItem> &items)
    : LogicVariable(name, VarType::SLogic, 32), _items(items) {}
const std::vector<enumItem> &EnumVariable::getItems() { return _items; }
void EnumVariable::acceptVisitor(OdenVisitor &vis) { vis.visit(*this); }
} // namespace oden
