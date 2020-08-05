
// Generated from varDeclaration.g4 by ANTLR 4.7.2


#include "varDeclarationListener.h"

#include "varDeclarationParser.h"


using namespace antlrcpp;
using namespace antlr4;

varDeclarationParser::varDeclarationParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

varDeclarationParser::~varDeclarationParser() {
  delete _interpreter;
}

std::string varDeclarationParser::getGrammarFileName() const {
  return "varDeclaration.g4";
}

const std::vector<std::string>& varDeclarationParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& varDeclarationParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

varDeclarationParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::CDeclarationContext* varDeclarationParser::FileContext::cDeclaration() {
  return getRuleContext<varDeclarationParser::CDeclarationContext>(0);
}

tree::TerminalNode* varDeclarationParser::FileContext::EOF() {
  return getToken(varDeclarationParser::EOF, 0);
}


size_t varDeclarationParser::FileContext::getRuleIndex() const {
  return varDeclarationParser::RuleFile;
}

void varDeclarationParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void varDeclarationParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

varDeclarationParser::FileContext* varDeclarationParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, varDeclarationParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    cDeclaration();
    setState(31);
    match(varDeclarationParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CDeclarationContext ------------------------------------------------------------------

varDeclarationParser::CDeclarationContext::CDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::CStatementContext* varDeclarationParser::CDeclarationContext::cStatement() {
  return getRuleContext<varDeclarationParser::CStatementContext>(0);
}

varDeclarationParser::CDeclarationContext* varDeclarationParser::CDeclarationContext::cDeclaration() {
  return getRuleContext<varDeclarationParser::CDeclarationContext>(0);
}


size_t varDeclarationParser::CDeclarationContext::getRuleIndex() const {
  return varDeclarationParser::RuleCDeclaration;
}

void varDeclarationParser::CDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCDeclaration(this);
}

void varDeclarationParser::CDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCDeclaration(this);
}

varDeclarationParser::CDeclarationContext* varDeclarationParser::cDeclaration() {
  CDeclarationContext *_localctx = _tracker.createInstance<CDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, varDeclarationParser::RuleCDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(33);
      cStatement();
      setState(34);
      match(varDeclarationParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(36);
      cStatement();
      setState(37);
      match(varDeclarationParser::T__0);
      setState(38);
      cDeclaration();
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

//----------------- CStatementContext ------------------------------------------------------------------

varDeclarationParser::CStatementContext::CStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::VarDecContext* varDeclarationParser::CStatementContext::varDec() {
  return getRuleContext<varDeclarationParser::VarDecContext>(0);
}

varDeclarationParser::EnumDecContext* varDeclarationParser::CStatementContext::enumDec() {
  return getRuleContext<varDeclarationParser::EnumDecContext>(0);
}


size_t varDeclarationParser::CStatementContext::getRuleIndex() const {
  return varDeclarationParser::RuleCStatement;
}

void varDeclarationParser::CStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCStatement(this);
}

void varDeclarationParser::CStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCStatement(this);
}

varDeclarationParser::CStatementContext* varDeclarationParser::cStatement() {
  CStatementContext *_localctx = _tracker.createInstance<CStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, varDeclarationParser::RuleCStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case varDeclarationParser::VARTYPE:
      case varDeclarationParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(42);
        varDec();
        break;
      }

      case varDeclarationParser::TYPEDEF:
      case varDeclarationParser::ENUM: {
        enterOuterAlt(_localctx, 2);
        setState(43);
        enumDec();
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

//----------------- VarDecContext ------------------------------------------------------------------

varDeclarationParser::VarDecContext::VarDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::VartypeContext* varDeclarationParser::VarDecContext::vartype() {
  return getRuleContext<varDeclarationParser::VartypeContext>(0);
}

varDeclarationParser::NameContext* varDeclarationParser::VarDecContext::name() {
  return getRuleContext<varDeclarationParser::NameContext>(0);
}

varDeclarationParser::AssContext* varDeclarationParser::VarDecContext::ass() {
  return getRuleContext<varDeclarationParser::AssContext>(0);
}


size_t varDeclarationParser::VarDecContext::getRuleIndex() const {
  return varDeclarationParser::RuleVarDec;
}

void varDeclarationParser::VarDecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDec(this);
}

void varDeclarationParser::VarDecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDec(this);
}

varDeclarationParser::VarDecContext* varDeclarationParser::varDec() {
  VarDecContext *_localctx = _tracker.createInstance<VarDecContext>(_ctx, getState());
  enterRule(_localctx, 6, varDeclarationParser::RuleVarDec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    vartype();
    setState(47);
    name();
    setState(49);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == varDeclarationParser::T__1) {
      setState(48);
      ass();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssContext ------------------------------------------------------------------

varDeclarationParser::AssContext::AssContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* varDeclarationParser::AssContext::NAME() {
  return getToken(varDeclarationParser::NAME, 0);
}

tree::TerminalNode* varDeclarationParser::AssContext::NUMERIC() {
  return getToken(varDeclarationParser::NUMERIC, 0);
}


size_t varDeclarationParser::AssContext::getRuleIndex() const {
  return varDeclarationParser::RuleAss;
}

void varDeclarationParser::AssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAss(this);
}

void varDeclarationParser::AssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAss(this);
}

varDeclarationParser::AssContext* varDeclarationParser::ass() {
  AssContext *_localctx = _tracker.createInstance<AssContext>(_ctx, getState());
  enterRule(_localctx, 8, varDeclarationParser::RuleAss);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(51);
      match(varDeclarationParser::T__1);
      setState(52);
      match(varDeclarationParser::NAME);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(53);
      match(varDeclarationParser::T__1);
      setState(54);
      match(varDeclarationParser::NUMERIC);
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

//----------------- EnumDecContext ------------------------------------------------------------------

varDeclarationParser::EnumDecContext::EnumDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* varDeclarationParser::EnumDecContext::ENUM() {
  return getToken(varDeclarationParser::ENUM, 0);
}

varDeclarationParser::NameContext* varDeclarationParser::EnumDecContext::name() {
  return getRuleContext<varDeclarationParser::NameContext>(0);
}

tree::TerminalNode* varDeclarationParser::EnumDecContext::OB() {
  return getToken(varDeclarationParser::OB, 0);
}

varDeclarationParser::Enum_listContext* varDeclarationParser::EnumDecContext::enum_list() {
  return getRuleContext<varDeclarationParser::Enum_listContext>(0);
}

tree::TerminalNode* varDeclarationParser::EnumDecContext::CB() {
  return getToken(varDeclarationParser::CB, 0);
}

tree::TerminalNode* varDeclarationParser::EnumDecContext::TYPEDEF() {
  return getToken(varDeclarationParser::TYPEDEF, 0);
}


size_t varDeclarationParser::EnumDecContext::getRuleIndex() const {
  return varDeclarationParser::RuleEnumDec;
}

void varDeclarationParser::EnumDecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumDec(this);
}

void varDeclarationParser::EnumDecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumDec(this);
}

varDeclarationParser::EnumDecContext* varDeclarationParser::enumDec() {
  EnumDecContext *_localctx = _tracker.createInstance<EnumDecContext>(_ctx, getState());
  enterRule(_localctx, 10, varDeclarationParser::RuleEnumDec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(57);
      match(varDeclarationParser::ENUM);
      setState(58);
      name();
      setState(59);
      match(varDeclarationParser::OB);
      setState(60);
      enum_list();
      setState(61);
      match(varDeclarationParser::CB);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      match(varDeclarationParser::TYPEDEF);
      setState(64);
      match(varDeclarationParser::ENUM);
      setState(65);
      match(varDeclarationParser::OB);
      setState(66);
      enum_list();
      setState(67);
      match(varDeclarationParser::CB);
      setState(68);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      match(varDeclarationParser::ENUM);
      setState(71);
      match(varDeclarationParser::OB);
      setState(72);
      enum_list();
      setState(73);
      match(varDeclarationParser::CB);
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

//----------------- Enum_listContext ------------------------------------------------------------------

varDeclarationParser::Enum_listContext::Enum_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::NameContext* varDeclarationParser::Enum_listContext::name() {
  return getRuleContext<varDeclarationParser::NameContext>(0);
}

varDeclarationParser::AddLogicContext* varDeclarationParser::Enum_listContext::addLogic() {
  return getRuleContext<varDeclarationParser::AddLogicContext>(0);
}

varDeclarationParser::Enum_listContext* varDeclarationParser::Enum_listContext::enum_list() {
  return getRuleContext<varDeclarationParser::Enum_listContext>(0);
}


size_t varDeclarationParser::Enum_listContext::getRuleIndex() const {
  return varDeclarationParser::RuleEnum_list;
}

void varDeclarationParser::Enum_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_list(this);
}

void varDeclarationParser::Enum_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_list(this);
}

varDeclarationParser::Enum_listContext* varDeclarationParser::enum_list() {
  Enum_listContext *_localctx = _tracker.createInstance<Enum_listContext>(_ctx, getState());
  enterRule(_localctx, 12, varDeclarationParser::RuleEnum_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      name();
      setState(80);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == varDeclarationParser::T__1) {
        setState(78);
        match(varDeclarationParser::T__1);
        setState(79);
        addLogic();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
      name();
      setState(85);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == varDeclarationParser::T__1) {
        setState(83);
        match(varDeclarationParser::T__1);
        setState(84);
        addLogic();
      }
      setState(87);
      match(varDeclarationParser::T__2);
      setState(88);
      enum_list();
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

//----------------- AddLogicContext ------------------------------------------------------------------

varDeclarationParser::AddLogicContext::AddLogicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::LogicContext* varDeclarationParser::AddLogicContext::logic() {
  return getRuleContext<varDeclarationParser::LogicContext>(0);
}


size_t varDeclarationParser::AddLogicContext::getRuleIndex() const {
  return varDeclarationParser::RuleAddLogic;
}

void varDeclarationParser::AddLogicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddLogic(this);
}

void varDeclarationParser::AddLogicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddLogic(this);
}

varDeclarationParser::AddLogicContext* varDeclarationParser::addLogic() {
  AddLogicContext *_localctx = _tracker.createInstance<AddLogicContext>(_ctx, getState());
  enterRule(_localctx, 14, varDeclarationParser::RuleAddLogic);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    logic(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

varDeclarationParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* varDeclarationParser::NameContext::NAME() {
  return getToken(varDeclarationParser::NAME, 0);
}


size_t varDeclarationParser::NameContext::getRuleIndex() const {
  return varDeclarationParser::RuleName;
}

void varDeclarationParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void varDeclarationParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}

varDeclarationParser::NameContext* varDeclarationParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 16, varDeclarationParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(varDeclarationParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicNameContext ------------------------------------------------------------------

varDeclarationParser::LogicNameContext::LogicNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* varDeclarationParser::LogicNameContext::NAME() {
  return getToken(varDeclarationParser::NAME, 0);
}


size_t varDeclarationParser::LogicNameContext::getRuleIndex() const {
  return varDeclarationParser::RuleLogicName;
}

void varDeclarationParser::LogicNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicName(this);
}

void varDeclarationParser::LogicNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicName(this);
}

varDeclarationParser::LogicNameContext* varDeclarationParser::logicName() {
  LogicNameContext *_localctx = _tracker.createInstance<LogicNameContext>(_ctx, getState());
  enterRule(_localctx, 18, varDeclarationParser::RuleLogicName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(varDeclarationParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

varDeclarationParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* varDeclarationParser::VartypeContext::VARTYPE() {
  return getToken(varDeclarationParser::VARTYPE, 0);
}

varDeclarationParser::EnumTypeContext* varDeclarationParser::VartypeContext::enumType() {
  return getRuleContext<varDeclarationParser::EnumTypeContext>(0);
}


size_t varDeclarationParser::VartypeContext::getRuleIndex() const {
  return varDeclarationParser::RuleVartype;
}

void varDeclarationParser::VartypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVartype(this);
}

void varDeclarationParser::VartypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVartype(this);
}

varDeclarationParser::VartypeContext* varDeclarationParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 20, varDeclarationParser::RuleVartype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(100);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case varDeclarationParser::VARTYPE: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        match(varDeclarationParser::VARTYPE);
        break;
      }

      case varDeclarationParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        enumType();
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

//----------------- EnumTypeContext ------------------------------------------------------------------

varDeclarationParser::EnumTypeContext::EnumTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::NameContext* varDeclarationParser::EnumTypeContext::name() {
  return getRuleContext<varDeclarationParser::NameContext>(0);
}


size_t varDeclarationParser::EnumTypeContext::getRuleIndex() const {
  return varDeclarationParser::RuleEnumType;
}

void varDeclarationParser::EnumTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumType(this);
}

void varDeclarationParser::EnumTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumType(this);
}

varDeclarationParser::EnumTypeContext* varDeclarationParser::enumType() {
  EnumTypeContext *_localctx = _tracker.createInstance<EnumTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, varDeclarationParser::RuleEnumType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicContext ------------------------------------------------------------------

varDeclarationParser::LogicContext::LogicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::LogicAtomContext* varDeclarationParser::LogicContext::logicAtom() {
  return getRuleContext<varDeclarationParser::LogicAtomContext>(0);
}

tree::TerminalNode* varDeclarationParser::LogicContext::LSBRACKET() {
  return getToken(varDeclarationParser::LSBRACKET, 0);
}

std::vector<varDeclarationParser::LogicContext *> varDeclarationParser::LogicContext::logic() {
  return getRuleContexts<varDeclarationParser::LogicContext>();
}

varDeclarationParser::LogicContext* varDeclarationParser::LogicContext::logic(size_t i) {
  return getRuleContext<varDeclarationParser::LogicContext>(i);
}

tree::TerminalNode* varDeclarationParser::LogicContext::RSBRACKET() {
  return getToken(varDeclarationParser::RSBRACKET, 0);
}

tree::TerminalNode* varDeclarationParser::LogicContext::TIMES() {
  return getToken(varDeclarationParser::TIMES, 0);
}

tree::TerminalNode* varDeclarationParser::LogicContext::DIV() {
  return getToken(varDeclarationParser::DIV, 0);
}

tree::TerminalNode* varDeclarationParser::LogicContext::PLUS() {
  return getToken(varDeclarationParser::PLUS, 0);
}

tree::TerminalNode* varDeclarationParser::LogicContext::MINUS() {
  return getToken(varDeclarationParser::MINUS, 0);
}


size_t varDeclarationParser::LogicContext::getRuleIndex() const {
  return varDeclarationParser::RuleLogic;
}

void varDeclarationParser::LogicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic(this);
}

void varDeclarationParser::LogicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic(this);
}


varDeclarationParser::LogicContext* varDeclarationParser::logic() {
   return logic(0);
}

varDeclarationParser::LogicContext* varDeclarationParser::logic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  varDeclarationParser::LogicContext *_localctx = _tracker.createInstance<LogicContext>(_ctx, parentState);
  varDeclarationParser::LogicContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, varDeclarationParser::RuleLogic, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case varDeclarationParser::NUMERIC:
      case varDeclarationParser::VERILOG_BINARY:
      case varDeclarationParser::GCC_BINARY:
      case varDeclarationParser::NAME: {
        setState(105);
        logicAtom();
        break;
      }

      case varDeclarationParser::LSBRACKET: {
        setState(106);
        match(varDeclarationParser::LSBRACKET);
        setState(107);
        logic(0);
        setState(108);
        match(varDeclarationParser::RSBRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(120);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(118);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(112);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(113);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == varDeclarationParser::TIMES

          || _la == varDeclarationParser::DIV)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(114);
          logic(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(115);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(116);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == varDeclarationParser::PLUS

          || _la == varDeclarationParser::MINUS)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(117);
          logic(4);
          break;
        }

        } 
      }
      setState(122);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
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

varDeclarationParser::LogicAtomContext::LogicAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::LogicConstantContext* varDeclarationParser::LogicAtomContext::logicConstant() {
  return getRuleContext<varDeclarationParser::LogicConstantContext>(0);
}

varDeclarationParser::LogicNameContext* varDeclarationParser::LogicAtomContext::logicName() {
  return getRuleContext<varDeclarationParser::LogicNameContext>(0);
}


size_t varDeclarationParser::LogicAtomContext::getRuleIndex() const {
  return varDeclarationParser::RuleLogicAtom;
}

void varDeclarationParser::LogicAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicAtom(this);
}

void varDeclarationParser::LogicAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicAtom(this);
}

varDeclarationParser::LogicAtomContext* varDeclarationParser::logicAtom() {
  LogicAtomContext *_localctx = _tracker.createInstance<LogicAtomContext>(_ctx, getState());
  enterRule(_localctx, 26, varDeclarationParser::RuleLogicAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case varDeclarationParser::NUMERIC:
      case varDeclarationParser::VERILOG_BINARY:
      case varDeclarationParser::GCC_BINARY: {
        enterOuterAlt(_localctx, 1);
        setState(123);
        logicConstant();
        break;
      }

      case varDeclarationParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(124);
        logicName();
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

//----------------- LogicConstantContext ------------------------------------------------------------------

varDeclarationParser::LogicConstantContext::LogicConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* varDeclarationParser::LogicConstantContext::VERILOG_BINARY() {
  return getToken(varDeclarationParser::VERILOG_BINARY, 0);
}

tree::TerminalNode* varDeclarationParser::LogicConstantContext::GCC_BINARY() {
  return getToken(varDeclarationParser::GCC_BINARY, 0);
}

tree::TerminalNode* varDeclarationParser::LogicConstantContext::NUMERIC() {
  return getToken(varDeclarationParser::NUMERIC, 0);
}


size_t varDeclarationParser::LogicConstantContext::getRuleIndex() const {
  return varDeclarationParser::RuleLogicConstant;
}

void varDeclarationParser::LogicConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicConstant(this);
}

void varDeclarationParser::LogicConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<varDeclarationListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicConstant(this);
}

varDeclarationParser::LogicConstantContext* varDeclarationParser::logicConstant() {
  LogicConstantContext *_localctx = _tracker.createInstance<LogicConstantContext>(_ctx, getState());
  enterRule(_localctx, 28, varDeclarationParser::RuleLogicConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << varDeclarationParser::NUMERIC)
      | (1ULL << varDeclarationParser::VERILOG_BINARY)
      | (1ULL << varDeclarationParser::GCC_BINARY))) != 0))) {
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

bool varDeclarationParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return logicSempred(dynamic_cast<LogicContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool varDeclarationParser::logicSempred(LogicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> varDeclarationParser::_decisionToDFA;
atn::PredictionContextCache varDeclarationParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN varDeclarationParser::_atn;
std::vector<uint16_t> varDeclarationParser::_serializedATN;

std::vector<std::string> varDeclarationParser::_ruleNames = {
  "file", "cDeclaration", "cStatement", "varDec", "ass", "enumDec", "enum_list", 
  "addLogic", "name", "logicName", "vartype", "enumType", "logic", "logicAtom", 
  "logicConstant"
};

std::vector<std::string> varDeclarationParser::_literalNames = {
  "", "';'", "'='", "','", "'('", "')'", "'typedef'", "'enum'", "'{'", "'}'", 
  "", "", "", "", "'+'", "'-'", "'*'", "'/'"
};

std::vector<std::string> varDeclarationParser::_symbolicNames = {
  "", "", "", "", "LSBRACKET", "RSBRACKET", "TYPEDEF", "ENUM", "OB", "CB", 
  "VARTYPE", "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "PLUS", "MINUS", 
  "TIMES", "DIV", "NAME", "WS"
};

dfa::Vocabulary varDeclarationParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> varDeclarationParser::_tokenNames;

varDeclarationParser::Initializer::Initializer() {
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
    0x3, 0x15, 0x84, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x2b, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x2f, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x34, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x3a, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x4e, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x53, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x58, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x5d, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0x67, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x71, 0xa, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x79, 
    0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x7c, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0x80, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x3, 0x1a, 
    0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x2, 0x5, 0x3, 0x2, 0x12, 0x13, 0x3, 0x2, 0x10, 0x11, 
    0x3, 0x2, 0xd, 0xf, 0x2, 0x82, 0x2, 0x20, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x39, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x14, 0x62, 0x3, 0x2, 0x2, 0x2, 0x16, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x68, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x21, 0x5, 0x4, 0x3, 0x2, 0x21, 0x22, 0x7, 0x2, 0x2, 
    0x3, 0x22, 0x3, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x5, 0x6, 0x4, 0x2, 
    0x24, 0x25, 0x7, 0x3, 0x2, 0x2, 0x25, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x27, 0x5, 0x6, 0x4, 0x2, 0x27, 0x28, 0x7, 0x3, 0x2, 0x2, 0x28, 0x29, 
    0x5, 0x4, 0x3, 0x2, 0x29, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x2a, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x2c, 0x2f, 0x5, 0x8, 0x5, 0x2, 0x2d, 0x2f, 0x5, 0xc, 0x7, 
    0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x2f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0x16, 0xc, 0x2, 0x31, 
    0x33, 0x5, 0x12, 0xa, 0x2, 0x32, 0x34, 0x5, 0xa, 0x6, 0x2, 0x33, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0x4, 0x2, 0x2, 0x36, 0x3a, 0x7, 0x14, 
    0x2, 0x2, 0x37, 0x38, 0x7, 0x4, 0x2, 0x2, 0x38, 0x3a, 0x7, 0xd, 0x2, 
    0x2, 0x39, 0x35, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x9, 0x2, 0x2, 0x3c, 
    0x3d, 0x5, 0x12, 0xa, 0x2, 0x3d, 0x3e, 0x7, 0xa, 0x2, 0x2, 0x3e, 0x3f, 
    0x5, 0xe, 0x8, 0x2, 0x3f, 0x40, 0x7, 0xb, 0x2, 0x2, 0x40, 0x4e, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x8, 0x2, 0x2, 0x42, 0x43, 0x7, 0x9, 
    0x2, 0x2, 0x43, 0x44, 0x7, 0xa, 0x2, 0x2, 0x44, 0x45, 0x5, 0xe, 0x8, 
    0x2, 0x45, 0x46, 0x7, 0xb, 0x2, 0x2, 0x46, 0x47, 0x5, 0x12, 0xa, 0x2, 
    0x47, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x9, 0x2, 0x2, 0x49, 
    0x4a, 0x7, 0xa, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0xe, 0x8, 0x2, 0x4b, 0x4c, 
    0x7, 0xb, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x5, 0x12, 0xa, 
    0x2, 0x50, 0x51, 0x7, 0x4, 0x2, 0x2, 0x51, 0x53, 0x5, 0x10, 0x9, 0x2, 
    0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x5, 0x12, 0xa, 0x2, 0x55, 0x56, 
    0x7, 0x4, 0x2, 0x2, 0x56, 0x58, 0x5, 0x10, 0x9, 0x2, 0x57, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x5a, 0x7, 0x5, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0xe, 0x8, 
    0x2, 0x5b, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x54, 0x3, 0x2, 0x2, 0x2, 0x5d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x5f, 0x5, 0x1a, 0xe, 0x2, 0x5f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 
    0x7, 0x14, 0x2, 0x2, 0x61, 0x13, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 
    0x14, 0x2, 0x2, 0x63, 0x15, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 0x7, 0xc, 
    0x2, 0x2, 0x65, 0x67, 0x5, 0x18, 0xd, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x66, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x69, 0x5, 0x12, 0xa, 0x2, 0x69, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x6b, 0x8, 0xe, 0x1, 0x2, 0x6b, 0x71, 0x5, 0x1c, 0xf, 0x2, 0x6c, 0x6d, 
    0x7, 0x6, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x1a, 0xe, 0x2, 0x6e, 0x6f, 0x7, 
    0x7, 0x2, 0x2, 0x6f, 0x71, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x71, 0x7a, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x73, 0xc, 0x6, 0x2, 0x2, 0x73, 0x74, 0x9, 0x2, 0x2, 0x2, 
    0x74, 0x79, 0x5, 0x1a, 0xe, 0x7, 0x75, 0x76, 0xc, 0x5, 0x2, 0x2, 0x76, 
    0x77, 0x9, 0x3, 0x2, 0x2, 0x77, 0x79, 0x5, 0x1a, 0xe, 0x6, 0x78, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x75, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x7b, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x80, 0x5, 0x1e, 0x10, 0x2, 0x7e, 0x80, 0x5, 0x14, 0xb, 0x2, 
    0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x9, 0x4, 0x2, 0x2, 0x82, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xf, 0x2a, 0x2e, 0x33, 0x39, 0x4d, 0x52, 0x57, 0x5c, 
    0x66, 0x70, 0x78, 0x7a, 0x7f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

varDeclarationParser::Initializer varDeclarationParser::_init;
