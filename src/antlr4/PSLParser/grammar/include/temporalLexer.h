
// Generated from temporal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  temporalLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    EVENTUALLY = 8, ALWAYS = 9, NEXT = 10, UNTIL = 11, WUNTIL = 12, SUNTIL = 13, 
    RELEASE = 14, SRELEASE = 15, DOTS = 16, IMPL = 17, IMPL2 = 18, IFF = 19, 
    XOR = 20, BIND1 = 21, BIND2 = 22, ASS = 23, DSYM1 = 24, SCOL = 25, COL = 26, 
    FIRST_MATCH = 27, SIGN = 28, LGPAREN = 29, RGPAREN = 30, LCPAREN = 31, 
    RCPAREN = 32, LPAREN = 33, RPAREN = 34, CAST_BOOL = 35, CAST_NUMERIC = 36, 
    VARIABLE = 37, NUMERIC = 38, VERILOG_BINARY = 39, GCC_BINARY = 40, BOOLEAN = 41, 
    PLUS = 42, MINUS = 43, TIMES = 44, DIV = 45, GT = 46, GE = 47, LT = 48, 
    LE = 49, EQ = 50, NEQ = 51, BAND = 52, BOR = 53, BXOR = 54, NEG = 55, 
    LSHIFT = 56, RSHIFT = 57, AND = 58, OR = 59, NOT = 60, WS = 61
  };

  temporalLexer(antlr4::CharStream *input);
  ~temporalLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

