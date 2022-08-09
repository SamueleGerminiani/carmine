#include "parserUtils.hh"
#include "parsers.hh"
#include <string>
std::unordered_map<std::string, std::string> foundVariablesDefault;
namespace oden {
bool exists(const std::string &varName) {
  return foundVariablesDefault.count(varName);
}

std::pair<std::pair<std::string, std::string>,
          std::unordered_map<std::string, Proposition *>>
parseLTLformula(std::string &formula, const std::string &decls,
                std::vector<std::pair<size_t, size_t>> &timers) {
  // DEBUG
  //    listener1.print();

  // parse var declarations
  oden::varDeclarationParserHandler listenerLocDec;
  antlr4::ANTLRInputStream inputLocDec(decls);
  varDeclarationLexer lexerLocDec(&inputLocDec);
  CommonTokenStream tokensLocDec(&lexerLocDec);
  varDeclarationParser parserPrecLocDec(&tokensLocDec);
  tree::ParseTree *treeLocDec = parserPrecLocDec.file();
  tree::ParseTreeWalker::DEFAULT.walk(&listenerLocDec, treeLocDec);

  std::vector<VarDeclaration> varDecls = listenerLocDec.getVarDeclarations();
  addTypeToProposition(formula, varDecls);

  // parse typed formula
  oden::TemporalParserHandler listener2;
  antlr4::ANTLRInputStream input2(formula);
  temporalLexer lexer2(&input2);
  CommonTokenStream tokens2(&lexer2);
  temporalParser parser2(&tokens2);
  tree::ParseTree *treeFragAnt = parser2.formula();
  std::cout << treeFragAnt->toStringTree(&parser2) << "\n\n\n";
  tree::ParseTreeWalker::DEFAULT.walk(&listener2, treeFragAnt);
  /*
  DEBUG
  exit(0);
  */

  timers = listener2.getTimers();
  std::cout << listener2.getSFormula() << "\n";
  return std::make_pair(
      std::make_pair(listener2.getSFormula(), listener2.getAntecedent()),
      listener2.getPropositions());
}
Proposition *parsePropositionAlreadyTyped(const std::string &formula) {
  // parse typed propositions
  oden::ParserHandler listener2;
  antlr4::ANTLRInputStream input2(formula);
  propositionLexer lexer2(&input2);
  CommonTokenStream tokens2(&lexer2);
  propositionParser parser2(&tokens2);
  tree::ParseTree *treeFragAnt = parser2.file();
  tree::ParseTreeWalker::DEFAULT.walk(&listener2, treeFragAnt);
  /*
  DEBUG
  std::cout << treeFragAnt->toStringTree(&parser2) << "\n\n\n";
  exit(0);
  */
  return listener2.getProposition();
}
Proposition *parseProposition(std::string &formula, const std::string &decls) {

  // parse local var declarations
  oden::varDeclarationParserHandler listenerLocDec;
  antlr4::ANTLRInputStream inputLocDec(decls);
  varDeclarationLexer lexerLocDec(&inputLocDec);
  CommonTokenStream tokensLocDec(&lexerLocDec);
  varDeclarationParser parserPrecLocDec(&tokensLocDec);
  tree::ParseTree *treeLocDec = parserPrecLocDec.file();
  tree::ParseTreeWalker::DEFAULT.walk(&listenerLocDec, treeLocDec);

  // DEBUG
  //    listener1.print();
  std::vector<VarDeclaration> varDecls = listenerLocDec.getVarDeclarations();

  addTypeToProposition(formula, varDecls);

  // parse typed propositions
  oden::ParserHandler listener2;
  antlr4::ANTLRInputStream input2(formula);
  propositionLexer lexer2(&input2);
  CommonTokenStream tokens2(&lexer2);
  propositionParser parser2(&tokens2);
  tree::ParseTree *treeFragAnt = parser2.file();
  tree::ParseTreeWalker::DEFAULT.walk(&listener2, treeFragAnt);
  /*
  DEBUG
  std::cout << treeFragAnt->toStringTree(&parser2) << "\n\n\n";
  exit(0);
  */
  return listener2.getProposition();
}
void addTypeToProposition(std::string &formula,
                          const std::vector<VarDeclaration> &varDeclaration) {
  /*all this code is to solve the problem of
  adding types to the variables in the formula:
  The complexity of the code is to handle the following problems:*/
  //(1) A variable can be used mutiple times non sequentially(need to parse
  // the string n times) (2) A variable can contain the words bool, logic,
  // numeric (3) A variable name can be contained in an other variable, ex.
  // state, next_state

  std::vector<std::pair<std::string, VarType>> names;
  std::unordered_map<std::string, size_t> nameToSize;

  // add variables as names
  for (auto varDecl : varDeclaration) {
    std::pair<VarType, uint8_t> t = string2VarTypes(varDecl.second);
    names.push_back(std::make_pair(varDecl.first, t.first));
    nameToSize[varDecl.first] = t.second;
  }

  /*now that with have all the variables, we can insert the types in the
  formula*/

  // match the longest variables first to solve (3)
  std::sort(begin(names), end(names),
            [](std::pair<std::string, VarType> &e1,
               std::pair<std::string, VarType> &e2) {
              return e1.first.size() > e2.first.size();
            });

  /* keep track of substitutions to solve (2) and (3)
   The false values correspond to characters of formula that can be
   substituted, the true values correspond to characters of formula that
   can not be substituted*/

  std::deque<bool> changes(formula.size());

  // Substitute each variable in the formula (if present)
  for (auto name : names) {
    std::string nameType = "";
    switch (name.second) {
    case VarType::Bool:
      nameType = "<" + name.first + ",bool>";
      break;
    case VarType::ULogic:
      nameType = "<" + name.first + ",logic(u," +
                 std::to_string(nameToSize.at(name.first)) + ")>";
      break;
    case VarType::SLogic:
      nameType = "<" + name.first + ",logic(s," +
                 std::to_string(nameToSize.at(name.first)) + ")>";
      break;
    case VarType::Numeric:
      nameType = "<" + name.first + ",numeric(" +
                 std::to_string(nameToSize.at(name.first)) + ")>";
      break;
    default:
      messageError("Variable is of \'Uknown type\'");
      break;
    }

    // restart from the beginning of the current formula
    auto it = begin(formula);
    std::string toFind = name.first;

    //    std::cout<<"matching:"<<toFind<<"\n";
    // add type to the variable (if present)
    while (1) {
      // search for the current var in the formula
      it = std::search(it, end(formula), begin(toFind), end(toFind));
      if (it == end(formula)) {
        // not found... terminating the substitution for this
        // variable
        //            std::cout<<"No\n";
        break;
      }

      /*check if you are trying to substitute a substring of an
      already substituted variable*/
      if (*(begin(changes) + (it - begin(formula)))) {
        /*increment the index iterator until the end of the
        forbidden area or until the end of the string*/
        while (*(begin(changes) + (it - begin(formula)))) {
          it++;
          if (it == end(formula)) {
            break;
          }
        }
        continue;
      }

      // substitute the typeless variable with <varName,type>

      // remove the plain variable
      formula.erase(it, it + toFind.size());

      /* keep track of substitutions: tranform the changes vector to
       mirror the state of formula*/
      std::transform(begin(changes) + (it - begin(formula)),
                     begin(changes) + (it - begin(formula)) + toFind.size(),
                     begin(changes) + (it - begin(formula)),
                     [](__attribute__((unused)) bool e) { return true; });

      /*calculate how much to extend the changes vector (must be of
      the same size of formula*/

      if (nameType.size() > toFind.size()) {
        size_t toAdd = nameType.size() - toFind.size();
        // extend changes to match the new size of formula
        changes.insert(begin(changes) + (it - begin(formula)), toAdd, true);
      } else {
        // restrict changes to match the new size of formula
        size_t toRemove = toFind.size() - nameType.size();
        changes.erase(begin(changes) + (it - begin(formula)),
                      begin(changes) + (it - begin(formula) + toRemove));
      }

      // insert the variable with its type
      size_t dist = std::distance(begin(formula), it);
      formula.insert(it, begin(nameType), end(nameType));
      it = begin(formula) + dist + nameType.size();
      /*'it' is an iterator to the character of formula after the last
      substitution*/
    } // end while(1) --> end of formula

    assert(changes.size() == formula.size());
  } // end var
    //    std::cout << "After: " << formula << "\n";
}

std::pair<VarType, uint8_t> string2VarTypes(std::string type) {
  if (type == "bool") {
    return std::make_pair(VarType::Bool, 8);
  } else if (type == "unsigned char") {
    return std::make_pair(VarType::ULogic, 8);
  } else if (type == "unsigned short") {
    return std::make_pair(VarType::ULogic, 16);
  } else if (type == "unsigned int") {
    return std::make_pair(VarType::ULogic, 32);
  } else if (type == "unsigned long long") {
    return std::make_pair(VarType::ULogic, 64);
  } else if (type == "char") {
    return std::make_pair(VarType::SLogic, 8);
  } else if (type == "short") {
    return std::make_pair(VarType::SLogic, 16);
  } else if (type == "int") {
    return std::make_pair(VarType::SLogic, 32);
  } else if (type == "long long") {
    return std::make_pair(VarType::SLogic, 64);
  } else if (type == "float") {
    return std::make_pair(VarType::Numeric, 32);
  } else if (type == "double") {
    return std::make_pair(VarType::Numeric, 64);
  } else {
    messageError("Uknown variable type '" + type + "'");
  }

  return std::make_pair(VarType::Bool, 0);
}
} // namespace oden
