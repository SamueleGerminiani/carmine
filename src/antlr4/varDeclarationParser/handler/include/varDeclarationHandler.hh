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
class varDeclarationParserHandler : public varDeclarationBaseListener {
public:
explicit varDeclarationParserHandler(std::string location);

  ~varDeclarationParserHandler() override = default;

  virtual void enterVarDec(varDeclarationParser::VarDecContext *ctx) override;

  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;

  std::vector<VarDeclaration> &getVarDeclarations();
void print() ;

private:
  bool _abort;

  std::vector<VarDeclaration> _varDecls;
  std::string _location;
};

} // namespace oden
