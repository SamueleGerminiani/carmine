#include "visitors/PrinterVisitor.hh"

//------------------------------------------------------------------------------
#define VARIABLE(LEAF)                                                         \
  void PrinterVisitor::visit(LEAF &o) { _ss << o.getName(); }

#define CONSTANT(LEAF)                                                         \
  void PrinterVisitor::visit(LEAF &o) { _ss << o._getValue(); }

#define EXPRESSION(NODE)                                                       \
  void PrinterVisitor::visit(expression::NODE &o) {                                  \
    auto &items = o.getItems();                                                \
                                                                               \
    if (!items.empty()) {                                                      \
      auto iterStop = items.end();                                             \
      auto iter = items.begin();                                               \
                                                                               \
      _ss << "(";                                                              \
      if (items.size() > 1) {                                                  \
        --iterStop;                                                            \
        for (; iter != iterStop; ++iter) {                                     \
          (*iter)->acceptVisitor(*this);                                       \
          _ss << " " << operators[ope::NODE] << " ";                           \
        }                                                                      \
      }                                                                        \
      (*iter)->acceptVisitor(*this);                                           \
      _ss << ")";                                                              \
    }                                                                          \
  }

#define NUMERIC_TO_BOOL(NODE)                                                  \
  void PrinterVisitor::visit(NODE &o) {                                        \
    /*                                                                         \
  _ss << "(";                                                                  \
  _ss << "(bool)";                                                             \
  */                                                                           \
    o.getItem().acceptVisitor(*this);                                          \
    /*      _ss << ")";*/                                                      \
  }

#define LOGIC_TO_BOOL(NODE)                                                    \
  void PrinterVisitor::visit(NODE &o) {                                        \
    /*                                                                         \
  _ss << "(";                                                                  \
  _ss << "(bool)";                                                             \
  */                                                                           \
    o.getItem().acceptVisitor(*this);                                          \
    /*      _ss << ")";*/                                                      \
  }

#define LOGIC_TO_NUMERIC(NODE)                                                 \
  void PrinterVisitor::visit(NODE &o) {                                        \
    /*                                                                         \
  _ss << "(";                                                                  \
  _ss << "(double)";                                                           \
  */                                                                           \
    o.getItem().acceptVisitor(*this);                                          \
    /*      _ss << ")";  */                                                    \
  }

//------------------------------------------------------------------------------

namespace expression {

PrinterVisitor::PrinterVisitor() : ExpVisitor(), _ss() {
  // proposition
  operators[ope::PropositionNot] = std::string("!");
  operators[ope::PropositionAnd] = std::string("&&");
  operators[ope::PropositionOr] = std::string("||");
  operators[ope::PropositionXor] = std::string("^");
  operators[ope::PropositionEq] = std::string("==");
  operators[ope::PropositionNeq] = std::string("!=");

  // numeric
  operators[ope::NumericSum] = std::string("+");
  operators[ope::NumericSub] = std::string("-");
  operators[ope::NumericMul] = std::string("*");
  operators[ope::NumericDiv] = std::string("/");
  operators[ope::NumericEq] = std::string("==");
  operators[ope::NumericNeq] = std::string("!=");
  operators[ope::NumericGreater] = std::string(">");
  operators[ope::NumericGreaterEq] = std::string(">=");
  operators[ope::NumericLess] = std::string("<");
  operators[ope::NumericLessEq] = std::string("<=");

  // logic
  operators[ope::LogicSum] = std::string("+");
  operators[ope::LogicSub] = std::string("-");
  operators[ope::LogicMul] = std::string("*");
  operators[ope::LogicDiv] = std::string("/");
  operators[ope::LogicBAnd] = std::string("&");
  operators[ope::LogicBOr] = std::string("|");
  operators[ope::LogicBXor] = std::string("^");
  operators[ope::LogicNot] = std::string("~");
  operators[ope::LogicEq] = std::string("==");
  operators[ope::LogicNeq] = std::string("!=");
  operators[ope::LogicGreater] = std::string(">");
  operators[ope::LogicGreaterEq] = std::string(">=");
  operators[ope::LogicLess] = std::string("<");
  operators[ope::LogicLessEq] = std::string("<=");
  operators[ope::LogicLShift] = std::string("<<");
  operators[ope::LogicRShift] = std::string(">>");
}

void PrinterVisitor::clear() {
  _ss.clear();
  _ss.str(std::string());
}

std::string PrinterVisitor::get() {
  std::string ret = _ss.str();
  clear();
  return ret;
}

// proposition
VARIABLE(BooleanVariable)
CONSTANT(BooleanConstant)
EXPRESSION(PropositionAnd)
EXPRESSION(PropositionOr)
EXPRESSION(PropositionXor)
EXPRESSION(PropositionEq)
EXPRESSION(PropositionNeq)

void PrinterVisitor::visit(expression::PropositionNot &o) {
  _ss << operators[ope::PropositionNot];
  o.getItems()[0]->acceptVisitor(*this);
}

void PrinterVisitor::visit(expression::LogicNot &o) {
  _ss << operators[ope::LogicNot];
  o.getItems()[0]->acceptVisitor(*this);
}
void PrinterVisitor::visit(expression::NamedLogicConstant &o) {
  _ss << o._getNamedValue();
}

// numeric
VARIABLE(NumericVariable)
CONSTANT(NumericConstant)
EXPRESSION(NumericSum)
EXPRESSION(NumericSub)
EXPRESSION(NumericMul)
EXPRESSION(NumericDiv)
EXPRESSION(NumericEq)
EXPRESSION(NumericNeq)
EXPRESSION(NumericGreater)
EXPRESSION(NumericGreaterEq)
EXPRESSION(NumericLess)
EXPRESSION(NumericLessEq)
NUMERIC_TO_BOOL(NumericToBool)

// logic
VARIABLE(LogicVariable)
VARIABLE(EnumVariable)
CONSTANT(LogicConstant)
EXPRESSION(LogicSum)
EXPRESSION(LogicSub)
EXPRESSION(LogicMul)
EXPRESSION(LogicDiv)
EXPRESSION(LogicBAnd)
EXPRESSION(LogicBOr)
EXPRESSION(LogicBXor)
EXPRESSION(LogicEq)
EXPRESSION(LogicNeq)
EXPRESSION(LogicGreater)
EXPRESSION(LogicGreaterEq)
EXPRESSION(LogicLess)
EXPRESSION(LogicLessEq)
LOGIC_TO_NUMERIC(LogicToNumeric)
LOGIC_TO_BOOL(LogicToBool)
EXPRESSION(LogicLShift)
EXPRESSION(LogicRShift)

} // namespace expression
