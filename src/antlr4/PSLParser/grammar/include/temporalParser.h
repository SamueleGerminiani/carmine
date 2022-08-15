
// Generated from temporal.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  temporalParser : public antlr4::Parser {
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

  enum {
    RuleFormula = 0, RuleImplication = 1, RuleSere = 2, RuleTformula = 3, 
    RuleFile = 4, RuleBoolean = 5, RuleBooleanAtom = 6, RuleBooleanConstant = 7, 
    RuleBooleanVariable = 8, RuleLogic = 9, RuleLogicAtom = 10, RuleLogicConstant = 11, 
    RuleNamedLogicConst = 12, RuleLogicVariable = 13, RuleEnumVariable = 14, 
    RuleEnumName = 15, RuleNamedConst = 16, RuleNumeric = 17, RuleNumericAtom = 18, 
    RuleNumericConstant = 19, RuleNumericVariable = 20, RuleVariable = 21, 
    RuleRelop = 22
  };

  explicit temporalParser(antlr4::TokenStream *input);
  ~temporalParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FormulaContext;
  class ImplicationContext;
  class SereContext;
  class TformulaContext;
  class FileContext;
  class BooleanContext;
  class BooleanAtomContext;
  class BooleanConstantContext;
  class BooleanVariableContext;
  class LogicContext;
  class LogicAtomContext;
  class LogicConstantContext;
  class NamedLogicConstContext;
  class LogicVariableContext;
  class EnumVariableContext;
  class EnumNameContext;
  class NamedConstContext;
  class NumericContext;
  class NumericAtomContext;
  class NumericConstantContext;
  class NumericVariableContext;
  class VariableContext;
  class RelopContext; 

  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ImplicationContext *implication();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FormulaContext* formula();

  class  ImplicationContext : public antlr4::ParserRuleContext {
  public:
    ImplicationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALWAYS();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<TformulaContext *> tformula();
    TformulaContext* tformula(size_t i);
    antlr4::tree::TerminalNode *IMPL();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *IMPL2();
    antlr4::tree::TerminalNode *LGPAREN();
    SereContext *sere();
    antlr4::tree::TerminalNode *RGPAREN();
    antlr4::tree::TerminalNode *LCPAREN();
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *SEREIMPL1();
    antlr4::tree::TerminalNode *SEREIMPL2();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImplicationContext* implication();

  class  SereContext : public antlr4::ParserRuleContext {
  public:
    SereContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanContext *boolean();
    antlr4::tree::TerminalNode *TIMER();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<antlr4::tree::TerminalNode *> NUMERIC();
    antlr4::tree::TerminalNode* NUMERIC(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<SereContext *> sere();
    SereContext* sere(size_t i);
    antlr4::tree::TerminalNode *LGPAREN();
    antlr4::tree::TerminalNode *RGPAREN();
    antlr4::tree::TerminalNode *DELAY();
    antlr4::tree::TerminalNode *LCPAREN();
    antlr4::tree::TerminalNode *DOTS();
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *BOR();
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *SCOL();
    antlr4::tree::TerminalNode *COL();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *ASS();
    antlr4::tree::TerminalNode *IMPL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SereContext* sere();
  SereContext* sere(int precedence);
  class  TformulaContext : public antlr4::ParserRuleContext {
  public:
    TformulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanContext *boolean();
    antlr4::tree::TerminalNode *TIMER();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *NUMERIC();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<TformulaContext *> tformula();
    TformulaContext* tformula(size_t i);
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *NEXT();
    antlr4::tree::TerminalNode *LCPAREN();
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *LGPAREN();
    SereContext *sere();
    antlr4::tree::TerminalNode *RGPAREN();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *UNTIL();
    antlr4::tree::TerminalNode *RELEASE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TformulaContext* tformula();
  TformulaContext* tformula(int precedence);
  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanContext *boolean();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  BooleanContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *booleanop = nullptr;
    BooleanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    std::vector<BooleanContext *> boolean();
    BooleanContext* boolean(size_t i);
    std::vector<LogicContext *> logic();
    LogicContext* logic(size_t i);
    RelopContext *relop();
    std::vector<NumericContext *> numeric();
    NumericContext* numeric(size_t i);
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    BooleanAtomContext *booleanAtom();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanContext* boolean();
  BooleanContext* boolean(int precedence);
  class  BooleanAtomContext : public antlr4::ParserRuleContext {
  public:
    BooleanAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanConstantContext *booleanConstant();
    BooleanVariableContext *booleanVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanAtomContext* booleanAtom();

  class  BooleanConstantContext : public antlr4::ParserRuleContext {
  public:
    BooleanConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanConstantContext* booleanConstant();

  class  BooleanVariableContext : public antlr4::ParserRuleContext {
  public:
    BooleanVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanVariableContext* booleanVariable();

  class  LogicContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *artop = nullptr;
    antlr4::Token *logop = nullptr;
    LogicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEG();
    std::vector<LogicContext *> logic();
    LogicContext* logic(size_t i);
    LogicAtomContext *logicAtom();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *BXOR();
    antlr4::tree::TerminalNode *BOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicContext* logic();
  LogicContext* logic(int precedence);
  class  LogicAtomContext : public antlr4::ParserRuleContext {
  public:
    LogicAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicConstantContext *logicConstant();
    LogicVariableContext *logicVariable();
    EnumVariableContext *enumVariable();
    NamedLogicConstContext *namedLogicConst();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicAtomContext* logicAtom();

  class  LogicConstantContext : public antlr4::ParserRuleContext {
  public:
    LogicConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERILOG_BINARY();
    antlr4::tree::TerminalNode *GCC_BINARY();
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicConstantContext* logicConstant();

  class  NamedLogicConstContext : public antlr4::ParserRuleContext {
  public:
    NamedLogicConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    NamedConstContext *namedConst();
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NamedLogicConstContext* namedLogicConst();

  class  LogicVariableContext : public antlr4::ParserRuleContext {
  public:
    LogicVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    VariableContext *variable();
    antlr4::tree::TerminalNode *SIGN();
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicVariableContext* logicVariable();

  class  EnumVariableContext : public antlr4::ParserRuleContext {
  public:
    EnumVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    VariableContext *variable();
    EnumNameContext *enumName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EnumVariableContext* enumVariable();

  class  EnumNameContext : public antlr4::ParserRuleContext {
  public:
    EnumNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EnumNameContext* enumName();

  class  NamedConstContext : public antlr4::ParserRuleContext {
  public:
    NamedConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NamedConstContext* namedConst();

  class  NumericContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *artop = nullptr;
    NumericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumericAtomContext *numericAtom();
    LogicContext *logic();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<NumericContext *> numeric();
    NumericContext* numeric(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericContext* numeric();
  NumericContext* numeric(int precedence);
  class  NumericAtomContext : public antlr4::ParserRuleContext {
  public:
    NumericAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumericConstantContext *numericConstant();
    NumericVariableContext *numericVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericAtomContext* numericAtom();

  class  NumericConstantContext : public antlr4::ParserRuleContext {
  public:
    NumericConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericConstantContext* numericConstant();

  class  NumericVariableContext : public antlr4::ParserRuleContext {
  public:
    NumericVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    VariableContext *variable();
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericVariableContext* numericVariable();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *TIMES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  RelopContext : public antlr4::ParserRuleContext {
  public:
    RelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelopContext* relop();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool sereSempred(SereContext *_localctx, size_t predicateIndex);
  bool tformulaSempred(TformulaContext *_localctx, size_t predicateIndex);
  bool booleanSempred(BooleanContext *_localctx, size_t predicateIndex);
  bool logicSempred(LogicContext *_localctx, size_t predicateIndex);
  bool numericSempred(NumericContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

