
// Generated from varDeclaration.g4 by ANTLR 4.10.1


#include "varDeclarationLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct VarDeclarationLexerStaticData final {
  VarDeclarationLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VarDeclarationLexerStaticData(const VarDeclarationLexerStaticData&) = delete;
  VarDeclarationLexerStaticData(VarDeclarationLexerStaticData&&) = delete;
  VarDeclarationLexerStaticData& operator=(const VarDeclarationLexerStaticData&) = delete;
  VarDeclarationLexerStaticData& operator=(VarDeclarationLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag vardeclarationlexerLexerOnceFlag;
VarDeclarationLexerStaticData *vardeclarationlexerLexerStaticData = nullptr;

void vardeclarationlexerLexerInitialize() {
  assert(vardeclarationlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<VarDeclarationLexerStaticData>(
    std::vector<std::string>{
      "T__0", "VARTYPE", "NAME", "VALID_ID_START", "VALID_ID_CHAR", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "';'"
    },
    std::vector<std::string>{
      "", "", "VARTYPE", "NAME", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,4,130,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,3,1,109,8,1,1,2,1,2,5,2,113,8,2,10,2,12,2,116,
  	9,2,1,3,3,3,119,8,3,1,4,1,4,1,4,1,4,3,4,125,8,4,1,5,1,5,1,5,1,5,0,0,6,
  	1,1,3,2,5,3,7,0,9,0,11,4,1,0,3,3,0,65,90,95,95,97,122,5,0,46,46,48,57,
  	91,91,93,93,95,95,3,0,9,10,13,13,32,32,140,0,1,1,0,0,0,0,3,1,0,0,0,0,
  	5,1,0,0,0,0,11,1,0,0,0,1,13,1,0,0,0,3,108,1,0,0,0,5,110,1,0,0,0,7,118,
  	1,0,0,0,9,124,1,0,0,0,11,126,1,0,0,0,13,14,5,59,0,0,14,2,1,0,0,0,15,16,
  	5,98,0,0,16,17,5,111,0,0,17,18,5,111,0,0,18,109,5,108,0,0,19,20,5,117,
  	0,0,20,21,5,110,0,0,21,22,5,115,0,0,22,23,5,105,0,0,23,24,5,103,0,0,24,
  	25,5,110,0,0,25,26,5,101,0,0,26,27,5,100,0,0,27,28,5,32,0,0,28,29,5,99,
  	0,0,29,30,5,104,0,0,30,31,5,97,0,0,31,109,5,114,0,0,32,33,5,117,0,0,33,
  	34,5,110,0,0,34,35,5,115,0,0,35,36,5,105,0,0,36,37,5,103,0,0,37,38,5,
  	110,0,0,38,39,5,101,0,0,39,40,5,100,0,0,40,41,5,32,0,0,41,42,5,115,0,
  	0,42,43,5,104,0,0,43,44,5,111,0,0,44,45,5,114,0,0,45,109,5,116,0,0,46,
  	47,5,117,0,0,47,48,5,110,0,0,48,49,5,115,0,0,49,50,5,105,0,0,50,51,5,
  	103,0,0,51,52,5,110,0,0,52,53,5,101,0,0,53,54,5,100,0,0,54,55,5,32,0,
  	0,55,56,5,105,0,0,56,57,5,110,0,0,57,109,5,116,0,0,58,59,5,117,0,0,59,
  	60,5,110,0,0,60,61,5,115,0,0,61,62,5,105,0,0,62,63,5,103,0,0,63,64,5,
  	110,0,0,64,65,5,101,0,0,65,66,5,100,0,0,66,67,5,32,0,0,67,68,5,108,0,
  	0,68,69,5,111,0,0,69,70,5,110,0,0,70,71,5,103,0,0,71,72,5,32,0,0,72,73,
  	5,108,0,0,73,74,5,111,0,0,74,75,5,110,0,0,75,109,5,103,0,0,76,77,5,99,
  	0,0,77,78,5,104,0,0,78,79,5,97,0,0,79,109,5,114,0,0,80,81,5,115,0,0,81,
  	82,5,104,0,0,82,83,5,111,0,0,83,84,5,114,0,0,84,109,5,116,0,0,85,86,5,
  	105,0,0,86,87,5,110,0,0,87,109,5,116,0,0,88,89,5,108,0,0,89,90,5,111,
  	0,0,90,91,5,110,0,0,91,92,5,103,0,0,92,93,5,32,0,0,93,94,5,108,0,0,94,
  	95,5,111,0,0,95,96,5,110,0,0,96,109,5,103,0,0,97,98,5,102,0,0,98,99,5,
  	108,0,0,99,100,5,111,0,0,100,101,5,97,0,0,101,109,5,116,0,0,102,103,5,
  	100,0,0,103,104,5,111,0,0,104,105,5,117,0,0,105,106,5,98,0,0,106,107,
  	5,108,0,0,107,109,5,101,0,0,108,15,1,0,0,0,108,19,1,0,0,0,108,32,1,0,
  	0,0,108,46,1,0,0,0,108,58,1,0,0,0,108,76,1,0,0,0,108,80,1,0,0,0,108,85,
  	1,0,0,0,108,88,1,0,0,0,108,97,1,0,0,0,108,102,1,0,0,0,109,4,1,0,0,0,110,
  	114,3,7,3,0,111,113,3,9,4,0,112,111,1,0,0,0,113,116,1,0,0,0,114,112,1,
  	0,0,0,114,115,1,0,0,0,115,6,1,0,0,0,116,114,1,0,0,0,117,119,7,0,0,0,118,
  	117,1,0,0,0,119,8,1,0,0,0,120,125,3,7,3,0,121,125,7,1,0,0,122,123,5,58,
  	0,0,123,125,5,58,0,0,124,120,1,0,0,0,124,121,1,0,0,0,124,122,1,0,0,0,
  	125,10,1,0,0,0,126,127,7,2,0,0,127,128,1,0,0,0,128,129,6,5,0,0,129,12,
  	1,0,0,0,5,0,108,114,118,124,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vardeclarationlexerLexerStaticData = staticData.release();
}

}

varDeclarationLexer::varDeclarationLexer(CharStream *input) : Lexer(input) {
  varDeclarationLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *vardeclarationlexerLexerStaticData->atn, vardeclarationlexerLexerStaticData->decisionToDFA, vardeclarationlexerLexerStaticData->sharedContextCache);
}

varDeclarationLexer::~varDeclarationLexer() {
  delete _interpreter;
}

std::string varDeclarationLexer::getGrammarFileName() const {
  return "varDeclaration.g4";
}

const std::vector<std::string>& varDeclarationLexer::getRuleNames() const {
  return vardeclarationlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& varDeclarationLexer::getChannelNames() const {
  return vardeclarationlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& varDeclarationLexer::getModeNames() const {
  return vardeclarationlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& varDeclarationLexer::getVocabulary() const {
  return vardeclarationlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView varDeclarationLexer::getSerializedATN() const {
  return vardeclarationlexerLexerStaticData->serializedATN;
}

const atn::ATN& varDeclarationLexer::getATN() const {
  return *vardeclarationlexerLexerStaticData->atn;
}




void varDeclarationLexer::initialize() {
  std::call_once(vardeclarationlexerLexerOnceFlag, vardeclarationlexerLexerInitialize);
}
