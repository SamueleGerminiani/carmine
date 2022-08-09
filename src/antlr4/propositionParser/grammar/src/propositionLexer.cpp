
// Generated from proposition.g4 by ANTLR 4.10.1


#include "propositionLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PropositionLexerStaticData final {
  PropositionLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PropositionLexerStaticData(const PropositionLexerStaticData&) = delete;
  PropositionLexerStaticData(PropositionLexerStaticData&&) = delete;
  PropositionLexerStaticData& operator=(const PropositionLexerStaticData&) = delete;
  PropositionLexerStaticData& operator=(PropositionLexerStaticData&&) = delete;

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

std::once_flag propositionlexerLexerOnceFlag;
PropositionLexerStaticData *propositionlexerLexerStaticData = nullptr;

void propositionlexerLexerInitialize() {
  assert(propositionlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<PropositionLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "SIGN", "LGPAREN", 
      "RGPAREN", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", "CAST_BOOL", 
      "CAST_NUMERIC", "VARIABLE", "VALID_ID_START", "VALID_ID_CHAR", "NUMERIC", 
      "VERILOG_BINARY", "GCC_BINARY", "BOOLEAN", "PLUS", "MINUS", "TIMES", 
      "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", 
      "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "',bool>'", "',constlogic('", "')>'", "',logic('", "','", "',enum('", 
      "',numeric('", "", "'{'", "'}'", "'['", "']'", "'('", "')'", "'bool'", 
      "'double'", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'>'", 
      "'>='", "'<'", "'<='", "'=='", "'!='", "'&'", "'|'", "'^'", "'~'", 
      "'<<'", "'>>'", "'&&'", "'||'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "SIGN", "LGPAREN", "RGPAREN", "LCPAREN", 
      "RCPAREN", "LPAREN", "RPAREN", "CAST_BOOL", "CAST_NUMERIC", "VARIABLE", 
      "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "BOOLEAN", "PLUS", "MINUS", 
      "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", 
      "BXOR", "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,41,273,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,
  	1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,
  	1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,5,16,166,
  	8,16,10,16,12,16,169,9,16,1,17,3,17,172,8,17,1,18,1,18,1,18,1,18,3,18,
  	178,8,18,1,19,3,19,181,8,19,1,19,4,19,184,8,19,11,19,12,19,185,1,19,1,
  	19,4,19,190,8,19,11,19,12,19,191,3,19,194,8,19,1,20,1,20,1,20,4,20,199,
  	8,20,11,20,12,20,200,1,21,1,21,1,21,1,21,4,21,207,8,21,11,21,12,21,208,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,222,8,22,
  	1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,29,
  	1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,34,1,34,
  	1,35,1,35,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,39,1,40,
  	1,40,1,40,1,41,1,41,1,42,1,42,1,42,1,42,0,0,43,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,0,
  	37,0,39,18,41,19,43,20,45,21,47,22,49,23,51,24,53,25,55,26,57,27,59,28,
  	61,29,63,30,65,31,67,32,69,33,71,34,73,35,75,36,77,37,79,38,81,39,83,
  	40,85,41,1,0,4,2,0,115,115,117,117,3,0,65,90,95,95,97,122,5,0,46,46,48,
  	57,91,91,93,93,95,95,3,0,9,10,13,13,32,32,280,0,1,1,0,0,0,0,3,1,0,0,0,
  	0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,
  	0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,
  	0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,39,1,0,0,0,0,
  	41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,
  	0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,
  	0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,
  	73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,
  	0,0,0,0,85,1,0,0,0,1,87,1,0,0,0,3,94,1,0,0,0,5,107,1,0,0,0,7,110,1,0,
  	0,0,9,118,1,0,0,0,11,120,1,0,0,0,13,127,1,0,0,0,15,137,1,0,0,0,17,139,
  	1,0,0,0,19,141,1,0,0,0,21,143,1,0,0,0,23,145,1,0,0,0,25,147,1,0,0,0,27,
  	149,1,0,0,0,29,151,1,0,0,0,31,156,1,0,0,0,33,163,1,0,0,0,35,171,1,0,0,
  	0,37,177,1,0,0,0,39,180,1,0,0,0,41,195,1,0,0,0,43,202,1,0,0,0,45,221,
  	1,0,0,0,47,223,1,0,0,0,49,225,1,0,0,0,51,227,1,0,0,0,53,229,1,0,0,0,55,
  	231,1,0,0,0,57,233,1,0,0,0,59,236,1,0,0,0,61,238,1,0,0,0,63,241,1,0,0,
  	0,65,244,1,0,0,0,67,247,1,0,0,0,69,249,1,0,0,0,71,251,1,0,0,0,73,253,
  	1,0,0,0,75,255,1,0,0,0,77,258,1,0,0,0,79,261,1,0,0,0,81,264,1,0,0,0,83,
  	267,1,0,0,0,85,269,1,0,0,0,87,88,5,44,0,0,88,89,5,98,0,0,89,90,5,111,
  	0,0,90,91,5,111,0,0,91,92,5,108,0,0,92,93,5,62,0,0,93,2,1,0,0,0,94,95,
  	5,44,0,0,95,96,5,99,0,0,96,97,5,111,0,0,97,98,5,110,0,0,98,99,5,115,0,
  	0,99,100,5,116,0,0,100,101,5,108,0,0,101,102,5,111,0,0,102,103,5,103,
  	0,0,103,104,5,105,0,0,104,105,5,99,0,0,105,106,5,40,0,0,106,4,1,0,0,0,
  	107,108,5,41,0,0,108,109,5,62,0,0,109,6,1,0,0,0,110,111,5,44,0,0,111,
  	112,5,108,0,0,112,113,5,111,0,0,113,114,5,103,0,0,114,115,5,105,0,0,115,
  	116,5,99,0,0,116,117,5,40,0,0,117,8,1,0,0,0,118,119,5,44,0,0,119,10,1,
  	0,0,0,120,121,5,44,0,0,121,122,5,101,0,0,122,123,5,110,0,0,123,124,5,
  	117,0,0,124,125,5,109,0,0,125,126,5,40,0,0,126,12,1,0,0,0,127,128,5,44,
  	0,0,128,129,5,110,0,0,129,130,5,117,0,0,130,131,5,109,0,0,131,132,5,101,
  	0,0,132,133,5,114,0,0,133,134,5,105,0,0,134,135,5,99,0,0,135,136,5,40,
  	0,0,136,14,1,0,0,0,137,138,7,0,0,0,138,16,1,0,0,0,139,140,5,123,0,0,140,
  	18,1,0,0,0,141,142,5,125,0,0,142,20,1,0,0,0,143,144,5,91,0,0,144,22,1,
  	0,0,0,145,146,5,93,0,0,146,24,1,0,0,0,147,148,5,40,0,0,148,26,1,0,0,0,
  	149,150,5,41,0,0,150,28,1,0,0,0,151,152,5,98,0,0,152,153,5,111,0,0,153,
  	154,5,111,0,0,154,155,5,108,0,0,155,30,1,0,0,0,156,157,5,100,0,0,157,
  	158,5,111,0,0,158,159,5,117,0,0,159,160,5,98,0,0,160,161,5,108,0,0,161,
  	162,5,101,0,0,162,32,1,0,0,0,163,167,3,35,17,0,164,166,3,37,18,0,165,
  	164,1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,34,1,
  	0,0,0,169,167,1,0,0,0,170,172,7,1,0,0,171,170,1,0,0,0,172,36,1,0,0,0,
  	173,178,3,35,17,0,174,178,7,2,0,0,175,176,5,58,0,0,176,178,5,58,0,0,177,
  	173,1,0,0,0,177,174,1,0,0,0,177,175,1,0,0,0,178,38,1,0,0,0,179,181,5,
  	45,0,0,180,179,1,0,0,0,180,181,1,0,0,0,181,183,1,0,0,0,182,184,2,48,57,
  	0,183,182,1,0,0,0,184,185,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,
  	193,1,0,0,0,187,189,5,46,0,0,188,190,2,48,57,0,189,188,1,0,0,0,190,191,
  	1,0,0,0,191,189,1,0,0,0,191,192,1,0,0,0,192,194,1,0,0,0,193,187,1,0,0,
  	0,193,194,1,0,0,0,194,40,1,0,0,0,195,196,5,39,0,0,196,198,5,98,0,0,197,
  	199,2,48,49,0,198,197,1,0,0,0,199,200,1,0,0,0,200,198,1,0,0,0,200,201,
  	1,0,0,0,201,42,1,0,0,0,202,203,5,48,0,0,203,204,5,98,0,0,204,206,1,0,
  	0,0,205,207,2,48,49,0,206,205,1,0,0,0,207,208,1,0,0,0,208,206,1,0,0,0,
  	208,209,1,0,0,0,209,44,1,0,0,0,210,211,5,64,0,0,211,212,5,116,0,0,212,
  	213,5,114,0,0,213,214,5,117,0,0,214,222,5,101,0,0,215,216,5,64,0,0,216,
  	217,5,102,0,0,217,218,5,97,0,0,218,219,5,108,0,0,219,220,5,115,0,0,220,
  	222,5,101,0,0,221,210,1,0,0,0,221,215,1,0,0,0,222,46,1,0,0,0,223,224,
  	5,43,0,0,224,48,1,0,0,0,225,226,5,45,0,0,226,50,1,0,0,0,227,228,5,42,
  	0,0,228,52,1,0,0,0,229,230,5,47,0,0,230,54,1,0,0,0,231,232,5,62,0,0,232,
  	56,1,0,0,0,233,234,5,62,0,0,234,235,5,61,0,0,235,58,1,0,0,0,236,237,5,
  	60,0,0,237,60,1,0,0,0,238,239,5,60,0,0,239,240,5,61,0,0,240,62,1,0,0,
  	0,241,242,5,61,0,0,242,243,5,61,0,0,243,64,1,0,0,0,244,245,5,33,0,0,245,
  	246,5,61,0,0,246,66,1,0,0,0,247,248,5,38,0,0,248,68,1,0,0,0,249,250,5,
  	124,0,0,250,70,1,0,0,0,251,252,5,94,0,0,252,72,1,0,0,0,253,254,5,126,
  	0,0,254,74,1,0,0,0,255,256,5,60,0,0,256,257,5,60,0,0,257,76,1,0,0,0,258,
  	259,5,62,0,0,259,260,5,62,0,0,260,78,1,0,0,0,261,262,5,38,0,0,262,263,
  	5,38,0,0,263,80,1,0,0,0,264,265,5,124,0,0,265,266,5,124,0,0,266,82,1,
  	0,0,0,267,268,5,33,0,0,268,84,1,0,0,0,269,270,7,3,0,0,270,271,1,0,0,0,
  	271,272,6,42,0,0,272,86,1,0,0,0,11,0,167,171,177,180,185,191,193,200,
  	208,221,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  propositionlexerLexerStaticData = staticData.release();
}

}

propositionLexer::propositionLexer(CharStream *input) : Lexer(input) {
  propositionLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *propositionlexerLexerStaticData->atn, propositionlexerLexerStaticData->decisionToDFA, propositionlexerLexerStaticData->sharedContextCache);
}

propositionLexer::~propositionLexer() {
  delete _interpreter;
}

std::string propositionLexer::getGrammarFileName() const {
  return "proposition.g4";
}

const std::vector<std::string>& propositionLexer::getRuleNames() const {
  return propositionlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& propositionLexer::getChannelNames() const {
  return propositionlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& propositionLexer::getModeNames() const {
  return propositionlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& propositionLexer::getVocabulary() const {
  return propositionlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView propositionLexer::getSerializedATN() const {
  return propositionlexerLexerStaticData->serializedATN;
}

const atn::ATN& propositionLexer::getATN() const {
  return *propositionlexerLexerStaticData->atn;
}




void propositionLexer::initialize() {
  std::call_once(propositionlexerLexerOnceFlag, propositionlexerLexerInitialize);
}
