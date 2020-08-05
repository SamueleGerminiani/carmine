
// Generated from varDeclaration.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "varDeclarationListener.h"


/**
 * This class provides an empty implementation of varDeclarationListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  varDeclarationBaseListener : public varDeclarationListener {
public:

  virtual void enterFile(varDeclarationParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(varDeclarationParser::FileContext * /*ctx*/) override { }

  virtual void enterCDeclaration(varDeclarationParser::CDeclarationContext * /*ctx*/) override { }
  virtual void exitCDeclaration(varDeclarationParser::CDeclarationContext * /*ctx*/) override { }

  virtual void enterCStatement(varDeclarationParser::CStatementContext * /*ctx*/) override { }
  virtual void exitCStatement(varDeclarationParser::CStatementContext * /*ctx*/) override { }

  virtual void enterVarDec(varDeclarationParser::VarDecContext * /*ctx*/) override { }
  virtual void exitVarDec(varDeclarationParser::VarDecContext * /*ctx*/) override { }

  virtual void enterAss(varDeclarationParser::AssContext * /*ctx*/) override { }
  virtual void exitAss(varDeclarationParser::AssContext * /*ctx*/) override { }

  virtual void enterEnumDec(varDeclarationParser::EnumDecContext * /*ctx*/) override { }
  virtual void exitEnumDec(varDeclarationParser::EnumDecContext * /*ctx*/) override { }

  virtual void enterEnum_list(varDeclarationParser::Enum_listContext * /*ctx*/) override { }
  virtual void exitEnum_list(varDeclarationParser::Enum_listContext * /*ctx*/) override { }

  virtual void enterAddLogic(varDeclarationParser::AddLogicContext * /*ctx*/) override { }
  virtual void exitAddLogic(varDeclarationParser::AddLogicContext * /*ctx*/) override { }

  virtual void enterName(varDeclarationParser::NameContext * /*ctx*/) override { }
  virtual void exitName(varDeclarationParser::NameContext * /*ctx*/) override { }

  virtual void enterLogicName(varDeclarationParser::LogicNameContext * /*ctx*/) override { }
  virtual void exitLogicName(varDeclarationParser::LogicNameContext * /*ctx*/) override { }

  virtual void enterVartype(varDeclarationParser::VartypeContext * /*ctx*/) override { }
  virtual void exitVartype(varDeclarationParser::VartypeContext * /*ctx*/) override { }

  virtual void enterEnumType(varDeclarationParser::EnumTypeContext * /*ctx*/) override { }
  virtual void exitEnumType(varDeclarationParser::EnumTypeContext * /*ctx*/) override { }

  virtual void enterLogic(varDeclarationParser::LogicContext * /*ctx*/) override { }
  virtual void exitLogic(varDeclarationParser::LogicContext * /*ctx*/) override { }

  virtual void enterLogicAtom(varDeclarationParser::LogicAtomContext * /*ctx*/) override { }
  virtual void exitLogicAtom(varDeclarationParser::LogicAtomContext * /*ctx*/) override { }

  virtual void enterLogicConstant(varDeclarationParser::LogicConstantContext * /*ctx*/) override { }
  virtual void exitLogicConstant(varDeclarationParser::LogicConstantContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

