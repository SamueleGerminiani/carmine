
// Generated from proposition.g4 by ANTLR 4.7.2


#include "propositionListener.h"

#include "propositionParser.h"


using namespace antlrcpp;
using namespace antlr4;

propositionParser::propositionParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

propositionParser::~propositionParser() {
  delete _interpreter;
}

std::string propositionParser::getGrammarFileName() const {
  return "proposition.g4";
}

const std::vector<std::string>& propositionParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& propositionParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

propositionParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::BooleanContext* propositionParser::FileContext::boolean() {
  return getRuleContext<propositionParser::BooleanContext>(0);
}

tree::TerminalNode* propositionParser::FileContext::EOF() {
  return getToken(propositionParser::EOF, 0);
}


size_t propositionParser::FileContext::getRuleIndex() const {
  return propositionParser::RuleFile;
}

void propositionParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void propositionParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

propositionParser::FileContext* propositionParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, propositionParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    boolean(0);
    setState(39);
    match(propositionParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

propositionParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::BooleanContext::NOT() {
  return getToken(propositionParser::NOT, 0);
}

std::vector<propositionParser::BooleanContext *> propositionParser::BooleanContext::boolean() {
  return getRuleContexts<propositionParser::BooleanContext>();
}

propositionParser::BooleanContext* propositionParser::BooleanContext::boolean(size_t i) {
  return getRuleContext<propositionParser::BooleanContext>(i);
}

std::vector<propositionParser::LogicContext *> propositionParser::BooleanContext::logic() {
  return getRuleContexts<propositionParser::LogicContext>();
}

propositionParser::LogicContext* propositionParser::BooleanContext::logic(size_t i) {
  return getRuleContext<propositionParser::LogicContext>(i);
}

propositionParser::RelopContext* propositionParser::BooleanContext::relop() {
  return getRuleContext<propositionParser::RelopContext>(0);
}

std::vector<propositionParser::NumericContext *> propositionParser::BooleanContext::numeric() {
  return getRuleContexts<propositionParser::NumericContext>();
}

propositionParser::NumericContext* propositionParser::BooleanContext::numeric(size_t i) {
  return getRuleContext<propositionParser::NumericContext>(i);
}

tree::TerminalNode* propositionParser::BooleanContext::EQ() {
  return getToken(propositionParser::EQ, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::NEQ() {
  return getToken(propositionParser::NEQ, 0);
}

propositionParser::BooleanAtomContext* propositionParser::BooleanContext::booleanAtom() {
  return getRuleContext<propositionParser::BooleanAtomContext>(0);
}

tree::TerminalNode* propositionParser::BooleanContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::AND() {
  return getToken(propositionParser::AND, 0);
}

tree::TerminalNode* propositionParser::BooleanContext::OR() {
  return getToken(propositionParser::OR, 0);
}


size_t propositionParser::BooleanContext::getRuleIndex() const {
  return propositionParser::RuleBoolean;
}

void propositionParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void propositionParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


propositionParser::BooleanContext* propositionParser::boolean() {
   return boolean(0);
}

propositionParser::BooleanContext* propositionParser::boolean(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, parentState);
  propositionParser::BooleanContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, propositionParser::RuleBoolean, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(42);
      match(propositionParser::NOT);
      setState(43);
      boolean(15);
      break;
    }

    case 2: {
      setState(44);
      logic(0);
      setState(45);
      relop();
      setState(46);
      logic(0);
      break;
    }

    case 3: {
      setState(48);
      numeric(0);
      setState(49);
      relop();
      setState(50);
      numeric(0);
      break;
    }

    case 4: {
      setState(52);
      logic(0);
      setState(53);
      match(propositionParser::EQ);
      setState(54);
      logic(0);
      break;
    }

    case 5: {
      setState(56);
      numeric(0);
      setState(57);
      match(propositionParser::EQ);
      setState(58);
      numeric(0);
      break;
    }

    case 6: {
      setState(60);
      logic(0);
      setState(61);
      match(propositionParser::NEQ);
      setState(62);
      logic(0);
      break;
    }

    case 7: {
      setState(64);
      numeric(0);
      setState(65);
      match(propositionParser::NEQ);
      setState(66);
      numeric(0);
      break;
    }

    case 8: {
      setState(68);
      booleanAtom();
      break;
    }

    case 9: {
      setState(69);
      logic(0);
      break;
    }

    case 10: {
      setState(70);
      numeric(0);
      break;
    }

    case 11: {
      setState(71);
      match(propositionParser::LPAREN);
      setState(72);
      boolean(0);
      setState(73);
      match(propositionParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(91);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(89);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(77);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(78);
          match(propositionParser::EQ);
          setState(79);
          boolean(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(80);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(81);
          match(propositionParser::NEQ);
          setState(82);
          boolean(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(83);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(84);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(propositionParser::AND);
          setState(85);
          boolean(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(86);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(87);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(propositionParser::OR);
          setState(88);
          boolean(6);
          break;
        }

        } 
      }
      setState(93);
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

//----------------- BooleanAtomContext ------------------------------------------------------------------

propositionParser::BooleanAtomContext::BooleanAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::BooleanConstantContext* propositionParser::BooleanAtomContext::booleanConstant() {
  return getRuleContext<propositionParser::BooleanConstantContext>(0);
}

propositionParser::BooleanVariableContext* propositionParser::BooleanAtomContext::booleanVariable() {
  return getRuleContext<propositionParser::BooleanVariableContext>(0);
}


size_t propositionParser::BooleanAtomContext::getRuleIndex() const {
  return propositionParser::RuleBooleanAtom;
}

void propositionParser::BooleanAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanAtom(this);
}

void propositionParser::BooleanAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanAtom(this);
}

propositionParser::BooleanAtomContext* propositionParser::booleanAtom() {
  BooleanAtomContext *_localctx = _tracker.createInstance<BooleanAtomContext>(_ctx, getState());
  enterRule(_localctx, 4, propositionParser::RuleBooleanAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(96);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::BOOLEAN: {
        enterOuterAlt(_localctx, 1);
        setState(94);
        booleanConstant();
        break;
      }

      case propositionParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(95);
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

propositionParser::BooleanConstantContext::BooleanConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::BooleanConstantContext::BOOLEAN() {
  return getToken(propositionParser::BOOLEAN, 0);
}


size_t propositionParser::BooleanConstantContext::getRuleIndex() const {
  return propositionParser::RuleBooleanConstant;
}

void propositionParser::BooleanConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanConstant(this);
}

void propositionParser::BooleanConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanConstant(this);
}

propositionParser::BooleanConstantContext* propositionParser::booleanConstant() {
  BooleanConstantContext *_localctx = _tracker.createInstance<BooleanConstantContext>(_ctx, getState());
  enterRule(_localctx, 6, propositionParser::RuleBooleanConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    match(propositionParser::BOOLEAN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanVariableContext ------------------------------------------------------------------

propositionParser::BooleanVariableContext::BooleanVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::BooleanVariableContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::VariableContext* propositionParser::BooleanVariableContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}


size_t propositionParser::BooleanVariableContext::getRuleIndex() const {
  return propositionParser::RuleBooleanVariable;
}

void propositionParser::BooleanVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanVariable(this);
}

void propositionParser::BooleanVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanVariable(this);
}

propositionParser::BooleanVariableContext* propositionParser::booleanVariable() {
  BooleanVariableContext *_localctx = _tracker.createInstance<BooleanVariableContext>(_ctx, getState());
  enterRule(_localctx, 8, propositionParser::RuleBooleanVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(propositionParser::LT);
    setState(101);
    variable();
    setState(102);
    match(propositionParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicContext ------------------------------------------------------------------

propositionParser::LogicContext::LogicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LogicContext::NEG() {
  return getToken(propositionParser::NEG, 0);
}

std::vector<propositionParser::LogicContext *> propositionParser::LogicContext::logic() {
  return getRuleContexts<propositionParser::LogicContext>();
}

propositionParser::LogicContext* propositionParser::LogicContext::logic(size_t i) {
  return getRuleContext<propositionParser::LogicContext>(i);
}

propositionParser::LogicAtomContext* propositionParser::LogicContext::logicAtom() {
  return getRuleContext<propositionParser::LogicAtomContext>(0);
}

tree::TerminalNode* propositionParser::LogicContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

tree::TerminalNode* propositionParser::LogicContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::LogicContext::TIMES() {
  return getToken(propositionParser::TIMES, 0);
}

tree::TerminalNode* propositionParser::LogicContext::DIV() {
  return getToken(propositionParser::DIV, 0);
}

tree::TerminalNode* propositionParser::LogicContext::PLUS() {
  return getToken(propositionParser::PLUS, 0);
}

tree::TerminalNode* propositionParser::LogicContext::MINUS() {
  return getToken(propositionParser::MINUS, 0);
}

tree::TerminalNode* propositionParser::LogicContext::LSHIFT() {
  return getToken(propositionParser::LSHIFT, 0);
}

tree::TerminalNode* propositionParser::LogicContext::RSHIFT() {
  return getToken(propositionParser::RSHIFT, 0);
}

tree::TerminalNode* propositionParser::LogicContext::BAND() {
  return getToken(propositionParser::BAND, 0);
}

tree::TerminalNode* propositionParser::LogicContext::BXOR() {
  return getToken(propositionParser::BXOR, 0);
}

tree::TerminalNode* propositionParser::LogicContext::BOR() {
  return getToken(propositionParser::BOR, 0);
}


size_t propositionParser::LogicContext::getRuleIndex() const {
  return propositionParser::RuleLogic;
}

void propositionParser::LogicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic(this);
}

void propositionParser::LogicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic(this);
}


propositionParser::LogicContext* propositionParser::logic() {
   return logic(0);
}

propositionParser::LogicContext* propositionParser::logic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::LogicContext *_localctx = _tracker.createInstance<LogicContext>(_ctx, parentState);
  propositionParser::LogicContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, propositionParser::RuleLogic, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(112);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::NEG: {
        setState(105);
        match(propositionParser::NEG);
        setState(106);
        logic(10);
        break;
      }

      case propositionParser::NUMERIC:
      case propositionParser::VERILOG_BINARY:
      case propositionParser::GCC_BINARY:
      case propositionParser::LT: {
        setState(107);
        logicAtom();
        break;
      }

      case propositionParser::LPAREN: {
        setState(108);
        match(propositionParser::LPAREN);
        setState(109);
        logic(0);
        setState(110);
        match(propositionParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(137);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(135);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(114);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(115);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::TIMES

          || _la == propositionParser::DIV)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(116);
          logic(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(117);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(118);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::PLUS

          || _la == propositionParser::MINUS)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(119);
          logic(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(120);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(121);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::LSHIFT);
          setState(122);
          logic(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(123);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(124);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::RSHIFT);
          setState(125);
          logic(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(126);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(127);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BAND);
          setState(128);
          logic(6);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(129);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(130);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BXOR);
          setState(131);
          logic(5);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(132);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(133);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(propositionParser::BOR);
          setState(134);
          logic(4);
          break;
        }

        } 
      }
      setState(139);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
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

propositionParser::LogicAtomContext::LogicAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::LogicConstantContext* propositionParser::LogicAtomContext::logicConstant() {
  return getRuleContext<propositionParser::LogicConstantContext>(0);
}

propositionParser::LogicVariableContext* propositionParser::LogicAtomContext::logicVariable() {
  return getRuleContext<propositionParser::LogicVariableContext>(0);
}

propositionParser::EnumVariableContext* propositionParser::LogicAtomContext::enumVariable() {
  return getRuleContext<propositionParser::EnumVariableContext>(0);
}

propositionParser::NamedLogicConstContext* propositionParser::LogicAtomContext::namedLogicConst() {
  return getRuleContext<propositionParser::NamedLogicConstContext>(0);
}


size_t propositionParser::LogicAtomContext::getRuleIndex() const {
  return propositionParser::RuleLogicAtom;
}

void propositionParser::LogicAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicAtom(this);
}

void propositionParser::LogicAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicAtom(this);
}

propositionParser::LogicAtomContext* propositionParser::logicAtom() {
  LogicAtomContext *_localctx = _tracker.createInstance<LogicAtomContext>(_ctx, getState());
  enterRule(_localctx, 12, propositionParser::RuleLogicAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      logicConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(141);
      logicVariable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(142);
      enumVariable();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(143);
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

propositionParser::LogicConstantContext::LogicConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LogicConstantContext::VERILOG_BINARY() {
  return getToken(propositionParser::VERILOG_BINARY, 0);
}

tree::TerminalNode* propositionParser::LogicConstantContext::GCC_BINARY() {
  return getToken(propositionParser::GCC_BINARY, 0);
}

tree::TerminalNode* propositionParser::LogicConstantContext::NUMERIC() {
  return getToken(propositionParser::NUMERIC, 0);
}


size_t propositionParser::LogicConstantContext::getRuleIndex() const {
  return propositionParser::RuleLogicConstant;
}

void propositionParser::LogicConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicConstant(this);
}

void propositionParser::LogicConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicConstant(this);
}

propositionParser::LogicConstantContext* propositionParser::logicConstant() {
  LogicConstantContext *_localctx = _tracker.createInstance<LogicConstantContext>(_ctx, getState());
  enterRule(_localctx, 14, propositionParser::RuleLogicConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::NUMERIC)
      | (1ULL << propositionParser::VERILOG_BINARY)
      | (1ULL << propositionParser::GCC_BINARY))) != 0))) {
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

propositionParser::NamedLogicConstContext::NamedLogicConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NamedLogicConstContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::NamedConstContext* propositionParser::NamedLogicConstContext::namedConst() {
  return getRuleContext<propositionParser::NamedConstContext>(0);
}

tree::TerminalNode* propositionParser::NamedLogicConstContext::NUMERIC() {
  return getToken(propositionParser::NUMERIC, 0);
}


size_t propositionParser::NamedLogicConstContext::getRuleIndex() const {
  return propositionParser::RuleNamedLogicConst;
}

void propositionParser::NamedLogicConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedLogicConst(this);
}

void propositionParser::NamedLogicConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedLogicConst(this);
}

propositionParser::NamedLogicConstContext* propositionParser::namedLogicConst() {
  NamedLogicConstContext *_localctx = _tracker.createInstance<NamedLogicConstContext>(_ctx, getState());
  enterRule(_localctx, 16, propositionParser::RuleNamedLogicConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(propositionParser::LT);
    setState(149);
    namedConst();
    setState(150);
    match(propositionParser::T__1);
    setState(151);
    match(propositionParser::NUMERIC);
    setState(152);
    match(propositionParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicVariableContext ------------------------------------------------------------------

propositionParser::LogicVariableContext::LogicVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::LogicVariableContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::VariableContext* propositionParser::LogicVariableContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}

tree::TerminalNode* propositionParser::LogicVariableContext::SIGN() {
  return getToken(propositionParser::SIGN, 0);
}

tree::TerminalNode* propositionParser::LogicVariableContext::NUMERIC() {
  return getToken(propositionParser::NUMERIC, 0);
}


size_t propositionParser::LogicVariableContext::getRuleIndex() const {
  return propositionParser::RuleLogicVariable;
}

void propositionParser::LogicVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicVariable(this);
}

void propositionParser::LogicVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicVariable(this);
}

propositionParser::LogicVariableContext* propositionParser::logicVariable() {
  LogicVariableContext *_localctx = _tracker.createInstance<LogicVariableContext>(_ctx, getState());
  enterRule(_localctx, 18, propositionParser::RuleLogicVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(propositionParser::LT);
    setState(155);
    variable();
    setState(156);
    match(propositionParser::T__3);
    setState(157);
    match(propositionParser::SIGN);
    setState(158);
    match(propositionParser::T__4);
    setState(159);
    match(propositionParser::NUMERIC);
    setState(160);
    match(propositionParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumVariableContext ------------------------------------------------------------------

propositionParser::EnumVariableContext::EnumVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::EnumVariableContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::VariableContext* propositionParser::EnumVariableContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}

propositionParser::EnumNameContext* propositionParser::EnumVariableContext::enumName() {
  return getRuleContext<propositionParser::EnumNameContext>(0);
}


size_t propositionParser::EnumVariableContext::getRuleIndex() const {
  return propositionParser::RuleEnumVariable;
}

void propositionParser::EnumVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumVariable(this);
}

void propositionParser::EnumVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumVariable(this);
}

propositionParser::EnumVariableContext* propositionParser::enumVariable() {
  EnumVariableContext *_localctx = _tracker.createInstance<EnumVariableContext>(_ctx, getState());
  enterRule(_localctx, 20, propositionParser::RuleEnumVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(propositionParser::LT);
    setState(163);
    variable();
    setState(164);
    match(propositionParser::T__5);
    setState(165);
    enumName();
    setState(166);
    match(propositionParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumNameContext ------------------------------------------------------------------

propositionParser::EnumNameContext::EnumNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::EnumNameContext::VARIABLE() {
  return getToken(propositionParser::VARIABLE, 0);
}


size_t propositionParser::EnumNameContext::getRuleIndex() const {
  return propositionParser::RuleEnumName;
}

void propositionParser::EnumNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumName(this);
}

void propositionParser::EnumNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumName(this);
}

propositionParser::EnumNameContext* propositionParser::enumName() {
  EnumNameContext *_localctx = _tracker.createInstance<EnumNameContext>(_ctx, getState());
  enterRule(_localctx, 22, propositionParser::RuleEnumName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(propositionParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedConstContext ------------------------------------------------------------------

propositionParser::NamedConstContext::NamedConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NamedConstContext::VARIABLE() {
  return getToken(propositionParser::VARIABLE, 0);
}


size_t propositionParser::NamedConstContext::getRuleIndex() const {
  return propositionParser::RuleNamedConst;
}

void propositionParser::NamedConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedConst(this);
}

void propositionParser::NamedConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedConst(this);
}

propositionParser::NamedConstContext* propositionParser::namedConst() {
  NamedConstContext *_localctx = _tracker.createInstance<NamedConstContext>(_ctx, getState());
  enterRule(_localctx, 24, propositionParser::RuleNamedConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(propositionParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericContext ------------------------------------------------------------------

propositionParser::NumericContext::NumericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::NumericAtomContext* propositionParser::NumericContext::numericAtom() {
  return getRuleContext<propositionParser::NumericAtomContext>(0);
}

propositionParser::LogicContext* propositionParser::NumericContext::logic() {
  return getRuleContext<propositionParser::LogicContext>(0);
}

tree::TerminalNode* propositionParser::NumericContext::LPAREN() {
  return getToken(propositionParser::LPAREN, 0);
}

std::vector<propositionParser::NumericContext *> propositionParser::NumericContext::numeric() {
  return getRuleContexts<propositionParser::NumericContext>();
}

propositionParser::NumericContext* propositionParser::NumericContext::numeric(size_t i) {
  return getRuleContext<propositionParser::NumericContext>(i);
}

tree::TerminalNode* propositionParser::NumericContext::RPAREN() {
  return getToken(propositionParser::RPAREN, 0);
}

tree::TerminalNode* propositionParser::NumericContext::TIMES() {
  return getToken(propositionParser::TIMES, 0);
}

tree::TerminalNode* propositionParser::NumericContext::DIV() {
  return getToken(propositionParser::DIV, 0);
}

tree::TerminalNode* propositionParser::NumericContext::PLUS() {
  return getToken(propositionParser::PLUS, 0);
}

tree::TerminalNode* propositionParser::NumericContext::MINUS() {
  return getToken(propositionParser::MINUS, 0);
}


size_t propositionParser::NumericContext::getRuleIndex() const {
  return propositionParser::RuleNumeric;
}

void propositionParser::NumericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric(this);
}

void propositionParser::NumericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric(this);
}


propositionParser::NumericContext* propositionParser::numeric() {
   return numeric(0);
}

propositionParser::NumericContext* propositionParser::numeric(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  propositionParser::NumericContext *_localctx = _tracker.createInstance<NumericContext>(_ctx, parentState);
  propositionParser::NumericContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, propositionParser::RuleNumeric, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(173);
      numericAtom();
      break;
    }

    case 2: {
      setState(174);
      logic(0);
      break;
    }

    case 3: {
      setState(175);
      match(propositionParser::LPAREN);
      setState(176);
      numeric(0);
      setState(177);
      match(propositionParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(189);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(187);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(181);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(182);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::TIMES

          || _la == propositionParser::DIV)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(183);
          numeric(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(184);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(185);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == propositionParser::PLUS

          || _la == propositionParser::MINUS)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(186);
          numeric(5);
          break;
        }

        } 
      }
      setState(191);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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

propositionParser::NumericAtomContext::NumericAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

propositionParser::NumericConstantContext* propositionParser::NumericAtomContext::numericConstant() {
  return getRuleContext<propositionParser::NumericConstantContext>(0);
}

propositionParser::NumericVariableContext* propositionParser::NumericAtomContext::numericVariable() {
  return getRuleContext<propositionParser::NumericVariableContext>(0);
}


size_t propositionParser::NumericAtomContext::getRuleIndex() const {
  return propositionParser::RuleNumericAtom;
}

void propositionParser::NumericAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericAtom(this);
}

void propositionParser::NumericAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericAtom(this);
}

propositionParser::NumericAtomContext* propositionParser::numericAtom() {
  NumericAtomContext *_localctx = _tracker.createInstance<NumericAtomContext>(_ctx, getState());
  enterRule(_localctx, 28, propositionParser::RuleNumericAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case propositionParser::NUMERIC: {
        enterOuterAlt(_localctx, 1);
        setState(192);
        numericConstant();
        break;
      }

      case propositionParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(193);
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

propositionParser::NumericConstantContext::NumericConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NumericConstantContext::NUMERIC() {
  return getToken(propositionParser::NUMERIC, 0);
}


size_t propositionParser::NumericConstantContext::getRuleIndex() const {
  return propositionParser::RuleNumericConstant;
}

void propositionParser::NumericConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericConstant(this);
}

void propositionParser::NumericConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericConstant(this);
}

propositionParser::NumericConstantContext* propositionParser::numericConstant() {
  NumericConstantContext *_localctx = _tracker.createInstance<NumericConstantContext>(_ctx, getState());
  enterRule(_localctx, 30, propositionParser::RuleNumericConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(propositionParser::NUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericVariableContext ------------------------------------------------------------------

propositionParser::NumericVariableContext::NumericVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::NumericVariableContext::LT() {
  return getToken(propositionParser::LT, 0);
}

propositionParser::VariableContext* propositionParser::NumericVariableContext::variable() {
  return getRuleContext<propositionParser::VariableContext>(0);
}

tree::TerminalNode* propositionParser::NumericVariableContext::NUMERIC() {
  return getToken(propositionParser::NUMERIC, 0);
}


size_t propositionParser::NumericVariableContext::getRuleIndex() const {
  return propositionParser::RuleNumericVariable;
}

void propositionParser::NumericVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericVariable(this);
}

void propositionParser::NumericVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericVariable(this);
}

propositionParser::NumericVariableContext* propositionParser::numericVariable() {
  NumericVariableContext *_localctx = _tracker.createInstance<NumericVariableContext>(_ctx, getState());
  enterRule(_localctx, 32, propositionParser::RuleNumericVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(propositionParser::LT);
    setState(199);
    variable();
    setState(200);
    match(propositionParser::T__6);
    setState(201);
    match(propositionParser::NUMERIC);
    setState(202);
    match(propositionParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

propositionParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::VariableContext::VARIABLE() {
  return getToken(propositionParser::VARIABLE, 0);
}

tree::TerminalNode* propositionParser::VariableContext::TIMES() {
  return getToken(propositionParser::TIMES, 0);
}


size_t propositionParser::VariableContext::getRuleIndex() const {
  return propositionParser::RuleVariable;
}

void propositionParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void propositionParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

propositionParser::VariableContext* propositionParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 34, propositionParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == propositionParser::TIMES) {
      setState(204);
      match(propositionParser::TIMES);
    }
    setState(207);
    match(propositionParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

propositionParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* propositionParser::RelopContext::GT() {
  return getToken(propositionParser::GT, 0);
}

tree::TerminalNode* propositionParser::RelopContext::GE() {
  return getToken(propositionParser::GE, 0);
}

tree::TerminalNode* propositionParser::RelopContext::LT() {
  return getToken(propositionParser::LT, 0);
}

tree::TerminalNode* propositionParser::RelopContext::LE() {
  return getToken(propositionParser::LE, 0);
}


size_t propositionParser::RelopContext::getRuleIndex() const {
  return propositionParser::RuleRelop;
}

void propositionParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void propositionParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<propositionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}

propositionParser::RelopContext* propositionParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 36, propositionParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << propositionParser::GT)
      | (1ULL << propositionParser::GE)
      | (1ULL << propositionParser::LT)
      | (1ULL << propositionParser::LE))) != 0))) {
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

bool propositionParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return booleanSempred(dynamic_cast<BooleanContext *>(context), predicateIndex);
    case 5: return logicSempred(dynamic_cast<LogicContext *>(context), predicateIndex);
    case 13: return numericSempred(dynamic_cast<NumericContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool propositionParser::booleanSempred(BooleanContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool propositionParser::logicSempred(LogicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 9);
    case 5: return precpred(_ctx, 8);
    case 6: return precpred(_ctx, 7);
    case 7: return precpred(_ctx, 6);
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);
    case 10: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool propositionParser::numericSempred(NumericContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 5);
    case 12: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> propositionParser::_decisionToDFA;
atn::PredictionContextCache propositionParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN propositionParser::_atn;
std::vector<uint16_t> propositionParser::_serializedATN;

std::vector<std::string> propositionParser::_ruleNames = {
  "file", "boolean", "booleanAtom", "booleanConstant", "booleanVariable", 
  "logic", "logicAtom", "logicConstant", "namedLogicConst", "logicVariable", 
  "enumVariable", "enumName", "namedConst", "numeric", "numericAtom", "numericConstant", 
  "numericVariable", "variable", "relop"
};

std::vector<std::string> propositionParser::_literalNames = {
  "", "',bool>'", "',constlogic('", "')>'", "',logic('", "','", "',enum('", 
  "',numeric('", "", "'{'", "'}'", "'['", "']'", "'('", "')'", "'bool'", 
  "'double'", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", 
  "'<'", "'<='", "'=='", "'!='", "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", 
  "'&&'", "'||'", "'!'"
};

std::vector<std::string> propositionParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "SIGN", "LGPAREN", "RGPAREN", "LCPAREN", 
  "RCPAREN", "LPAREN", "RPAREN", "CAST_BOOL", "CAST_NUMERIC", "VARIABLE", 
  "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "BOOLEAN", "PLUS", "MINUS", 
  "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", 
  "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", "WS"
};

dfa::Vocabulary propositionParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> propositionParser::_tokenNames;

propositionParser::Initializer::Initializer() {
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
    0x3, 0x2b, 0xd6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x4e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x5c, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x5f, 0xb, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x63, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x73, 0xa, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x8a, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x8d, 0xb, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x93, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xb6, 0xa, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xbe, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0xc1, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 
    0x10, 0xc5, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x5, 0x13, 0xd0, 0xa, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x2, 0x5, 
    0x4, 0xc, 0x1c, 0x15, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x2, 0x6, 
    0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x18, 0x19, 0x3, 0x2, 0x14, 0x16, 0x3, 
    0x2, 0x1c, 0x1f, 0x2, 0xe3, 0x2, 0x28, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x62, 0x3, 0x2, 0x2, 0x2, 0x8, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x66, 0x3, 0x2, 0x2, 0x2, 0xc, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x92, 0x3, 0x2, 0x2, 0x2, 0x10, 0x94, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x14, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x22, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x26, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x29, 0x5, 0x4, 0x3, 0x2, 0x29, 0x2a, 0x7, 0x2, 0x2, 0x3, 0x2a, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x8, 0x3, 0x1, 0x2, 0x2c, 0x2d, 
    0x7, 0x2a, 0x2, 0x2, 0x2d, 0x4e, 0x5, 0x4, 0x3, 0x11, 0x2e, 0x2f, 0x5, 
    0xc, 0x7, 0x2, 0x2f, 0x30, 0x5, 0x26, 0x14, 0x2, 0x30, 0x31, 0x5, 0xc, 
    0x7, 0x2, 0x31, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x5, 0x1c, 0xf, 
    0x2, 0x33, 0x34, 0x5, 0x26, 0x14, 0x2, 0x34, 0x35, 0x5, 0x1c, 0xf, 0x2, 
    0x35, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x5, 0xc, 0x7, 0x2, 0x37, 
    0x38, 0x7, 0x20, 0x2, 0x2, 0x38, 0x39, 0x5, 0xc, 0x7, 0x2, 0x39, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x1c, 0xf, 0x2, 0x3b, 0x3c, 0x7, 
    0x20, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x1c, 0xf, 0x2, 0x3d, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x3f, 0x5, 0xc, 0x7, 0x2, 0x3f, 0x40, 0x7, 0x21, 0x2, 
    0x2, 0x40, 0x41, 0x5, 0xc, 0x7, 0x2, 0x41, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x5, 0x1c, 0xf, 0x2, 0x43, 0x44, 0x7, 0x21, 0x2, 0x2, 0x44, 
    0x45, 0x5, 0x1c, 0xf, 0x2, 0x45, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x46, 0x4e, 
    0x5, 0x6, 0x4, 0x2, 0x47, 0x4e, 0x5, 0xc, 0x7, 0x2, 0x48, 0x4e, 0x5, 
    0x1c, 0xf, 0x2, 0x49, 0x4a, 0x7, 0xf, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x4, 
    0x3, 0x2, 0x4b, 0x4c, 0x7, 0x10, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x32, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x36, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0xc, 0xc, 0x2, 
    0x2, 0x50, 0x51, 0x7, 0x20, 0x2, 0x2, 0x51, 0x5c, 0x5, 0x4, 0x3, 0xd, 
    0x52, 0x53, 0xc, 0x9, 0x2, 0x2, 0x53, 0x54, 0x7, 0x21, 0x2, 0x2, 0x54, 
    0x5c, 0x5, 0x4, 0x3, 0xa, 0x55, 0x56, 0xc, 0x8, 0x2, 0x2, 0x56, 0x57, 
    0x7, 0x28, 0x2, 0x2, 0x57, 0x5c, 0x5, 0x4, 0x3, 0x9, 0x58, 0x59, 0xc, 
    0x7, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x29, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x4, 
    0x3, 0x8, 0x5b, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x52, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x55, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x63, 0x5, 0x8, 0x5, 0x2, 0x61, 0x63, 0x5, 
    0xa, 0x6, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x7, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x17, 0x2, 
    0x2, 0x65, 0x9, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x1e, 0x2, 0x2, 
    0x67, 0x68, 0x5, 0x24, 0x13, 0x2, 0x68, 0x69, 0x7, 0x3, 0x2, 0x2, 0x69, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x8, 0x7, 0x1, 0x2, 0x6b, 0x6c, 
    0x7, 0x25, 0x2, 0x2, 0x6c, 0x73, 0x5, 0xc, 0x7, 0xc, 0x6d, 0x73, 0x5, 
    0xe, 0x8, 0x2, 0x6e, 0x6f, 0x7, 0xf, 0x2, 0x2, 0x6f, 0x70, 0x5, 0xc, 
    0x7, 0x2, 0x70, 0x71, 0x7, 0x10, 0x2, 0x2, 0x71, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x73, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x75, 0xc, 0xb, 0x2, 0x2, 0x75, 0x76, 0x9, 0x2, 0x2, 0x2, 0x76, 0x8a, 
    0x5, 0xc, 0x7, 0xc, 0x77, 0x78, 0xc, 0xa, 0x2, 0x2, 0x78, 0x79, 0x9, 
    0x3, 0x2, 0x2, 0x79, 0x8a, 0x5, 0xc, 0x7, 0xb, 0x7a, 0x7b, 0xc, 0x9, 
    0x2, 0x2, 0x7b, 0x7c, 0x7, 0x26, 0x2, 0x2, 0x7c, 0x8a, 0x5, 0xc, 0x7, 
    0xa, 0x7d, 0x7e, 0xc, 0x8, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x27, 0x2, 0x2, 
    0x7f, 0x8a, 0x5, 0xc, 0x7, 0x9, 0x80, 0x81, 0xc, 0x7, 0x2, 0x2, 0x81, 
    0x82, 0x7, 0x22, 0x2, 0x2, 0x82, 0x8a, 0x5, 0xc, 0x7, 0x8, 0x83, 0x84, 
    0xc, 0x6, 0x2, 0x2, 0x84, 0x85, 0x7, 0x24, 0x2, 0x2, 0x85, 0x8a, 0x5, 
    0xc, 0x7, 0x7, 0x86, 0x87, 0xc, 0x5, 0x2, 0x2, 0x87, 0x88, 0x7, 0x23, 
    0x2, 0x2, 0x88, 0x8a, 0x5, 0xc, 0x7, 0x6, 0x89, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x89, 0x77, 0x3, 0x2, 0x2, 0x2, 0x89, 0x7a, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x89, 0x80, 0x3, 0x2, 0x2, 0x2, 0x89, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x89, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x93, 0x5, 0x10, 0x9, 0x2, 0x8f, 0x93, 0x5, 0x14, 0xb, 
    0x2, 0x90, 0x93, 0x5, 0x16, 0xc, 0x2, 0x91, 0x93, 0x5, 0x12, 0xa, 0x2, 
    0x92, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x92, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x9, 0x4, 0x2, 0x2, 0x95, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x1e, 0x2, 0x2, 0x97, 0x98, 0x5, 0x1a, 
    0xe, 0x2, 0x98, 0x99, 0x7, 0x4, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x14, 0x2, 
    0x2, 0x9a, 0x9b, 0x7, 0x5, 0x2, 0x2, 0x9b, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x9d, 0x7, 0x1e, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x24, 0x13, 0x2, 0x9e, 
    0x9f, 0x7, 0x6, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0xa, 0x2, 0x2, 0xa0, 0xa1, 
    0x7, 0x7, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x14, 0x2, 0x2, 0xa2, 0xa3, 0x7, 
    0x5, 0x2, 0x2, 0xa3, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x1e, 
    0x2, 0x2, 0xa5, 0xa6, 0x5, 0x24, 0x13, 0x2, 0xa6, 0xa7, 0x7, 0x8, 0x2, 
    0x2, 0xa7, 0xa8, 0x5, 0x18, 0xd, 0x2, 0xa8, 0xa9, 0x7, 0x5, 0x2, 0x2, 
    0xa9, 0x17, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x13, 0x2, 0x2, 0xab, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x7, 0x13, 0x2, 0x2, 0xad, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x8, 0xf, 0x1, 0x2, 0xaf, 0xb6, 0x5, 
    0x1e, 0x10, 0x2, 0xb0, 0xb6, 0x5, 0xc, 0x7, 0x2, 0xb1, 0xb2, 0x7, 0xf, 
    0x2, 0x2, 0xb2, 0xb3, 0x5, 0x1c, 0xf, 0x2, 0xb3, 0xb4, 0x7, 0x10, 0x2, 
    0x2, 0xb4, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb6, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0xc, 0x7, 0x2, 0x2, 0xb8, 0xb9, 
    0x9, 0x2, 0x2, 0x2, 0xb9, 0xbe, 0x5, 0x1c, 0xf, 0x8, 0xba, 0xbb, 0xc, 
    0x6, 0x2, 0x2, 0xbb, 0xbc, 0x9, 0x3, 0x2, 0x2, 0xbc, 0xbe, 0x5, 0x1c, 
    0xf, 0x7, 0xbd, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc1, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x5, 0x20, 0x11, 0x2, 0xc3, 0xc5, 
    0x5, 0x22, 0x12, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xc5, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x14, 
    0x2, 0x2, 0xc7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x1e, 0x2, 
    0x2, 0xc9, 0xca, 0x5, 0x24, 0x13, 0x2, 0xca, 0xcb, 0x7, 0x9, 0x2, 0x2, 
    0xcb, 0xcc, 0x7, 0x14, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x5, 0x2, 0x2, 0xcd, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd0, 0x7, 0x1a, 0x2, 0x2, 0xcf, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x13, 0x2, 0x2, 0xd2, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd4, 0x9, 0x5, 0x2, 0x2, 0xd4, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xf, 0x4d, 0x5b, 0x5d, 0x62, 0x72, 0x89, 0x8b, 0x92, 0xb5, 0xbd, 
    0xbf, 0xc4, 0xcf, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

propositionParser::Initializer propositionParser::_init;
