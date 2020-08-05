#include "oden/classes/expression/TypeCast.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

template <>
void TypeCast<LogicExpression, Proposition>::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}
template <>
void TypeCast<NumericExpression, Proposition>::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

template <>
void TypeCast<LogicExpression, NumericExpression>::acceptVisitor(
    OdenVisitor &vis) {
  vis.visit(*this);
}

} // namespace oden
