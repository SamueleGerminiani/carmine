#include "varDeclarationHandler.hh"

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace oden {
varDeclarationParserHandler::varDeclarationParserHandler(std::string location): _location(location) {}

void varDeclarationParserHandler::enterVarDec(
    varDeclarationParser::VarDecContext *ctx) {

  if (ctx->ass()!=nullptr) {
    std::string varname = ctx->name()->getText();
    std::string initVal=ctx->ass()->getText();
    initVal.erase(begin(initVal),begin(initVal)+1);
    _debugVariables.emplace_back(varname,initVal);
  }

  if (ctx->vartype()->getText().back() == '*') {
    std::string vartype = ctx->vartype()->getText();
    std::string varname = ctx->name()->getText();
    vartype.pop_back();
    vartype.pop_back();
    // var for pointer
    _varDecls.push_back(std::make_pair(varname, "unsigned int"));
    // var for pointed value
    _varDecls.push_back(std::make_pair("*" + varname, vartype));
  } else {
    _varDecls.push_back(
        std::make_pair(ctx->name()->getText(), ctx->vartype()->getText()));
  }
}
void varDeclarationParserHandler::enterEnumDec(
    varDeclarationParser::EnumDecContext *ctx) {
  if (ctx->name() != nullptr) {
    _currEnum = ctx->name()->getText();
  } else {
    _currEnum = "";
  }
  _enums[_currEnum];
  _lastLogic = -1;
}
void varDeclarationParserHandler::exitEnumDec(
    varDeclarationParser::EnumDecContext *) {}

void varDeclarationParserHandler::enterEnum_list(
    varDeclarationParser::Enum_listContext *ctx) {
  // std::cout << __func__ << ctx->name()->getText() << "\n";

  if (ctx->addLogic() == nullptr) {
    _lastLogic++;
  }

  _enums[_currEnum].push_back(
      std::make_pair(ctx->name()->getText(), _lastLogic));
  _enumToInt.insert({{_enums[_currEnum].back().first, _lastLogic}});
}
void varDeclarationParserHandler::exitAddLogic(
    varDeclarationParser::AddLogicContext * /*ctx*/) {
  // std::cout << __func__ <<"\n";
  assert(_logicExpressions.size() == 1);
  _lastLogic = _logicExpressions.top();
  _logicExpressions.pop();
  _enumToInt[_enums[_currEnum].back().first] = _lastLogic;
  _enums[_currEnum].back().second = _lastLogic;
}
void varDeclarationParserHandler::exitLogic(
    varDeclarationParser::LogicContext *ctx) {
  // std::cout << __func__ << "\n";
  antlr4::Token *artop = ctx->artop;

  if (artop != nullptr) {
    int le2 = _logicExpressions.top();
    _logicExpressions.pop();

    int le1 = _logicExpressions.top();
    _logicExpressions.pop();

    if (artop->getText() == "*") {
      _logicExpressions.push(le2 * le1);
      return;
    }
    if (artop->getText() == "/") {
      _logicExpressions.push(le2 / le1);
      return;
    }
    if (artop->getText() == "-") {
      _logicExpressions.push(le2 - le1);
      return;
    }
    if (artop->getText() == "+") {
      _logicExpressions.push(le2 + le1);
      return;
    }
    messageError("Unknown binary arithmetic operator in logic expression!");
  }
}
void varDeclarationParserHandler::enterLogicName(
    varDeclarationParser::LogicNameContext *ctx) {
  // std::cout << __func__ << ctx->getText() << "\n";
  if (_enumToInt.count(ctx->getText())) {
    _logicExpressions.push(_enumToInt.at(ctx->getText()));
  } else {
    messageError("Undefined reference to " + ctx->getText());
  }
}
void varDeclarationParserHandler::enterLogicConstant(
    varDeclarationParser::LogicConstantContext *ctx) {
  // std::cout << __func__ << ctx->getText() << "\n";

  std::string conStr = std::string(ctx->getText());

  if (ctx->VERILOG_BINARY() != nullptr) {
    int value = std::stoull(conStr.substr(2, conStr.size() - 2));
    _logicExpressions.push(value);
    return;
  } else if (ctx->GCC_BINARY() != nullptr) {
    int value = std::stoull(conStr.substr(2, conStr.size() - 2));
    _logicExpressions.push(value);
    return;
  } else if (ctx->NUMERIC() != nullptr) {
    size_t res = conStr.find('.');
    if (res != std::string::npos) {
      messageWarning("Float literal truncated to integer");
      conStr = conStr.substr(0, res);
    }

    int value = std::stoll(conStr);
    _logicExpressions.push(value);
    return;
  }
  messageError("Unknown logic constant!");
}

void varDeclarationParserHandler::print() {
  for (auto enumDecl : _enums) {
    std::cout << enumDecl.first << ":\n";
    for (auto val : enumDecl.second) {
      std::cout << val.first << ":" << val.second << "\n";
    }
  }
  for (auto var : _varDecls) {
    std::cout << var.first << " " << var.second << "\n";
  }
}

void varDeclarationParserHandler::enterEnumType(
    varDeclarationParser::EnumTypeContext *ctx) {
  messageErrorIf(_enums.count(ctx->name()->getText()) == 0,
                 "Undefined reference to type '" + ctx->name()->getText()+"'" + " in "+_location);
}
void varDeclarationParserHandler::visitErrorNode(antlr4::tree::ErrorNode * /*node*/) {
  messageError("Antlr parse error in "+ _location);
}

std::vector<VarDeclaration> &varDeclarationParserHandler::getVarDeclarations() {
  return _varDecls;
}
std::vector<std::pair<std::string,std::string>> &varDeclarationParserHandler::getDebugVars() {
  return _debugVariables;
}
const EnumMap &varDeclarationParserHandler::getEnums() { return _enums; }
} // namespace oden
