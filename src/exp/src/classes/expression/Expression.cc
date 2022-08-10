#include "classes/expression/Expression.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

//==== Call to Visitor's methods ===============================================
#define VISITOR_CALL(Operator, ET, OT)                                         \
  template <>                                                                  \
  void Expression<BinaryOperator::Operator, ET, OT>::acceptVisitor(            \
      ExpVisitor &vis) {                                                      \
    vis.visit(*this);                                                          \
  }

// proposition
VISITOR_CALL(AND, Proposition, Proposition)
VISITOR_CALL(OR, Proposition, Proposition)
VISITOR_CALL(XOR, Proposition, Proposition)
VISITOR_CALL(EQ, Proposition, Proposition)
VISITOR_CALL(NEQ, Proposition, Proposition)
VISITOR_CALL(NOT, Proposition, Proposition)

// numeric
VISITOR_CALL(SUM, NumericExpression, NumericExpression)
VISITOR_CALL(SUB, NumericExpression, NumericExpression)
VISITOR_CALL(MUL, NumericExpression, NumericExpression)
VISITOR_CALL(DIV, NumericExpression, NumericExpression)
VISITOR_CALL(EQ, NumericExpression, Proposition)
VISITOR_CALL(NEQ, NumericExpression, Proposition)
VISITOR_CALL(GT, NumericExpression, Proposition)
VISITOR_CALL(GE, NumericExpression, Proposition)
VISITOR_CALL(LT, NumericExpression, Proposition)
VISITOR_CALL(LE, NumericExpression, Proposition)

// logic
VISITOR_CALL(SUM, LogicExpression, LogicExpression)
VISITOR_CALL(SUB, LogicExpression, LogicExpression)
VISITOR_CALL(MUL, LogicExpression, LogicExpression)
VISITOR_CALL(DIV, LogicExpression, LogicExpression)
VISITOR_CALL(BAND, LogicExpression, LogicExpression)
VISITOR_CALL(BOR, LogicExpression, LogicExpression)
VISITOR_CALL(BXOR, LogicExpression, LogicExpression)
VISITOR_CALL(EQ, LogicExpression, Proposition)
VISITOR_CALL(NEQ, LogicExpression, Proposition)
VISITOR_CALL(GT, LogicExpression, Proposition)
VISITOR_CALL(GE, LogicExpression, Proposition)
VISITOR_CALL(LT, LogicExpression, Proposition)
VISITOR_CALL(LE, LogicExpression, Proposition)
VISITOR_CALL(NOT, LogicExpression, LogicExpression)
VISITOR_CALL(LS, LogicExpression, LogicExpression)
VISITOR_CALL(RS, LogicExpression, LogicExpression)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

} // namespace expression
