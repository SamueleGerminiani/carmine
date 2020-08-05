#pragma once

#include "odenCore.hh"
#include "varDeclarationBaseListener.h"

#include <cmath>
#include <stack>
#include <string>

using namespace antlr4;

namespace oden {

using Name = std::string;
using Type = std::string;
using VarDeclaration = std::pair<Name, Type>;
using EnumValues = std::vector<std::pair<Name, int>>;
using EnumMap = std::unordered_map<Name, EnumValues>;
class varDeclarationParserHandler : public varDeclarationBaseListener {
public:
explicit varDeclarationParserHandler(std::string location);

  ~varDeclarationParserHandler() override = default;

  virtual void enterVarDec(varDeclarationParser::VarDecContext *ctx) override;
  virtual void enterEnumDec(varDeclarationParser::EnumDecContext *ctx) override;
  virtual void exitEnumDec(varDeclarationParser::EnumDecContext *) override;

  virtual void
  enterEnum_list(varDeclarationParser::Enum_listContext *ctx) override;
  virtual void
  exitAddLogic(varDeclarationParser::AddLogicContext * /*ctx*/) override;
  virtual void exitLogic(varDeclarationParser::LogicContext *ctx) override;
  virtual void
  enterLogicName(varDeclarationParser::LogicNameContext *ctx) override;
  virtual void
  enterLogicConstant(varDeclarationParser::LogicConstantContext *ctx) override;
  void print();
  virtual void
  enterEnumType(varDeclarationParser::EnumTypeContext *ctx) override;
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;

  std::vector<VarDeclaration> &getVarDeclarations();
std::vector<std::pair<std::string,std::string>> &getDebugVars() ;
  const EnumMap &getEnums();

private:
  bool _abort;

  std::vector<VarDeclaration> _varDecls;
  std::vector<std::pair<std::string,std::string>> _debugVariables;
  EnumMap _enums;
  std::unordered_map<std::string, int> _enumToInt;
  std::string _currEnum = "";
  int _lastLogic = -1;
  std::stack<int> _logicExpressions;
  std::string _location;
};

} // namespace oden
