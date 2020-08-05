#include "oden/visitors/VarsExtractVisitor.hh"

//------------------------------------------------------------------------------
#define VARIABLE(LEAF)                                                         \
  void VarsExtractVisitor::visit(LEAF &o) { _varsWithType.emplace_back(o.getName(),o.getType());\
      _vars.push_back(o.getName());\
  }



#define CONSTANT(LEAF)                                                         \
  void VarsExtractVisitor::visit(__attribute__((unused)) LEAF &o) {}

#define EXPRESSION(NODE)                                                       \
  void VarsExtractVisitor::visit(oden::NODE &o) {                              \
    auto &items = o.getItems();                                                \
                                                                               \
    if (!items.empty()) {                                                      \
      auto iterStop = items.end();                                             \
      auto iter = items.begin();                                               \
                                                                               \
      if (items.size() > 1) {                                                  \
        --iterStop;                                                            \
        for (; iter != iterStop; ++iter) {                                     \
          (*iter)->acceptVisitor(*this);                                       \
        }                                                                      \
      }                                                                        \
      (*iter)->acceptVisitor(*this);                                           \
    }                                                                          \
  }

#define NUMERIC_TO_BOOL(NODE)                                                  \
  void VarsExtractVisitor::visit(NODE &o) { o.getItem().acceptVisitor(*this); }

#define LOGIC_TO_BOOL(NODE)                                                    \
  void VarsExtractVisitor::visit(NODE &o) { o.getItem().acceptVisitor(*this); }

#define LOGIC_TO_NUMERIC(NODE)                                                 \
  void VarsExtractVisitor::visit(NODE &o) { o.getItem().acceptVisitor(*this); }

//------------------------------------------------------------------------------

namespace oden {

VarsExtractVisitor::VarsExtractVisitor() : OdenVisitor() {
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

void VarsExtractVisitor::clear() { _vars.clear(); }

const std::vector<std::pair<std::string,VarType>>& VarsExtractVisitor::getWithType() { return _varsWithType; }
const std::vector<std::string>& VarsExtractVisitor::get() { return _vars; }

// proposition
VARIABLE(BooleanVariable)
CONSTANT(BooleanConstant)
EXPRESSION(PropositionAnd)
EXPRESSION(PropositionOr)
EXPRESSION(PropositionXor)
EXPRESSION(PropositionEq)
EXPRESSION(PropositionNeq)

void VarsExtractVisitor::visit(oden::PropositionNot &o) {
  o.getItems()[0]->acceptVisitor(*this);
}

void VarsExtractVisitor::visit(oden::LogicNot &o) {
  o.getItems()[0]->acceptVisitor(*this);
}
void VarsExtractVisitor::visit(__attribute__((unused))
                               oden::NamedLogicConstant &o) {}

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

} // namespace oden
