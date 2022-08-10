#include "classes/expression/TypeCast.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

template <>
void TypeCast<LogicExpression, Proposition>::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}
template <>
void TypeCast<NumericExpression, Proposition>::acceptVisitor(ExpVisitor &vis) {
  vis.visit(*this);
}

template <>
void TypeCast<LogicExpression, NumericExpression>::acceptVisitor(
    ExpVisitor &vis) {
  vis.visit(*this);
}

} // namespace expression
