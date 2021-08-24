#include "codeGenerator.hh"
#include "checkerGenerator.hh"
#include "converter.hh"
#include "handlerGenerator.hh"
#include "parserUtils.hh"
#include "specificationParser.hh"
#include "types.hh"
namespace timer {
extern std::vector<std::pair<size_t, size_t>> timers;
}
namespace codeGenerator {
void generateVerEnv(const std::string &pathToSpec) {

  strHandler handler = parseSpecifications(pathToSpec);

  // Each item in the array is the number o placeholders generated for each
  // checker formula
  int *nPhs = new int[handler._checkers.size()];
  int i = 0;
  // Parse each checker and generate code
  for (auto &ch : handler._checkers) {

    std::string declarations = "";

    // declarations of variables used in the formula
    for (auto v : ch._variables) {
      declarations += v._decl + ";";
    }
    // clear the timers used in the previous checkers (global var)
    timer::timers.clear();

    //<<implication,antecedent>, map: placeholder -> Proposition>
    auto parsedFormula = oden::parseLTLformula(ch._LTLformula, declarations, "",
                                               "", timer::timers);

    // save the number of placeholders in this checker
    nPhs[i] = parsedFormula.second.size();

    // Generate two automata: one for the antecedent and one for the whole
    // formula
    auto fsms = codeGenerator::converter::generateAutomata(
        parsedFormula.first.first, parsedFormula.first.second);

    // generate the checker's source file
    if (generateCheckerSource(fsms, ch._variables, parsedFormula, ch._name) &&
        // generate the checker's header file
        generateCheckerHeader(fsms, ch._variables, ch._name)) {
      std::cout << "Successfully generated files for checker " << ch._name
                << std::endl;
    } else {
      std::cout << "Could not generate files for checker " << ch._name
                << std::endl;
      exit(1);
    }

    i++;
  }

  // generate include_checkers.hh
  if (!generateHandlerHeader(handler._checkers)) {
    std::cout << "Could not generate header file for handler node" << std::endl;
    exit(1);
  }

  // generate ver_env.cpp
  if (!generateHandlerSource(handler._checkers, nPhs, handler._name,
                             handler._migrateTo)) {
    delete[] nPhs;
    std::cout << "Could not generate handler node" << std::endl;
    exit(1);
  }

  delete[] nPhs;
}
}
