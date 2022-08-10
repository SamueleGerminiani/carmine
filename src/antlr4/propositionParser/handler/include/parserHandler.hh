#pragma once

#include "classes/classes.hh"
 #include "utils/propositionUtils.hh"
#include "propositionBaseListener.h"

#include <cmath>
#include <stack>
#include <string>

using namespace antlr4;

using Name = std::string;
using Type = std::string;
using VarDeclaration = std::pair<Name, Type>;
namespace expression {

class ParserHandler : public propositionBaseListener {

public:
  explicit ParserHandler(std::string location="unknown location");

  ~ParserHandler() override = default;

  Proposition *getProposition();

private:
  bool _abort;
  bool createExpression = false;

  std::stack<Proposition *> _proposition;
  std::stack<LogicExpression *> _logicExpressions;
  std::stack<NumericExpression *> _numericExpressions;
  std::string _location;
  size_t boolStack = 0;
  size_t logicStack = 0;
  size_t numeriStack = 0;

  // already implemented
  void enterFile(propositionParser::FileContext *ctx) override;

  // already implemented
  void exitBoolean(propositionParser::BooleanContext *ctx) override;
  // already implemented
  virtual void exitLogic(propositionParser::LogicContext *ctx) override;
  // already implemented
  virtual void exitNumeric(propositionParser::NumericContext *ctx) override;
  // to implement
  // virtual void enterString(propositionParser::StringContext *ctx) override;

  // already implemented
  void
  enterBooleanVariable(propositionParser::BooleanVariableContext *ctx) override;
  // already implemented
  virtual void
  enterLogicVariable(propositionParser::LogicVariableContext *ctx) override;
  // already implemented
  virtual void
  enterNumericVariable(propositionParser::NumericVariableContext *ctx) override;
  // to implement
  // virtual void enterStringVariable(propositionParser::StringVariableContext
  // *ctx) override;

  // already implemented
  virtual void
  enterBooleanConstant(propositionParser::BooleanConstantContext *ctx) override;
  // already implemented
  virtual void
  enterLogicConstant(propositionParser::LogicConstantContext *ctx) override;
  // already implemented
  virtual void
  enterNumericConstant(propositionParser::NumericConstantContext *ctx) override;
  // to implement
  //  virtual void enterStringConstant(propositionParser::StringConstantContext
  //  *ctx) override;

  virtual void
  enterNamedLogicConst(propositionParser::NamedLogicConstContext *ctx) override;

  virtual void visitErrorNode(antlr4::tree::ErrorNode *node) override;
};

} // namespace expression
