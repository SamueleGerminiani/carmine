
// Generated from proposition.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  propositionLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    SIGN = 8, LGPAREN = 9, RGPAREN = 10, LCPAREN = 11, RCPAREN = 12, LPAREN = 13, 
    RPAREN = 14, CAST_BOOL = 15, CAST_NUMERIC = 16, VARIABLE = 17, NUMERIC = 18, 
    VERILOG_BINARY = 19, GCC_BINARY = 20, BOOLEAN = 21, PLUS = 22, MINUS = 23, 
    TIMES = 24, DIV = 25, GT = 26, GE = 27, LT = 28, LE = 29, EQ = 30, NEQ = 31, 
    BAND = 32, BOR = 33, BXOR = 34, NEG = 35, LSHIFT = 36, RSHIFT = 37, 
    AND = 38, OR = 39, NOT = 40, WS = 41
  };

  explicit propositionLexer(antlr4::CharStream *input);

  ~propositionLexer() override;


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

