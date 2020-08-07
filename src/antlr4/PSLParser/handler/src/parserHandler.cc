#include "temporalParserHandler.hh"

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace oden {

TemporalParserHandler::TemporalParserHandler(const EnumMap &enums,
                                             std::string location)
    : _abort(false), _proposition(), _logicExpressions(), _numericExpressions(),
      _location(location) {
  for (const auto &name_values : enums) {
    std::vector<enumItem> tmpEnumValues;
    for (const auto &val : name_values.second) {
      tmpEnumValues.push_back(enumItem(val.first, val.second));
    }
    _enums.insert({{name_values.first, tmpEnumValues}});
  }
}

/*
void TemporalParserHandler::enterFile(__attribute__((unused))
                              temporalParser::FileContext *ctx) {
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
*/

void TemporalParserHandler::enterBooleanConstant(
    temporalParser::BooleanConstantContext *ctx) {
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
void TemporalParserHandler::enterNamedLogicConst(
    temporalParser::NamedLogicConstContext *ctx) {
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

void TemporalParserHandler::enterEnumVariable(
    temporalParser::EnumVariableContext *ctx) {
  temporalParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  _logicExpressions.push(
      new EnumVariable(varName, _enums.at(ctx->enumName()->getText())));
}
void TemporalParserHandler::enterLogicConstant(
    temporalParser::LogicConstantContext *ctx) {
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
void TemporalParserHandler::enterNumericConstant(
    temporalParser::NumericConstantContext *ctx) {
  if (ctx->NUMERIC() != nullptr) {
    Numeric value = std::stod(ctx->getText());
    auto *c = new NumericConstant(value, VarType::Numeric, 64);
    _numericExpressions.push(c);
    return;
  }
}

/*
void
TemporalParserHandler::enterStringConstant(temporalParser::StringConstantContext
*ctx){
if (ctx->STRING() != nullptr) {
auto *c = new StringConstant(ctx->getText());
_numericExpressions.push(c);
return;
}
}
*/

void TemporalParserHandler::enterBooleanVariable(
    temporalParser::BooleanVariableContext *ctx) {
  temporalParser::VariableContext *tNode = ctx->variable();
  std::string varName = std::string(tNode->getText());
  // //std::cout << __func__ << ": " << varName << std::endl;

  Proposition *n = new BooleanVariable(varName);

  _proposition.push(n);
}
void TemporalParserHandler::enterLogicVariable(
    temporalParser::LogicVariableContext *ctx) {
  temporalParser::VariableContext *tNode = ctx->variable();
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
void TemporalParserHandler::enterNumericVariable(
    temporalParser::NumericVariableContext *ctx) {
  temporalParser::VariableContext *tNode = ctx->variable();
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
void TemporalParserHandler::exitBoolean(temporalParser::BooleanContext *ctx) {
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
    temporalParser::RelopContext *relop = ctx->relop();
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
    temporalParser::RelopContext *relop = ctx->relop();
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
void TemporalParserHandler::exitLogic(temporalParser::LogicContext *ctx) {
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
void TemporalParserHandler::exitNumeric(temporalParser::NumericContext *ctx) {
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

void TemporalParserHandler::visitErrorNode(__attribute__((unused))
                                           antlr4::tree::ErrorNode *node) {
  messageError("Antlr parse error in " + _location);
}

std::unordered_map<std::string, Proposition *>
TemporalParserHandler::getPropositions() {
  return _phToProp;
}

void TemporalParserHandler::exitTformula(temporalParser::TformulaContext *ctx) {
  if (ctx->boolean() != nullptr) {
    _subFormulas.push("p" + std::to_string(placeholdN));
    _phToProp["p" + std::to_string(placeholdN++)] = _proposition.top();
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->AND() != nullptr) {
    std::string newFormula = " && " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->OR() != nullptr) {
    std::string newFormula = " || " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->XOR() != nullptr) {
    std::string newFormula = " xor " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->IMPL() != nullptr) {
    std::string newFormula = " -> " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->IFF() != nullptr) {
    std::string newFormula = " <-> " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->sere() != nullptr &&
      ctx->LGPAREN() != nullptr && ctx->LCPAREN() != nullptr &&
      ctx->RCPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
      ctx->IMPL() != nullptr) {

    std::string newFormula = "[]->" + _subFormulas.top();
    _subFormulas.pop();
    newFormula = "{" + _subFormulas.top() + "}" + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->sere() != nullptr &&
      ctx->LGPAREN() != nullptr && ctx->LCPAREN() != nullptr &&
      ctx->RCPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
      ctx->IMPL2() != nullptr) {

    std::string newFormula = "[]->" + _subFormulas.top();
    _subFormulas.pop();
    newFormula = "{" + _subFormulas.top() + "}" + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->sere() != nullptr &&
      ctx->LGPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
      ctx->BIND1() != nullptr) {

    std::string newFormula = "<>->" + _subFormulas.top();
    _subFormulas.pop();
    newFormula = "{" + _subFormulas.top() + "}" + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->sere() != nullptr &&
      ctx->LGPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
      ctx->BIND2() != nullptr) {

    std::string newFormula = "<>=>" + _subFormulas.top();
    _subFormulas.pop();
    newFormula = "{" + _subFormulas.top() + "}" + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->NEXT() != nullptr &&
      ctx->LCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->LCPAREN() != nullptr &&
      ctx->NOT() != nullptr) {

    std::string newFormula = "X[" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "!]" +
                             _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->NEXT() != nullptr &&
      ctx->LCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->LCPAREN() != nullptr) {

    std::string newFormula = "X[" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]" +
                             _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->NEXT() != nullptr) {
    std::string newFormula = "X" + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 1 && ctx->ALWAYS() != nullptr &&
      ctx->LCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->LCPAREN() != nullptr &&
      ctx->NOT() != nullptr) {

    std::string newFormula = "G[" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "!]" +
                             _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->ALWAYS() != nullptr &&
      ctx->LCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->LCPAREN() != nullptr) {

    std::string newFormula = "G[" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]" +
                             _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 1 && ctx->EVENTUALLY() != nullptr &&
      ctx->LCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->LCPAREN() != nullptr &&
      ctx->NOT() != nullptr) {

    std::string newFormula = "F[" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "!]" +
                             _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->EVENTUALLY() != nullptr &&
      ctx->LCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->LCPAREN() != nullptr) {

    std::string newFormula = "F[" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]" +
                             _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 2 && ctx->UNTIL() != nullptr) {
    std::string newFormula = _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + " U " + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->WUNTIL() != nullptr) {
    std::string newFormula = _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + " W " + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->RELEASE() != nullptr) {
    std::string newFormula = _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + " R " + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->SRELEASE() != nullptr) {
    std::string newFormula = _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + " M " + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->LPAREN() != nullptr &&
      ctx->RPAREN() != nullptr) {
    std::string newFormula = "(" + _subFormulas.top() + ")";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->sere() != nullptr && ctx->LGPAREN() != nullptr &&
      ctx->RGPAREN() != nullptr && ctx->NOT() != nullptr) {
    std::string newFormula = "{" + _subFormulas.top() + "}!";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere() != nullptr && ctx->LGPAREN() != nullptr &&
      ctx->RGPAREN() != nullptr) {
    std::string newFormula = "{" + _subFormulas.top() + "}";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 1 && ctx->NOT() != nullptr) {
    std::string newFormula = "!" + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 1 && ctx->ALWAYS() != nullptr) {
    std::string newFormula = "G" + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 1 && ctx->EVENTUALLY() != nullptr) {
    std::string newFormula = "F" + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
}
void TemporalParserHandler::exitSere(temporalParser::SereContext *ctx) {

  if (ctx->boolean() != nullptr) {
    _subFormulas.push("p" + std::to_string(placeholdN));
    _phToProp["p" + std::to_string(placeholdN++)] = _proposition.top();
    return;
  }

  if (ctx->sere().size() == 2 && ctx->AND() != nullptr) {
    std::string newFormula = " && " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 2 && ctx->OR() != nullptr) {
    std::string newFormula = " || " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }


  if (ctx->sere().size() == 2 && ctx->LCPAREN() != nullptr &&
      ctx->RCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->DSYM1() != nullptr) {
    std::string newFormula =
        " ##[" + ctx->NUMERIC()[0]->getText() + ".." + ctx->NUMERIC()[1]->getText()+"]" + _subFormulas.top();
    _subFormulas.pop();
    newFormula= _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->RCPAREN() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->DSYM1() != nullptr) {
    std::string newFormula =
        " ##[" + ctx->NUMERIC()[0]->getText() + ".." + ctx->NUMERIC()[1]->getText()+"]" + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->NUMERIC().size() == 1 &&
      ctx->DSYM1() != nullptr) {
    std::string newFormula =
        " ##" + ctx->NUMERIC()[0]->getText() + " " + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 2 && ctx->NUMERIC().size() == 1 &&
      ctx->DSYM1() != nullptr) {
    std::string newFormula =
        " ##" + ctx->NUMERIC()[0]->getText() + " " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->TIMES() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->RCPAREN() != nullptr &&
      ctx->COL() != nullptr) {
    std::string newFormula = _subFormulas.top() + "[:*" +
                             ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->PLUS() != nullptr && ctx->RCPAREN() != nullptr &&
      ctx->COL() != nullptr) {
    std::string newFormula = _subFormulas.top() + "[:+]";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->PLUS() != nullptr && ctx->RCPAREN() != nullptr) {
    std::string newFormula = _subFormulas.top() + "[+]";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->TIMES() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->RCPAREN() != nullptr) {
    std::string newFormula = _subFormulas.top() + "[*" +
                             ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->ASS() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->RCPAREN() != nullptr) {
    std::string newFormula = _subFormulas.top() +
                             "[=" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->IMPL() != nullptr && ctx->NUMERIC().size() == 2 &&
      ctx->DOTS() != nullptr && ctx->RCPAREN() != nullptr) {
    std::string newFormula = _subFormulas.top() + "[->" +
                             ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->LCPAREN() != nullptr && ctx->TIMES() != nullptr &&
      ctx->NUMERIC().size() == 2 && ctx->DOTS() != nullptr &&
      ctx->RCPAREN() != nullptr) {
    std::string newFormula = "[*" + ctx->NUMERIC()[0]->getText() + ".." +
                             ctx->NUMERIC()[1]->getText() + "]";
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->LCPAREN() != nullptr && ctx->PLUS() != nullptr &&
      ctx->RCPAREN() != nullptr) {
    _subFormulas.push("[+]");
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LPAREN() != nullptr &&
      ctx->RPAREN() != nullptr && ctx->FIRST_MATCH() != nullptr) {
    std::string newFormula = "first_match(" + _subFormulas.top() + ")";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->RCPAREN() != nullptr) {
    std::string newFormula = "(" + _subFormulas.top() + ")";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->sere().size() == 2 && ctx->COL() != nullptr ) {
    std::string newFormula = " : " + _subFormulas.top();
    _subFormulas.pop();
    newFormula= _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->sere().size() == 2 && ctx->SCOL() != nullptr ) {
    std::string newFormula = " ; " + _subFormulas.top();
    _subFormulas.pop();
    newFormula= _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

}
} // namespace oden
