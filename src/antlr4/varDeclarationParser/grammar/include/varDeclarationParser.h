
// Generated from varDeclaration.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  varDeclarationParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, LSBRACKET = 4, RSBRACKET = 5, TYPEDEF = 6, 
    ENUM = 7, OB = 8, CB = 9, VARTYPE = 10, NUMERIC = 11, VERILOG_BINARY = 12, 
    GCC_BINARY = 13, PLUS = 14, MINUS = 15, TIMES = 16, DIV = 17, NAME = 18, 
    WS = 19
  };

  enum {
    RuleFile = 0, RuleCDeclaration = 1, RuleCStatement = 2, RuleVarDec = 3, 
    RuleAss = 4, RuleEnumDec = 5, RuleEnum_list = 6, RuleAddLogic = 7, RuleName = 8, 
    RuleLogicName = 9, RuleVartype = 10, RuleEnumType = 11, RuleLogic = 12, 
    RuleLogicAtom = 13, RuleLogicConstant = 14
  };

  varDeclarationParser(antlr4::TokenStream *input);
  ~varDeclarationParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class CDeclarationContext;
  class CStatementContext;
  class VarDecContext;
  class AssContext;
  class EnumDecContext;
  class Enum_listContext;
  class AddLogicContext;
  class NameContext;
  class LogicNameContext;
  class VartypeContext;
  class EnumTypeContext;
  class LogicContext;
  class LogicAtomContext;
  class LogicConstantContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CDeclarationContext *cDeclaration();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  CDeclarationContext : public antlr4::ParserRuleContext {
  public:
    CDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CStatementContext *cStatement();
    CDeclarationContext *cDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CDeclarationContext* cDeclaration();

  class  CStatementContext : public antlr4::ParserRuleContext {
  public:
    CStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDecContext *varDec();
    EnumDecContext *enumDec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CStatementContext* cStatement();

  class  VarDecContext : public antlr4::ParserRuleContext {
  public:
    VarDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VartypeContext *vartype();
    NameContext *name();
    AssContext *ass();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarDecContext* varDec();

  class  AssContext : public antlr4::ParserRuleContext {
  public:
    AssContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssContext* ass();

  class  EnumDecContext : public antlr4::ParserRuleContext {
  public:
    EnumDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    NameContext *name();
    antlr4::tree::TerminalNode *OB();
    Enum_listContext *enum_list();
    antlr4::tree::TerminalNode *CB();
    antlr4::tree::TerminalNode *TYPEDEF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EnumDecContext* enumDec();

  class  Enum_listContext : public antlr4::ParserRuleContext {
  public:
    Enum_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    AddLogicContext *addLogic();
    Enum_listContext *enum_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enum_listContext* enum_list();

  class  AddLogicContext : public antlr4::ParserRuleContext {
  public:
    AddLogicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicContext *logic();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddLogicContext* addLogic();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NameContext* name();

  class  LogicNameContext : public antlr4::ParserRuleContext {
  public:
    LogicNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicNameContext* logicName();

  class  VartypeContext : public antlr4::ParserRuleContext {
  public:
    VartypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARTYPE();
    EnumTypeContext *enumType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VartypeContext* vartype();

  class  EnumTypeContext : public antlr4::ParserRuleContext {
  public:
    EnumTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EnumTypeContext* enumType();

  class  LogicContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *artop = nullptr;;
    LogicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicAtomContext *logicAtom();
    antlr4::tree::TerminalNode *LSBRACKET();
    std::vector<LogicContext *> logic();
    LogicContext* logic(size_t i);
    antlr4::tree::TerminalNode *RSBRACKET();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

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
    LogicNameContext *logicName();

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


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool logicSempred(LogicContext *_localctx, size_t predicateIndex);

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

