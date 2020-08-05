
// Generated from varDeclaration.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "varDeclarationParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by varDeclarationParser.
 */
class  varDeclarationListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(varDeclarationParser::FileContext *ctx) = 0;
  virtual void exitFile(varDeclarationParser::FileContext *ctx) = 0;

  virtual void enterCDeclaration(varDeclarationParser::CDeclarationContext *ctx) = 0;
  virtual void exitCDeclaration(varDeclarationParser::CDeclarationContext *ctx) = 0;

  virtual void enterCStatement(varDeclarationParser::CStatementContext *ctx) = 0;
  virtual void exitCStatement(varDeclarationParser::CStatementContext *ctx) = 0;

  virtual void enterVarDec(varDeclarationParser::VarDecContext *ctx) = 0;
  virtual void exitVarDec(varDeclarationParser::VarDecContext *ctx) = 0;

  virtual void enterAss(varDeclarationParser::AssContext *ctx) = 0;
  virtual void exitAss(varDeclarationParser::AssContext *ctx) = 0;

  virtual void enterEnumDec(varDeclarationParser::EnumDecContext *ctx) = 0;
  virtual void exitEnumDec(varDeclarationParser::EnumDecContext *ctx) = 0;

  virtual void enterEnum_list(varDeclarationParser::Enum_listContext *ctx) = 0;
  virtual void exitEnum_list(varDeclarationParser::Enum_listContext *ctx) = 0;

  virtual void enterAddLogic(varDeclarationParser::AddLogicContext *ctx) = 0;
  virtual void exitAddLogic(varDeclarationParser::AddLogicContext *ctx) = 0;

  virtual void enterName(varDeclarationParser::NameContext *ctx) = 0;
  virtual void exitName(varDeclarationParser::NameContext *ctx) = 0;

  virtual void enterLogicName(varDeclarationParser::LogicNameContext *ctx) = 0;
  virtual void exitLogicName(varDeclarationParser::LogicNameContext *ctx) = 0;

  virtual void enterVartype(varDeclarationParser::VartypeContext *ctx) = 0;
  virtual void exitVartype(varDeclarationParser::VartypeContext *ctx) = 0;

  virtual void enterEnumType(varDeclarationParser::EnumTypeContext *ctx) = 0;
  virtual void exitEnumType(varDeclarationParser::EnumTypeContext *ctx) = 0;

  virtual void enterLogic(varDeclarationParser::LogicContext *ctx) = 0;
  virtual void exitLogic(varDeclarationParser::LogicContext *ctx) = 0;

  virtual void enterLogicAtom(varDeclarationParser::LogicAtomContext *ctx) = 0;
  virtual void exitLogicAtom(varDeclarationParser::LogicAtomContext *ctx) = 0;

  virtual void enterLogicConstant(varDeclarationParser::LogicConstantContext *ctx) = 0;
  virtual void exitLogicConstant(varDeclarationParser::LogicConstantContext *ctx) = 0;


};

