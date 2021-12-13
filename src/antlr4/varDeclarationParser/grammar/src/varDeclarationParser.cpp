
// Generated from varDeclaration.g4 by ANTLR 4.9.3


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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    cDeclaration();
    setState(13);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(22);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(15);
      cStatement();
      setState(16);
      match(varDeclarationParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(18);
      cStatement();
      setState(19);
      match(varDeclarationParser::T__0);
      setState(20);
      cDeclaration();
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

//----------------- CStatementContext ------------------------------------------------------------------

varDeclarationParser::CStatementContext::CStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

varDeclarationParser::VarDecContext* varDeclarationParser::CStatementContext::varDec() {
  return getRuleContext<varDeclarationParser::VarDecContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    varDec();
   
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    vartype();
    setState(27);
    name();
   
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
  enterRule(_localctx, 8, varDeclarationParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
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
  enterRule(_localctx, 10, varDeclarationParser::RuleVartype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    match(varDeclarationParser::VARTYPE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> varDeclarationParser::_decisionToDFA;
atn::PredictionContextCache varDeclarationParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN varDeclarationParser::_atn;
std::vector<uint16_t> varDeclarationParser::_serializedATN;

std::vector<std::string> varDeclarationParser::_ruleNames = {
  "file", "cDeclaration", "cStatement", "varDec", "name", "vartype"
};

std::vector<std::string> varDeclarationParser::_literalNames = {
  "", "';'"
};

std::vector<std::string> varDeclarationParser::_symbolicNames = {
  "", "", "VARTYPE", "NAME", "WS"
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x6, 0x24, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x2, 0x2, 0x8, 0x2, 0x4, 0x6, 
       0x8, 0xa, 0xc, 0x2, 0x2, 0x2, 0x1e, 0x2, 0xe, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x8, 
       0x1c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x5, 0x4, 0x3, 0x2, 0xf, 0x10, 0x7, 
       0x2, 0x2, 0x3, 0x10, 0x3, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0x5, 0x6, 
       0x4, 0x2, 0x12, 0x13, 0x7, 0x3, 0x2, 0x2, 0x13, 0x19, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0x15, 0x5, 0x6, 0x4, 0x2, 0x15, 0x16, 0x7, 0x3, 0x2, 0x2, 
       0x16, 0x17, 0x5, 0x4, 0x3, 0x2, 0x17, 0x19, 0x3, 0x2, 0x2, 0x2, 0x18, 
       0x11, 0x3, 0x2, 0x2, 0x2, 0x18, 0x14, 0x3, 0x2, 0x2, 0x2, 0x19, 0x5, 
       0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x5, 0x8, 0x5, 0x2, 0x1b, 0x7, 0x3, 
       0x2, 0x2, 0x2, 0x1c, 0x1d, 0x5, 0xc, 0x7, 0x2, 0x1d, 0x1e, 0x5, 0xa, 
       0x6, 0x2, 0x1e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x5, 0x2, 
       0x2, 0x20, 0xb, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x7, 0x4, 0x2, 0x2, 
       0x22, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3, 0x18, 
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

varDeclarationParser::Initializer varDeclarationParser::_init;
