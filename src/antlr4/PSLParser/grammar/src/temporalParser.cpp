
// Generated from temporal.g4 by ANTLR 4.9.3


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

temporalParser::ImplicationContext* temporalParser::FormulaContext::implication() {
  return getRuleContext<temporalParser::ImplicationContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    implication();
    setState(47);
    match(temporalParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImplicationContext ------------------------------------------------------------------

temporalParser::ImplicationContext::ImplicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* temporalParser::ImplicationContext::ALWAYS() {
  return getToken(temporalParser::ALWAYS, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

std::vector<temporalParser::TformulaContext *> temporalParser::ImplicationContext::tformula() {
  return getRuleContexts<temporalParser::TformulaContext>();
}

temporalParser::TformulaContext* temporalParser::ImplicationContext::tformula(size_t i) {
  return getRuleContext<temporalParser::TformulaContext>(i);
}

tree::TerminalNode* temporalParser::ImplicationContext::IMPL() {
  return getToken(temporalParser::IMPL, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::IMPL2() {
  return getToken(temporalParser::IMPL2, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::LGPAREN() {
  return getToken(temporalParser::LGPAREN, 0);
}

temporalParser::SereContext* temporalParser::ImplicationContext::sere() {
  return getRuleContext<temporalParser::SereContext>(0);
}

tree::TerminalNode* temporalParser::ImplicationContext::RGPAREN() {
  return getToken(temporalParser::RGPAREN, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::LCPAREN() {
  return getToken(temporalParser::LCPAREN, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::RCPAREN() {
  return getToken(temporalParser::RCPAREN, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::SEREIMPL1() {
  return getToken(temporalParser::SEREIMPL1, 0);
}

tree::TerminalNode* temporalParser::ImplicationContext::SEREIMPL2() {
  return getToken(temporalParser::SEREIMPL2, 0);
}


size_t temporalParser::ImplicationContext::getRuleIndex() const {
  return temporalParser::RuleImplication;
}

void temporalParser::ImplicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImplication(this);
}

void temporalParser::ImplicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImplication(this);
}

temporalParser::ImplicationContext* temporalParser::implication() {
  ImplicationContext *_localctx = _tracker.createInstance<ImplicationContext>(_ctx, getState());
  enterRule(_localctx, 2, temporalParser::RuleImplication);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(49);
      match(temporalParser::ALWAYS);
      setState(50);
      match(temporalParser::LPAREN);
      setState(51);
      tformula(0);
      setState(52);
      match(temporalParser::IMPL);
      setState(53);
      tformula(0);
      setState(54);
      match(temporalParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(56);
      match(temporalParser::ALWAYS);
      setState(57);
      match(temporalParser::LPAREN);
      setState(58);
      tformula(0);
      setState(59);
      match(temporalParser::IMPL2);
      setState(60);
      tformula(0);
      setState(61);
      match(temporalParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(63);
      match(temporalParser::ALWAYS);
      setState(64);
      match(temporalParser::LPAREN);
      setState(65);
      match(temporalParser::LGPAREN);
      setState(66);
      sere(0);
      setState(67);
      match(temporalParser::RGPAREN);
      setState(68);
      match(temporalParser::LCPAREN);
      setState(69);
      match(temporalParser::RCPAREN);
      setState(70);
      match(temporalParser::IMPL);
      setState(71);
      tformula(0);
      setState(72);
      match(temporalParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(74);
      match(temporalParser::ALWAYS);
      setState(75);
      match(temporalParser::LPAREN);
      setState(76);
      match(temporalParser::LGPAREN);
      setState(77);
      sere(0);
      setState(78);
      match(temporalParser::RGPAREN);
      setState(79);
      match(temporalParser::LCPAREN);
      setState(80);
      match(temporalParser::RCPAREN);
      setState(81);
      match(temporalParser::IMPL2);
      setState(82);
      tformula(0);
      setState(83);
      match(temporalParser::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(85);
      match(temporalParser::ALWAYS);
      setState(86);
      match(temporalParser::LPAREN);
      setState(87);
      match(temporalParser::LGPAREN);
      setState(88);
      sere(0);
      setState(89);
      match(temporalParser::RGPAREN);
      setState(90);
      match(temporalParser::SEREIMPL1);
      setState(91);
      tformula(0);
      setState(92);
      match(temporalParser::RPAREN);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(94);
      match(temporalParser::ALWAYS);
      setState(95);
      match(temporalParser::LPAREN);
      setState(96);
      match(temporalParser::LGPAREN);
      setState(97);
      sere(0);
      setState(98);
      match(temporalParser::RGPAREN);
      setState(99);
      match(temporalParser::SEREIMPL2);
      setState(100);
      tformula(0);
      setState(101);
      match(temporalParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
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

tree::TerminalNode* temporalParser::SereContext::TIMER() {
  return getToken(temporalParser::TIMER, 0);
}

tree::TerminalNode* temporalParser::SereContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> temporalParser::SereContext::NUMERIC() {
  return getTokens(temporalParser::NUMERIC);
}

tree::TerminalNode* temporalParser::SereContext::NUMERIC(size_t i) {
  return getToken(temporalParser::NUMERIC, i);
}

tree::TerminalNode* temporalParser::SereContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

std::vector<temporalParser::SereContext *> temporalParser::SereContext::sere() {
  return getRuleContexts<temporalParser::SereContext>();
}

temporalParser::SereContext* temporalParser::SereContext::sere(size_t i) {
  return getRuleContext<temporalParser::SereContext>(i);
}

tree::TerminalNode* temporalParser::SereContext::LGPAREN() {
  return getToken(temporalParser::LGPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::RGPAREN() {
  return getToken(temporalParser::RGPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::DELAY() {
  return getToken(temporalParser::DELAY, 0);
}

tree::TerminalNode* temporalParser::SereContext::LCPAREN() {
  return getToken(temporalParser::LCPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::DOTS() {
  return getToken(temporalParser::DOTS, 0);
}

tree::TerminalNode* temporalParser::SereContext::RCPAREN() {
  return getToken(temporalParser::RCPAREN, 0);
}

tree::TerminalNode* temporalParser::SereContext::BOR() {
  return getToken(temporalParser::BOR, 0);
}

tree::TerminalNode* temporalParser::SereContext::BAND() {
  return getToken(temporalParser::BAND, 0);
}

tree::TerminalNode* temporalParser::SereContext::AND() {
  return getToken(temporalParser::AND, 0);
}

tree::TerminalNode* temporalParser::SereContext::SCOL() {
  return getToken(temporalParser::SCOL, 0);
}

tree::TerminalNode* temporalParser::SereContext::COL() {
  return getToken(temporalParser::COL, 0);
}

tree::TerminalNode* temporalParser::SereContext::TIMES() {
  return getToken(temporalParser::TIMES, 0);
}

tree::TerminalNode* temporalParser::SereContext::PLUS() {
  return getToken(temporalParser::PLUS, 0);
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
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, temporalParser::RuleSere, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(106);
      boolean(0);
      break;
    }

    case 2: {
      setState(107);
      match(temporalParser::TIMER);
      setState(108);
      match(temporalParser::LPAREN);
      setState(109);
      boolean(0);
      setState(110);
      match(temporalParser::T__0);
      setState(111);
      match(temporalParser::NUMERIC);
      setState(112);
      match(temporalParser::RPAREN);
      break;
    }

    case 3: {
      setState(114);
      match(temporalParser::LPAREN);
      setState(115);
      sere(0);
      setState(116);
      match(temporalParser::RPAREN);
      break;
    }

    case 4: {
      setState(118);
      match(temporalParser::LGPAREN);
      setState(119);
      sere(0);
      setState(120);
      match(temporalParser::RGPAREN);
      break;
    }

    case 5: {
      setState(122);
      match(temporalParser::DELAY);
      setState(124);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == temporalParser::LCPAREN) {
        setState(123);
        match(temporalParser::LCPAREN);
      }
      setState(126);
      match(temporalParser::NUMERIC);
      setState(128);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == temporalParser::DOTS) {
        setState(127);
        match(temporalParser::DOTS);
      }
      setState(131);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(130);
        match(temporalParser::NUMERIC);
        break;
      }

      default:
        break;
      }
      setState(134);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == temporalParser::RCPAREN) {
        setState(133);
        match(temporalParser::RCPAREN);
      }
      setState(136);
      sere(2);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(213);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(211);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(139);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(140);
          match(temporalParser::BOR);
          setState(141);
          sere(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(142);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(143);
          match(temporalParser::BAND);
          setState(144);
          sere(11);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(145);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(146);
          match(temporalParser::AND);
          setState(147);
          sere(10);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(148);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(149);
          match(temporalParser::SCOL);
          setState(150);
          sere(9);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(151);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(152);
          match(temporalParser::COL);
          setState(153);
          sere(8);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(154);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(155);
          match(temporalParser::DELAY);
          setState(157);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::LCPAREN) {
            setState(156);
            match(temporalParser::LCPAREN);
          }
          setState(160);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
          case 1: {
            setState(159);
            match(temporalParser::NUMERIC);
            break;
          }

          default:
            break;
          }
          setState(163);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::DOTS) {
            setState(162);
            match(temporalParser::DOTS);
          }
          setState(166);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
          case 1: {
            setState(165);
            match(temporalParser::NUMERIC);
            break;
          }

          default:
            break;
          }
          setState(169);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::RCPAREN) {
            setState(168);
            match(temporalParser::RCPAREN);
          }
          setState(171);
          sere(2);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(172);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(173);
          match(temporalParser::LCPAREN);
          setState(174);
          match(temporalParser::TIMES);
          setState(176);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
          case 1: {
            setState(175);
            match(temporalParser::NUMERIC);
            break;
          }

          default:
            break;
          }
          setState(179);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::DOTS) {
            setState(178);
            match(temporalParser::DOTS);
          }
          setState(182);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::NUMERIC) {
            setState(181);
            match(temporalParser::NUMERIC);
          }
          setState(184);
          match(temporalParser::RCPAREN);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(185);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(186);
          match(temporalParser::LCPAREN);
          setState(187);
          match(temporalParser::PLUS);
          setState(188);
          match(temporalParser::RCPAREN);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(189);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(190);
          match(temporalParser::LCPAREN);
          setState(191);
          match(temporalParser::ASS);
          setState(192);
          match(temporalParser::NUMERIC);
          setState(194);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::DOTS) {
            setState(193);
            match(temporalParser::DOTS);
          }
          setState(197);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::NUMERIC) {
            setState(196);
            match(temporalParser::NUMERIC);
          }
          setState(199);
          match(temporalParser::RCPAREN);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<SereContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSere);
          setState(200);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(201);
          match(temporalParser::LCPAREN);
          setState(202);
          match(temporalParser::IMPL);
          setState(203);
          match(temporalParser::NUMERIC);
          setState(205);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::DOTS) {
            setState(204);
            match(temporalParser::DOTS);
          }
          setState(208);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == temporalParser::NUMERIC) {
            setState(207);
            match(temporalParser::NUMERIC);
          }
          setState(210);
          match(temporalParser::RCPAREN);
          break;
        }

        default:
          break;
        } 
      }
      setState(215);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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

tree::TerminalNode* temporalParser::TformulaContext::TIMER() {
  return getToken(temporalParser::TIMER, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::LPAREN() {
  return getToken(temporalParser::LPAREN, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::NUMERIC() {
  return getToken(temporalParser::NUMERIC, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::RPAREN() {
  return getToken(temporalParser::RPAREN, 0);
}

std::vector<temporalParser::TformulaContext *> temporalParser::TformulaContext::tformula() {
  return getRuleContexts<temporalParser::TformulaContext>();
}

temporalParser::TformulaContext* temporalParser::TformulaContext::tformula(size_t i) {
  return getRuleContext<temporalParser::TformulaContext>(i);
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

tree::TerminalNode* temporalParser::TformulaContext::RCPAREN() {
  return getToken(temporalParser::RCPAREN, 0);
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

tree::TerminalNode* temporalParser::TformulaContext::AND() {
  return getToken(temporalParser::AND, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::OR() {
  return getToken(temporalParser::OR, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::XOR() {
  return getToken(temporalParser::XOR, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::UNTIL() {
  return getToken(temporalParser::UNTIL, 0);
}

tree::TerminalNode* temporalParser::TformulaContext::RELEASE() {
  return getToken(temporalParser::RELEASE, 0);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, temporalParser::RuleTformula, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(217);
      boolean(0);
      break;
    }

    case 2: {
      setState(218);
      match(temporalParser::TIMER);
      setState(219);
      match(temporalParser::LPAREN);
      setState(220);
      boolean(0);
      setState(221);
      match(temporalParser::T__0);
      setState(222);
      match(temporalParser::NUMERIC);
      setState(223);
      match(temporalParser::RPAREN);
      break;
    }

    case 3: {
      setState(225);
      match(temporalParser::LPAREN);
      setState(226);
      tformula(0);
      setState(227);
      match(temporalParser::RPAREN);
      break;
    }

    case 4: {
      setState(229);
      match(temporalParser::NOT);
      setState(230);
      tformula(9);
      break;
    }

    case 5: {
      setState(231);
      match(temporalParser::NEXT);
      setState(232);
      match(temporalParser::LCPAREN);
      setState(233);
      match(temporalParser::NUMERIC);
      setState(234);
      match(temporalParser::RCPAREN);
      setState(235);
      tformula(3);
      break;
    }

    case 6: {
      setState(236);
      match(temporalParser::NEXT);
      setState(237);
      tformula(2);
      break;
    }

    case 7: {
      setState(238);
      match(temporalParser::LGPAREN);
      setState(239);
      sere(0);
      setState(240);
      match(temporalParser::RGPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(261);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(259);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(244);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(245);
          match(temporalParser::AND);
          setState(246);
          tformula(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(247);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(248);
          match(temporalParser::OR);
          setState(249);
          tformula(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(250);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(251);
          match(temporalParser::XOR);
          setState(252);
          tformula(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(253);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(254);
          match(temporalParser::UNTIL);
          setState(255);
          tformula(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(256);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(257);
          match(temporalParser::RELEASE);
          setState(258);
          tformula(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(263);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FileContext ------------------------------------------------------------------

temporalParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

temporalParser::BooleanContext* temporalParser::FileContext::boolean() {
  return getRuleContext<temporalParser::BooleanContext>(0);
}

tree::TerminalNode* temporalParser::FileContext::EOF() {
  return getToken(temporalParser::EOF, 0);
}


size_t temporalParser::FileContext::getRuleIndex() const {
  return temporalParser::RuleFile;
}

void temporalParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void temporalParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<temporalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

temporalParser::FileContext* temporalParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 8, temporalParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    boolean(0);
    setState(265);
    match(temporalParser::EOF);
   
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
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, temporalParser::RuleBoolean, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(301);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(268);
      match(temporalParser::NOT);
      setState(269);
      boolean(15);
      break;
    }

    case 2: {
      setState(270);
      logic(0);
      setState(271);
      relop();
      setState(272);
      logic(0);
      break;
    }

    case 3: {
      setState(274);
      numeric(0);
      setState(275);
      relop();
      setState(276);
      numeric(0);
      break;
    }

    case 4: {
      setState(278);
      logic(0);
      setState(279);
      match(temporalParser::EQ);
      setState(280);
      logic(0);
      break;
    }

    case 5: {
      setState(282);
      numeric(0);
      setState(283);
      match(temporalParser::EQ);
      setState(284);
      numeric(0);
      break;
    }

    case 6: {
      setState(286);
      logic(0);
      setState(287);
      match(temporalParser::NEQ);
      setState(288);
      logic(0);
      break;
    }

    case 7: {
      setState(290);
      numeric(0);
      setState(291);
      match(temporalParser::NEQ);
      setState(292);
      numeric(0);
      break;
    }

    case 8: {
      setState(294);
      booleanAtom();
      break;
    }

    case 9: {
      setState(295);
      logic(0);
      break;
    }

    case 10: {
      setState(296);
      numeric(0);
      break;
    }

    case 11: {
      setState(297);
      match(temporalParser::LPAREN);
      setState(298);
      boolean(0);
      setState(299);
      match(temporalParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(317);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(315);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(303);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(304);
          match(temporalParser::EQ);
          setState(305);
          boolean(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(306);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(307);
          match(temporalParser::NEQ);
          setState(308);
          boolean(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(309);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(310);
          antlrcpp::downCast<BooleanContext *>(_localctx)->booleanop = match(temporalParser::AND);
          setState(311);
          boolean(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(312);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(313);
          antlrcpp::downCast<BooleanContext *>(_localctx)->booleanop = match(temporalParser::OR);
          setState(314);
          boolean(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
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
  enterRule(_localctx, 12, temporalParser::RuleBooleanAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case temporalParser::BOOLEAN: {
        enterOuterAlt(_localctx, 1);
        setState(320);
        booleanConstant();
        break;
      }

      case temporalParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(321);
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
  enterRule(_localctx, 14, temporalParser::RuleBooleanConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
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
  enterRule(_localctx, 16, temporalParser::RuleBooleanVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    match(temporalParser::LT);
    setState(327);
    variable();
    setState(328);
    match(temporalParser::T__1);
   
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
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, temporalParser::RuleLogic, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(338);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case temporalParser::NEG: {
        setState(331);
        match(temporalParser::NEG);
        setState(332);
        logic(10);
        break;
      }

      case temporalParser::NUMERIC:
      case temporalParser::VERILOG_BINARY:
      case temporalParser::GCC_BINARY:
      case temporalParser::LT: {
        setState(333);
        logicAtom();
        break;
      }

      case temporalParser::LPAREN: {
        setState(334);
        match(temporalParser::LPAREN);
        setState(335);
        logic(0);
        setState(336);
        match(temporalParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(363);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(361);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(340);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(341);
          antlrcpp::downCast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::TIMES

          || _la == temporalParser::DIV)) {
            antlrcpp::downCast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(342);
          logic(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(343);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(344);
          antlrcpp::downCast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::PLUS

          || _la == temporalParser::MINUS)) {
            antlrcpp::downCast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(345);
          logic(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(346);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(347);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(temporalParser::LSHIFT);
          setState(348);
          logic(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(349);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(350);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(temporalParser::RSHIFT);
          setState(351);
          logic(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(352);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(353);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(temporalParser::BAND);
          setState(354);
          logic(6);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(355);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(356);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(temporalParser::BXOR);
          setState(357);
          logic(5);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(358);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(359);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(temporalParser::BOR);
          setState(360);
          logic(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(365);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
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
  enterRule(_localctx, 20, temporalParser::RuleLogicAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(370);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(366);
      logicConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(367);
      logicVariable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(368);
      enumVariable();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(369);
      namedLogicConst();
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 22, temporalParser::RuleLogicConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
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
  enterRule(_localctx, 24, temporalParser::RuleNamedLogicConst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    match(temporalParser::LT);
    setState(375);
    namedConst();
    setState(376);
    match(temporalParser::T__2);
    setState(377);
    match(temporalParser::NUMERIC);
    setState(378);
    match(temporalParser::T__3);
   
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
  enterRule(_localctx, 26, temporalParser::RuleLogicVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(temporalParser::LT);
    setState(381);
    variable();
    setState(382);
    match(temporalParser::T__4);
    setState(383);
    match(temporalParser::SIGN);
    setState(384);
    match(temporalParser::T__0);
    setState(385);
    match(temporalParser::NUMERIC);
    setState(386);
    match(temporalParser::T__3);
   
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
  enterRule(_localctx, 28, temporalParser::RuleEnumVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    match(temporalParser::LT);
    setState(389);
    variable();
    setState(390);
    match(temporalParser::T__5);
    setState(391);
    enumName();
    setState(392);
    match(temporalParser::T__3);
   
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
  enterRule(_localctx, 30, temporalParser::RuleEnumName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
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
  enterRule(_localctx, 32, temporalParser::RuleNamedConst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
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
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, temporalParser::RuleNumeric, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(399);
      numericAtom();
      break;
    }

    case 2: {
      setState(400);
      logic(0);
      break;
    }

    case 3: {
      setState(401);
      match(temporalParser::LPAREN);
      setState(402);
      numeric(0);
      setState(403);
      match(temporalParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(415);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(413);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(407);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(408);
          antlrcpp::downCast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::TIMES

          || _la == temporalParser::DIV)) {
            antlrcpp::downCast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(409);
          numeric(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(410);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(411);
          antlrcpp::downCast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == temporalParser::PLUS

          || _la == temporalParser::MINUS)) {
            antlrcpp::downCast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(412);
          numeric(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(417);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
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
  enterRule(_localctx, 36, temporalParser::RuleNumericAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(420);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case temporalParser::NUMERIC: {
        enterOuterAlt(_localctx, 1);
        setState(418);
        numericConstant();
        break;
      }

      case temporalParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(419);
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
  enterRule(_localctx, 38, temporalParser::RuleNumericConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(422);
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
  enterRule(_localctx, 40, temporalParser::RuleNumericVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(temporalParser::LT);
    setState(425);
    variable();
    setState(426);
    match(temporalParser::T__6);
    setState(427);
    match(temporalParser::NUMERIC);
    setState(428);
    match(temporalParser::T__3);
   
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
  enterRule(_localctx, 42, temporalParser::RuleVariable);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == temporalParser::TIMES) {
      setState(430);
      match(temporalParser::TIMES);
    }
    setState(433);
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
  enterRule(_localctx, 44, temporalParser::RuleRelop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
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
    case 2: return sereSempred(antlrcpp::downCast<SereContext *>(context), predicateIndex);
    case 3: return tformulaSempred(antlrcpp::downCast<TformulaContext *>(context), predicateIndex);
    case 5: return booleanSempred(antlrcpp::downCast<BooleanContext *>(context), predicateIndex);
    case 9: return logicSempred(antlrcpp::downCast<LogicContext *>(context), predicateIndex);
    case 17: return numericSempred(antlrcpp::downCast<NumericContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool temporalParser::sereSempred(SereContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 1);
    case 6: return precpred(_ctx, 6);
    case 7: return precpred(_ctx, 5);
    case 8: return precpred(_ctx, 4);
    case 9: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool temporalParser::tformulaSempred(TformulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 8);
    case 11: return precpred(_ctx, 7);
    case 12: return precpred(_ctx, 6);
    case 13: return precpred(_ctx, 5);
    case 14: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool temporalParser::booleanSempred(BooleanContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 15: return precpred(_ctx, 10);
    case 16: return precpred(_ctx, 7);
    case 17: return precpred(_ctx, 6);
    case 18: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool temporalParser::logicSempred(LogicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 9);
    case 20: return precpred(_ctx, 8);
    case 21: return precpred(_ctx, 7);
    case 22: return precpred(_ctx, 6);
    case 23: return precpred(_ctx, 5);
    case 24: return precpred(_ctx, 4);
    case 25: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool temporalParser::numericSempred(NumericContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 5);
    case 27: return precpred(_ctx, 4);

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
  "formula", "implication", "sere", "tformula", "file", "boolean", "booleanAtom", 
  "booleanConstant", "booleanVariable", "logic", "logicAtom", "logicConstant", 
  "namedLogicConst", "logicVariable", "enumVariable", "enumName", "namedConst", 
  "numeric", "numericAtom", "numericConstant", "numericVariable", "variable", 
  "relop"
};

std::vector<std::string> temporalParser::_literalNames = {
  "", "','", "',bool>'", "',constlogic('", "')>'", "',logic('", "',enum('", 
  "',numeric('", "'$timeout'", "'F'", "'G'", "'X'", "'U'", "'W'", "'X[!]'", 
  "'R'", "'M'", "'..'", "'->'", "'=>'", "'|->'", "'|=>'", "'<->'", "'xor'", 
  "'<>->'", "'<>=>'", "'='", "';'", "':'", "'first_match'", "'##'", "", 
  "'{'", "'}'", "'['", "']'", "'('", "')'", "'bool'", "'double'", "", "", 
  "", "", "", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", 
  "'=='", "'!='", "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", "'&&'", "'||'", 
  "'!'"
};

std::vector<std::string> temporalParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "TIMER", "EVENTUALLY", "ALWAYS", "NEXT", 
  "UNTIL", "WUNTIL", "SUNTIL", "RELEASE", "SRELEASE", "DOTS", "IMPL", "IMPL2", 
  "SEREIMPL1", "SEREIMPL2", "IFF", "XOR", "BIND1", "BIND2", "ASS", "SCOL", 
  "COL", "FIRST_MATCH", "DELAY", "SIGN", "LGPAREN", "RGPAREN", "LCPAREN", 
  "RCPAREN", "LPAREN", "RPAREN", "CAST_BOOL", "CAST_NUMERIC", "VARIABLE", 
  "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "BOOLEAN", "PLUS", "MINUS", 
  "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", 
  "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", "WS"
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x42, 0x1b8, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x5, 0x3, 0x6a, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x7f, 0xa, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0x83, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x86, 
       0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x89, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0x8c, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x5, 0x4, 0xa0, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa3, 0xa, 0x4, 0x3, 
       0x4, 0x5, 0x4, 0xa6, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa9, 0xa, 0x4, 
       0x3, 0x4, 0x5, 0x4, 0xac, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb3, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0xb6, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0xb9, 0xa, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xc5, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0xc8, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x5, 0x4, 0xd0, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0xd3, 0xa, 
       0x4, 0x3, 0x4, 0x7, 0x4, 0xd6, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xd9, 
       0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x5, 0x5, 0xf5, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
       0x106, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x109, 0xb, 0x5, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x130, 0xa, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x13e, 0xa, 
       0x7, 0xc, 0x7, 0xe, 0x7, 0x141, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 
       0x8, 0x145, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x155, 0xa, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x7, 0xb, 0x16c, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x16f, 0xb, 0xb, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x175, 0xa, 0xc, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x5, 0x13, 0x198, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x1a0, 0xa, 
       0x13, 0xc, 0x13, 0xe, 0x13, 0x1a3, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 
       0x5, 0x14, 0x1a7, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x5, 
       0x17, 0x1b2, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x2, 0x7, 0x6, 0x8, 0xc, 0x14, 0x24, 0x19, 0x2, 0x4, 0x6, 
       0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
       0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x6, 0x3, 0x2, 
       0x31, 0x32, 0x3, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2b, 0x2d, 0x3, 0x2, 
       0x33, 0x36, 0x2, 0x1ef, 0x2, 0x30, 0x3, 0x2, 0x2, 0x2, 0x4, 0x69, 
       0x3, 0x2, 0x2, 0x2, 0x6, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8, 0xf4, 0x3, 
       0x2, 0x2, 0x2, 0xa, 0x10a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x12f, 0x3, 0x2, 
       0x2, 0x2, 0xe, 0x144, 0x3, 0x2, 0x2, 0x2, 0x10, 0x146, 0x3, 0x2, 
       0x2, 0x2, 0x12, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14, 0x154, 0x3, 0x2, 
       0x2, 0x2, 0x16, 0x174, 0x3, 0x2, 0x2, 0x2, 0x18, 0x176, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x17e, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0x186, 0x3, 0x2, 0x2, 0x2, 0x20, 0x18c, 0x3, 0x2, 
       0x2, 0x2, 0x22, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x24, 0x197, 0x3, 0x2, 
       0x2, 0x2, 0x26, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1a8, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1b1, 0x3, 0x2, 
       0x2, 0x2, 0x2e, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0x4, 
       0x3, 0x2, 0x31, 0x32, 0x7, 0x2, 0x2, 0x3, 0x32, 0x3, 0x3, 0x2, 0x2, 
       0x2, 0x33, 0x34, 0x7, 0xc, 0x2, 0x2, 0x34, 0x35, 0x7, 0x26, 0x2, 
       0x2, 0x35, 0x36, 0x5, 0x8, 0x5, 0x2, 0x36, 0x37, 0x7, 0x14, 0x2, 
       0x2, 0x37, 0x38, 0x5, 0x8, 0x5, 0x2, 0x38, 0x39, 0x7, 0x27, 0x2, 
       0x2, 0x39, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0xc, 0x2, 0x2, 
       0x3b, 0x3c, 0x7, 0x26, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x8, 0x5, 0x2, 
       0x3d, 0x3e, 0x7, 0x15, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0x8, 0x5, 0x2, 
       0x3f, 0x40, 0x7, 0x27, 0x2, 0x2, 0x40, 0x6a, 0x3, 0x2, 0x2, 0x2, 
       0x41, 0x42, 0x7, 0xc, 0x2, 0x2, 0x42, 0x43, 0x7, 0x26, 0x2, 0x2, 
       0x43, 0x44, 0x7, 0x22, 0x2, 0x2, 0x44, 0x45, 0x5, 0x6, 0x4, 0x2, 
       0x45, 0x46, 0x7, 0x23, 0x2, 0x2, 0x46, 0x47, 0x7, 0x24, 0x2, 0x2, 
       0x47, 0x48, 0x7, 0x25, 0x2, 0x2, 0x48, 0x49, 0x7, 0x14, 0x2, 0x2, 
       0x49, 0x4a, 0x5, 0x8, 0x5, 0x2, 0x4a, 0x4b, 0x7, 0x27, 0x2, 0x2, 
       0x4b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0xc, 0x2, 0x2, 0x4d, 
       0x4e, 0x7, 0x26, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x22, 0x2, 0x2, 0x4f, 
       0x50, 0x5, 0x6, 0x4, 0x2, 0x50, 0x51, 0x7, 0x23, 0x2, 0x2, 0x51, 
       0x52, 0x7, 0x24, 0x2, 0x2, 0x52, 0x53, 0x7, 0x25, 0x2, 0x2, 0x53, 
       0x54, 0x7, 0x15, 0x2, 0x2, 0x54, 0x55, 0x5, 0x8, 0x5, 0x2, 0x55, 
       0x56, 0x7, 0x27, 0x2, 0x2, 0x56, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x57, 
       0x58, 0x7, 0xc, 0x2, 0x2, 0x58, 0x59, 0x7, 0x26, 0x2, 0x2, 0x59, 
       0x5a, 0x7, 0x22, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0x6, 0x4, 0x2, 0x5b, 
       0x5c, 0x7, 0x23, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x16, 0x2, 0x2, 0x5d, 
       0x5e, 0x5, 0x8, 0x5, 0x2, 0x5e, 0x5f, 0x7, 0x27, 0x2, 0x2, 0x5f, 
       0x6a, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0xc, 0x2, 0x2, 0x61, 0x62, 
       0x7, 0x26, 0x2, 0x2, 0x62, 0x63, 0x7, 0x22, 0x2, 0x2, 0x63, 0x64, 
       0x5, 0x6, 0x4, 0x2, 0x64, 0x65, 0x7, 0x23, 0x2, 0x2, 0x65, 0x66, 
       0x7, 0x17, 0x2, 0x2, 0x66, 0x67, 0x5, 0x8, 0x5, 0x2, 0x67, 0x68, 
       0x7, 0x27, 0x2, 0x2, 0x68, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x69, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x69, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x69, 0x41, 0x3, 
       0x2, 0x2, 0x2, 0x69, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x69, 0x57, 0x3, 0x2, 
       0x2, 0x2, 0x69, 0x60, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0x6b, 0x6c, 0x8, 0x4, 0x1, 0x2, 0x6c, 0x8c, 0x5, 0xc, 0x7, 0x2, 
       0x6d, 0x6e, 0x7, 0xa, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x26, 0x2, 0x2, 
       0x6f, 0x70, 0x5, 0xc, 0x7, 0x2, 0x70, 0x71, 0x7, 0x3, 0x2, 0x2, 0x71, 
       0x72, 0x7, 0x2b, 0x2, 0x2, 0x72, 0x73, 0x7, 0x27, 0x2, 0x2, 0x73, 
       0x8c, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x26, 0x2, 0x2, 0x75, 
       0x76, 0x5, 0x6, 0x4, 0x2, 0x76, 0x77, 0x7, 0x27, 0x2, 0x2, 0x77, 
       0x8c, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0x22, 0x2, 0x2, 0x79, 
       0x7a, 0x5, 0x6, 0x4, 0x2, 0x7a, 0x7b, 0x7, 0x23, 0x2, 0x2, 0x7b, 
       0x8c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x7, 0x20, 0x2, 0x2, 0x7d, 
       0x7f, 0x7, 0x24, 0x2, 0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7e, 
       0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 
       0x7, 0x2b, 0x2, 0x2, 0x81, 0x83, 0x7, 0x13, 0x2, 0x2, 0x82, 0x81, 
       0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x85, 0x3, 
       0x2, 0x2, 0x2, 0x84, 0x86, 0x7, 0x2b, 0x2, 0x2, 0x85, 0x84, 0x3, 
       0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 
       0x2, 0x2, 0x87, 0x89, 0x7, 0x25, 0x2, 0x2, 0x88, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 
       0x2, 0x8a, 0x8c, 0x5, 0x6, 0x4, 0x4, 0x8b, 0x6b, 0x3, 0x2, 0x2, 0x2, 
       0x8b, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x74, 0x3, 0x2, 0x2, 0x2, 0x8b, 
       0x78, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0xd7, 
       0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0xc, 0xd, 0x2, 0x2, 0x8e, 0x8f, 0x7, 
       0x3a, 0x2, 0x2, 0x8f, 0xd6, 0x5, 0x6, 0x4, 0xe, 0x90, 0x91, 0xc, 
       0xc, 0x2, 0x2, 0x91, 0x92, 0x7, 0x39, 0x2, 0x2, 0x92, 0xd6, 0x5, 
       0x6, 0x4, 0xd, 0x93, 0x94, 0xc, 0xb, 0x2, 0x2, 0x94, 0x95, 0x7, 0x3f, 
       0x2, 0x2, 0x95, 0xd6, 0x5, 0x6, 0x4, 0xc, 0x96, 0x97, 0xc, 0xa, 0x2, 
       0x2, 0x97, 0x98, 0x7, 0x1d, 0x2, 0x2, 0x98, 0xd6, 0x5, 0x6, 0x4, 
       0xb, 0x99, 0x9a, 0xc, 0x9, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x1e, 0x2, 
       0x2, 0x9b, 0xd6, 0x5, 0x6, 0x4, 0xa, 0x9c, 0x9d, 0xc, 0x3, 0x2, 0x2, 
       0x9d, 0x9f, 0x7, 0x20, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x24, 0x2, 0x2, 
       0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 
       0xa2, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x7, 0x2b, 0x2, 0x2, 0xa2, 
       0xa1, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa5, 
       0x3, 0x2, 0x2, 0x2, 0xa4, 0xa6, 0x7, 0x13, 0x2, 0x2, 0xa5, 0xa4, 
       0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x3, 
       0x2, 0x2, 0x2, 0xa7, 0xa9, 0x7, 0x2b, 0x2, 0x2, 0xa8, 0xa7, 0x3, 
       0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xab, 0x3, 0x2, 
       0x2, 0x2, 0xaa, 0xac, 0x7, 0x25, 0x2, 0x2, 0xab, 0xaa, 0x3, 0x2, 
       0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 
       0x2, 0xad, 0xd6, 0x5, 0x6, 0x4, 0x4, 0xae, 0xaf, 0xc, 0x8, 0x2, 0x2, 
       0xaf, 0xb0, 0x7, 0x24, 0x2, 0x2, 0xb0, 0xb2, 0x7, 0x31, 0x2, 0x2, 
       0xb1, 0xb3, 0x7, 0x2b, 0x2, 0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 0x2, 
       0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb4, 
       0xb6, 0x7, 0x13, 0x2, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb5, 
       0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 
       0x7, 0x2b, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xd6, 0x7, 
       0x25, 0x2, 0x2, 0xbb, 0xbc, 0xc, 0x7, 0x2, 0x2, 0xbc, 0xbd, 0x7, 
       0x24, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x2f, 0x2, 0x2, 0xbe, 0xd6, 0x7, 
       0x25, 0x2, 0x2, 0xbf, 0xc0, 0xc, 0x6, 0x2, 0x2, 0xc0, 0xc1, 0x7, 
       0x24, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x1c, 0x2, 0x2, 0xc2, 0xc4, 0x7, 
       0x2b, 0x2, 0x2, 0xc3, 0xc5, 0x7, 0x13, 0x2, 0x2, 0xc4, 0xc3, 0x3, 
       0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 
       0x2, 0x2, 0xc6, 0xc8, 0x7, 0x2b, 0x2, 0x2, 0xc7, 0xc6, 0x3, 0x2, 
       0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 
       0x2, 0xc9, 0xd6, 0x7, 0x25, 0x2, 0x2, 0xca, 0xcb, 0xc, 0x5, 0x2, 
       0x2, 0xcb, 0xcc, 0x7, 0x24, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x14, 0x2, 
       0x2, 0xcd, 0xcf, 0x7, 0x2b, 0x2, 0x2, 0xce, 0xd0, 0x7, 0x13, 0x2, 
       0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 
       0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd3, 0x7, 0x2b, 0x2, 0x2, 
       0xd2, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 
       0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd6, 0x7, 0x25, 0x2, 0x2, 0xd5, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x90, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x93, 
       0x3, 0x2, 0x2, 0x2, 0xd5, 0x96, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x99, 0x3, 
       0x2, 0x2, 0x2, 0xd5, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xae, 0x3, 0x2, 
       0x2, 0x2, 0xd5, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xbf, 0x3, 0x2, 0x2, 
       0x2, 0xd5, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 
       0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 
       0x7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 
       0x8, 0x5, 0x1, 0x2, 0xdb, 0xf5, 0x5, 0xc, 0x7, 0x2, 0xdc, 0xdd, 0x7, 
       0xa, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x26, 0x2, 0x2, 0xde, 0xdf, 0x5, 
       0xc, 0x7, 0x2, 0xdf, 0xe0, 0x7, 0x3, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x2b, 
       0x2, 0x2, 0xe1, 0xe2, 0x7, 0x27, 0x2, 0x2, 0xe2, 0xf5, 0x3, 0x2, 
       0x2, 0x2, 0xe3, 0xe4, 0x7, 0x26, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x8, 
       0x5, 0x2, 0xe5, 0xe6, 0x7, 0x27, 0x2, 0x2, 0xe6, 0xf5, 0x3, 0x2, 
       0x2, 0x2, 0xe7, 0xe8, 0x7, 0x41, 0x2, 0x2, 0xe8, 0xf5, 0x5, 0x8, 
       0x5, 0xb, 0xe9, 0xea, 0x7, 0xd, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x24, 
       0x2, 0x2, 0xeb, 0xec, 0x7, 0x2b, 0x2, 0x2, 0xec, 0xed, 0x7, 0x25, 
       0x2, 0x2, 0xed, 0xf5, 0x5, 0x8, 0x5, 0x5, 0xee, 0xef, 0x7, 0xd, 0x2, 
       0x2, 0xef, 0xf5, 0x5, 0x8, 0x5, 0x4, 0xf0, 0xf1, 0x7, 0x22, 0x2, 
       0x2, 0xf1, 0xf2, 0x5, 0x6, 0x4, 0x2, 0xf2, 0xf3, 0x7, 0x23, 0x2, 
       0x2, 0xf3, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xda, 0x3, 0x2, 0x2, 0x2, 
       0xf4, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf4, 
       0xe7, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xee, 
       0x3, 0x2, 0x2, 0x2, 0xf4, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf5, 0x107, 
       0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0xc, 0xa, 0x2, 0x2, 0xf7, 0xf8, 0x7, 
       0x3f, 0x2, 0x2, 0xf8, 0x106, 0x5, 0x8, 0x5, 0xb, 0xf9, 0xfa, 0xc, 
       0x9, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x40, 0x2, 0x2, 0xfb, 0x106, 0x5, 
       0x8, 0x5, 0xa, 0xfc, 0xfd, 0xc, 0x8, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x19, 
       0x2, 0x2, 0xfe, 0x106, 0x5, 0x8, 0x5, 0x9, 0xff, 0x100, 0xc, 0x7, 
       0x2, 0x2, 0x100, 0x101, 0x7, 0xe, 0x2, 0x2, 0x101, 0x106, 0x5, 0x8, 
       0x5, 0x8, 0x102, 0x103, 0xc, 0x6, 0x2, 0x2, 0x103, 0x104, 0x7, 0x11, 
       0x2, 0x2, 0x104, 0x106, 0x5, 0x8, 0x5, 0x7, 0x105, 0xf6, 0x3, 0x2, 
       0x2, 0x2, 0x105, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x105, 0xfc, 0x3, 0x2, 
       0x2, 0x2, 0x105, 0xff, 0x3, 0x2, 0x2, 0x2, 0x105, 0x102, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x109, 0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 
       0x2, 0x2, 0x107, 0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 0x9, 0x3, 0x2, 
       0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x5, 0xc, 
       0x7, 0x2, 0x10b, 0x10c, 0x7, 0x2, 0x2, 0x3, 0x10c, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0x10d, 0x10e, 0x8, 0x7, 0x1, 0x2, 0x10e, 0x10f, 0x7, 0x41, 
       0x2, 0x2, 0x10f, 0x130, 0x5, 0xc, 0x7, 0x11, 0x110, 0x111, 0x5, 0x14, 
       0xb, 0x2, 0x111, 0x112, 0x5, 0x2e, 0x18, 0x2, 0x112, 0x113, 0x5, 
       0x14, 0xb, 0x2, 0x113, 0x130, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x5, 
       0x24, 0x13, 0x2, 0x115, 0x116, 0x5, 0x2e, 0x18, 0x2, 0x116, 0x117, 
       0x5, 0x24, 0x13, 0x2, 0x117, 0x130, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
       0x5, 0x14, 0xb, 0x2, 0x119, 0x11a, 0x7, 0x37, 0x2, 0x2, 0x11a, 0x11b, 
       0x5, 0x14, 0xb, 0x2, 0x11b, 0x130, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 
       0x5, 0x24, 0x13, 0x2, 0x11d, 0x11e, 0x7, 0x37, 0x2, 0x2, 0x11e, 0x11f, 
       0x5, 0x24, 0x13, 0x2, 0x11f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
       0x5, 0x14, 0xb, 0x2, 0x121, 0x122, 0x7, 0x38, 0x2, 0x2, 0x122, 0x123, 
       0x5, 0x14, 0xb, 0x2, 0x123, 0x130, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 
       0x5, 0x24, 0x13, 0x2, 0x125, 0x126, 0x7, 0x38, 0x2, 0x2, 0x126, 0x127, 
       0x5, 0x24, 0x13, 0x2, 0x127, 0x130, 0x3, 0x2, 0x2, 0x2, 0x128, 0x130, 
       0x5, 0xe, 0x8, 0x2, 0x129, 0x130, 0x5, 0x14, 0xb, 0x2, 0x12a, 0x130, 
       0x5, 0x24, 0x13, 0x2, 0x12b, 0x12c, 0x7, 0x26, 0x2, 0x2, 0x12c, 0x12d, 
       0x5, 0xc, 0x7, 0x2, 0x12d, 0x12e, 0x7, 0x27, 0x2, 0x2, 0x12e, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x110, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x114, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x118, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x120, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x124, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x128, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12a, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x130, 0x13f, 
       0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0xc, 0xc, 0x2, 0x2, 0x132, 0x133, 
       0x7, 0x37, 0x2, 0x2, 0x133, 0x13e, 0x5, 0xc, 0x7, 0xd, 0x134, 0x135, 
       0xc, 0x9, 0x2, 0x2, 0x135, 0x136, 0x7, 0x38, 0x2, 0x2, 0x136, 0x13e, 
       0x5, 0xc, 0x7, 0xa, 0x137, 0x138, 0xc, 0x8, 0x2, 0x2, 0x138, 0x139, 
       0x7, 0x3f, 0x2, 0x2, 0x139, 0x13e, 0x5, 0xc, 0x7, 0x9, 0x13a, 0x13b, 
       0xc, 0x7, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x40, 0x2, 0x2, 0x13c, 0x13e, 
       0x5, 0xc, 0x7, 0x8, 0x13d, 0x131, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x134, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x13e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 
       0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0xd, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x145, 
       0x5, 0x10, 0x9, 0x2, 0x143, 0x145, 0x5, 0x12, 0xa, 0x2, 0x144, 0x142, 
       0x3, 0x2, 0x2, 0x2, 0x144, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 0x2e, 0x2, 0x2, 0x147, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x7, 0x35, 0x2, 0x2, 0x149, 0x14a, 
       0x5, 0x2c, 0x17, 0x2, 0x14a, 0x14b, 0x7, 0x4, 0x2, 0x2, 0x14b, 0x13, 
       0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x8, 0xb, 0x1, 0x2, 0x14d, 0x14e, 
       0x7, 0x3c, 0x2, 0x2, 0x14e, 0x155, 0x5, 0x14, 0xb, 0xc, 0x14f, 0x155, 
       0x5, 0x16, 0xc, 0x2, 0x150, 0x151, 0x7, 0x26, 0x2, 0x2, 0x151, 0x152, 
       0x5, 0x14, 0xb, 0x2, 0x152, 0x153, 0x7, 0x27, 0x2, 0x2, 0x153, 0x155, 
       0x3, 0x2, 0x2, 0x2, 0x154, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x154, 0x14f, 
       0x3, 0x2, 0x2, 0x2, 0x154, 0x150, 0x3, 0x2, 0x2, 0x2, 0x155, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0xc, 0xb, 0x2, 0x2, 0x157, 0x158, 
       0x9, 0x2, 0x2, 0x2, 0x158, 0x16c, 0x5, 0x14, 0xb, 0xc, 0x159, 0x15a, 
       0xc, 0xa, 0x2, 0x2, 0x15a, 0x15b, 0x9, 0x3, 0x2, 0x2, 0x15b, 0x16c, 
       0x5, 0x14, 0xb, 0xb, 0x15c, 0x15d, 0xc, 0x9, 0x2, 0x2, 0x15d, 0x15e, 
       0x7, 0x3d, 0x2, 0x2, 0x15e, 0x16c, 0x5, 0x14, 0xb, 0xa, 0x15f, 0x160, 
       0xc, 0x8, 0x2, 0x2, 0x160, 0x161, 0x7, 0x3e, 0x2, 0x2, 0x161, 0x16c, 
       0x5, 0x14, 0xb, 0x9, 0x162, 0x163, 0xc, 0x7, 0x2, 0x2, 0x163, 0x164, 
       0x7, 0x39, 0x2, 0x2, 0x164, 0x16c, 0x5, 0x14, 0xb, 0x8, 0x165, 0x166, 
       0xc, 0x6, 0x2, 0x2, 0x166, 0x167, 0x7, 0x3b, 0x2, 0x2, 0x167, 0x16c, 
       0x5, 0x14, 0xb, 0x7, 0x168, 0x169, 0xc, 0x5, 0x2, 0x2, 0x169, 0x16a, 
       0x7, 0x3a, 0x2, 0x2, 0x16a, 0x16c, 0x5, 0x14, 0xb, 0x6, 0x16b, 0x156, 
       0x3, 0x2, 0x2, 0x2, 0x16b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x15c, 
       0x3, 0x2, 0x2, 0x2, 0x16b, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x162, 
       0x3, 0x2, 0x2, 0x2, 0x16b, 0x165, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x168, 
       0x3, 0x2, 0x2, 0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 
       0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x15, 
       0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x170, 0x175, 
       0x5, 0x18, 0xd, 0x2, 0x171, 0x175, 0x5, 0x1c, 0xf, 0x2, 0x172, 0x175, 
       0x5, 0x1e, 0x10, 0x2, 0x173, 0x175, 0x5, 0x1a, 0xe, 0x2, 0x174, 0x170, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x171, 0x3, 0x2, 0x2, 0x2, 0x174, 0x172, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x173, 0x3, 0x2, 0x2, 0x2, 0x175, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x9, 0x4, 0x2, 0x2, 0x177, 0x19, 
       0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x7, 0x35, 0x2, 0x2, 0x179, 0x17a, 
       0x5, 0x22, 0x12, 0x2, 0x17a, 0x17b, 0x7, 0x5, 0x2, 0x2, 0x17b, 0x17c, 
       0x7, 0x2b, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x6, 0x2, 0x2, 0x17d, 0x1b, 
       0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x35, 0x2, 0x2, 0x17f, 0x180, 
       0x5, 0x2c, 0x17, 0x2, 0x180, 0x181, 0x7, 0x7, 0x2, 0x2, 0x181, 0x182, 
       0x7, 0x21, 0x2, 0x2, 0x182, 0x183, 0x7, 0x3, 0x2, 0x2, 0x183, 0x184, 
       0x7, 0x2b, 0x2, 0x2, 0x184, 0x185, 0x7, 0x6, 0x2, 0x2, 0x185, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x7, 0x35, 0x2, 0x2, 0x187, 0x188, 
       0x5, 0x2c, 0x17, 0x2, 0x188, 0x189, 0x7, 0x8, 0x2, 0x2, 0x189, 0x18a, 
       0x5, 0x20, 0x11, 0x2, 0x18a, 0x18b, 0x7, 0x6, 0x2, 0x2, 0x18b, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x2a, 0x2, 0x2, 0x18d, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x7, 0x2a, 0x2, 0x2, 0x18f, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x8, 0x13, 0x1, 0x2, 0x191, 0x198, 
       0x5, 0x26, 0x14, 0x2, 0x192, 0x198, 0x5, 0x14, 0xb, 0x2, 0x193, 0x194, 
       0x7, 0x26, 0x2, 0x2, 0x194, 0x195, 0x5, 0x24, 0x13, 0x2, 0x195, 0x196, 
       0x7, 0x27, 0x2, 0x2, 0x196, 0x198, 0x3, 0x2, 0x2, 0x2, 0x197, 0x190, 
       0x3, 0x2, 0x2, 0x2, 0x197, 0x192, 0x3, 0x2, 0x2, 0x2, 0x197, 0x193, 
       0x3, 0x2, 0x2, 0x2, 0x198, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 
       0xc, 0x7, 0x2, 0x2, 0x19a, 0x19b, 0x9, 0x2, 0x2, 0x2, 0x19b, 0x1a0, 
       0x5, 0x24, 0x13, 0x8, 0x19c, 0x19d, 0xc, 0x6, 0x2, 0x2, 0x19d, 0x19e, 
       0x9, 0x3, 0x2, 0x2, 0x19e, 0x1a0, 0x5, 0x24, 0x13, 0x7, 0x19f, 0x199, 
       0x3, 0x2, 0x2, 0x2, 0x19f, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a3, 
       0x3, 0x2, 0x2, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 
       0x3, 0x2, 0x2, 0x2, 0x1a2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a1, 
       0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a7, 0x5, 0x28, 0x15, 0x2, 0x1a5, 0x1a7, 
       0x5, 0x2a, 0x16, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a5, 
       0x3, 0x2, 0x2, 0x2, 0x1a7, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 
       0x7, 0x2b, 0x2, 0x2, 0x1a9, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 
       0x7, 0x35, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 0x2c, 0x17, 0x2, 0x1ac, 0x1ad, 
       0x7, 0x9, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x2b, 0x2, 0x2, 0x1ae, 0x1af, 
       0x7, 0x6, 0x2, 0x2, 0x1af, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b2, 
       0x7, 0x31, 0x2, 0x2, 0x1b1, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 
       0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 
       0x7, 0x2a, 0x2, 0x2, 0x1b4, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 
       0x9, 0x5, 0x2, 0x2, 0x1b6, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x26, 0x69, 
       0x7e, 0x82, 0x85, 0x88, 0x8b, 0x9f, 0xa2, 0xa5, 0xa8, 0xab, 0xb2, 
       0xb5, 0xb8, 0xc4, 0xc7, 0xcf, 0xd2, 0xd5, 0xd7, 0xf4, 0x105, 0x107, 
       0x12f, 0x13d, 0x13f, 0x144, 0x154, 0x16b, 0x16d, 0x174, 0x197, 0x19f, 
       0x1a1, 0x1a6, 0x1b1, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

temporalParser::Initializer temporalParser::_init;
