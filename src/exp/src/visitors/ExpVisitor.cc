#include "visitors/ExpVisitor.hh"

//------------------------------------------------------------------------------
#define LEAF_NODE(LEAF)                                                        \
  void ExpVisitor::visit(LEAF &) {}

#define EXPRESSION_NODE_1(NODE)                                                \
  void ExpVisitor::visit(NODE &o) {                                           \
    auto &propositions = o.getItems();                                         \
    for (auto *prop : propositions)                                            \
      prop->acceptVisitor(*this);                                              \
  }

#define EXPRESSION_NODE_2(NODE)                                                \
  void ExpVisitor::visit(NODE &o) { o.getItem().acceptVisitor(*this); }

#define EXPRESSION_NODE_3(NODE)                                                \
  void ExpVisitor::visit(NODE &o) {                                           \
    o.getItem1().acceptVisitor(*this);                                         \
    o.getItem2().acceptVisitor(*this);                                         \
  }

#define NUMERIC_TO_BOOL(NODE)                                                  \
  void ExpVisitor::visit(NODE &o) { o.getItem().acceptVisitor(*this); }

#define LOGIC_TO_BOOL(NODE)                                                    \
  void ExpVisitor::visit(NODE &o) { o.getItem().acceptVisitor(*this); }

#define LOGIC_TO_NUMERIC(NODE)                                                 \
  void ExpVisitor::visit(NODE &o) { o.getItem().acceptVisitor(*this); }
//------------------------------------------------------------------------------

namespace expression {

// proposition
LEAF_NODE(BooleanConstant)
LEAF_NODE(BooleanVariable)
EXPRESSION_NODE_1(PropositionAnd)
EXPRESSION_NODE_1(PropositionOr)
EXPRESSION_NODE_1(PropositionXor)
EXPRESSION_NODE_1(PropositionEq)
EXPRESSION_NODE_1(PropositionNeq)
EXPRESSION_NODE_1(PropositionNot)

// numeric
LEAF_NODE(NumericConstant)
LEAF_NODE(NumericVariable)
EXPRESSION_NODE_1(NumericSum)
EXPRESSION_NODE_1(NumericSub)
EXPRESSION_NODE_1(NumericMul)
EXPRESSION_NODE_1(NumericDiv)
EXPRESSION_NODE_1(NumericEq)
EXPRESSION_NODE_1(NumericNeq)
EXPRESSION_NODE_1(NumericGreater)
EXPRESSION_NODE_1(NumericGreaterEq)
EXPRESSION_NODE_1(NumericLess)
EXPRESSION_NODE_1(NumericLessEq)
NUMERIC_TO_BOOL(NumericToBool)

// logic
LEAF_NODE(LogicConstant)
LEAF_NODE(NamedLogicConstant)
LEAF_NODE(LogicVariable)
LEAF_NODE(EnumVariable)
EXPRESSION_NODE_1(LogicSum)
EXPRESSION_NODE_1(LogicSub)
EXPRESSION_NODE_1(LogicMul)
EXPRESSION_NODE_1(LogicDiv)
EXPRESSION_NODE_1(LogicBAnd)
EXPRESSION_NODE_1(LogicBOr)
EXPRESSION_NODE_1(LogicBXor)
EXPRESSION_NODE_1(LogicEq)
EXPRESSION_NODE_1(LogicNeq)
EXPRESSION_NODE_1(LogicGreater)
EXPRESSION_NODE_1(LogicGreaterEq)
EXPRESSION_NODE_1(LogicLess)
EXPRESSION_NODE_1(LogicLessEq)
EXPRESSION_NODE_1(LogicNot)
LOGIC_TO_NUMERIC(LogicToNumeric)
LOGIC_TO_BOOL(LogicToBool)
EXPRESSION_NODE_1(LogicLShift)
EXPRESSION_NODE_1(LogicRShift)

} // namespace expression
