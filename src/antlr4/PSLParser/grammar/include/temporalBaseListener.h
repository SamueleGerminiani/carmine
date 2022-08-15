
// Generated from temporal.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "temporalListener.h"


/**
 * This class provides an empty implementation of temporalListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  temporalBaseListener : public temporalListener {
public:

  virtual void enterFormula(temporalParser::FormulaContext * /*ctx*/) override { }
  virtual void exitFormula(temporalParser::FormulaContext * /*ctx*/) override { }

  virtual void enterImplication(temporalParser::ImplicationContext * /*ctx*/) override { }
  virtual void exitImplication(temporalParser::ImplicationContext * /*ctx*/) override { }

  virtual void enterSere(temporalParser::SereContext * /*ctx*/) override { }
  virtual void exitSere(temporalParser::SereContext * /*ctx*/) override { }

  virtual void enterTformula(temporalParser::TformulaContext * /*ctx*/) override { }
  virtual void exitTformula(temporalParser::TformulaContext * /*ctx*/) override { }

  virtual void enterFile(temporalParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(temporalParser::FileContext * /*ctx*/) override { }

  virtual void enterBoolean(temporalParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(temporalParser::BooleanContext * /*ctx*/) override { }

  virtual void enterBooleanAtom(temporalParser::BooleanAtomContext * /*ctx*/) override { }
  virtual void exitBooleanAtom(temporalParser::BooleanAtomContext * /*ctx*/) override { }

  virtual void enterBooleanConstant(temporalParser::BooleanConstantContext * /*ctx*/) override { }
  virtual void exitBooleanConstant(temporalParser::BooleanConstantContext * /*ctx*/) override { }

  virtual void enterBooleanVariable(temporalParser::BooleanVariableContext * /*ctx*/) override { }
  virtual void exitBooleanVariable(temporalParser::BooleanVariableContext * /*ctx*/) override { }

  virtual void enterLogic(temporalParser::LogicContext * /*ctx*/) override { }
  virtual void exitLogic(temporalParser::LogicContext * /*ctx*/) override { }

  virtual void enterLogicAtom(temporalParser::LogicAtomContext * /*ctx*/) override { }
  virtual void exitLogicAtom(temporalParser::LogicAtomContext * /*ctx*/) override { }

  virtual void enterLogicConstant(temporalParser::LogicConstantContext * /*ctx*/) override { }
  virtual void exitLogicConstant(temporalParser::LogicConstantContext * /*ctx*/) override { }

  virtual void enterNamedLogicConst(temporalParser::NamedLogicConstContext * /*ctx*/) override { }
  virtual void exitNamedLogicConst(temporalParser::NamedLogicConstContext * /*ctx*/) override { }

  virtual void enterLogicVariable(temporalParser::LogicVariableContext * /*ctx*/) override { }
  virtual void exitLogicVariable(temporalParser::LogicVariableContext * /*ctx*/) override { }

  virtual void enterEnumVariable(temporalParser::EnumVariableContext * /*ctx*/) override { }
  virtual void exitEnumVariable(temporalParser::EnumVariableContext * /*ctx*/) override { }

  virtual void enterEnumName(temporalParser::EnumNameContext * /*ctx*/) override { }
  virtual void exitEnumName(temporalParser::EnumNameContext * /*ctx*/) override { }

  virtual void enterNamedConst(temporalParser::NamedConstContext * /*ctx*/) override { }
  virtual void exitNamedConst(temporalParser::NamedConstContext * /*ctx*/) override { }

  virtual void enterNumeric(temporalParser::NumericContext * /*ctx*/) override { }
  virtual void exitNumeric(temporalParser::NumericContext * /*ctx*/) override { }

  virtual void enterNumericAtom(temporalParser::NumericAtomContext * /*ctx*/) override { }
  virtual void exitNumericAtom(temporalParser::NumericAtomContext * /*ctx*/) override { }

  virtual void enterNumericConstant(temporalParser::NumericConstantContext * /*ctx*/) override { }
  virtual void exitNumericConstant(temporalParser::NumericConstantContext * /*ctx*/) override { }

  virtual void enterNumericVariable(temporalParser::NumericVariableContext * /*ctx*/) override { }
  virtual void exitNumericVariable(temporalParser::NumericVariableContext * /*ctx*/) override { }

  virtual void enterVariable(temporalParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(temporalParser::VariableContext * /*ctx*/) override { }

  virtual void enterRelop(temporalParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(temporalParser::RelopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

