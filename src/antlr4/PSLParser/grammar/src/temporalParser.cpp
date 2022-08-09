
// Generated from temporal.g4 by ANTLR 4.10.1


#include "temporalListener.h"

#include "temporalParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct TemporalParserStaticData final {
  TemporalParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TemporalParserStaticData(const TemporalParserStaticData&) = delete;
  TemporalParserStaticData(TemporalParserStaticData&&) = delete;
  TemporalParserStaticData& operator=(const TemporalParserStaticData&) = delete;
  TemporalParserStaticData& operator=(TemporalParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag temporalParserOnceFlag;
TemporalParserStaticData *temporalParserStaticData = nullptr;

void temporalParserInitialize() {
  assert(temporalParserStaticData == nullptr);
  auto staticData = std::make_unique<TemporalParserStaticData>(
    std::vector<std::string>{
      "formula", "implication", "sere", "tformula", "file", "boolean", "booleanAtom", 
      "booleanConstant", "booleanVariable", "logic", "logicAtom", "logicConstant", 
      "namedLogicConst", "logicVariable", "enumVariable", "enumName", "namedConst", 
      "numeric", "numericAtom", "numericConstant", "numericVariable", "variable", 
      "relop"
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
  	4,1,64,438,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,104,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,125,8,2,1,2,1,2,
  	3,2,129,8,2,1,2,3,2,132,8,2,1,2,3,2,135,8,2,1,2,3,2,138,8,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,158,
  	8,2,1,2,3,2,161,8,2,1,2,3,2,164,8,2,1,2,3,2,167,8,2,1,2,3,2,170,8,2,1,
  	2,1,2,1,2,1,2,1,2,3,2,177,8,2,1,2,3,2,180,8,2,1,2,3,2,183,8,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,195,8,2,1,2,3,2,198,8,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,3,2,206,8,2,1,2,3,2,209,8,2,1,2,5,2,212,8,2,10,2,12,2,215,
  	9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,243,8,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,260,8,3,10,3,12,3,263,9,3,
  	1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,3,5,302,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,
  	5,316,8,5,10,5,12,5,319,9,5,1,6,1,6,3,6,323,8,6,1,7,1,7,1,8,1,8,1,8,1,
  	8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,339,8,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,362,8,
  	9,10,9,12,9,365,9,9,1,10,1,10,1,10,1,10,3,10,371,8,10,1,11,1,11,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,3,17,406,8,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,414,8,17,10,
  	17,12,17,417,9,17,1,18,1,18,3,18,421,8,18,1,19,1,19,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,21,3,21,432,8,21,1,21,1,21,1,22,1,22,1,22,0,5,4,6,10,18,
  	34,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	0,4,1,0,47,48,1,0,45,46,1,0,41,43,1,0,49,52,493,0,46,1,0,0,0,2,103,1,
  	0,0,0,4,137,1,0,0,0,6,242,1,0,0,0,8,264,1,0,0,0,10,301,1,0,0,0,12,322,
  	1,0,0,0,14,324,1,0,0,0,16,326,1,0,0,0,18,338,1,0,0,0,20,370,1,0,0,0,22,
  	372,1,0,0,0,24,374,1,0,0,0,26,380,1,0,0,0,28,388,1,0,0,0,30,394,1,0,0,
  	0,32,396,1,0,0,0,34,405,1,0,0,0,36,420,1,0,0,0,38,422,1,0,0,0,40,424,
  	1,0,0,0,42,431,1,0,0,0,44,435,1,0,0,0,46,47,3,2,1,0,47,48,5,0,0,1,48,
  	1,1,0,0,0,49,50,5,10,0,0,50,51,5,36,0,0,51,52,3,6,3,0,52,53,5,18,0,0,
  	53,54,3,6,3,0,54,55,5,37,0,0,55,104,1,0,0,0,56,57,5,10,0,0,57,58,5,36,
  	0,0,58,59,3,6,3,0,59,60,5,19,0,0,60,61,3,6,3,0,61,62,5,37,0,0,62,104,
  	1,0,0,0,63,64,5,10,0,0,64,65,5,36,0,0,65,66,5,32,0,0,66,67,3,4,2,0,67,
  	68,5,33,0,0,68,69,5,34,0,0,69,70,5,35,0,0,70,71,5,18,0,0,71,72,3,6,3,
  	0,72,73,5,37,0,0,73,104,1,0,0,0,74,75,5,10,0,0,75,76,5,36,0,0,76,77,5,
  	32,0,0,77,78,3,4,2,0,78,79,5,33,0,0,79,80,5,34,0,0,80,81,5,35,0,0,81,
  	82,5,19,0,0,82,83,3,6,3,0,83,84,5,37,0,0,84,104,1,0,0,0,85,86,5,10,0,
  	0,86,87,5,36,0,0,87,88,5,32,0,0,88,89,3,4,2,0,89,90,5,33,0,0,90,91,5,
  	20,0,0,91,92,3,6,3,0,92,93,5,37,0,0,93,104,1,0,0,0,94,95,5,10,0,0,95,
  	96,5,36,0,0,96,97,5,32,0,0,97,98,3,4,2,0,98,99,5,33,0,0,99,100,5,21,0,
  	0,100,101,3,6,3,0,101,102,5,37,0,0,102,104,1,0,0,0,103,49,1,0,0,0,103,
  	56,1,0,0,0,103,63,1,0,0,0,103,74,1,0,0,0,103,85,1,0,0,0,103,94,1,0,0,
  	0,104,3,1,0,0,0,105,106,6,2,-1,0,106,138,3,10,5,0,107,108,5,8,0,0,108,
  	109,5,36,0,0,109,110,3,10,5,0,110,111,5,1,0,0,111,112,5,41,0,0,112,113,
  	5,37,0,0,113,138,1,0,0,0,114,115,5,36,0,0,115,116,3,4,2,0,116,117,5,37,
  	0,0,117,138,1,0,0,0,118,119,5,32,0,0,119,120,3,4,2,0,120,121,5,33,0,0,
  	121,138,1,0,0,0,122,124,5,30,0,0,123,125,5,34,0,0,124,123,1,0,0,0,124,
  	125,1,0,0,0,125,126,1,0,0,0,126,128,5,41,0,0,127,129,5,17,0,0,128,127,
  	1,0,0,0,128,129,1,0,0,0,129,131,1,0,0,0,130,132,5,41,0,0,131,130,1,0,
  	0,0,131,132,1,0,0,0,132,134,1,0,0,0,133,135,5,35,0,0,134,133,1,0,0,0,
  	134,135,1,0,0,0,135,136,1,0,0,0,136,138,3,4,2,2,137,105,1,0,0,0,137,107,
  	1,0,0,0,137,114,1,0,0,0,137,118,1,0,0,0,137,122,1,0,0,0,138,213,1,0,0,
  	0,139,140,10,11,0,0,140,141,5,56,0,0,141,212,3,4,2,12,142,143,10,10,0,
  	0,143,144,5,55,0,0,144,212,3,4,2,11,145,146,10,9,0,0,146,147,5,61,0,0,
  	147,212,3,4,2,10,148,149,10,8,0,0,149,150,5,27,0,0,150,212,3,4,2,9,151,
  	152,10,7,0,0,152,153,5,28,0,0,153,212,3,4,2,8,154,155,10,1,0,0,155,157,
  	5,30,0,0,156,158,5,34,0,0,157,156,1,0,0,0,157,158,1,0,0,0,158,160,1,0,
  	0,0,159,161,5,41,0,0,160,159,1,0,0,0,160,161,1,0,0,0,161,163,1,0,0,0,
  	162,164,5,17,0,0,163,162,1,0,0,0,163,164,1,0,0,0,164,166,1,0,0,0,165,
  	167,5,41,0,0,166,165,1,0,0,0,166,167,1,0,0,0,167,169,1,0,0,0,168,170,
  	5,35,0,0,169,168,1,0,0,0,169,170,1,0,0,0,170,171,1,0,0,0,171,212,3,4,
  	2,2,172,173,10,6,0,0,173,174,5,34,0,0,174,176,5,47,0,0,175,177,5,41,0,
  	0,176,175,1,0,0,0,176,177,1,0,0,0,177,179,1,0,0,0,178,180,5,17,0,0,179,
  	178,1,0,0,0,179,180,1,0,0,0,180,182,1,0,0,0,181,183,5,41,0,0,182,181,
  	1,0,0,0,182,183,1,0,0,0,183,184,1,0,0,0,184,212,5,35,0,0,185,186,10,5,
  	0,0,186,187,5,34,0,0,187,188,5,45,0,0,188,212,5,35,0,0,189,190,10,4,0,
  	0,190,191,5,34,0,0,191,192,5,26,0,0,192,194,5,41,0,0,193,195,5,17,0,0,
  	194,193,1,0,0,0,194,195,1,0,0,0,195,197,1,0,0,0,196,198,5,41,0,0,197,
  	196,1,0,0,0,197,198,1,0,0,0,198,199,1,0,0,0,199,212,5,35,0,0,200,201,
  	10,3,0,0,201,202,5,34,0,0,202,203,5,18,0,0,203,205,5,41,0,0,204,206,5,
  	17,0,0,205,204,1,0,0,0,205,206,1,0,0,0,206,208,1,0,0,0,207,209,5,41,0,
  	0,208,207,1,0,0,0,208,209,1,0,0,0,209,210,1,0,0,0,210,212,5,35,0,0,211,
  	139,1,0,0,0,211,142,1,0,0,0,211,145,1,0,0,0,211,148,1,0,0,0,211,151,1,
  	0,0,0,211,154,1,0,0,0,211,172,1,0,0,0,211,185,1,0,0,0,211,189,1,0,0,0,
  	211,200,1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,214,1,0,0,0,214,5,
  	1,0,0,0,215,213,1,0,0,0,216,217,6,3,-1,0,217,243,3,10,5,0,218,219,5,8,
  	0,0,219,220,5,36,0,0,220,221,3,10,5,0,221,222,5,1,0,0,222,223,5,41,0,
  	0,223,224,5,37,0,0,224,243,1,0,0,0,225,226,5,36,0,0,226,227,3,6,3,0,227,
  	228,5,37,0,0,228,243,1,0,0,0,229,230,5,63,0,0,230,243,3,6,3,9,231,232,
  	5,11,0,0,232,233,5,34,0,0,233,234,5,41,0,0,234,235,5,35,0,0,235,243,3,
  	6,3,3,236,237,5,11,0,0,237,243,3,6,3,2,238,239,5,32,0,0,239,240,3,4,2,
  	0,240,241,5,33,0,0,241,243,1,0,0,0,242,216,1,0,0,0,242,218,1,0,0,0,242,
  	225,1,0,0,0,242,229,1,0,0,0,242,231,1,0,0,0,242,236,1,0,0,0,242,238,1,
  	0,0,0,243,261,1,0,0,0,244,245,10,8,0,0,245,246,5,61,0,0,246,260,3,6,3,
  	9,247,248,10,7,0,0,248,249,5,62,0,0,249,260,3,6,3,8,250,251,10,6,0,0,
  	251,252,5,23,0,0,252,260,3,6,3,7,253,254,10,5,0,0,254,255,5,12,0,0,255,
  	260,3,6,3,6,256,257,10,4,0,0,257,258,5,15,0,0,258,260,3,6,3,5,259,244,
  	1,0,0,0,259,247,1,0,0,0,259,250,1,0,0,0,259,253,1,0,0,0,259,256,1,0,0,
  	0,260,263,1,0,0,0,261,259,1,0,0,0,261,262,1,0,0,0,262,7,1,0,0,0,263,261,
  	1,0,0,0,264,265,3,10,5,0,265,266,5,0,0,1,266,9,1,0,0,0,267,268,6,5,-1,
  	0,268,269,5,63,0,0,269,302,3,10,5,15,270,271,3,18,9,0,271,272,3,44,22,
  	0,272,273,3,18,9,0,273,302,1,0,0,0,274,275,3,34,17,0,275,276,3,44,22,
  	0,276,277,3,34,17,0,277,302,1,0,0,0,278,279,3,18,9,0,279,280,5,53,0,0,
  	280,281,3,18,9,0,281,302,1,0,0,0,282,283,3,34,17,0,283,284,5,53,0,0,284,
  	285,3,34,17,0,285,302,1,0,0,0,286,287,3,18,9,0,287,288,5,54,0,0,288,289,
  	3,18,9,0,289,302,1,0,0,0,290,291,3,34,17,0,291,292,5,54,0,0,292,293,3,
  	34,17,0,293,302,1,0,0,0,294,302,3,12,6,0,295,302,3,18,9,0,296,302,3,34,
  	17,0,297,298,5,36,0,0,298,299,3,10,5,0,299,300,5,37,0,0,300,302,1,0,0,
  	0,301,267,1,0,0,0,301,270,1,0,0,0,301,274,1,0,0,0,301,278,1,0,0,0,301,
  	282,1,0,0,0,301,286,1,0,0,0,301,290,1,0,0,0,301,294,1,0,0,0,301,295,1,
  	0,0,0,301,296,1,0,0,0,301,297,1,0,0,0,302,317,1,0,0,0,303,304,10,10,0,
  	0,304,305,5,53,0,0,305,316,3,10,5,11,306,307,10,7,0,0,307,308,5,54,0,
  	0,308,316,3,10,5,8,309,310,10,6,0,0,310,311,5,61,0,0,311,316,3,10,5,7,
  	312,313,10,5,0,0,313,314,5,62,0,0,314,316,3,10,5,6,315,303,1,0,0,0,315,
  	306,1,0,0,0,315,309,1,0,0,0,315,312,1,0,0,0,316,319,1,0,0,0,317,315,1,
  	0,0,0,317,318,1,0,0,0,318,11,1,0,0,0,319,317,1,0,0,0,320,323,3,14,7,0,
  	321,323,3,16,8,0,322,320,1,0,0,0,322,321,1,0,0,0,323,13,1,0,0,0,324,325,
  	5,44,0,0,325,15,1,0,0,0,326,327,5,51,0,0,327,328,3,42,21,0,328,329,5,
  	2,0,0,329,17,1,0,0,0,330,331,6,9,-1,0,331,332,5,58,0,0,332,339,3,18,9,
  	10,333,339,3,20,10,0,334,335,5,36,0,0,335,336,3,18,9,0,336,337,5,37,0,
  	0,337,339,1,0,0,0,338,330,1,0,0,0,338,333,1,0,0,0,338,334,1,0,0,0,339,
  	363,1,0,0,0,340,341,10,9,0,0,341,342,7,0,0,0,342,362,3,18,9,10,343,344,
  	10,8,0,0,344,345,7,1,0,0,345,362,3,18,9,9,346,347,10,7,0,0,347,348,5,
  	59,0,0,348,362,3,18,9,8,349,350,10,6,0,0,350,351,5,60,0,0,351,362,3,18,
  	9,7,352,353,10,5,0,0,353,354,5,55,0,0,354,362,3,18,9,6,355,356,10,4,0,
  	0,356,357,5,57,0,0,357,362,3,18,9,5,358,359,10,3,0,0,359,360,5,56,0,0,
  	360,362,3,18,9,4,361,340,1,0,0,0,361,343,1,0,0,0,361,346,1,0,0,0,361,
  	349,1,0,0,0,361,352,1,0,0,0,361,355,1,0,0,0,361,358,1,0,0,0,362,365,1,
  	0,0,0,363,361,1,0,0,0,363,364,1,0,0,0,364,19,1,0,0,0,365,363,1,0,0,0,
  	366,371,3,22,11,0,367,371,3,26,13,0,368,371,3,28,14,0,369,371,3,24,12,
  	0,370,366,1,0,0,0,370,367,1,0,0,0,370,368,1,0,0,0,370,369,1,0,0,0,371,
  	21,1,0,0,0,372,373,7,2,0,0,373,23,1,0,0,0,374,375,5,51,0,0,375,376,3,
  	32,16,0,376,377,5,3,0,0,377,378,5,41,0,0,378,379,5,4,0,0,379,25,1,0,0,
  	0,380,381,5,51,0,0,381,382,3,42,21,0,382,383,5,5,0,0,383,384,5,31,0,0,
  	384,385,5,1,0,0,385,386,5,41,0,0,386,387,5,4,0,0,387,27,1,0,0,0,388,389,
  	5,51,0,0,389,390,3,42,21,0,390,391,5,6,0,0,391,392,3,30,15,0,392,393,
  	5,4,0,0,393,29,1,0,0,0,394,395,5,40,0,0,395,31,1,0,0,0,396,397,5,40,0,
  	0,397,33,1,0,0,0,398,399,6,17,-1,0,399,406,3,36,18,0,400,406,3,18,9,0,
  	401,402,5,36,0,0,402,403,3,34,17,0,403,404,5,37,0,0,404,406,1,0,0,0,405,
  	398,1,0,0,0,405,400,1,0,0,0,405,401,1,0,0,0,406,415,1,0,0,0,407,408,10,
  	5,0,0,408,409,7,0,0,0,409,414,3,34,17,6,410,411,10,4,0,0,411,412,7,1,
  	0,0,412,414,3,34,17,5,413,407,1,0,0,0,413,410,1,0,0,0,414,417,1,0,0,0,
  	415,413,1,0,0,0,415,416,1,0,0,0,416,35,1,0,0,0,417,415,1,0,0,0,418,421,
  	3,38,19,0,419,421,3,40,20,0,420,418,1,0,0,0,420,419,1,0,0,0,421,37,1,
  	0,0,0,422,423,5,41,0,0,423,39,1,0,0,0,424,425,5,51,0,0,425,426,3,42,21,
  	0,426,427,5,7,0,0,427,428,5,41,0,0,428,429,5,4,0,0,429,41,1,0,0,0,430,
  	432,5,47,0,0,431,430,1,0,0,0,431,432,1,0,0,0,432,433,1,0,0,0,433,434,
  	5,40,0,0,434,43,1,0,0,0,435,436,7,3,0,0,436,45,1,0,0,0,36,103,124,128,
  	131,134,137,157,160,163,166,169,176,179,182,194,197,205,208,211,213,242,
  	259,261,301,315,317,322,338,361,363,370,405,413,415,420,431
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  temporalParserStaticData = staticData.release();
}

}

temporalParser::temporalParser(TokenStream *input) : temporalParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

temporalParser::temporalParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  temporalParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *temporalParserStaticData->atn, temporalParserStaticData->decisionToDFA, temporalParserStaticData->sharedContextCache, options);
}

temporalParser::~temporalParser() {
  delete _interpreter;
}

const atn::ATN& temporalParser::getATN() const {
  return *temporalParserStaticData->atn;
}

std::string temporalParser::getGrammarFileName() const {
  return "temporal.g4";
}

const std::vector<std::string>& temporalParser::getRuleNames() const {
  return temporalParserStaticData->ruleNames;
}

const dfa::Vocabulary& temporalParser::getVocabulary() const {
  return temporalParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView temporalParser::getSerializedATN() const {
  return temporalParserStaticData->serializedATN;
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

void temporalParser::initialize() {
  std::call_once(temporalParserOnceFlag, temporalParserInitialize);
}
