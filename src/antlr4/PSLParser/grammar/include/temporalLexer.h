
// Generated from temporal.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  temporalLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    TIMER = 8, EVENTUALLY = 9, ALWAYS = 10, NEXT = 11, UNTIL = 12, WUNTIL = 13, 
    SUNTIL = 14, RELEASE = 15, SRELEASE = 16, DOTS = 17, IMPL = 18, IMPL2 = 19, 
    SEREIMPL1 = 20, SEREIMPL2 = 21, IFF = 22, XOR = 23, BIND1 = 24, BIND2 = 25, 
    ASS = 26, SCOL = 27, COL = 28, FIRST_MATCH = 29, DELAY = 30, SIGN = 31, 
    LGPAREN = 32, RGPAREN = 33, LCPAREN = 34, RCPAREN = 35, LPAREN = 36, 
    RPAREN = 37, CAST_BOOL = 38, CAST_NUMERIC = 39, VARIABLE = 40, NUMERIC = 41, 
    VERILOG_BINARY = 42, GCC_BINARY = 43, BOOLEAN = 44, PLUS = 45, MINUS = 46, 
    TIMES = 47, DIV = 48, GT = 49, GE = 50, LT = 51, LE = 52, EQ = 53, NEQ = 54, 
    BAND = 55, BOR = 56, BXOR = 57, NEG = 58, LSHIFT = 59, RSHIFT = 60, 
    AND = 61, OR = 62, NOT = 63, WS = 64
  };

  explicit temporalLexer(antlr4::CharStream *input);

  ~temporalLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

