#include "codeGenerator.hh"
#include "checkerGenerator.hh"
#include "converter.hh"
#include "globals.hh"
#include "parserUtils.hh"
#include "specificationParser.hh"
#include "types.hh"
#include "ver_EnvGenerator.hh"
#include <filesystem>
#include <fstream>
using namespace std::filesystem;
namespace codeGenerator {
void generateVerEnv(const std::string &pathToSpec) {

  strHandler handler = parseSpecifications(pathToSpec);

  // Each item in the array is the number o placeholders generated for each
  // checker formula
  int *nPhs = new int[handler._checkers.size()];
  int i = 0;
  remove_all(path("build/output"));
  create_directories("build/output/checkers/src");
  create_directories("build/output/checkers/include");

  // Parse each checker and generate code
  for (auto &ch : handler._checkers) {

    std::string declarations = "";

    // declarations of variables used in the formula
    for (auto v : ch._variables) {
      declarations += v._decl + ";";
    }
    // clear the timers used in the previous checkers (global var)
    timer::timers.clear();

    //auto is <<implication,antecedent>, map: placeholder -> Proposition>
    auto parsedFormula =
        oden::parseLTLformula(ch._LTLformula, declarations, timer::timers);

    // save the number of placeholders in this checker
    nPhs[i] = parsedFormula.second.size();

    // Generate two automata: one for the antecedent and one for the whole
    // formula
    auto fsms = codeGenerator::converter::generateAutomata(
        parsedFormula.first.first, parsedFormula.first.second);

    // generate the checker's source file
    if (generateCheckerSource(fsms, parsedFormula, ch) &&
        // generate the checker's header file
        generateCheckerHeader(fsms, ch._variables, ch._name, parsedFormula)) {
      std::cout << "Successfully generated files for checker " << ch._name
                << std::endl;
    } else {
      std::cout << "Could not generate files for checker " << ch._name
                << std::endl;
      exit(1);
    }

    i++;
  }

  // generate ver_env
  if (!generateCallbackHeader(handler._checkers)) {
    std::cout << "Could not generate CallbackHeader" << std::endl;
    exit(1);
  }
  if (!generateCheckerHelperHeader(handler._checkers, nPhs)) {
    std::cout << "Could not generate CheckerHelperHeader" << std::endl;
    exit(1);
  }

  if (!generateGlobalsHeader(handler._checkers)) {
    std::cout << "Could not generate GlobalsHeader" << std::endl;
    exit(1);
  }

  if (!generateGlobalsSource(handler._checkers)) {
    std::cout << "Could not generate GlobalsSource" << std::endl;
    exit(1);
  }
  delete[] nPhs;
}
} // namespace codeGenerator
