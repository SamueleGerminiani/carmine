
// Generated from varDeclaration.g4 by ANTLR 4.10.1


#include "varDeclarationListener.h"

#include "varDeclarationParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct VarDeclarationParserStaticData final {
  VarDeclarationParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VarDeclarationParserStaticData(const VarDeclarationParserStaticData&) = delete;
  VarDeclarationParserStaticData(VarDeclarationParserStaticData&&) = delete;
  VarDeclarationParserStaticData& operator=(const VarDeclarationParserStaticData&) = delete;
  VarDeclarationParserStaticData& operator=(VarDeclarationParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag vardeclarationParserOnceFlag;
VarDeclarationParserStaticData *vardeclarationParserStaticData = nullptr;

void vardeclarationParserInitialize() {
  assert(vardeclarationParserStaticData == nullptr);
  auto staticData = std::make_unique<VarDeclarationParserStaticData>(
    std::vector<std::string>{
      "file", "cDeclaration", "cStatement", "varDec", "name", "vartype"
    },
    std::vector<std::string>{
      "", "';'"
    },
    std::vector<std::string>{
      "", "", "VARTYPE", "NAME", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,4,34,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,0,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,23,8,1,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,
  	5,1,5,1,5,0,0,6,0,2,4,6,8,10,0,0,28,0,12,1,0,0,0,2,22,1,0,0,0,4,24,1,
  	0,0,0,6,26,1,0,0,0,8,29,1,0,0,0,10,31,1,0,0,0,12,13,3,2,1,0,13,14,5,0,
  	0,1,14,1,1,0,0,0,15,16,3,4,2,0,16,17,5,1,0,0,17,23,1,0,0,0,18,19,3,4,
  	2,0,19,20,5,1,0,0,20,21,3,2,1,0,21,23,1,0,0,0,22,15,1,0,0,0,22,18,1,0,
  	0,0,23,3,1,0,0,0,24,25,3,6,3,0,25,5,1,0,0,0,26,27,3,10,5,0,27,28,3,8,
  	4,0,28,7,1,0,0,0,29,30,5,3,0,0,30,9,1,0,0,0,31,32,5,2,0,0,32,11,1,0,0,
  	0,1,22
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vardeclarationParserStaticData = staticData.release();
}

}

varDeclarationParser::varDeclarationParser(TokenStream *input) : varDeclarationParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

varDeclarationParser::varDeclarationParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  varDeclarationParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *vardeclarationParserStaticData->atn, vardeclarationParserStaticData->decisionToDFA, vardeclarationParserStaticData->sharedContextCache, options);
}

varDeclarationParser::~varDeclarationParser() {
  delete _interpreter;
}

const atn::ATN& varDeclarationParser::getATN() const {
  return *vardeclarationParserStaticData->atn;
}

std::string varDeclarationParser::getGrammarFileName() const {
  return "varDeclaration.g4";
}

const std::vector<std::string>& varDeclarationParser::getRuleNames() const {
  return vardeclarationParserStaticData->ruleNames;
}

const dfa::Vocabulary& varDeclarationParser::getVocabulary() const {
  return vardeclarationParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView varDeclarationParser::getSerializedATN() const {
  return vardeclarationParserStaticData->serializedATN;
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

void varDeclarationParser::initialize() {
  std::call_once(vardeclarationParserOnceFlag, vardeclarationParserInitialize);
}
