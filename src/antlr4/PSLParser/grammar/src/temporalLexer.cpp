
// Generated from temporal.g4 by ANTLR 4.10.1


#include "temporalLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct TemporalLexerStaticData final {
  TemporalLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TemporalLexerStaticData(const TemporalLexerStaticData&) = delete;
  TemporalLexerStaticData(TemporalLexerStaticData&&) = delete;
  TemporalLexerStaticData& operator=(const TemporalLexerStaticData&) = delete;
  TemporalLexerStaticData& operator=(TemporalLexerStaticData&&) = delete;

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

std::once_flag temporallexerLexerOnceFlag;
TemporalLexerStaticData *temporallexerLexerStaticData = nullptr;

void temporallexerLexerInitialize() {
  assert(temporallexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<TemporalLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "TIMER", "EVENTUALLY", 
      "ALWAYS", "NEXT", "UNTIL", "WUNTIL", "SUNTIL", "RELEASE", "SRELEASE", 
      "DOTS", "IMPL", "IMPL2", "SEREIMPL1", "SEREIMPL2", "IFF", "XOR", "BIND1", 
      "BIND2", "ASS", "SCOL", "COL", "FIRST_MATCH", "DELAY", "SIGN", "LGPAREN", 
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
      "", "','", "',bool>'", "',constlogic('", "')>'", "',logic('", "',enum('", 
      "',numeric('", "'$timeout'", "'F'", "'G'", "'X'", "'U'", "'W'", "'X[!]'", 
      "'R'", "'M'", "'..'", "'->'", "'=>'", "'|->'", "'|=>'", "'<->'", "'xor'", 
      "'<>->'", "'<>=>'", "'='", "';'", "':'", "'first_match'", "'##'", 
      "", "'{'", "'}'", "'['", "']'", "'('", "')'", "'bool'", "'double'", 
      "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", 
      "'<='", "'=='", "'!='", "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", 
      "'&&'", "'||'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "TIMER", "EVENTUALLY", "ALWAYS", "NEXT", 
      "UNTIL", "WUNTIL", "SUNTIL", "RELEASE", "SRELEASE", "DOTS", "IMPL", 
      "IMPL2", "SEREIMPL1", "SEREIMPL2", "IFF", "XOR", "BIND1", "BIND2", 
      "ASS", "SCOL", "COL", "FIRST_MATCH", "DELAY", "SIGN", "LGPAREN", "RGPAREN", 
      "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", "CAST_BOOL", "CAST_NUMERIC", 
      "VARIABLE", "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "BOOLEAN", 
      "PLUS", "MINUS", "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", 
      "BAND", "BOR", "BXOR", "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,64,403,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,
  	10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,15,1,
  	15,1,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,
  	20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,23,1,23,1,
  	23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,
  	28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,
  	29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,
  	36,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,
  	39,5,39,296,8,39,10,39,12,39,299,9,39,1,40,3,40,302,8,40,1,41,1,41,1,
  	41,1,41,3,41,308,8,41,1,42,3,42,311,8,42,1,42,4,42,314,8,42,11,42,12,
  	42,315,1,42,1,42,4,42,320,8,42,11,42,12,42,321,3,42,324,8,42,1,43,1,43,
  	1,43,4,43,329,8,43,11,43,12,43,330,1,44,1,44,1,44,1,44,4,44,337,8,44,
  	11,44,12,44,338,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,
  	3,45,352,8,45,1,46,1,46,1,47,1,47,1,48,1,48,1,49,1,49,1,50,1,50,1,51,
  	1,51,1,51,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,54,1,55,1,55,1,55,1,56,
  	1,56,1,57,1,57,1,58,1,58,1,59,1,59,1,60,1,60,1,60,1,61,1,61,1,61,1,62,
  	1,62,1,62,1,63,1,63,1,63,1,64,1,64,1,65,1,65,1,65,1,65,0,0,66,1,1,3,2,
  	5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,
  	16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,
  	55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,
  	39,79,40,81,0,83,0,85,41,87,42,89,43,91,44,93,45,95,46,97,47,99,48,101,
  	49,103,50,105,51,107,52,109,53,111,54,113,55,115,56,117,57,119,58,121,
  	59,123,60,125,61,127,62,129,63,131,64,1,0,4,2,0,115,115,117,117,3,0,65,
  	90,95,95,97,122,5,0,46,46,48,57,91,91,93,93,95,95,3,0,9,10,13,13,32,32,
  	410,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,
  	1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,
  	0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,
  	0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,
  	1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,
  	0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,
  	0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,
  	1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,
  	0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,
  	0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,
  	0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,
  	0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,
  	0,131,1,0,0,0,1,133,1,0,0,0,3,135,1,0,0,0,5,142,1,0,0,0,7,155,1,0,0,0,
  	9,158,1,0,0,0,11,166,1,0,0,0,13,173,1,0,0,0,15,183,1,0,0,0,17,192,1,0,
  	0,0,19,194,1,0,0,0,21,196,1,0,0,0,23,198,1,0,0,0,25,200,1,0,0,0,27,202,
  	1,0,0,0,29,207,1,0,0,0,31,209,1,0,0,0,33,211,1,0,0,0,35,214,1,0,0,0,37,
  	217,1,0,0,0,39,220,1,0,0,0,41,224,1,0,0,0,43,228,1,0,0,0,45,232,1,0,0,
  	0,47,236,1,0,0,0,49,241,1,0,0,0,51,246,1,0,0,0,53,248,1,0,0,0,55,250,
  	1,0,0,0,57,252,1,0,0,0,59,264,1,0,0,0,61,267,1,0,0,0,63,269,1,0,0,0,65,
  	271,1,0,0,0,67,273,1,0,0,0,69,275,1,0,0,0,71,277,1,0,0,0,73,279,1,0,0,
  	0,75,281,1,0,0,0,77,286,1,0,0,0,79,293,1,0,0,0,81,301,1,0,0,0,83,307,
  	1,0,0,0,85,310,1,0,0,0,87,325,1,0,0,0,89,332,1,0,0,0,91,351,1,0,0,0,93,
  	353,1,0,0,0,95,355,1,0,0,0,97,357,1,0,0,0,99,359,1,0,0,0,101,361,1,0,
  	0,0,103,363,1,0,0,0,105,366,1,0,0,0,107,368,1,0,0,0,109,371,1,0,0,0,111,
  	374,1,0,0,0,113,377,1,0,0,0,115,379,1,0,0,0,117,381,1,0,0,0,119,383,1,
  	0,0,0,121,385,1,0,0,0,123,388,1,0,0,0,125,391,1,0,0,0,127,394,1,0,0,0,
  	129,397,1,0,0,0,131,399,1,0,0,0,133,134,5,44,0,0,134,2,1,0,0,0,135,136,
  	5,44,0,0,136,137,5,98,0,0,137,138,5,111,0,0,138,139,5,111,0,0,139,140,
  	5,108,0,0,140,141,5,62,0,0,141,4,1,0,0,0,142,143,5,44,0,0,143,144,5,99,
  	0,0,144,145,5,111,0,0,145,146,5,110,0,0,146,147,5,115,0,0,147,148,5,116,
  	0,0,148,149,5,108,0,0,149,150,5,111,0,0,150,151,5,103,0,0,151,152,5,105,
  	0,0,152,153,5,99,0,0,153,154,5,40,0,0,154,6,1,0,0,0,155,156,5,41,0,0,
  	156,157,5,62,0,0,157,8,1,0,0,0,158,159,5,44,0,0,159,160,5,108,0,0,160,
  	161,5,111,0,0,161,162,5,103,0,0,162,163,5,105,0,0,163,164,5,99,0,0,164,
  	165,5,40,0,0,165,10,1,0,0,0,166,167,5,44,0,0,167,168,5,101,0,0,168,169,
  	5,110,0,0,169,170,5,117,0,0,170,171,5,109,0,0,171,172,5,40,0,0,172,12,
  	1,0,0,0,173,174,5,44,0,0,174,175,5,110,0,0,175,176,5,117,0,0,176,177,
  	5,109,0,0,177,178,5,101,0,0,178,179,5,114,0,0,179,180,5,105,0,0,180,181,
  	5,99,0,0,181,182,5,40,0,0,182,14,1,0,0,0,183,184,5,36,0,0,184,185,5,116,
  	0,0,185,186,5,105,0,0,186,187,5,109,0,0,187,188,5,101,0,0,188,189,5,111,
  	0,0,189,190,5,117,0,0,190,191,5,116,0,0,191,16,1,0,0,0,192,193,5,70,0,
  	0,193,18,1,0,0,0,194,195,5,71,0,0,195,20,1,0,0,0,196,197,5,88,0,0,197,
  	22,1,0,0,0,198,199,5,85,0,0,199,24,1,0,0,0,200,201,5,87,0,0,201,26,1,
  	0,0,0,202,203,5,88,0,0,203,204,5,91,0,0,204,205,5,33,0,0,205,206,5,93,
  	0,0,206,28,1,0,0,0,207,208,5,82,0,0,208,30,1,0,0,0,209,210,5,77,0,0,210,
  	32,1,0,0,0,211,212,5,46,0,0,212,213,5,46,0,0,213,34,1,0,0,0,214,215,5,
  	45,0,0,215,216,5,62,0,0,216,36,1,0,0,0,217,218,5,61,0,0,218,219,5,62,
  	0,0,219,38,1,0,0,0,220,221,5,124,0,0,221,222,5,45,0,0,222,223,5,62,0,
  	0,223,40,1,0,0,0,224,225,5,124,0,0,225,226,5,61,0,0,226,227,5,62,0,0,
  	227,42,1,0,0,0,228,229,5,60,0,0,229,230,5,45,0,0,230,231,5,62,0,0,231,
  	44,1,0,0,0,232,233,5,120,0,0,233,234,5,111,0,0,234,235,5,114,0,0,235,
  	46,1,0,0,0,236,237,5,60,0,0,237,238,5,62,0,0,238,239,5,45,0,0,239,240,
  	5,62,0,0,240,48,1,0,0,0,241,242,5,60,0,0,242,243,5,62,0,0,243,244,5,61,
  	0,0,244,245,5,62,0,0,245,50,1,0,0,0,246,247,5,61,0,0,247,52,1,0,0,0,248,
  	249,5,59,0,0,249,54,1,0,0,0,250,251,5,58,0,0,251,56,1,0,0,0,252,253,5,
  	102,0,0,253,254,5,105,0,0,254,255,5,114,0,0,255,256,5,115,0,0,256,257,
  	5,116,0,0,257,258,5,95,0,0,258,259,5,109,0,0,259,260,5,97,0,0,260,261,
  	5,116,0,0,261,262,5,99,0,0,262,263,5,104,0,0,263,58,1,0,0,0,264,265,5,
  	35,0,0,265,266,5,35,0,0,266,60,1,0,0,0,267,268,7,0,0,0,268,62,1,0,0,0,
  	269,270,5,123,0,0,270,64,1,0,0,0,271,272,5,125,0,0,272,66,1,0,0,0,273,
  	274,5,91,0,0,274,68,1,0,0,0,275,276,5,93,0,0,276,70,1,0,0,0,277,278,5,
  	40,0,0,278,72,1,0,0,0,279,280,5,41,0,0,280,74,1,0,0,0,281,282,5,98,0,
  	0,282,283,5,111,0,0,283,284,5,111,0,0,284,285,5,108,0,0,285,76,1,0,0,
  	0,286,287,5,100,0,0,287,288,5,111,0,0,288,289,5,117,0,0,289,290,5,98,
  	0,0,290,291,5,108,0,0,291,292,5,101,0,0,292,78,1,0,0,0,293,297,3,81,40,
  	0,294,296,3,83,41,0,295,294,1,0,0,0,296,299,1,0,0,0,297,295,1,0,0,0,297,
  	298,1,0,0,0,298,80,1,0,0,0,299,297,1,0,0,0,300,302,7,1,0,0,301,300,1,
  	0,0,0,302,82,1,0,0,0,303,308,3,81,40,0,304,308,7,2,0,0,305,306,5,58,0,
  	0,306,308,5,58,0,0,307,303,1,0,0,0,307,304,1,0,0,0,307,305,1,0,0,0,308,
  	84,1,0,0,0,309,311,5,45,0,0,310,309,1,0,0,0,310,311,1,0,0,0,311,313,1,
  	0,0,0,312,314,2,48,57,0,313,312,1,0,0,0,314,315,1,0,0,0,315,313,1,0,0,
  	0,315,316,1,0,0,0,316,323,1,0,0,0,317,319,5,46,0,0,318,320,2,48,57,0,
  	319,318,1,0,0,0,320,321,1,0,0,0,321,319,1,0,0,0,321,322,1,0,0,0,322,324,
  	1,0,0,0,323,317,1,0,0,0,323,324,1,0,0,0,324,86,1,0,0,0,325,326,5,39,0,
  	0,326,328,5,98,0,0,327,329,2,48,49,0,328,327,1,0,0,0,329,330,1,0,0,0,
  	330,328,1,0,0,0,330,331,1,0,0,0,331,88,1,0,0,0,332,333,5,48,0,0,333,334,
  	5,98,0,0,334,336,1,0,0,0,335,337,2,48,49,0,336,335,1,0,0,0,337,338,1,
  	0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,339,90,1,0,0,0,340,341,5,64,0,0,
  	341,342,5,116,0,0,342,343,5,114,0,0,343,344,5,117,0,0,344,352,5,101,0,
  	0,345,346,5,64,0,0,346,347,5,102,0,0,347,348,5,97,0,0,348,349,5,108,0,
  	0,349,350,5,115,0,0,350,352,5,101,0,0,351,340,1,0,0,0,351,345,1,0,0,0,
  	352,92,1,0,0,0,353,354,5,43,0,0,354,94,1,0,0,0,355,356,5,45,0,0,356,96,
  	1,0,0,0,357,358,5,42,0,0,358,98,1,0,0,0,359,360,5,47,0,0,360,100,1,0,
  	0,0,361,362,5,62,0,0,362,102,1,0,0,0,363,364,5,62,0,0,364,365,5,61,0,
  	0,365,104,1,0,0,0,366,367,5,60,0,0,367,106,1,0,0,0,368,369,5,60,0,0,369,
  	370,5,61,0,0,370,108,1,0,0,0,371,372,5,61,0,0,372,373,5,61,0,0,373,110,
  	1,0,0,0,374,375,5,33,0,0,375,376,5,61,0,0,376,112,1,0,0,0,377,378,5,38,
  	0,0,378,114,1,0,0,0,379,380,5,124,0,0,380,116,1,0,0,0,381,382,5,94,0,
  	0,382,118,1,0,0,0,383,384,5,126,0,0,384,120,1,0,0,0,385,386,5,60,0,0,
  	386,387,5,60,0,0,387,122,1,0,0,0,388,389,5,62,0,0,389,390,5,62,0,0,390,
  	124,1,0,0,0,391,392,5,38,0,0,392,393,5,38,0,0,393,126,1,0,0,0,394,395,
  	5,124,0,0,395,396,5,124,0,0,396,128,1,0,0,0,397,398,5,33,0,0,398,130,
  	1,0,0,0,399,400,7,3,0,0,400,401,1,0,0,0,401,402,6,65,0,0,402,132,1,0,
  	0,0,11,0,297,301,307,310,315,321,323,330,338,351,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  temporallexerLexerStaticData = staticData.release();
}

}

temporalLexer::temporalLexer(CharStream *input) : Lexer(input) {
  temporalLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *temporallexerLexerStaticData->atn, temporallexerLexerStaticData->decisionToDFA, temporallexerLexerStaticData->sharedContextCache);
}

temporalLexer::~temporalLexer() {
  delete _interpreter;
}

std::string temporalLexer::getGrammarFileName() const {
  return "temporal.g4";
}

const std::vector<std::string>& temporalLexer::getRuleNames() const {
  return temporallexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& temporalLexer::getChannelNames() const {
  return temporallexerLexerStaticData->channelNames;
}

const std::vector<std::string>& temporalLexer::getModeNames() const {
  return temporallexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& temporalLexer::getVocabulary() const {
  return temporallexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView temporalLexer::getSerializedATN() const {
  return temporallexerLexerStaticData->serializedATN;
}

const atn::ATN& temporalLexer::getATN() const {
  return *temporallexerLexerStaticData->atn;
}




void temporalLexer::initialize() {
  std::call_once(temporallexerLexerOnceFlag, temporallexerLexerInitialize);
}
