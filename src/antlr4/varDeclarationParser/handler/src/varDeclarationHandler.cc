#include "varDeclarationHandler.hh"

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace oden {

void varDeclarationParserHandler::enterVarDec(
    varDeclarationParser::VarDecContext *ctx) {

    _varDecls.push_back(
        std::make_pair(ctx->name()->getText(), ctx->vartype()->getText()));
}

void varDeclarationParserHandler::print() {
  for (auto var : _varDecls) {
    std::cout << var.first << " " << var.second << "\n";
  }
}

void varDeclarationParserHandler::visitErrorNode(antlr4::tree::ErrorNode * /*node*/) {
  messageError("Antlr parse error");
}

std::vector<VarDeclaration> &varDeclarationParserHandler::getVarDeclarations() {
  return _varDecls;
}
} // namespace oden
