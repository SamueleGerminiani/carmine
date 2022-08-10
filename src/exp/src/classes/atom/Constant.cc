#include "classes/atom/Constant.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

template <> void BooleanConstant::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}

template <> void NumericConstant::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}

template <> void LogicConstant::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}

template <> void NamedLogicConstant::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}
} // namespace expression
