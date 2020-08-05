#include "oden/classes/atom/Constant.hh"
#include "oden/OdenVisitor.hh"

namespace oden {

template <> void BooleanConstant::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

template <> void NumericConstant::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

template <> void LogicConstant::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}

template <> void NamedLogicConstant::acceptVisitor(OdenVisitor &vis) {
  vis.visit(*this);
}
} // namespace oden
