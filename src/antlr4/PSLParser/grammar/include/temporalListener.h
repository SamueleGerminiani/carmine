
// Generated from temporal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "temporalParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by temporalParser.
 */
class  temporalListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFormula(temporalParser::FormulaContext *ctx) = 0;
  virtual void exitFormula(temporalParser::FormulaContext *ctx) = 0;

  virtual void enterSere(temporalParser::SereContext *ctx) = 0;
  virtual void exitSere(temporalParser::SereContext *ctx) = 0;

  virtual void enterTformula(temporalParser::TformulaContext *ctx) = 0;
  virtual void exitTformula(temporalParser::TformulaContext *ctx) = 0;

  virtual void enterBoolean(temporalParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(temporalParser::BooleanContext *ctx) = 0;

  virtual void enterBooleanAtom(temporalParser::BooleanAtomContext *ctx) = 0;
  virtual void exitBooleanAtom(temporalParser::BooleanAtomContext *ctx) = 0;

  virtual void enterBooleanConstant(temporalParser::BooleanConstantContext *ctx) = 0;
  virtual void exitBooleanConstant(temporalParser::BooleanConstantContext *ctx) = 0;

  virtual void enterBooleanVariable(temporalParser::BooleanVariableContext *ctx) = 0;
  virtual void exitBooleanVariable(temporalParser::BooleanVariableContext *ctx) = 0;

  virtual void enterLogic(temporalParser::LogicContext *ctx) = 0;
  virtual void exitLogic(temporalParser::LogicContext *ctx) = 0;

  virtual void enterLogicAtom(temporalParser::LogicAtomContext *ctx) = 0;
  virtual void exitLogicAtom(temporalParser::LogicAtomContext *ctx) = 0;

  virtual void enterLogicConstant(temporalParser::LogicConstantContext *ctx) = 0;
  virtual void exitLogicConstant(temporalParser::LogicConstantContext *ctx) = 0;

  virtual void enterNamedLogicConst(temporalParser::NamedLogicConstContext *ctx) = 0;
  virtual void exitNamedLogicConst(temporalParser::NamedLogicConstContext *ctx) = 0;

  virtual void enterLogicVariable(temporalParser::LogicVariableContext *ctx) = 0;
  virtual void exitLogicVariable(temporalParser::LogicVariableContext *ctx) = 0;

  virtual void enterEnumVariable(temporalParser::EnumVariableContext *ctx) = 0;
  virtual void exitEnumVariable(temporalParser::EnumVariableContext *ctx) = 0;

  virtual void enterEnumName(temporalParser::EnumNameContext *ctx) = 0;
  virtual void exitEnumName(temporalParser::EnumNameContext *ctx) = 0;

  virtual void enterNamedConst(temporalParser::NamedConstContext *ctx) = 0;
  virtual void exitNamedConst(temporalParser::NamedConstContext *ctx) = 0;

  virtual void enterNumeric(temporalParser::NumericContext *ctx) = 0;
  virtual void exitNumeric(temporalParser::NumericContext *ctx) = 0;

  virtual void enterNumericAtom(temporalParser::NumericAtomContext *ctx) = 0;
  virtual void exitNumericAtom(temporalParser::NumericAtomContext *ctx) = 0;

  virtual void enterNumericConstant(temporalParser::NumericConstantContext *ctx) = 0;
  virtual void exitNumericConstant(temporalParser::NumericConstantContext *ctx) = 0;

  virtual void enterNumericVariable(temporalParser::NumericVariableContext *ctx) = 0;
  virtual void exitNumericVariable(temporalParser::NumericVariableContext *ctx) = 0;

  virtual void enterVariable(temporalParser::VariableContext *ctx) = 0;
  virtual void exitVariable(temporalParser::VariableContext *ctx) = 0;

  virtual void enterRelop(temporalParser::RelopContext *ctx) = 0;
  virtual void exitRelop(temporalParser::RelopContext *ctx) = 0;


};

