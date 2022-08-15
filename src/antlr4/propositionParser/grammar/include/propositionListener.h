
// Generated from proposition.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "propositionParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by propositionParser.
 */
class  propositionListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(propositionParser::FileContext *ctx) = 0;
  virtual void exitFile(propositionParser::FileContext *ctx) = 0;

  virtual void enterBoolean(propositionParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(propositionParser::BooleanContext *ctx) = 0;

  virtual void enterBooleanAtom(propositionParser::BooleanAtomContext *ctx) = 0;
  virtual void exitBooleanAtom(propositionParser::BooleanAtomContext *ctx) = 0;

  virtual void enterBooleanConstant(propositionParser::BooleanConstantContext *ctx) = 0;
  virtual void exitBooleanConstant(propositionParser::BooleanConstantContext *ctx) = 0;

  virtual void enterBooleanVariable(propositionParser::BooleanVariableContext *ctx) = 0;
  virtual void exitBooleanVariable(propositionParser::BooleanVariableContext *ctx) = 0;

  virtual void enterLogic(propositionParser::LogicContext *ctx) = 0;
  virtual void exitLogic(propositionParser::LogicContext *ctx) = 0;

  virtual void enterLogicAtom(propositionParser::LogicAtomContext *ctx) = 0;
  virtual void exitLogicAtom(propositionParser::LogicAtomContext *ctx) = 0;

  virtual void enterLogicConstant(propositionParser::LogicConstantContext *ctx) = 0;
  virtual void exitLogicConstant(propositionParser::LogicConstantContext *ctx) = 0;

  virtual void enterNamedLogicConst(propositionParser::NamedLogicConstContext *ctx) = 0;
  virtual void exitNamedLogicConst(propositionParser::NamedLogicConstContext *ctx) = 0;

  virtual void enterLogicVariable(propositionParser::LogicVariableContext *ctx) = 0;
  virtual void exitLogicVariable(propositionParser::LogicVariableContext *ctx) = 0;

  virtual void enterEnumVariable(propositionParser::EnumVariableContext *ctx) = 0;
  virtual void exitEnumVariable(propositionParser::EnumVariableContext *ctx) = 0;

  virtual void enterEnumName(propositionParser::EnumNameContext *ctx) = 0;
  virtual void exitEnumName(propositionParser::EnumNameContext *ctx) = 0;

  virtual void enterNamedConst(propositionParser::NamedConstContext *ctx) = 0;
  virtual void exitNamedConst(propositionParser::NamedConstContext *ctx) = 0;

  virtual void enterNumeric(propositionParser::NumericContext *ctx) = 0;
  virtual void exitNumeric(propositionParser::NumericContext *ctx) = 0;

  virtual void enterNumericAtom(propositionParser::NumericAtomContext *ctx) = 0;
  virtual void exitNumericAtom(propositionParser::NumericAtomContext *ctx) = 0;

  virtual void enterNumericConstant(propositionParser::NumericConstantContext *ctx) = 0;
  virtual void exitNumericConstant(propositionParser::NumericConstantContext *ctx) = 0;

  virtual void enterNumericVariable(propositionParser::NumericVariableContext *ctx) = 0;
  virtual void exitNumericVariable(propositionParser::NumericVariableContext *ctx) = 0;

  virtual void enterVariable(propositionParser::VariableContext *ctx) = 0;
  virtual void exitVariable(propositionParser::VariableContext *ctx) = 0;

  virtual void enterRelop(propositionParser::RelopContext *ctx) = 0;
  virtual void exitRelop(propositionParser::RelopContext *ctx) = 0;


};

