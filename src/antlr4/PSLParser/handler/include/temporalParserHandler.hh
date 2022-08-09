#pragma once

//#include "oden/classes/classes.hh"
//#include "oden/odenUtils/propositionUtils.hh"
#include "temporalBaseListener.h"

#include <cmath>
#include <stack>
#include <string>

using namespace antlr4;

using Name = std::string;
using Type = std::string;
using VarDeclaration = std::pair<Name, Type>;
namespace oden {

class TemporalParserHandler : public temporalBaseListener {

public:
  TemporalParserHandler() = default;

  ~TemporalParserHandler() override = default;

  std::unordered_map<std::string, Proposition *> getPropositions();
  std::string getSFormula();
  std::string getAntecedent();
  std::vector<std::pair<size_t, size_t>> getTimers();
  void printAllPropositions();

private:
  bool _abort;
  bool createExpression = false;

  std::stack<Proposition *> _proposition;
  std::stack<LogicExpression *> _logicExpressions;
  std::stack<NumericExpression *> _numericExpressions;
  std::stack<std::string> _subFormulas;
  std::string antecedent = "";
  size_t boolStack = 0;
  size_t logicStack = 0;
  size_t numeriStack = 0;
  size_t placeholdN = 0;
  size_t constantsN = 0;
  size_t timerN = 0;
  std::unordered_map<std::string, Proposition *> _phToProp;
  std::vector<std::pair<size_t, size_t>> _timers;

  virtual void exitTformula(temporalParser::TformulaContext *ctx) override;
  virtual void
  exitImplication(temporalParser::ImplicationContext *ctx) override;
  virtual void exitSere(temporalParser::SereContext *ctx) override;
  virtual void visitErrorNode(antlr4::tree::ErrorNode *node) override;
};

} // namespace oden
