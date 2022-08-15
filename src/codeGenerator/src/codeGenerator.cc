#include "codeGenerator.hh"
#include "monitorGenerator.hh"
#include "converter.hh"
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
  // monitor formula
  int *nPhs = new int[handler._monitors.size()];
  int i = 0;
  remove_all(path("build/output"));
  create_directories("build/output/monitors/src");
  create_directories("build/output/monitors/include");

  // Parse each monitor and generate code
  for (auto &ch : handler._monitors) {

    std::string declarations = "";

    // declarations of variables used in the formula
    for (auto v : ch._variables) {
      declarations += v._decl + ";";
    }
    //<id, timeout>
    std::vector<std::pair<size_t, size_t>> timers;

    //auto is <<implication,antecedent>, map: placeholder -> Proposition>
    auto parsedFormula =
        expression::parseLTLformula(ch._LTLformula, declarations, timers);

    // save the number of placeholders in this monitor
    nPhs[i] = parsedFormula.second.size();

    // Generate two automata: one for the antecedent and one for the whole
    // formula
    auto fsms = codeGenerator::converter::generateAutomata(
        parsedFormula.first.first, parsedFormula.first.second);

    // generate the monitor's source file
    if (generateMonitorSource(fsms, parsedFormula, ch, timers) &&
        // generate the monitor's header file
        generateMonitorHeader(fsms, ch._variables, ch._name, parsedFormula)) {
      std::cout << "Successfully generated files for monitor " << ch._name
                << std::endl;
    } else {
      std::cout << "Could not generate files for monitor " << ch._name
                << std::endl;
      exit(1);
    }

    i++;
  }

  // generate ver_env
  if (!generateCallbackHeader(handler._monitors)) {
    std::cout << "Could not generate CallbackHeader" << std::endl;
    exit(1);
  }
  if (!generateMonitorHelperHeader(handler._monitors, nPhs)) {
    std::cout << "Could not generate MonitorHelperHeader" << std::endl;
    exit(1);
  }

  if (!generateGlobalsHeader(handler._monitors)) {
    std::cout << "Could not generate GlobalsHeader" << std::endl;
    exit(1);
  }

  if (!generateGlobalsSource(handler._monitors)) {
    std::cout << "Could not generate GlobalsSource" << std::endl;
    exit(1);
  }
  delete[] nPhs;
}
} // namespace codeGenerator
