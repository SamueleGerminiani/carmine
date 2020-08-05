#include "parserHandler.hh"

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace oden {

  ParserHandler::ParserHandler(const EnumMap &enums,std::string location) : _abort(false), _proposition(), _logicExpressions(),
      _numericExpressions() , _location(location){
  for (const auto &name_values : enums) {
    std::vector<enumItem> tmpEnumValues;
    for (const auto &val : name_values.second) {
      tmpEnumValues.push_back(enumItem(val.first, val.second));
    }
    _enums.insert({{name_values.first, tmpEnumValues}});
  }
}

void ParserHandler::enterFile(__attribute__((unused))
                              propositionParser::FileContext *ctx) {
  _abort = false;

  while (!_proposition.empty()) {
    delete _proposition.top();
    _proposition.pop();
  }

  while (!_numericExpressions.empty()) {
    delete _numericExpressions.top();
    _numericExpressions.pop();
  }

  while (!_logicExpressions.empty()) {
    delete _logicExpressions.top();
    _logicExpressions.pop();
  }
}

void ParserHandler::enterBooleanConstant(
    propositionParser::BooleanConstantContext *ctx) {
  antlr4::tree::TerminalNode *con = ctx->BOOLEAN();
  std::string conStr = std::string(con->getText());

  if (conStr == "@false") {
    auto *c = new BooleanConstant(false);
    _proposition.push(c);
    return;
  } else if (conStr == "@true") {
    auto *c = new BooleanConstant(true);
    _proposition.push(c);
    return;
  } else {
    messageError("Uknown boolean constant!");
  }
}
void ParserHandler::enterNamedLogicConst(
    propositionParser::NamedLogicConstContext *ctx) {
  std::string conStr = std::string(ctx->NUMERIC()->getText());

  if (ctx->NUMERIC() != nullptr) {
    size_t res = conStr.find('.');
    if (res != std::string::npos) {
      messageWarning("Float literal truncated to integer");
      conStr = conStr.substr(0, res);
    }

    if (std::stoll(conStr) < 0) {
      // Store the logic as 2s complement int
      Logic value = std::stoll(conStr);
      auto *c = new NamedLogicConstant(
          ctx->namedConst()->getText(), value, VarType::SLogic,
          (uint8_t)(value != 0 ? std::log2(value) + 2 : 1));
      _logicExpressions.push(c);
    } else {
      // Store the logic as classic unsigned binary
      Logic value = std::stoull(conStr);
      auto *c = new NamedLogicConstant(
          ctx->namedConst()->getText(), value, VarType::ULogic,
          (uint8_t)(value != 0 ? std::log2(value) + 1 : 1));
      _logicExpressions.push(c);
    }
    return;
  }
}

void ParserHandler::enterEnumVariable(
    propositionParser::EnumVariableContext *ctx) {
  propositionParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  _logicExpressions.push(
      new EnumVariable(varName, _enums.at(ctx->enumName()->getText())));
}
void ParserHandler::enterLogicConstant(
    propositionParser::LogicConstantContext *ctx) {
  std::string conStr = std::string(ctx->getText());

  if (ctx->VERILOG_BINARY() != nullptr) {
    Logic value = std::stoull(conStr.substr(2, conStr.size() - 2));
    auto *c = new LogicConstant(value, VarType::ULogic, conStr.size() - 2);
    _logicExpressions.push(c);
    return;
  } else if (ctx->GCC_BINARY() != nullptr) {
    Logic value = std::stoull(conStr.substr(2, conStr.size() - 2));
    auto *c = new LogicConstant(value, VarType::ULogic, conStr.size() - 2);
    _logicExpressions.push(c);
    return;
  } else if (ctx->NUMERIC() != nullptr) {
    size_t res = conStr.find('.');
    if (res != std::string::npos) {
      messageWarning("Float literal truncated to integer");
      conStr = conStr.substr(0, res);
    }

    if (std::stoll(conStr) < 0) {
      // Store the logic as 2s complement int
      Logic value = std::stoll(conStr);
      std::cout << value << "\n";
      auto *c =
          new LogicConstant(value, VarType::SLogic,
                            (uint8_t)(value != 0 ? std::log2(value) + 2 : 1));
      _logicExpressions.push(c);
    } else {
      // Store the logic as classic unsigned binary
      Logic value = std::stoull(conStr);
      auto *c =
          new LogicConstant(value, VarType::ULogic,
                            (uint8_t)(value != 0 ? std::log2(value) + 1 : 1));
      _logicExpressions.push(c);
    }
    return;
  }
  messageError("Unknown logic constant!");
}
void ParserHandler::enterNumericConstant(
    propositionParser::NumericConstantContext *ctx) {
  if (ctx->NUMERIC() != nullptr) {
    Numeric value = std::stod(ctx->getText());
    auto *c = new NumericConstant(value, VarType::Numeric, 64);
    _numericExpressions.push(c);
    return;
  }
}

/*
void ParserHandler::enterStringConstant(propositionParser::StringConstantContext
*ctx){
if (ctx->STRING() != nullptr) {
auto *c = new StringConstant(ctx->getText());
_numericExpressions.push(c);
return;
}
}
*/

void ParserHandler::enterBooleanVariable(
    propositionParser::BooleanVariableContext *ctx) {
  propositionParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  Proposition *n = new BooleanVariable(varName);

  _proposition.push(n);
}
void ParserHandler::enterLogicVariable(
    propositionParser::LogicVariableContext *ctx) {
  propositionParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  if (ctx->SIGN() != nullptr && ctx->NUMERIC() != nullptr) {
    LogicExpression *n;
    if (ctx->SIGN()->toString()[0] == 'u') {
      n = new LogicVariable(varName, VarType::ULogic,
                            std::stoul(ctx->NUMERIC()->toString()));
    } else if (ctx->SIGN()->toString()[0] == 's') {
      n = new LogicVariable(varName, VarType::SLogic,
                            std::stoul(ctx->NUMERIC()->toString()));
    } else {
      messageError("Uknown sign in logic variable");
    }

    _logicExpressions.push(n);
  } else {
    messageError("Sign or size not set in logic variable");
  }
}
void ParserHandler::enterNumericVariable(
    propositionParser::NumericVariableContext *ctx) {
  propositionParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  if (ctx->NUMERIC() != nullptr) {
    uint8_t size = std::stoul(ctx->NUMERIC()->toString());
    if (size == 32 || size == 64) {
      NumericExpression *n =
          new NumericVariable(varName, VarType::Numeric, size);
      _numericExpressions.push(n);
    } else {
      messageError("Sign or size not set in numeric variable");
    }
  }
}
void ParserHandler::exitBoolean(propositionParser::BooleanContext *ctx) {
  if (ctx->LPAREN() && ctx->RPAREN() /*&& ctx->CAST_BOOL() == nullptr*/) {
    // std::cout<<__func__<<"()"<<std::endl;
    return;
  }
  if (ctx->boolean().size() == 1) {
    if (ctx->NOT()) {
      // std::cout<<__func__<<"!"<<std::endl;
      Proposition *p = _proposition.top();
      _proposition.pop();
      _proposition.push(makeExpression<PropositionNot>(p));
      return;
    }
    messageError("Unknown unary boolean operator!");
  } else if (ctx->boolean().size() == 2) {
    antlr4::Token *boolop = ctx->booleanop;
    if (boolop != nullptr) {
      // std::cout<<__func__<<"boolop"<<std::endl;
      Proposition *p2 = _proposition.top();
      _proposition.pop();
      Proposition *p1 = _proposition.top();
      _proposition.pop();
      if (boolop->getText() == "&&") {
        _proposition.push(makeExpression<PropositionAnd>(p1, p2));
        return;
      } else if (boolop->getText() == "||") {
        _proposition.push(makeExpression<PropositionOr>(p1, p2));
        return;
      }
      messageError("Unknown boolean operator in expression!");
    }
    if (ctx->EQ() != nullptr) {
      // std::cout<<__func__<<"="<<std::endl;
      Proposition *p2 = _proposition.top();
      _proposition.pop();
      Proposition *p1 = _proposition.top();
      _proposition.pop();
      _proposition.push(makeExpression<PropositionEq>(p1, p2));
      return;
    }
    if (ctx->NEQ() != nullptr) {
      // std::cout<<__func__<<"!="<<std::endl;
      Proposition *p2 = _proposition.top();
      _proposition.pop();
      Proposition *p1 = _proposition.top();
      _proposition.pop();
      _proposition.push(makeExpression<PropositionNeq>(p1, p2));
      return;
    }
    messageError("Unknown binary boolean operator!");
  }

  if (_logicExpressions.size() == 1 /*&& ctx->CAST_BOOL() != nullptr*/) {
    LogicExpression *le = _logicExpressions.top();
    _logicExpressions.pop();
    _proposition.push(new LogicToBool(le));
    return;
    messageError("Unknown unary logic operator in boolean expression!");
  } else if (ctx->logic().size() == 2) {
    propositionParser::RelopContext *relop = ctx->relop();
    if (relop != nullptr) {
      // std::cout<<__func__<<"relop"<<std::endl;
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();

      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();

      if (relop->LT() != nullptr) {
        _proposition.push(makeExpression<LogicLess>(le1, le2));
        return;
      }
      if (relop->LE() != nullptr) {
        _proposition.push(makeExpression<LogicLessEq>(le1, le2));
        return;
      }
      if (relop->GT() != nullptr) {
        _proposition.push(makeExpression<LogicGreater>(le1, le2));
        return;
      }
      if (relop->GE() != nullptr) {
        _proposition.push(makeExpression<LogicGreaterEq>(le1, le2));
        return;
      }
      messageError("Unknown relational operator!");
    }
    if (ctx->EQ() != nullptr) {
      // std::cout<<__func__<<"="<<std::endl;
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();
      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();
      _proposition.push(makeExpression<LogicEq>(le1, le2));
      return;
    }
    if (ctx->NEQ() != nullptr) {
      // std::cout<<__func__<<"!="<<std::endl;
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();
      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();
      _proposition.push(makeExpression<LogicNeq>(le1, le2));
      return;
    }
    messageError("Unknown binary logic operator!");
  }

  if (_numericExpressions.size() == 1 /*&& ctx->CAST_BOOL() != nullptr*/) {
    NumericExpression *ne = _numericExpressions.top();
    _numericExpressions.pop();
    _proposition.push(new NumericToBool(ne));
    return;
  } else if (ctx->numeric().size() == 2) {
    propositionParser::RelopContext *relop = ctx->relop();
    if (relop != nullptr) {
      // std::cout<<__func__<<"relop"<<std::endl;
      NumericExpression *ne2 = _numericExpressions.top();
      _numericExpressions.pop();

      NumericExpression *ne1 = _numericExpressions.top();
      _numericExpressions.pop();

      if (relop->LT() != nullptr) {
        _proposition.push(makeExpression<NumericLess>(ne1, ne2));
        return;
      }
      if (relop->LE() != nullptr) {
        _proposition.push(makeExpression<NumericLessEq>(ne1, ne2));
        return;
      }
      if (relop->GT() != nullptr) {
        _proposition.push(makeExpression<NumericGreater>(ne1, ne2));
        return;
      }
      if (relop->GE() != nullptr) {
        _proposition.push(makeExpression<NumericGreaterEq>(ne1, ne2));
        return;
      }
      messageError("Unknown relational operator!");
    }
    if (ctx->EQ() != nullptr) {
      // std::cout<<__func__<<"="<<std::endl;
      NumericExpression *le2 = _numericExpressions.top();
      _numericExpressions.pop();
      NumericExpression *le1 = _numericExpressions.top();
      _numericExpressions.pop();
      _proposition.push(makeExpression<NumericEq>(le1, le2));
      return;
    }
    if (ctx->NEQ() != nullptr) {
      // std::cout<<__func__<<"!="<<std::endl;
      NumericExpression *le2 = _numericExpressions.top();
      _numericExpressions.pop();
      NumericExpression *le1 = _numericExpressions.top();
      _numericExpressions.pop();
      _proposition.push(makeExpression<NumericNeq>(le1, le2));
      return;
    }
    messageError("Unknown binary numeric operator!");
  }
}
void ParserHandler::exitLogic(propositionParser::LogicContext *ctx) {
  // std::cout<<__func__<<std::endl;
  // TODO
  /*
   */

  if (ctx->LPAREN() && ctx->RPAREN()) {
    return;
  }

  if (ctx->logic().size() == 1) {
    if (ctx->NEG() != nullptr) {
      LogicExpression *le_r = makeExpression<LogicNot>(_logicExpressions.top());
      _logicExpressions.pop();
      _logicExpressions.push(le_r);
      return;
    }

    messageError("Unknown unary logic operator in logic expression!");

  } else if (ctx->logic().size() == 2) {
    antlr4::Token *logop = ctx->logop;

    if (logop != nullptr) {
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();

      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();

      auto conversionResult = applyCStandardConversion(
          std::make_pair(le1->getType(), le1->getSize()),
          std::make_pair(le2->getType(), le2->getSize()));

      if (logop->getText() == "&") {
        LogicExpression *le_r = makeExpression<LogicBAnd>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      if (logop->getText() == "|") {
        LogicExpression *le_r = makeExpression<LogicBOr>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      if (logop->getText() == "^") {
        LogicExpression *le_r = makeExpression<LogicBXor>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      if (logop->getText() == "<<") {
        LogicExpression *le_r = makeExpression<LogicLShift>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      if (logop->getText() == ">>") {
        LogicExpression *le_r = makeExpression<LogicRShift>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }

      messageError("Unknown binary logic operator in logic expression!");
    }

    antlr4::Token *artop = ctx->artop;

    if (artop != nullptr) {
      LogicExpression *le2 = _logicExpressions.top();
      _logicExpressions.pop();

      LogicExpression *le1 = _logicExpressions.top();
      _logicExpressions.pop();

      auto conversionResult = applyCStandardConversion(
          std::make_pair(le1->getType(), le1->getSize()),
          std::make_pair(le2->getType(), le2->getSize()));

      if (artop->getText() == "*") {
        LogicExpression *le_r = makeExpression<LogicMul>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      if (artop->getText() == "/") {
        LogicExpression *le_r = makeExpression<LogicDiv>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      if (artop->getText() == "-") {
        LogicExpression *le_r = makeExpression<LogicSub>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      if (artop->getText() == "+") {
        LogicExpression *le_r = makeExpression<LogicSum>(le1, le2);
        le_r->setParams(conversionResult.first, conversionResult.second);
        _logicExpressions.push(le_r);
        return;
      }
      messageError("Unknown binary arithmetic operator in logic expression!");
    }
  }
}
void ParserHandler::exitNumeric(propositionParser::NumericContext *ctx) {
  // std::cout<<__func__<<std::endl;

  if (ctx->LPAREN() && ctx->RPAREN() /*&& ctx->CAST_NUMERIC() == nullptr*/) {
    return;
  }

  if (_logicExpressions.size() == 1 /*&& ctx->CAST_NUMERIC() != nullptr*/) {
    LogicExpression *le = _logicExpressions.top();
    _logicExpressions.pop();
    _numericExpressions.push(new LogicToNumeric(le, VarType::Numeric, 32));
    return;
  }

  if (ctx->numeric().size() == 1) {
    messageError("Unknown unary numeric operator in logic expression!");
  } else if (ctx->numeric().size() == 2) {
    antlr4::Token *artop = ctx->artop;

    if (artop != nullptr) {
      NumericExpression *ne2 = _numericExpressions.top();
      _numericExpressions.pop();

      NumericExpression *ne1 = _numericExpressions.top();
      _numericExpressions.pop();

      auto conversionResult = applyCStandardConversion(
          std::make_pair(ne1->getType(), ne1->getSize()),
          std::make_pair(ne2->getType(), ne2->getSize()));

      if (artop->getText() == "*") {
        NumericExpression *ne_r = makeExpression<NumericMul>(ne1, ne2);
        ne_r->setParams(conversionResult.first, conversionResult.second);
        _numericExpressions.push(ne_r);
        return;
      }
      if (artop->getText() == "/") {
        NumericExpression *ne_r = makeExpression<NumericDiv>(ne1, ne2);
        ne_r->setParams(conversionResult.first, conversionResult.second);
        _numericExpressions.push(ne_r);
        return;
      }
      if (artop->getText() == "-") {
        NumericExpression *ne_r = makeExpression<NumericSub>(ne1, ne2);
        ne_r->setParams(conversionResult.first, conversionResult.second);
        _numericExpressions.push(ne_r);
        return;
      }
      if (artop->getText() == "+") {
        NumericExpression *ne_r = makeExpression<NumericSum>(ne1, ne2);
        ne_r->setParams(conversionResult.first, conversionResult.second);
        _numericExpressions.push(ne_r);
        return;
      }
      messageError("Unknown binary arithmetic operator in numeric expression!");
    }
  }
}

void ParserHandler::visitErrorNode(__attribute__((unused))
                                   antlr4::tree::ErrorNode *node) {
  messageError("Antlr parse error in "+ _location);
}

Proposition *ParserHandler::getProposition() {
  if (_proposition.size() != 1)
    return nullptr;

  Proposition *ret = _proposition.top();
  _proposition.pop();

  return ret;
}
} // namespace oden
