#pragma once

#include "oden/classes/classes.hh"
#include "oden/odenUtils/propositionUtils.hh"
#include "temporalBaseListener.h"

#include <cmath>
#include <stack>
#include <string>

using namespace antlr4;

using Name = std::string;
using Type = std::string;
using VarDeclaration = std::pair<Name, Type>;
using EnumValues = std::vector<std::pair<Name, int>>;
using EnumMap = std::unordered_map<Name, EnumValues>;
namespace oden {

class TemporalParserHandler : public temporalBaseListener {

public:
  explicit TemporalParserHandler(const EnumMap &enums,
                                 std::string location = "unknown location");

  ~TemporalParserHandler() override = default;

 std::unordered_map<std::string,Proposition*> getPropositions() ;
  std::string getSFormula(){
	  return _subFormulas.top();

  }

  void printAllPropositions() {
	  for (auto p : _phToProp) {
		  std::cout << p.first<<":"<<oden::prop2String(*p.second) << "\n";
	  }
  }

private:
  bool _abort;
  bool createExpression = false;
  std::unordered_map<std::string, std::vector<enumItem>> _enums;

  std::stack<Proposition *> _proposition;
  std::stack<LogicExpression *> _logicExpressions;
  std::stack<NumericExpression *> _numericExpressions;
  std::stack<std::string> _subFormulas;
  std::string _location;
  size_t boolStack = 0;
  size_t logicStack = 0;
  size_t numeriStack = 0;
  size_t placeholdN=0;
  std::unordered_map<std::string,Proposition*> _phToProp;

  // already implemented
  // void enterFile(temporalParser::FileContext *ctx) override;

  // already implemented
  void exitBoolean(temporalParser::BooleanContext *ctx) override;
  // already implemented
  virtual void exitLogic(temporalParser::LogicContext *ctx) override;
  // already implemented
  virtual void exitNumeric(temporalParser::NumericContext *ctx) override;
  // to implement
  // virtual void enterString(temporalParser::StringContext *ctx) override;

  // already implemented
  void
  enterBooleanVariable(temporalParser::BooleanVariableContext *ctx) override;
  // already implemented
  virtual void
  enterLogicVariable(temporalParser::LogicVariableContext *ctx) override;
  // already implemented
  virtual void
  enterNumericVariable(temporalParser::NumericVariableContext *ctx) override;
  // to implement
  // virtual void enterStringVariable(temporalParser::StringVariableContext
  // *ctx) override;

  // already implemented
  virtual void
  enterBooleanConstant(temporalParser::BooleanConstantContext *ctx) override;
  // already implemented
  virtual void
  enterLogicConstant(temporalParser::LogicConstantContext *ctx) override;
  // already implemented
  virtual void
  enterNumericConstant(temporalParser::NumericConstantContext *ctx) override;
  // to implement
  //  virtual void enterStringConstant(temporalParser::StringConstantContext
  //  *ctx) override;

  virtual void
  enterNamedLogicConst(temporalParser::NamedLogicConstContext *ctx) override;

  virtual void
  enterEnumVariable(temporalParser::EnumVariableContext *ctx) override;
  virtual void visitErrorNode(antlr4::tree::ErrorNode *node) override;
  virtual void exitTformula(temporalParser::TformulaContext * ctx) override;
  virtual void exitSere(temporalParser::SereContext * ctx) override;

};

} // namespace oden
