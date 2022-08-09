#include "oden/classes/classes.hh"
#include "oden/odenUtils/propositionUtils.hh"
#include "parserUtils.hh"
#include "temporalParserHandler.hh"

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace oden {

void TemporalParserHandler::visitErrorNode(__attribute__((unused))
                                           antlr4::tree::ErrorNode *node) {
  messageError("Antlr parse error");
}

std::unordered_map<std::string, Proposition *>
TemporalParserHandler::getPropositions() {
  return _phToProp;
}

void TemporalParserHandler::exitImplication(
    temporalParser::ImplicationContext *ctx) {
  if (ctx->tformula().size() == 2 && ctx->IMPL() != nullptr) {
    std::string newFormula = " -> " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    antecedent = _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 2 && ctx->IMPL2() != nullptr) {
    std::string newFormula = " => " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    antecedent = _subFormulas.top();
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
    antecedent = "{" + _subFormulas.top() + "}";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->sere() != nullptr &&
      ctx->LGPAREN() != nullptr && ctx->LCPAREN() != nullptr &&
      ctx->RCPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
      ctx->IMPL2() != nullptr) {

    std::string newFormula = "[]=>" + _subFormulas.top();
    _subFormulas.pop();
    newFormula = "{" + _subFormulas.top() + "}" + newFormula;
    antecedent = "{" + _subFormulas.top() + "}";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->tformula().size() == 1 && ctx->sere() != nullptr &&
      ctx->LGPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
      ctx->SEREIMPL1() != nullptr) {

    std::string newFormula = "|->" + _subFormulas.top();
    _subFormulas.pop();
    newFormula = "{" + _subFormulas.top() + "}" + newFormula;
    antecedent = "{" + _subFormulas.top() + "}";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->sere() != nullptr &&
      ctx->LGPAREN() != nullptr && ctx->RGPAREN() != nullptr &&
      ctx->SEREIMPL2() != nullptr) {

    std::string newFormula = "|=>" + _subFormulas.top();
    _subFormulas.pop();
    newFormula = "{" + _subFormulas.top() + "}" + newFormula;
    antecedent = "{" + _subFormulas.top() + "}";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
}
void TemporalParserHandler::exitTformula(temporalParser::TformulaContext *ctx) {
  if (ctx->TIMER() != nullptr) {
    _proposition.push(parsePropositionAlreadyTyped(ctx->boolean()->getText()));
    std::stringstream ss;
    ss << "("
       << "start" << timerN << " & ("
       << "(!stop" << timerN << " & "
       << "!p" << placeholdN << ")"
       << " U "
       << "p" << placeholdN << "))";

    _timers.emplace_back(timerN++,
                         std::stoull(ctx->NUMERIC()->getText(), nullptr, 10));
    _subFormulas.push(ss.str());
    _phToProp["p" + std::to_string(placeholdN++)] = _proposition.top();
    return;
  }

  if (ctx->boolean() != nullptr) {
    _proposition.push(parsePropositionAlreadyTyped(ctx->boolean()->getText()));

    if (!oden::isConstant(*_proposition.top())) {
      _subFormulas.push("p" + std::to_string(placeholdN));
      _phToProp["p" + std::to_string(placeholdN)] = _proposition.top();
      placeholdN++;
    } else {
      _subFormulas.push("c" + std::to_string(constantsN++));
    }
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

  if (ctx->tformula().size() == 1 && ctx->NEXT() != nullptr) {
    std::string newFormula = "";
    if (ctx->LCPAREN() != nullptr && ctx->RCPAREN() != nullptr) {
      newFormula = "X[" + ctx->NUMERIC()->getText() + "]" + _subFormulas.top();
    } else {
      newFormula = "X" + _subFormulas.top();
    }
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
  if (ctx->tformula().size() == 2 && ctx->RELEASE() != nullptr) {
    std::string newFormula = _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + " R " + newFormula;
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
}
void TemporalParserHandler::exitSere(temporalParser::SereContext *ctx) {

  if (ctx->TIMER() != nullptr) {
    _proposition.push(parsePropositionAlreadyTyped(ctx->boolean()->getText()));
    std::stringstream ss;
    ss << "("
       << "start" << timerN << " & ("
       << "(!stop" << timerN << " & "
       << "!p" << placeholdN << ")"
       << "[*];"
       << "p" << placeholdN << "))";

    _timers.emplace_back(
        timerN++, std::stoull(ctx->NUMERIC()[0]->getText(), nullptr, 10));
    _subFormulas.push(ss.str());
    _phToProp["p" + std::to_string(placeholdN++)] = _proposition.top();
    return;
  }

  if (ctx->boolean() != nullptr) {
    _proposition.push(parsePropositionAlreadyTyped(ctx->boolean()->getText()));

    if (!oden::isConstant(*_proposition.top())) {
      _subFormulas.push("p" + std::to_string(placeholdN));
      _phToProp["p" + std::to_string(placeholdN)] = _proposition.top();
      placeholdN++;
    } else {
      _subFormulas.push("c" + std::to_string(constantsN));
      _phToProp["c" + std::to_string(constantsN)] = _proposition.top();
      constantsN++;
    }
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
  if (ctx->sere().size() == 2 && ctx->BAND() != nullptr) {
    std::string newFormula = " & " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
  if (ctx->sere().size() == 2 && ctx->BOR() != nullptr) {
    std::string newFormula = " | " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
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

  if (ctx->DELAY() != nullptr) {
    std::string newFormula;
    std::string right = _subFormulas.top();
    _subFormulas.pop();
    ;
    std::string left;
    if (ctx->sere().size() == 2) {
      left = _subFormulas.top();
      _subFormulas.pop();
    }

    if (ctx->LCPAREN() != nullptr && ctx->RCPAREN() != nullptr &&
        ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 2) {
      newFormula = left + " ##[" + ctx->NUMERIC()[0]->getText() + ".." +
                   ctx->NUMERIC()[1]->getText() + "] " + right;
      _subFormulas.push(newFormula);
    } else if (ctx->LCPAREN() != nullptr && ctx->RCPAREN() != nullptr &&
               ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 1) {
      newFormula =
          left + " ##[" + ctx->NUMERIC()[0]->getText() + ".." + "] " + right;
      _subFormulas.push(newFormula);
    } else if (ctx->LCPAREN() != nullptr && ctx->RCPAREN() != nullptr &&
               ctx->NUMERIC().size() == 1) {
      newFormula = left + " ##[" + ctx->NUMERIC()[0]->getText() + "] " + right;
      _subFormulas.push(newFormula);
    } else {
      newFormula = left + " ##" + ctx->NUMERIC()[0]->getText() + " " + right;
      _subFormulas.push(newFormula);
    }
    return;
  }

  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->ASS() != nullptr && !ctx->NUMERIC().empty() &&
      ctx->RCPAREN() != nullptr) {
    if (ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 1) {
      std::string newFormula =
          _subFormulas.top() + "[=" + ctx->NUMERIC()[0]->getText() + ".." + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    } else if (ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 2) {
      std::string newFormula = _subFormulas.top() +
                               "[=" + ctx->NUMERIC()[0]->getText() + ".." +
                               ctx->NUMERIC()[1]->getText() + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    } else {
      std::string newFormula =
          _subFormulas.top() + "[=" + ctx->NUMERIC()[0]->getText() + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    }
    return;
  }

  if (ctx->sere().size() == 1 && ctx->LCPAREN() != nullptr &&
      ctx->IMPL() != nullptr && !ctx->NUMERIC().empty() &&
      ctx->RCPAREN() != nullptr) {
    if (ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 1) {
      std::string newFormula = _subFormulas.top() + "[->" +
                               ctx->NUMERIC()[0]->getText() + ".." + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    } else if (ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 2) {
      std::string newFormula = _subFormulas.top() + "[->" +
                               ctx->NUMERIC()[0]->getText() + ".." +
                               ctx->NUMERIC()[1]->getText() + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    } else {
      std::string newFormula =
          _subFormulas.top() + "[->" + ctx->NUMERIC()[0]->getText() + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    }
    return;
  }

  if (ctx->LCPAREN() != nullptr && ctx->TIMES() != nullptr &&
      ctx->RCPAREN() != nullptr) {
    if (ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 2) {
      std::string newFormula = _subFormulas.top() + "[*" +
                               ctx->NUMERIC()[0]->getText() + ".." +
                               ctx->NUMERIC()[1]->getText() + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    } else if (ctx->DOTS() != nullptr && ctx->NUMERIC().size() == 1) {
      std::string newFormula =
          _subFormulas.top() + "[*" + ctx->NUMERIC()[0]->getText() + ".." + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    } else if (ctx->NUMERIC().size() == 1) {
      std::string newFormula =
          _subFormulas.top() + "[*" + ctx->NUMERIC()[0]->getText() + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    } else {
      std::string newFormula = _subFormulas.top() + "[*" + "]";
      _subFormulas.pop();
      _subFormulas.push(newFormula);
    }
    return;
  }

  if (ctx->sere().size() == 1 && ctx->LPAREN() != nullptr &&
      ctx->RPAREN() != nullptr) {
    std::string newFormula = "(" + _subFormulas.top() + ")";
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->sere().size() == 2 && ctx->COL() != nullptr) {
    std::string newFormula = " : " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->sere().size() == 2 && ctx->SCOL() != nullptr) {
    std::string newFormula = " ; " + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
}
std::string TemporalParserHandler::getSFormula() { return _subFormulas.top(); }
std::string TemporalParserHandler::getAntecedent() { return antecedent; }
std::vector<std::pair<size_t, size_t>> TemporalParserHandler::getTimers() {
  return _timers;
}

void TemporalParserHandler::printAllPropositions() {
  for (auto p : _phToProp) {
    std::cout << p.first << ":" << oden::prop2String(*p.second) << "\n";
  }
}
} // namespace oden
