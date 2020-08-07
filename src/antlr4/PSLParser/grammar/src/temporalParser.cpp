
// Generated from temporal.g4 by ANTLR 4.7.2


#include "temporalListener.h"

#include "temporalParser.h"


using namespace antlrcpp;
using namespace antlr4;

temporalParser::temporalParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

temporalParser::~temporalParser() {
  delete _interpreter;
}

std::string temporalParser::getGrammarFileName() const {
  return "temporal.g4";
}

const std::vector<std::string>& temporalParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& temporalParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FormulaContext ------------------------------------------------------------------

temporalParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::TformulaContext* temporalParser::FormulaContext::tformula() {
  return getRuleContext<temporalParser::TformulaContext>(0);
}

tree::TerminalNode* temporalParser::FormulaContext::EOF() {
  return getToken(temporalParser::EOF, 0);
}


size_t temporalParser::FormulaContext::getRuleIndex() const {
  return temporalParser::RuleFormula;
}

void temporalParser::FormulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula(this);
}

void temporalParser::FormulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula(this);
}

temporalParser::FormulaContext* temporalParser::formula() {
  FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, getState());
  enterRule(_localctx, 0, temporalParser::RuleFormula);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    tformula(0);
    setState(43);
    match(temporalParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SereContext ------------------------------------------------------------------

temporalParser::SereContext::SereContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::BooleanContext* temporalParser::SereContext::boolean() {
  return getRuleContext<temporalParser::BooleanContext>(0);
}

tree::TerminalNode* temporalParser::SereContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

std::vector<temporalParser::SereContext *> temporalParser::SereContext::sere() {
  return getRuleContexts<temporalParser::SereContext>();
}

temporalParser::SereContext* temporalParser::SereContext::sere(size_t i) {
  return getRuleContext<temporalParser::SereContext>(i);
}

tree::TerminalNode* temporalParser::SereContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::LGPAREN() {
  return getToken(temporalParser::LGPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::RGPAREN() {
  return getToken(temporalParser::RGPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::LCPAREN() {
  return getToken(temporalParser::LCPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::TIMES() {
  return getToken(temporalParser::TIMES, 0);
}

std::vector<tree::TerminalNode *> temporalParser::SereContext::NUMERIC() {
  return getTokens(temporalParser::NUMERIC);
}

tree::TerminalNode* temporalParser::SereContext::NUMERIC(size_t i) {
  return getToken(temporalParser::NUMERIC, i);
}

tree::TerminalNode* temporalParser::SereContext::DOTS() {
  return getToken(temporalParser::DOTS, 0);
}

tree::TerminalNode* temporalParser::SereContext::RCPAREN() {
  return getToken(temporalParser::RCPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::PLUS() {
  return getToken(temporalParser::PLUS, 0);
}

tree::TerminalNode* temporalParser::SereContext::DSYM1() {
  return getToken(temporalParser::DSYM1, 0);
}

tree::TerminalNode* temporalParser::SereContext::FIRST_MATCH() {
  return getToken(temporalParser::FIRST_MATCH, 0);
}

tree::TerminalNode* temporalParser::SereContext::AND() {
  return getToken(temporalParser::AND, 0);
}

tree::TerminalNode* temporalParser::SereContext::OR() {
  return getToken(temporalParser::OR, 0);
}

tree::TerminalNode* temporalParser::SereContext::COL() {
  return getToken(temporalParser::COL, 0);
}

tree::TerminalNode* temporalParser::SereContext::SCOL() {
  return getToken(temporalParser::SCOL, 0);
}

tree::TerminalNode* temporalParser::SereContext::ASS() {
  return getToken(temporalParser::ASS, 0);
}

tree::TerminalNode* temporalParser::SereContext::IMPL() {
  return getToken(temporalParser::IMPL, 0);
}


size_t temporalParser::SereContext::getRuleIndex() const {
  return temporalParser::RuleSere;
}

void temporalParser::SereContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSere(this);
}

void temporalParser::SereContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSere(this);
}


temporalParser::SereContext* temporalParser::sere() {
   return sere(0);
}

temporalParser::SereContext* temporalParser::sere(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  temporalParser::SereContext *_localctx = _tracker.createInstance<SereContext>(_ctx, parentState);
  temporalParser::SereContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, temporalParser::RuleSere, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(46);
      boolean(0);
      break;
    }

    case 2: {
      setState(47);
      match(temporalParser::LPAREN);
      setState(48);
      sere(0);
      setState(49);
      match(temporalParser::RPAREN);
      break;
    }

    case 3: {
      setState(51);
      match(temporalParser::LGPAREN);
      setState(52);
      sere(0);
      setState(53);
      match(temporalParser::RGPAREN);
      break;
    }

    case 4: {
      setState(55);
      match(temporalParser::LCPAREN);
      setState(56);
      match(temporalParser::TIMES);
      setState(57);
      match(temporalParser::NUMERIC);
      setState(58);
      match(temporalParser::DOTS);
      setState(59);
      match(temporalParser::NUMERIC);
      setState(60);
      match(temporalParser::RCPAREN);
      break;
    }

    case 5: {
      setState(61);
      match(temporalParser::LCPAREN);
      setState(62);
      match(temporalParser::PLUS);
      setState(63);
      match(temporalParser::RCPAREN);
      break;
    }

    case 6: {
      setState(64);
      match(temporalParser::DSYM1);
      setState(65);
      match(temporalParser::NUMERIC);
      setState(66);
      sere(7);
      break;
    }

    case 7: {
      setState(67);
      match(temporalParser::DSYM1);
      setState(68);
      match(temporalParser::LCPAREN);
      setState(69);
      match(temporalParser::NUMERIC);
      setState(70);
      match(temporalParser::DOTS);
      setState(71);
      match(temporalParser::NUMERIC);
      setState(72);
      match(temporalParser::RCPAREN);
      setState(73);
      sere(6);
      break;
    }

    case 8: {
      setState(74);
      match(temporalParser::FIRST_MATCH);
      setState(75);
      match(temporalParser::LPAREN);
      setState(76);
      sere(0);
      setState(77);
      match(temporalParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(145);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(143);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(81);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(82);
          match(temporalParser::AND);
          setState(83);
          sere(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(84);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(85);
          match(temporalParser::OR);
          setState(86);
          sere(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(87);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(88);
          match(temporalParser::DSYM1);
          setState(89);
          match(temporalParser::NUMERIC);
          setState(90);
          sere(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(91);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(92);
          match(temporalParser::DSYM1);
          setState(93);
          match(temporalParser::LCPAREN);
          setState(94);
          match(temporalParser::NUMERIC);
          setState(95);
          match(temporalParser::DOTS);
          setState(96);
          match(temporalParser::NUMERIC);
          setState(97);
          match(temporalParser::RCPAREN);
          setState(98);
          sere(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(99);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(100);
          match(temporalParser::COL);
          setState(101);
          sere(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(102);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(103);
          match(temporalParser::SCOL);
          setState(104);
          sere(3);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(105);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(106);
          match(temporalParser::LCPAREN);
          setState(107);
          match(temporalParser::TIMES);
          setState(108);
          match(temporalParser::NUMERIC);
          setState(109);
          match(temporalParser::DOTS);
          setState(110);
          match(temporalParser::NUMERIC);
          setState(111);
          match(temporalParser::RCPAREN);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(112);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(113);
          match(temporalParser::LCPAREN);
          setState(114);
          match(temporalParser::PLUS);
          setState(115);
          match(temporalParser::RCPAREN);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(116);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(117);
          match(temporalParser::LCPAREN);
          setState(118);
          match(temporalParser::COL);
          setState(119);
          match(temporalParser::TIMES);
          setState(120);
          match(temporalParser::NUMERIC);
          setState(121);
          match(temporalParser::DOTS);
          setState(122);
          match(temporalParser::NUMERIC);
          setState(123);
          match(temporalParser::RCPAREN);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(124);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(125);
          match(temporalParser::LCPAREN);
          setState(126);
          match(temporalParser::COL);
          setState(127);
          match(temporalParser::PLUS);
          setState(128);
          match(temporalParser::RCPAREN);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(129);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(130);
          match(temporalParser::LCPAREN);
          setState(131);
          match(temporalParser::ASS);
          setState(132);
          match(temporalParser::NUMERIC);
          setState(133);
          match(temporalParser::DOTS);
          setState(134);
          match(temporalParser::NUMERIC);
          setState(135);
          match(temporalParser::RCPAREN);
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(136);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(137);
          match(temporalParser::LCPAREN);
          setState(138);
          match(temporalParser::IMPL);
          setState(139);
          match(temporalParser::NUMERIC);
          setState(140);
          match(temporalParser::DOTS);
          setState(141);
          match(temporalParser::NUMERIC);
          setState(142);
          match(temporalParser::RCPAREN);
          break;
        }

        } 
      }
      setState(147);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TformulaContext ------------------------------------------------------------------

temporalParser::TformulaContext::TformulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::BooleanContext* temporalParser::TformulaContext::boolean() {
  return getRuleContext<temporalParser::BooleanContext>(0);
}

tree::TerminalNode* temporalParser::TformulaContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

std::vector<temporalParser::TformulaContext *> temporalParser::TformulaContext::tformula() {
  return getRuleContexts<temporalParser::TformulaContext>();
}

temporalParser::TformulaContext* temporalParser::TformulaContext::tformula(size_t i) {
  return getRuleContext<temporalParser::TformulaContext>(i);
}

tree::TerminalNode* temporalParser::TformulaContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::LGPAREN() {
  return getToken(temporalParser::LGPAREN, 0);
}

temporalParser::SereContext* temporalParser::TformulaContext::sere() {
  return getRuleContext<temporalParser::SereContext>(0);
}

tree::TerminalNode* temporalParser::TformulaContext::RGPAREN() {
  return getToken(temporalParser::RGPAREN, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::NOT() {
  return getToken(temporalParser::NOT, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::NEXT() {
  return getToken(temporalParser::NEXT, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::LCPAREN() {
  return getToken(temporalParser::LCPAREN, 0);
}

std::vector<tree::TerminalNode *> temporalParser::TformulaContext::NUMERIC() {
  return getTokens(temporalParser::NUMERIC);
}

tree::TerminalNode* temporalParser::TformulaContext::NUMERIC(size_t i) {
  return getToken(temporalParser::NUMERIC, i);
}

tree::TerminalNode* temporalParser::TformulaContext::DOTS() {
  return getToken(temporalParser::DOTS, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::RCPAREN() {
  return getToken(temporalParser::RCPAREN, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::ALWAYS() {
  return getToken(temporalParser::ALWAYS, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::EVENTUALLY() {
  return getToken(temporalParser::EVENTUALLY, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::IMPL() {
  return getToken(temporalParser::IMPL, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::IMPL2() {
  return getToken(temporalParser::IMPL2, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::BIND1() {
  return getToken(temporalParser::BIND1, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::BIND2() {
  return getToken(temporalParser::BIND2, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::UNTIL() {
  return getToken(temporalParser::UNTIL, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::WUNTIL() {
  return getToken(temporalParser::WUNTIL, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::SRELEASE() {
  return getToken(temporalParser::SRELEASE, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::RELEASE() {
  return getToken(temporalParser::RELEASE, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::AND() {
  return getToken(temporalParser::AND, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::OR() {
  return getToken(temporalParser::OR, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::XOR() {
  return getToken(temporalParser::XOR, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::IFF() {
  return getToken(temporalParser::IFF, 0);
}


size_t temporalParser::TformulaContext::getRuleIndex() const {
  return temporalParser::RuleTformula;
}

void temporalParser::TformulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTformula(this);
}

void temporalParser::TformulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTformula(this);
}


temporalParser::TformulaContext* temporalParser::tformula() {
   return tformula(0);
}

temporalParser::TformulaContext* temporalParser::tformula(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  temporalParser::TformulaContext *_localctx = _tracker.createInstance<TformulaContext>(_ctx, parentState);
  temporalParser::TformulaContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, temporalParser::RuleTformula, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(149);
      boolean(0);
      break;
    }

    case 2: {
      setState(150);
      match(temporalParser::LPAREN);
      setState(151);
      tformula(0);
      setState(152);
      match(temporalParser::RPAREN);
      break;
    }

    case 3: {
      setState(154);
      match(temporalParser::LGPAREN);
      setState(155);
      sere(0);
      setState(156);
      match(temporalParser::RGPAREN);
      break;
    }

    case 4: {
      setState(158);
      match(temporalParser::LGPAREN);
      setState(159);
      sere(0);
      setState(160);
      match(temporalParser::RGPAREN);
      setState(161);
      match(temporalParser::NOT);
      break;
    }

    case 5: {
      setState(163);
      match(temporalParser::NOT);
      setState(164);
      tformula(23);
      break;
    }

    case 6: {
      setState(165);
      match(temporalParser::NEXT);
      setState(166);
      tformula(22);
      break;
    }

    case 7: {
      setState(167);
      match(temporalParser::NEXT);
      setState(168);
      match(temporalParser::LCPAREN);
      setState(169);
      match(temporalParser::NUMERIC);
      setState(170);
      match(temporalParser::DOTS);
      setState(171);
      match(temporalParser::NUMERIC);
      setState(172);
      match(temporalParser::RCPAREN);
      setState(173);
      tformula(21);
      break;
    }

    case 8: {
      setState(174);
      match(temporalParser::NEXT);
      setState(175);
      match(temporalParser::LCPAREN);
      setState(176);
      match(temporalParser::NUMERIC);
      setState(177);
      match(temporalParser::DOTS);
      setState(178);
      match(temporalParser::NUMERIC);
      setState(179);
      match(temporalParser::NOT);
      setState(180);
      match(temporalParser::RCPAREN);
      setState(181);
      tformula(20);
      break;
    }

    case 9: {
      setState(182);
      match(temporalParser::ALWAYS);
      setState(183);
      tformula(19);
      break;
    }

    case 10: {
      setState(184);
      match(temporalParser::ALWAYS);
      setState(185);
      match(temporalParser::LCPAREN);
      setState(186);
      match(temporalParser::NUMERIC);
      setState(187);
      match(temporalParser::DOTS);
      setState(188);
      match(temporalParser::NUMERIC);
      setState(189);
      match(temporalParser::RCPAREN);
      setState(190);
      tformula(18);
      break;
    }

    case 11: {
      setState(191);
      match(temporalParser::ALWAYS);
      setState(192);
      match(temporalParser::LCPAREN);
      setState(193);
      match(temporalParser::NUMERIC);
      setState(194);
      match(temporalParser::DOTS);
      setState(195);
      match(temporalParser::NUMERIC);
      setState(196);
      match(temporalParser::NOT);
      setState(197);
      match(temporalParser::RCPAREN);
      setState(198);
      tformula(17);
      break;
    }

    case 12: {
      setState(199);
      match(temporalParser::EVENTUALLY);
      setState(200);
      tformula(16);
      break;
    }

    case 13: {
      setState(201);
      match(temporalParser::EVENTUALLY);
      setState(202);
      match(temporalParser::LCPAREN);
      setState(203);
      match(temporalParser::NUMERIC);
      setState(204);
      match(temporalParser::DOTS);
      setState(205);
      match(temporalParser::NUMERIC);
      setState(206);
      match(temporalParser::RCPAREN);
      setState(207);
      tformula(15);
      break;
    }

    case 14: {
      setState(208);
      match(temporalParser::EVENTUALLY);
      setState(209);
      match(temporalParser::LCPAREN);
      setState(210);
      match(temporalParser::NUMERIC);
      setState(211);
      match(temporalParser::DOTS);
      setState(212);
      match(temporalParser::NUMERIC);
      setState(213);
      match(temporalParser::NOT);
      setState(214);
      match(temporalParser::RCPAREN);
      setState(215);
      tformula(14);
      break;
    }

    case 15: {
      setState(216);
      match(temporalParser::LGPAREN);
      setState(217);
      sere(0);
      setState(218);
      match(temporalParser::RGPAREN);
      setState(219);
      match(temporalParser::LCPAREN);
      setState(220);
      match(temporalParser::RCPAREN);
      setState(221);
      match(temporalParser::IMPL);
      setState(222);
      tformula(4);
      break;
    }

    case 16: {
      setState(224);
      match(temporalParser::LGPAREN);
      setState(225);
      sere(0);
      setState(226);
      match(temporalParser::RGPAREN);
      setState(227);
      match(temporalParser::LCPAREN);
      setState(228);
      match(temporalParser::RCPAREN);
      setState(229);
      match(temporalParser::IMPL2);
      setState(230);
      tformula(3);
      break;
    }

    case 17: {
      setState(232);
      match(temporalParser::LGPAREN);
      setState(233);
      sere(0);
      setState(234);
      match(temporalParser::RGPAREN);
      setState(235);
      match(temporalParser::BIND1);
      setState(236);
      tformula(2);
      break;
    }

    case 18: {
      setState(238);
      match(temporalParser::LGPAREN);
      setState(239);
      sere(0);
      setState(240);
      match(temporalParser::RGPAREN);
      setState(241);
      match(temporalParser::BIND2);
      setState(242);
      tformula(1);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(275);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(273);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(246);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(247);
          match(temporalParser::UNTIL);
          setState(248);
          tformula(14);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(249);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(250);
          match(temporalParser::WUNTIL);
          setState(251);
          tformula(13);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(252);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(253);
          match(temporalParser::SRELEASE);
          setState(254);
          tformula(12);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(255);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(256);
          match(temporalParser::RELEASE);
          setState(257);
          tformula(11);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(258);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(259);
          match(temporalParser::AND);
          setState(260);
          tformula(10);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(261);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(262);
          match(temporalParser::OR);
          setState(263);
          tformula(9);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(264);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(265);
          match(temporalParser::XOR);
          setState(266);
          tformula(8);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(267);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(268);
          match(temporalParser::IMPL);
          setState(269);
          tformula(7);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(270);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(271);
          match(temporalParser::IFF);
          setState(272);
          tformula(6);
          break;
        }

        } 
      }
      setState(277);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

temporalParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::BooleanContext::NOT() {
  return getToken(temporalParser::NOT, 0);
}

std::vector<temporalParser::BooleanContext *> temporalParser::BooleanContext::boolean() {
  return getRuleContexts<temporalParser::BooleanContext>();
}

temporalParser::BooleanContext* temporalParser::BooleanContext::boolean(size_t i) {
  return getRuleContext<temporalParser::BooleanContext>(i);
}

std::vector<temporalParser::LogicContext *> temporalParser::BooleanContext::logic() {
  return getRuleContexts<temporalParser::LogicContext>();
}

temporalParser::LogicContext* temporalParser::BooleanContext::logic(size_t i) {
  return getRuleContext<temporalParser::LogicContext>(i);
}

temporalParser::RelopContext* temporalParser::BooleanContext::relop() {
  return getRuleContext<temporalParser::RelopContext>(0);
}

std::vector<temporalParser::NumericContext *> temporalParser::BooleanContext::numeric() {
  return getRuleContexts<temporalParser::NumericContext>();
}

temporalParser::NumericContext* temporalParser::BooleanContext::numeric(size_t i) {
  return getRuleContext<temporalParser::NumericContext>(i);
}

tree::TerminalNode* temporalParser::BooleanContext::EQ() {
  return getToken(temporalParser::EQ, 0);
}

tree::TerminalNode* temporalParser::BooleanContext::NEQ() {
  return getToken(temporalParser::NEQ, 0);
}

temporalParser::BooleanAtomContext* temporalParser::BooleanContext::booleanAtom() {
  return getRuleContext<temporalParser::BooleanAtomContext>(0);
}

tree::TerminalNode* temporalParser::BooleanContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

tree::TerminalNode* temporalParser::BooleanContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

tree::TerminalNode* temporalParser::BooleanContext::AND() {
  return getToken(temporalParser::AND, 0);
}

tree::TerminalNode* temporalParser::BooleanContext::OR() {
  return getToken(temporalParser::OR, 0);
}


size_t temporalParser::BooleanContext::getRuleIndex() const {
  return temporalParser::RuleBoolean;
}

void temporalParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void temporalParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


temporalParser::BooleanContext* temporalParser::boolean() {
   return boolean(0);
}

temporalParser::BooleanContext* temporalParser::boolean(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  temporalParser::BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, parentState);
  temporalParser::BooleanContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, temporalParser::RuleBoolean, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(312);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(279);
      match(temporalParser::NOT);
      setState(280);
      boolean(15);
      break;
    }

    case 2: {
      setState(281);
      logic(0);
      setState(282);
      relop();
      setState(283);
      logic(0);
      break;
    }

    case 3: {
      setState(285);
      numeric(0);
      setState(286);
      relop();
      setState(287);
      numeric(0);
      break;
    }

    case 4: {
      setState(289);
      logic(0);
      setState(290);
      match(temporalParser::EQ);
      setState(291);
      logic(0);
      break;
    }

    case 5: {
      setState(293);
      numeric(0);
      setState(294);
      match(temporalParser::EQ);
      setState(295);
      numeric(0);
      break;
    }

    case 6: {
      setState(297);
      logic(0);
      setState(298);
      match(temporalParser::NEQ);
      setState(299);
      logic(0);
      break;
    }

    case 7: {
      setState(301);
      numeric(0);
      setState(302);
      match(temporalParser::NEQ);
      setState(303);
      numeric(0);
      break;
    }

    case 8: {
      setState(305);
      booleanAtom();
      break;
    }

    case 9: {
      setState(306);
      logic(0);
      break;
    }

    case 10: {
      setState(307);
      numeric(0);
      break;
    }

    case 11: {
      setState(308);
      match(temporalParser::LPAREN);
      setState(309);
      boolean(0);
      setState(310);
      match(temporalParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(328);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(326);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(314);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(315);
          match(temporalParser::EQ);
          setState(316);
          boolean(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(317);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(318);
          match(temporalParser::NEQ);
          setState(319);
          boolean(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(320);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(321);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(temporalParser::AND);
          setState(322);
          boolean(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(323);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(324);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(temporalParser::OR);
          setState(325);
          boolean(6);
          break;
        }

        } 
      }
      setState(330);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BooleanAtomContext ------------------------------------------------------------------

temporalParser::BooleanAtomContext::BooleanAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::BooleanConstantContext* temporalParser::BooleanAtomContext::booleanConstant() {
  return getRuleContext<temporalParser::BooleanConstantContext>(0);
}

temporalParser::BooleanVariableContext* temporalParser::BooleanAtomContext::booleanVariable() {
  return getRuleContext<temporalParser::BooleanVariableContext>(0);
}


size_t temporalParser::BooleanAtomContext::getRuleIndex() const {
  return temporalParser::RuleBooleanAtom;
}

void temporalParser::BooleanAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanAtom(this);
}

void temporalParser::BooleanAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanAtom(this);
}

temporalParser::BooleanAtomContext* temporalParser::booleanAtom() {
  BooleanAtomContext *_localctx = _tracker.createInstance<BooleanAtomContext>(_ctx, getState());
  enterRule(_localctx, 8, temporalParser::RuleBooleanAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(333);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case temporalParser::BOOLEAN: {
        enterOuterAlt(_localctx, 1);
        setState(331);
        booleanConstant();
        break;
      }

      case temporalParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(332);
        booleanVariable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanConstantContext ------------------------------------------------------------------

temporalParser::BooleanConstantContext::BooleanConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::BooleanConstantContext::BOOLEAN() {
  return getToken(temporalParser::BOOLEAN, 0);
}


size_t temporalParser::BooleanConstantContext::getRuleIndex() const {
  return temporalParser::RuleBooleanConstant;
}

void temporalParser::BooleanConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanConstant(this);
}

void temporalParser::BooleanConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanConstant(this);
}

temporalParser::BooleanConstantContext* temporalParser::booleanConstant() {
  BooleanConstantContext *_localctx = _tracker.createInstance<BooleanConstantContext>(_ctx, getState());
  enterRule(_localctx, 10, temporalParser::RuleBooleanConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(temporalParser::BOOLEAN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanVariableContext ------------------------------------------------------------------

temporalParser::BooleanVariableContext::BooleanVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::BooleanVariableContext::LT() {
  return getToken(temporalParser::LT, 0);
}

temporalParser::VariableContext* temporalParser::BooleanVariableContext::variable() {
  return getRuleContext<temporalParser::VariableContext>(0);
}


size_t temporalParser::BooleanVariableContext::getRuleIndex() const {
  return temporalParser::RuleBooleanVariable;
}

void temporalParser::BooleanVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanVariable(this);
}

void temporalParser::BooleanVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanVariable(this);
}

temporalParser::BooleanVariableContext* temporalParser::booleanVariable() {
  BooleanVariableContext *_localctx = _tracker.createInstance<BooleanVariableContext>(_ctx, getState());
  enterRule(_localctx, 12, temporalParser::RuleBooleanVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(337);
    match(temporalParser::LT);
    setState(338);
    variable();
    setState(339);
    match(temporalParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicContext ------------------------------------------------------------------

temporalParser::LogicContext::LogicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::LogicContext::NEG() {
  return getToken(temporalParser::NEG, 0);
}

std::vector<temporalParser::LogicContext *> temporalParser::LogicContext::logic() {
  return getRuleContexts<temporalParser::LogicContext>();
}

temporalParser::LogicContext* temporalParser::LogicContext::logic(size_t i) {
  return getRuleContext<temporalParser::LogicContext>(i);
}

temporalParser::LogicAtomContext* temporalParser::LogicContext::logicAtom() {
  return getRuleContext<temporalParser::LogicAtomContext>(0);
}

tree::TerminalNode* temporalParser::LogicContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

tree::TerminalNode* temporalParser::LogicContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

tree::TerminalNode* temporalParser::LogicContext::TIMES() {
  return getToken(temporalParser::TIMES, 0);
}

tree::TerminalNode* temporalParser::LogicContext::DIV() {
  return getToken(temporalParser::DIV, 0);
}

tree::TerminalNode* temporalParser::LogicContext::PLUS() {
  return getToken(temporalParser::PLUS, 0);
}

tree::TerminalNode* temporalParser::LogicContext::MINUS() {
  return getToken(temporalParser::MINUS, 0);
}

tree::TerminalNode* temporalParser::LogicContext::LSHIFT() {
  return getToken(temporalParser::LSHIFT, 0);
}

tree::TerminalNode* temporalParser::LogicContext::RSHIFT() {
  return getToken(temporalParser::RSHIFT, 0);
}

tree::TerminalNode* temporalParser::LogicContext::BAND() {
  return getToken(temporalParser::BAND, 0);
}

tree::TerminalNode* temporalParser::LogicContext::BXOR() {
  return getToken(temporalParser::BXOR, 0);
}

tree::TerminalNode* temporalParser::LogicContext::BOR() {
  return getToken(temporalParser::BOR, 0);
}


size_t temporalParser::LogicContext::getRuleIndex() const {
  return temporalParser::RuleLogic;
}

void temporalParser::LogicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic(this);
}

void temporalParser::LogicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic(this);
}


temporalParser::LogicContext* temporalParser::logic() {
   return logic(0);
}

temporalParser::LogicContext* temporalParser::logic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  temporalParser::LogicContext *_localctx = _tracker.createInstance<LogicContext>(_ctx, parentState);
  temporalParser::LogicContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, temporalParser::RuleLogic, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case temporalParser::NEG: {
        setState(342);
        match(temporalParser::NEG);
        setState(343);
        logic(10);
        break;
      }

      case temporalParser::NUMERIC:
      case temporalParser::VERILOG_BINARY:
      case temporalParser::GCC_BINARY:
      case temporalParser::LT: {
        setState(344);
        logicAtom();
        break;
      }

      case temporalParser::LPAREN: {
        setState(345);
        match(temporalParser::LPAREN);
        setState(346);
        logic(0);
        setState(347);
        match(temporalParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(374);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(372);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(351);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(352);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::TIMES

          || _la == temporalParser::DIV)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(353);
          logic(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(354);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(355);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::PLUS

          || _la == temporalParser::MINUS)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(356);
          logic(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(357);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(358);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(temporalParser::LSHIFT);
          setState(359);
          logic(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(360);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(361);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(temporalParser::RSHIFT);
          setState(362);
          logic(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(363);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(364);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(temporalParser::BAND);
          setState(365);
          logic(6);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(366);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(367);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(temporalParser::BXOR);
          setState(368);
          logic(5);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(369);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(370);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(temporalParser::BOR);
          setState(371);
          logic(4);
          break;
        }

        } 
      }
      setState(376);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicAtomContext ------------------------------------------------------------------

temporalParser::LogicAtomContext::LogicAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::LogicConstantContext* temporalParser::LogicAtomContext::logicConstant() {
  return getRuleContext<temporalParser::LogicConstantContext>(0);
}

temporalParser::LogicVariableContext* temporalParser::LogicAtomContext::logicVariable() {
  return getRuleContext<temporalParser::LogicVariableContext>(0);
}

temporalParser::EnumVariableContext* temporalParser::LogicAtomContext::enumVariable() {
  return getRuleContext<temporalParser::EnumVariableContext>(0);
}

temporalParser::NamedLogicConstContext* temporalParser::LogicAtomContext::namedLogicConst() {
  return getRuleContext<temporalParser::NamedLogicConstContext>(0);
}


size_t temporalParser::LogicAtomContext::getRuleIndex() const {
  return temporalParser::RuleLogicAtom;
}

void temporalParser::LogicAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicAtom(this);
}

void temporalParser::LogicAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicAtom(this);
}

temporalParser::LogicAtomContext* temporalParser::logicAtom() {
  LogicAtomContext *_localctx = _tracker.createInstance<LogicAtomContext>(_ctx, getState());
  enterRule(_localctx, 16, temporalParser::RuleLogicAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(381);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(377);
      logicConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(378);
      logicVariable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(379);
      enumVariable();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(380);
      namedLogicConst();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicConstantContext ------------------------------------------------------------------

temporalParser::LogicConstantContext::LogicConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::LogicConstantContext::VERILOG_BINARY() {
  return getToken(temporalParser::VERILOG_BINARY, 0);
}

tree::TerminalNode* temporalParser::LogicConstantContext::GCC_BINARY() {
  return getToken(temporalParser::GCC_BINARY, 0);
}

tree::TerminalNode* temporalParser::LogicConstantContext::NUMERIC() {
  return getToken(temporalParser::NUMERIC, 0);
}


size_t temporalParser::LogicConstantContext::getRuleIndex() const {
  return temporalParser::RuleLogicConstant;
}

void temporalParser::LogicConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicConstant(this);
}

void temporalParser::LogicConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicConstant(this);
}

temporalParser::LogicConstantContext* temporalParser::logicConstant() {
  LogicConstantContext *_localctx = _tracker.createInstance<LogicConstantContext>(_ctx, getState());
  enterRule(_localctx, 18, temporalParser::RuleLogicConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << temporalParser::NUMERIC)
      | (1ULL << temporalParser::VERILOG_BINARY)
      | (1ULL << temporalParser::GCC_BINARY))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedLogicConstContext ------------------------------------------------------------------

temporalParser::NamedLogicConstContext::NamedLogicConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::NamedLogicConstContext::LT() {
  return getToken(temporalParser::LT, 0);
}

temporalParser::NamedConstContext* temporalParser::NamedLogicConstContext::namedConst() {
  return getRuleContext<temporalParser::NamedConstContext>(0);
}

tree::TerminalNode* temporalParser::NamedLogicConstContext::NUMERIC() {
  return getToken(temporalParser::NUMERIC, 0);
}


size_t temporalParser::NamedLogicConstContext::getRuleIndex() const {
  return temporalParser::RuleNamedLogicConst;
}

void temporalParser::NamedLogicConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedLogicConst(this);
}

void temporalParser::NamedLogicConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedLogicConst(this);
}

temporalParser::NamedLogicConstContext* temporalParser::namedLogicConst() {
  NamedLogicConstContext *_localctx = _tracker.createInstance<NamedLogicConstContext>(_ctx, getState());
  enterRule(_localctx, 20, temporalParser::RuleNamedLogicConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    match(temporalParser::LT);
    setState(386);
    namedConst();
    setState(387);
    match(temporalParser::T__1);
    setState(388);
    match(temporalParser::NUMERIC);
    setState(389);
    match(temporalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicVariableContext ------------------------------------------------------------------

temporalParser::LogicVariableContext::LogicVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::LogicVariableContext::LT() {
  return getToken(temporalParser::LT, 0);
}

temporalParser::VariableContext* temporalParser::LogicVariableContext::variable() {
  return getRuleContext<temporalParser::VariableContext>(0);
}

tree::TerminalNode* temporalParser::LogicVariableContext::SIGN() {
  return getToken(temporalParser::SIGN, 0);
}

tree::TerminalNode* temporalParser::LogicVariableContext::NUMERIC() {
  return getToken(temporalParser::NUMERIC, 0);
}


size_t temporalParser::LogicVariableContext::getRuleIndex() const {
  return temporalParser::RuleLogicVariable;
}

void temporalParser::LogicVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicVariable(this);
}

void temporalParser::LogicVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicVariable(this);
}

temporalParser::LogicVariableContext* temporalParser::logicVariable() {
  LogicVariableContext *_localctx = _tracker.createInstance<LogicVariableContext>(_ctx, getState());
  enterRule(_localctx, 22, temporalParser::RuleLogicVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    match(temporalParser::LT);
    setState(392);
    variable();
    setState(393);
    match(temporalParser::T__3);
    setState(394);
    match(temporalParser::SIGN);
    setState(395);
    match(temporalParser::T__4);
    setState(396);
    match(temporalParser::NUMERIC);
    setState(397);
    match(temporalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumVariableContext ------------------------------------------------------------------

temporalParser::EnumVariableContext::EnumVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::EnumVariableContext::LT() {
  return getToken(temporalParser::LT, 0);
}

temporalParser::VariableContext* temporalParser::EnumVariableContext::variable() {
  return getRuleContext<temporalParser::VariableContext>(0);
}

temporalParser::EnumNameContext* temporalParser::EnumVariableContext::enumName() {
  return getRuleContext<temporalParser::EnumNameContext>(0);
}


size_t temporalParser::EnumVariableContext::getRuleIndex() const {
  return temporalParser::RuleEnumVariable;
}

void temporalParser::EnumVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumVariable(this);
}

void temporalParser::EnumVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumVariable(this);
}

temporalParser::EnumVariableContext* temporalParser::enumVariable() {
  EnumVariableContext *_localctx = _tracker.createInstance<EnumVariableContext>(_ctx, getState());
  enterRule(_localctx, 24, temporalParser::RuleEnumVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(temporalParser::LT);
    setState(400);
    variable();
    setState(401);
    match(temporalParser::T__5);
    setState(402);
    enumName();
    setState(403);
    match(temporalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumNameContext ------------------------------------------------------------------

temporalParser::EnumNameContext::EnumNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::EnumNameContext::VARIABLE() {
  return getToken(temporalParser::VARIABLE, 0);
}


size_t temporalParser::EnumNameContext::getRuleIndex() const {
  return temporalParser::RuleEnumName;
}

void temporalParser::EnumNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumName(this);
}

void temporalParser::EnumNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumName(this);
}

temporalParser::EnumNameContext* temporalParser::enumName() {
  EnumNameContext *_localctx = _tracker.createInstance<EnumNameContext>(_ctx, getState());
  enterRule(_localctx, 26, temporalParser::RuleEnumName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    match(temporalParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedConstContext ------------------------------------------------------------------

temporalParser::NamedConstContext::NamedConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::NamedConstContext::VARIABLE() {
  return getToken(temporalParser::VARIABLE, 0);
}


size_t temporalParser::NamedConstContext::getRuleIndex() const {
  return temporalParser::RuleNamedConst;
}

void temporalParser::NamedConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedConst(this);
}

void temporalParser::NamedConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedConst(this);
}

temporalParser::NamedConstContext* temporalParser::namedConst() {
  NamedConstContext *_localctx = _tracker.createInstance<NamedConstContext>(_ctx, getState());
  enterRule(_localctx, 28, temporalParser::RuleNamedConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(temporalParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericContext ------------------------------------------------------------------

temporalParser::NumericContext::NumericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::NumericAtomContext* temporalParser::NumericContext::numericAtom() {
  return getRuleContext<temporalParser::NumericAtomContext>(0);
}

temporalParser::LogicContext* temporalParser::NumericContext::logic() {
  return getRuleContext<temporalParser::LogicContext>(0);
}

tree::TerminalNode* temporalParser::NumericContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

std::vector<temporalParser::NumericContext *> temporalParser::NumericContext::numeric() {
  return getRuleContexts<temporalParser::NumericContext>();
}

temporalParser::NumericContext* temporalParser::NumericContext::numeric(size_t i) {
  return getRuleContext<temporalParser::NumericContext>(i);
}

tree::TerminalNode* temporalParser::NumericContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

tree::TerminalNode* temporalParser::NumericContext::TIMES() {
  return getToken(temporalParser::TIMES, 0);
}

tree::TerminalNode* temporalParser::NumericContext::DIV() {
  return getToken(temporalParser::DIV, 0);
}

tree::TerminalNode* temporalParser::NumericContext::PLUS() {
  return getToken(temporalParser::PLUS, 0);
}

tree::TerminalNode* temporalParser::NumericContext::MINUS() {
  return getToken(temporalParser::MINUS, 0);
}


size_t temporalParser::NumericContext::getRuleIndex() const {
  return temporalParser::RuleNumeric;
}

void temporalParser::NumericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric(this);
}

void temporalParser::NumericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric(this);
}


temporalParser::NumericContext* temporalParser::numeric() {
   return numeric(0);
}

temporalParser::NumericContext* temporalParser::numeric(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  temporalParser::NumericContext *_localctx = _tracker.createInstance<NumericContext>(_ctx, parentState);
  temporalParser::NumericContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, temporalParser::RuleNumeric, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(416);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(410);
      numericAtom();
      break;
    }

    case 2: {
      setState(411);
      logic(0);
      break;
    }

    case 3: {
      setState(412);
      match(temporalParser::LPAREN);
      setState(413);
      numeric(0);
      setState(414);
      match(temporalParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(426);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(424);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(418);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(419);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::TIMES

          || _la == temporalParser::DIV)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(420);
          numeric(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(421);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(422);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::PLUS

          || _la == temporalParser::MINUS)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(423);
          numeric(5);
          break;
        }

        } 
      }
      setState(428);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NumericAtomContext ------------------------------------------------------------------

temporalParser::NumericAtomContext::NumericAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::NumericConstantContext* temporalParser::NumericAtomContext::numericConstant() {
  return getRuleContext<temporalParser::NumericConstantContext>(0);
}

temporalParser::NumericVariableContext* temporalParser::NumericAtomContext::numericVariable() {
  return getRuleContext<temporalParser::NumericVariableContext>(0);
}


size_t temporalParser::NumericAtomContext::getRuleIndex() const {
  return temporalParser::RuleNumericAtom;
}

void temporalParser::NumericAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericAtom(this);
}

void temporalParser::NumericAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericAtom(this);
}

temporalParser::NumericAtomContext* temporalParser::numericAtom() {
  NumericAtomContext *_localctx = _tracker.createInstance<NumericAtomContext>(_ctx, getState());
  enterRule(_localctx, 32, temporalParser::RuleNumericAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(431);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case temporalParser::NUMERIC: {
        enterOuterAlt(_localctx, 1);
        setState(429);
        numericConstant();
        break;
      }

      case temporalParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(430);
        numericVariable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericConstantContext ------------------------------------------------------------------

temporalParser::NumericConstantContext::NumericConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::NumericConstantContext::NUMERIC() {
  return getToken(temporalParser::NUMERIC, 0);
}


size_t temporalParser::NumericConstantContext::getRuleIndex() const {
  return temporalParser::RuleNumericConstant;
}

void temporalParser::NumericConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericConstant(this);
}

void temporalParser::NumericConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericConstant(this);
}

temporalParser::NumericConstantContext* temporalParser::numericConstant() {
  NumericConstantContext *_localctx = _tracker.createInstance<NumericConstantContext>(_ctx, getState());
  enterRule(_localctx, 34, temporalParser::RuleNumericConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(temporalParser::NUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericVariableContext ------------------------------------------------------------------

temporalParser::NumericVariableContext::NumericVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::NumericVariableContext::LT() {
  return getToken(temporalParser::LT, 0);
}

temporalParser::VariableContext* temporalParser::NumericVariableContext::variable() {
  return getRuleContext<temporalParser::VariableContext>(0);
}

tree::TerminalNode* temporalParser::NumericVariableContext::NUMERIC() {
  return getToken(temporalParser::NUMERIC, 0);
}


size_t temporalParser::NumericVariableContext::getRuleIndex() const {
  return temporalParser::RuleNumericVariable;
}

void temporalParser::NumericVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericVariable(this);
}

void temporalParser::NumericVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericVariable(this);
}

temporalParser::NumericVariableContext* temporalParser::numericVariable() {
  NumericVariableContext *_localctx = _tracker.createInstance<NumericVariableContext>(_ctx, getState());
  enterRule(_localctx, 36, temporalParser::RuleNumericVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    match(temporalParser::LT);
    setState(436);
    variable();
    setState(437);
    match(temporalParser::T__6);
    setState(438);
    match(temporalParser::NUMERIC);
    setState(439);
    match(temporalParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

temporalParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::VariableContext::VARIABLE() {
  return getToken(temporalParser::VARIABLE, 0);
}

tree::TerminalNode* temporalParser::VariableContext::TIMES() {
  return getToken(temporalParser::TIMES, 0);
}


size_t temporalParser::VariableContext::getRuleIndex() const {
  return temporalParser::RuleVariable;
}

void temporalParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void temporalParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

temporalParser::VariableContext* temporalParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 38, temporalParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(442);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == temporalParser::TIMES) {
      setState(441);
      match(temporalParser::TIMES);
    }
    setState(444);
    match(temporalParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

temporalParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::RelopContext::GT() {
  return getToken(temporalParser::GT, 0);
}

tree::TerminalNode* temporalParser::RelopContext::GE() {
  return getToken(temporalParser::GE, 0);
}

tree::TerminalNode* temporalParser::RelopContext::LT() {
  return getToken(temporalParser::LT, 0);
}

tree::TerminalNode* temporalParser::RelopContext::LE() {
  return getToken(temporalParser::LE, 0);
}


size_t temporalParser::RelopContext::getRuleIndex() const {
  return temporalParser::RuleRelop;
}

void temporalParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void temporalParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}

temporalParser::RelopContext* temporalParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 40, temporalParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << temporalParser::GT)
      | (1ULL << temporalParser::GE)
      | (1ULL << temporalParser::LT)
      | (1ULL << temporalParser::LE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool temporalParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return sereSempred(dynamic_cast<SereContext *>(context), predicateIndex);
    case 2: return tformulaSempred(dynamic_cast<TformulaContext *>(context), predicateIndex);
    case 3: return booleanSempred(dynamic_cast<BooleanContext *>(context), predicateIndex);
    case 7: return logicSempred(dynamic_cast<LogicContext *>(context), predicateIndex);
    case 15: return numericSempred(dynamic_cast<NumericContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool temporalParser::sereSempred(SereContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);
    case 6: return precpred(_ctx, 15);
    case 7: return precpred(_ctx, 14);
    case 8: return precpred(_ctx, 13);
    case 9: return precpred(_ctx, 12);
    case 10: return precpred(_ctx, 11);
    case 11: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

bool temporalParser::tformulaSempred(TformulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 13);
    case 13: return precpred(_ctx, 12);
    case 14: return precpred(_ctx, 11);
    case 15: return precpred(_ctx, 10);
    case 16: return precpred(_ctx, 9);
    case 17: return precpred(_ctx, 8);
    case 18: return precpred(_ctx, 7);
    case 19: return precpred(_ctx, 6);
    case 20: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool temporalParser::booleanSempred(BooleanContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 10);
    case 22: return precpred(_ctx, 7);
    case 23: return precpred(_ctx, 6);
    case 24: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool temporalParser::logicSempred(LogicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 9);
    case 26: return precpred(_ctx, 8);
    case 27: return precpred(_ctx, 7);
    case 28: return precpred(_ctx, 6);
    case 29: return precpred(_ctx, 5);
    case 30: return precpred(_ctx, 4);
    case 31: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool temporalParser::numericSempred(NumericContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 32: return precpred(_ctx, 5);
    case 33: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> temporalParser::_decisionToDFA;
atn::PredictionContextCache temporalParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN temporalParser::_atn;
std::vector<uint16_t> temporalParser::_serializedATN;

std::vector<std::string> temporalParser::_ruleNames = {
  "formula", "sere", "tformula", "boolean", "booleanAtom", "booleanConstant", 
  "booleanVariable", "logic", "logicAtom", "logicConstant", "namedLogicConst", 
  "logicVariable", "enumVariable", "enumName", "namedConst", "numeric", 
  "numericAtom", "numericConstant", "numericVariable", "variable", "relop"
};

std::vector<std::string> temporalParser::_literalNames = {
  "", "',bool>'", "',constlogic('", "')>'", "',logic('", "','", "',enum('", 
  "',numeric('", "'F'", "'G'", "'X'", "'U'", "'W'", "'X[!]'", "'R'", "'M'", 
  "'..'", "'->'", "'=>'", "'<->'", "'xor'", "'<>->'", "'<>=>'", "'='", "'##'", 
  "';'", "':'", "'first_match'", "", "'{'", "'}'", "'['", "']'", "'('", 
  "')'", "'bool'", "'double'", "", "", "", "", "", "'+'", "'-'", "'*'", 
  "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&'", "'|'", "'^'", 
  "'~'", "'<<'", "'>>'", "'&&'", "'||'", "'!'"
};

std::vector<std::string> temporalParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "EVENTUALLY", "ALWAYS", "NEXT", "UNTIL", 
  "WUNTIL", "SUNTIL", "RELEASE", "SRELEASE", "DOTS", "IMPL", "IMPL2", "IFF", 
  "XOR", "BIND1", "BIND2", "ASS", "DSYM1", "SCOL", "COL", "FIRST_MATCH", 
  "SIGN", "LGPAREN", "RGPAREN", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", 
  "CAST_BOOL", "CAST_NUMERIC", "VARIABLE", "NUMERIC", "VERILOG_BINARY", 
  "GCC_BINARY", "BOOLEAN", "PLUS", "MINUS", "TIMES", "DIV", "GT", "GE", 
  "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", "LSHIFT", "RSHIFT", 
  "AND", "OR", "NOT", "WS"
};

dfa::Vocabulary temporalParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> temporalParser::_tokenNames;

temporalParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3f, 0x1c3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x52, 
    0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x92, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x95, 0xb, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xf7, 0xa, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x114, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x117, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x13b, 0xa, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x149, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x14c, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x150, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x160, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x177, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0x17a, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x180, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0x1a3, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x1ab, 0xa, 0x11, 0xc, 0x11, 
    0xe, 0x11, 0x1ae, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1b2, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x5, 0x15, 0x1bd, 0xa, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x2, 0x7, 0x4, 
    0x6, 0x8, 0x10, 0x20, 0x17, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2, 0x6, 0x3, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2c, 0x2d, 0x3, 0x2, 
    0x28, 0x2a, 0x3, 0x2, 0x30, 0x33, 0x2, 0x1fb, 0x2, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x51, 0x3, 0x2, 0x2, 0x2, 0x6, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x14f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x153, 0x3, 0x2, 0x2, 0x2, 0x10, 0x15f, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x181, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x183, 0x3, 0x2, 0x2, 0x2, 0x18, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x191, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x197, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x199, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1b5, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x1c0, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x6, 0x4, 0x2, 0x2d, 0x2e, 0x7, 0x2, 
    0x2, 0x3, 0x2e, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x8, 0x3, 0x1, 
    0x2, 0x30, 0x52, 0x5, 0x8, 0x5, 0x2, 0x31, 0x32, 0x7, 0x23, 0x2, 0x2, 
    0x32, 0x33, 0x5, 0x4, 0x3, 0x2, 0x33, 0x34, 0x7, 0x24, 0x2, 0x2, 0x34, 
    0x52, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0x1f, 0x2, 0x2, 0x36, 0x37, 
    0x5, 0x4, 0x3, 0x2, 0x37, 0x38, 0x7, 0x20, 0x2, 0x2, 0x38, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x21, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x2e, 
    0x2, 0x2, 0x3b, 0x3c, 0x7, 0x28, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x12, 0x2, 
    0x2, 0x3d, 0x3e, 0x7, 0x28, 0x2, 0x2, 0x3e, 0x52, 0x7, 0x22, 0x2, 0x2, 
    0x3f, 0x40, 0x7, 0x21, 0x2, 0x2, 0x40, 0x41, 0x7, 0x2c, 0x2, 0x2, 0x41, 
    0x52, 0x7, 0x22, 0x2, 0x2, 0x42, 0x43, 0x7, 0x1a, 0x2, 0x2, 0x43, 0x44, 
    0x7, 0x28, 0x2, 0x2, 0x44, 0x52, 0x5, 0x4, 0x3, 0x9, 0x45, 0x46, 0x7, 
    0x1a, 0x2, 0x2, 0x46, 0x47, 0x7, 0x21, 0x2, 0x2, 0x47, 0x48, 0x7, 0x28, 
    0x2, 0x2, 0x48, 0x49, 0x7, 0x12, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x28, 0x2, 
    0x2, 0x4a, 0x4b, 0x7, 0x22, 0x2, 0x2, 0x4b, 0x52, 0x5, 0x4, 0x3, 0x8, 
    0x4c, 0x4d, 0x7, 0x1d, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x23, 0x2, 0x2, 0x4e, 
    0x4f, 0x5, 0x4, 0x3, 0x2, 0x4f, 0x50, 0x7, 0x24, 0x2, 0x2, 0x50, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x35, 0x3, 0x2, 0x2, 0x2, 0x51, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x42, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x45, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x93, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0xc, 0xb, 0x2, 0x2, 0x54, 
    0x55, 0x7, 0x3c, 0x2, 0x2, 0x55, 0x92, 0x5, 0x4, 0x3, 0xc, 0x56, 0x57, 
    0xc, 0xa, 0x2, 0x2, 0x57, 0x58, 0x7, 0x3d, 0x2, 0x2, 0x58, 0x92, 0x5, 
    0x4, 0x3, 0xb, 0x59, 0x5a, 0xc, 0x7, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x1a, 
    0x2, 0x2, 0x5b, 0x5c, 0x7, 0x28, 0x2, 0x2, 0x5c, 0x92, 0x5, 0x4, 0x3, 
    0x8, 0x5d, 0x5e, 0xc, 0x6, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x1a, 0x2, 0x2, 
    0x5f, 0x60, 0x7, 0x21, 0x2, 0x2, 0x60, 0x61, 0x7, 0x28, 0x2, 0x2, 0x61, 
    0x62, 0x7, 0x12, 0x2, 0x2, 0x62, 0x63, 0x7, 0x28, 0x2, 0x2, 0x63, 0x64, 
    0x7, 0x22, 0x2, 0x2, 0x64, 0x92, 0x5, 0x4, 0x3, 0x7, 0x65, 0x66, 0xc, 
    0x5, 0x2, 0x2, 0x66, 0x67, 0x7, 0x1c, 0x2, 0x2, 0x67, 0x92, 0x5, 0x4, 
    0x3, 0x6, 0x68, 0x69, 0xc, 0x4, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x1b, 0x2, 
    0x2, 0x6a, 0x92, 0x5, 0x4, 0x3, 0x5, 0x6b, 0x6c, 0xc, 0x11, 0x2, 0x2, 
    0x6c, 0x6d, 0x7, 0x21, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x2e, 0x2, 0x2, 0x6e, 
    0x6f, 0x7, 0x28, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x12, 0x2, 0x2, 0x70, 0x71, 
    0x7, 0x28, 0x2, 0x2, 0x71, 0x92, 0x7, 0x22, 0x2, 0x2, 0x72, 0x73, 0xc, 
    0x10, 0x2, 0x2, 0x73, 0x74, 0x7, 0x21, 0x2, 0x2, 0x74, 0x75, 0x7, 0x2c, 
    0x2, 0x2, 0x75, 0x92, 0x7, 0x22, 0x2, 0x2, 0x76, 0x77, 0xc, 0xf, 0x2, 
    0x2, 0x77, 0x78, 0x7, 0x21, 0x2, 0x2, 0x78, 0x79, 0x7, 0x1c, 0x2, 0x2, 
    0x79, 0x7a, 0x7, 0x2e, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x28, 0x2, 0x2, 0x7b, 
    0x7c, 0x7, 0x12, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x28, 0x2, 0x2, 0x7d, 0x92, 
    0x7, 0x22, 0x2, 0x2, 0x7e, 0x7f, 0xc, 0xe, 0x2, 0x2, 0x7f, 0x80, 0x7, 
    0x21, 0x2, 0x2, 0x80, 0x81, 0x7, 0x1c, 0x2, 0x2, 0x81, 0x82, 0x7, 0x2c, 
    0x2, 0x2, 0x82, 0x92, 0x7, 0x22, 0x2, 0x2, 0x83, 0x84, 0xc, 0xd, 0x2, 
    0x2, 0x84, 0x85, 0x7, 0x21, 0x2, 0x2, 0x85, 0x86, 0x7, 0x19, 0x2, 0x2, 
    0x86, 0x87, 0x7, 0x28, 0x2, 0x2, 0x87, 0x88, 0x7, 0x12, 0x2, 0x2, 0x88, 
    0x89, 0x7, 0x28, 0x2, 0x2, 0x89, 0x92, 0x7, 0x22, 0x2, 0x2, 0x8a, 0x8b, 
    0xc, 0xc, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x21, 0x2, 0x2, 0x8c, 0x8d, 0x7, 
    0x13, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x28, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x12, 
    0x2, 0x2, 0x8f, 0x90, 0x7, 0x28, 0x2, 0x2, 0x90, 0x92, 0x7, 0x22, 0x2, 
    0x2, 0x91, 0x53, 0x3, 0x2, 0x2, 0x2, 0x91, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x59, 0x3, 0x2, 0x2, 0x2, 0x91, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x91, 0x68, 0x3, 0x2, 0x2, 0x2, 0x91, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x72, 0x3, 0x2, 0x2, 0x2, 0x91, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x5, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x8, 0x4, 0x1, 0x2, 0x97, 0xf7, 0x5, 0x8, 0x5, 0x2, 0x98, 0x99, 
    0x7, 0x23, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x6, 0x4, 0x2, 0x9a, 0x9b, 0x7, 
    0x24, 0x2, 0x2, 0x9b, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x1f, 
    0x2, 0x2, 0x9d, 0x9e, 0x5, 0x4, 0x3, 0x2, 0x9e, 0x9f, 0x7, 0x20, 0x2, 
    0x2, 0x9f, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x1f, 0x2, 0x2, 
    0xa1, 0xa2, 0x5, 0x4, 0x3, 0x2, 0xa2, 0xa3, 0x7, 0x20, 0x2, 0x2, 0xa3, 
    0xa4, 0x7, 0x3e, 0x2, 0x2, 0xa4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 
    0x7, 0x3e, 0x2, 0x2, 0xa6, 0xf7, 0x5, 0x6, 0x4, 0x19, 0xa7, 0xa8, 0x7, 
    0xc, 0x2, 0x2, 0xa8, 0xf7, 0x5, 0x6, 0x4, 0x18, 0xa9, 0xaa, 0x7, 0xc, 
    0x2, 0x2, 0xaa, 0xab, 0x7, 0x21, 0x2, 0x2, 0xab, 0xac, 0x7, 0x28, 0x2, 
    0x2, 0xac, 0xad, 0x7, 0x12, 0x2, 0x2, 0xad, 0xae, 0x7, 0x28, 0x2, 0x2, 
    0xae, 0xaf, 0x7, 0x22, 0x2, 0x2, 0xaf, 0xf7, 0x5, 0x6, 0x4, 0x17, 0xb0, 
    0xb1, 0x7, 0xc, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x21, 0x2, 0x2, 0xb2, 0xb3, 
    0x7, 0x28, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x12, 0x2, 0x2, 0xb4, 0xb5, 0x7, 
    0x28, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x3e, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x22, 
    0x2, 0x2, 0xb7, 0xf7, 0x5, 0x6, 0x4, 0x16, 0xb8, 0xb9, 0x7, 0xb, 0x2, 
    0x2, 0xb9, 0xf7, 0x5, 0x6, 0x4, 0x15, 0xba, 0xbb, 0x7, 0xb, 0x2, 0x2, 
    0xbb, 0xbc, 0x7, 0x21, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x28, 0x2, 0x2, 0xbd, 
    0xbe, 0x7, 0x12, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x28, 0x2, 0x2, 0xbf, 0xc0, 
    0x7, 0x22, 0x2, 0x2, 0xc0, 0xf7, 0x5, 0x6, 0x4, 0x14, 0xc1, 0xc2, 0x7, 
    0xb, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x21, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x28, 
    0x2, 0x2, 0xc4, 0xc5, 0x7, 0x12, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x28, 0x2, 
    0x2, 0xc6, 0xc7, 0x7, 0x3e, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x22, 0x2, 0x2, 
    0xc8, 0xf7, 0x5, 0x6, 0x4, 0x13, 0xc9, 0xca, 0x7, 0xa, 0x2, 0x2, 0xca, 
    0xf7, 0x5, 0x6, 0x4, 0x12, 0xcb, 0xcc, 0x7, 0xa, 0x2, 0x2, 0xcc, 0xcd, 
    0x7, 0x21, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x28, 0x2, 0x2, 0xce, 0xcf, 0x7, 
    0x12, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x28, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x22, 
    0x2, 0x2, 0xd1, 0xf7, 0x5, 0x6, 0x4, 0x11, 0xd2, 0xd3, 0x7, 0xa, 0x2, 
    0x2, 0xd3, 0xd4, 0x7, 0x21, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x28, 0x2, 0x2, 
    0xd5, 0xd6, 0x7, 0x12, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x28, 0x2, 0x2, 0xd7, 
    0xd8, 0x7, 0x3e, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x22, 0x2, 0x2, 0xd9, 0xf7, 
    0x5, 0x6, 0x4, 0x10, 0xda, 0xdb, 0x7, 0x1f, 0x2, 0x2, 0xdb, 0xdc, 0x5, 
    0x4, 0x3, 0x2, 0xdc, 0xdd, 0x7, 0x20, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x21, 
    0x2, 0x2, 0xde, 0xdf, 0x7, 0x22, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x13, 0x2, 
    0x2, 0xe0, 0xe1, 0x5, 0x6, 0x4, 0x6, 0xe1, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xe2, 0xe3, 0x7, 0x1f, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x4, 0x3, 0x2, 0xe4, 
    0xe5, 0x7, 0x20, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x21, 0x2, 0x2, 0xe6, 0xe7, 
    0x7, 0x22, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x14, 0x2, 0x2, 0xe8, 0xe9, 0x5, 
    0x6, 0x4, 0x5, 0xe9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x1f, 
    0x2, 0x2, 0xeb, 0xec, 0x5, 0x4, 0x3, 0x2, 0xec, 0xed, 0x7, 0x20, 0x2, 
    0x2, 0xed, 0xee, 0x7, 0x17, 0x2, 0x2, 0xee, 0xef, 0x5, 0x6, 0x4, 0x4, 
    0xef, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x1f, 0x2, 0x2, 0xf1, 
    0xf2, 0x5, 0x4, 0x3, 0x2, 0xf2, 0xf3, 0x7, 0x20, 0x2, 0x2, 0xf3, 0xf4, 
    0x7, 0x18, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x6, 0x4, 0x3, 0xf5, 0xf7, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0x96, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xf6, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xba, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xcb, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xf6, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0xf9, 0xc, 0xf, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0xd, 0x2, 0x2, 0xfa, 
    0x114, 0x5, 0x6, 0x4, 0x10, 0xfb, 0xfc, 0xc, 0xe, 0x2, 0x2, 0xfc, 0xfd, 
    0x7, 0xe, 0x2, 0x2, 0xfd, 0x114, 0x5, 0x6, 0x4, 0xf, 0xfe, 0xff, 0xc, 
    0xd, 0x2, 0x2, 0xff, 0x100, 0x7, 0x11, 0x2, 0x2, 0x100, 0x114, 0x5, 
    0x6, 0x4, 0xe, 0x101, 0x102, 0xc, 0xc, 0x2, 0x2, 0x102, 0x103, 0x7, 
    0x10, 0x2, 0x2, 0x103, 0x114, 0x5, 0x6, 0x4, 0xd, 0x104, 0x105, 0xc, 
    0xb, 0x2, 0x2, 0x105, 0x106, 0x7, 0x3c, 0x2, 0x2, 0x106, 0x114, 0x5, 
    0x6, 0x4, 0xc, 0x107, 0x108, 0xc, 0xa, 0x2, 0x2, 0x108, 0x109, 0x7, 
    0x3d, 0x2, 0x2, 0x109, 0x114, 0x5, 0x6, 0x4, 0xb, 0x10a, 0x10b, 0xc, 
    0x9, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x16, 0x2, 0x2, 0x10c, 0x114, 0x5, 
    0x6, 0x4, 0xa, 0x10d, 0x10e, 0xc, 0x8, 0x2, 0x2, 0x10e, 0x10f, 0x7, 
    0x13, 0x2, 0x2, 0x10f, 0x114, 0x5, 0x6, 0x4, 0x9, 0x110, 0x111, 0xc, 
    0x7, 0x2, 0x2, 0x111, 0x112, 0x7, 0x15, 0x2, 0x2, 0x112, 0x114, 0x5, 
    0x6, 0x4, 0x8, 0x113, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x113, 0xfb, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x113, 0x101, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x104, 0x3, 0x2, 0x2, 0x2, 0x113, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x113, 0x10d, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x110, 0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x7, 0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x118, 0x119, 0x8, 0x5, 0x1, 0x2, 0x119, 0x11a, 0x7, 0x3e, 0x2, 0x2, 
    0x11a, 0x13b, 0x5, 0x8, 0x5, 0x11, 0x11b, 0x11c, 0x5, 0x10, 0x9, 0x2, 
    0x11c, 0x11d, 0x5, 0x2a, 0x16, 0x2, 0x11d, 0x11e, 0x5, 0x10, 0x9, 0x2, 
    0x11e, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x5, 0x20, 0x11, 0x2, 
    0x120, 0x121, 0x5, 0x2a, 0x16, 0x2, 0x121, 0x122, 0x5, 0x20, 0x11, 0x2, 
    0x122, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x5, 0x10, 0x9, 0x2, 
    0x124, 0x125, 0x7, 0x34, 0x2, 0x2, 0x125, 0x126, 0x5, 0x10, 0x9, 0x2, 
    0x126, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x5, 0x20, 0x11, 0x2, 
    0x128, 0x129, 0x7, 0x34, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x20, 0x11, 0x2, 
    0x12a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x10, 0x9, 0x2, 
    0x12c, 0x12d, 0x7, 0x35, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x10, 0x9, 0x2, 
    0x12e, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x20, 0x11, 0x2, 
    0x130, 0x131, 0x7, 0x35, 0x2, 0x2, 0x131, 0x132, 0x5, 0x20, 0x11, 0x2, 
    0x132, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x133, 0x13b, 0x5, 0xa, 0x6, 0x2, 
    0x134, 0x13b, 0x5, 0x10, 0x9, 0x2, 0x135, 0x13b, 0x5, 0x20, 0x11, 0x2, 
    0x136, 0x137, 0x7, 0x23, 0x2, 0x2, 0x137, 0x138, 0x5, 0x8, 0x5, 0x2, 
    0x138, 0x139, 0x7, 0x24, 0x2, 0x2, 0x139, 0x13b, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x11b, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x123, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x127, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x134, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13d, 0xc, 0xc, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x34, 0x2, 0x2, 
    0x13e, 0x149, 0x5, 0x8, 0x5, 0xd, 0x13f, 0x140, 0xc, 0x9, 0x2, 0x2, 
    0x140, 0x141, 0x7, 0x35, 0x2, 0x2, 0x141, 0x149, 0x5, 0x8, 0x5, 0xa, 
    0x142, 0x143, 0xc, 0x8, 0x2, 0x2, 0x143, 0x144, 0x7, 0x3c, 0x2, 0x2, 
    0x144, 0x149, 0x5, 0x8, 0x5, 0x9, 0x145, 0x146, 0xc, 0x7, 0x2, 0x2, 
    0x146, 0x147, 0x7, 0x3d, 0x2, 0x2, 0x147, 0x149, 0x5, 0x8, 0x5, 0x8, 
    0x148, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x148, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0x148, 0x142, 0x3, 0x2, 0x2, 0x2, 0x148, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x150, 0x5, 0xc, 0x7, 0x2, 0x14e, 
    0x150, 0x5, 0xe, 0x8, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x150, 0xb, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 
    0x7, 0x2b, 0x2, 0x2, 0x152, 0xd, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x7, 
    0x32, 0x2, 0x2, 0x154, 0x155, 0x5, 0x28, 0x15, 0x2, 0x155, 0x156, 0x7, 
    0x3, 0x2, 0x2, 0x156, 0xf, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x8, 0x9, 
    0x1, 0x2, 0x158, 0x159, 0x7, 0x39, 0x2, 0x2, 0x159, 0x160, 0x5, 0x10, 
    0x9, 0xc, 0x15a, 0x160, 0x5, 0x12, 0xa, 0x2, 0x15b, 0x15c, 0x7, 0x23, 
    0x2, 0x2, 0x15c, 0x15d, 0x5, 0x10, 0x9, 0x2, 0x15d, 0x15e, 0x7, 0x24, 
    0x2, 0x2, 0x15e, 0x160, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x178, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0xc, 0xb, 
    0x2, 0x2, 0x162, 0x163, 0x9, 0x2, 0x2, 0x2, 0x163, 0x177, 0x5, 0x10, 
    0x9, 0xc, 0x164, 0x165, 0xc, 0xa, 0x2, 0x2, 0x165, 0x166, 0x9, 0x3, 
    0x2, 0x2, 0x166, 0x177, 0x5, 0x10, 0x9, 0xb, 0x167, 0x168, 0xc, 0x9, 
    0x2, 0x2, 0x168, 0x169, 0x7, 0x3a, 0x2, 0x2, 0x169, 0x177, 0x5, 0x10, 
    0x9, 0xa, 0x16a, 0x16b, 0xc, 0x8, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x3b, 
    0x2, 0x2, 0x16c, 0x177, 0x5, 0x10, 0x9, 0x9, 0x16d, 0x16e, 0xc, 0x7, 
    0x2, 0x2, 0x16e, 0x16f, 0x7, 0x36, 0x2, 0x2, 0x16f, 0x177, 0x5, 0x10, 
    0x9, 0x8, 0x170, 0x171, 0xc, 0x6, 0x2, 0x2, 0x171, 0x172, 0x7, 0x38, 
    0x2, 0x2, 0x172, 0x177, 0x5, 0x10, 0x9, 0x7, 0x173, 0x174, 0xc, 0x5, 
    0x2, 0x2, 0x174, 0x175, 0x7, 0x37, 0x2, 0x2, 0x175, 0x177, 0x5, 0x10, 
    0x9, 0x6, 0x176, 0x161, 0x3, 0x2, 0x2, 0x2, 0x176, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x167, 0x3, 0x2, 0x2, 0x2, 0x176, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x176, 0x170, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x173, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x3, 0x2, 
    0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 
    0x2, 0x2, 0x179, 0x11, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x17b, 0x180, 0x5, 0x14, 0xb, 0x2, 0x17c, 0x180, 0x5, 0x18, 0xd, 
    0x2, 0x17d, 0x180, 0x5, 0x1a, 0xe, 0x2, 0x17e, 0x180, 0x5, 0x16, 0xc, 
    0x2, 0x17f, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17e, 0x3, 0x2, 0x2, 
    0x2, 0x180, 0x13, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x9, 0x4, 0x2, 0x2, 
    0x182, 0x15, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x7, 0x32, 0x2, 0x2, 
    0x184, 0x185, 0x5, 0x1e, 0x10, 0x2, 0x185, 0x186, 0x7, 0x4, 0x2, 0x2, 
    0x186, 0x187, 0x7, 0x28, 0x2, 0x2, 0x187, 0x188, 0x7, 0x5, 0x2, 0x2, 
    0x188, 0x17, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x7, 0x32, 0x2, 0x2, 
    0x18a, 0x18b, 0x5, 0x28, 0x15, 0x2, 0x18b, 0x18c, 0x7, 0x6, 0x2, 0x2, 
    0x18c, 0x18d, 0x7, 0x1e, 0x2, 0x2, 0x18d, 0x18e, 0x7, 0x7, 0x2, 0x2, 
    0x18e, 0x18f, 0x7, 0x28, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x5, 0x2, 0x2, 
    0x190, 0x19, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 0x32, 0x2, 0x2, 
    0x192, 0x193, 0x5, 0x28, 0x15, 0x2, 0x193, 0x194, 0x7, 0x8, 0x2, 0x2, 
    0x194, 0x195, 0x5, 0x1c, 0xf, 0x2, 0x195, 0x196, 0x7, 0x5, 0x2, 0x2, 
    0x196, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x7, 0x27, 0x2, 0x2, 
    0x198, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x7, 0x27, 0x2, 0x2, 
    0x19a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x8, 0x11, 0x1, 0x2, 
    0x19c, 0x1a3, 0x5, 0x22, 0x12, 0x2, 0x19d, 0x1a3, 0x5, 0x10, 0x9, 0x2, 
    0x19e, 0x19f, 0x7, 0x23, 0x2, 0x2, 0x19f, 0x1a0, 0x5, 0x20, 0x11, 0x2, 
    0x1a0, 0x1a1, 0x7, 0x24, 0x2, 0x2, 0x1a1, 0x1a3, 0x3, 0x2, 0x2, 0x2, 
    0x1a2, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x19d, 0x3, 0x2, 0x2, 0x2, 
    0x1a2, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1ac, 0x3, 0x2, 0x2, 0x2, 
    0x1a4, 0x1a5, 0xc, 0x7, 0x2, 0x2, 0x1a5, 0x1a6, 0x9, 0x2, 0x2, 0x2, 
    0x1a6, 0x1ab, 0x5, 0x20, 0x11, 0x8, 0x1a7, 0x1a8, 0xc, 0x6, 0x2, 0x2, 
    0x1a8, 0x1a9, 0x9, 0x3, 0x2, 0x2, 0x1a9, 0x1ab, 0x5, 0x20, 0x11, 0x7, 
    0x1aa, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a7, 0x3, 0x2, 0x2, 0x2, 
    0x1ab, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b2, 0x5, 0x24, 0x13, 0x2, 0x1b0, 
    0x1b2, 0x5, 0x26, 0x14, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 
    0x7, 0x28, 0x2, 0x2, 0x1b4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 
    0x7, 0x32, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x28, 0x15, 0x2, 0x1b7, 0x1b8, 
    0x7, 0x9, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x28, 0x2, 0x2, 0x1b9, 0x1ba, 
    0x7, 0x5, 0x2, 0x2, 0x1ba, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bd, 0x7, 
    0x2e, 0x2, 0x2, 0x1bc, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x3, 
    0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x7, 
    0x27, 0x2, 0x2, 0x1bf, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x9, 
    0x5, 0x2, 0x2, 0x1c1, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x15, 0x51, 0x91, 0x93, 
    0xf6, 0x113, 0x115, 0x13a, 0x148, 0x14a, 0x14f, 0x15f, 0x176, 0x178, 
    0x17f, 0x1a2, 0x1aa, 0x1ac, 0x1b1, 0x1bc, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

temporalParser::Initializer temporalParser::_init;
