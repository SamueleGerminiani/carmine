#include "codeGenerator.hh"
#include "commandLineParser.hh"
#include "xmlUtils.hh"
#include <filesystem>
using namespace std::filesystem;
int main(int argc, char *args[]) {

  if (argc < 2) {
    std::cout << "Missing XML specification file, call as ./carmine "
                 "<specification.xml>"
              << std::endl;
    return 0;
  }

  // Parse xml file
  rapidxml::file<> *_xmlFile;
  rapidxml::xml_document<> *_doc;

  // find root node
  try {
    _xmlFile = new rapidxml::file<>(args[1]);
    _doc = new rapidxml::xml_document<>();
    _doc->parse<0>(_xmlFile->data());
  } catch (rapidxml::parse_error &e) {
    std::stringstream ss;
    ss << "Parsing error in " << /*configFile <<*/ " "
       << "\n"
       << e.m_what << " at line " << e.m_lineNumber << std::endl;
    if (!reinterpret_cast<char *>(e.m_where)[0]) {
      ss << "Hint: you probably forgot to close a tag\n";
    }
  }

  // the current machine handler
  auto root = _doc->first_node("handler");
  std::string handlerName = "";
  std::string migrateTo = "";
  handlerName = rapidxml::getAttributeValue(root, "name", "");
  migrateTo = rapidxml::getAttributeValue(root, "migrateTo", "");
  rapidxml::XmlNodeList checkers;

  // the checkers in the current machine handler
  rapidxml::getNodesFromName(root, "checker", checkers);

  // Each item in the array is the number o placeholders generated for each
  // checker formula
  int *nPhs = new int[checkers.size()];
  int i = 0;
  // Parse each checker and generate code
  for (auto &ch : checkers) {
    std::vector<checkerVar> varList;

    std::string formula = rapidxml::getAttributeValue(ch, "LTLformula", "");
    rapidxml::XmlNodeList variables;
    rapidxml::getNodesFromName(ch, "variable", variables);
    std::string declarations = "";

    // declarations of variables used in the formula
    for (auto v : variables) {
      declarations += rapidxml::getAttributeValue(v, "decl", "") + ";";
    }
    //clear the timers used in the previous checkers (global var)
    timer::timers.clear();

    //<<implication,antecedent>, map: placeholder -> Proposition>
    auto parsedFormula =
        oden::parseLTLformula(formula, declarations, "", "", timer::timers);

    // save the number of placeholders in this checker
    nPhs[i] = parsedFormula.second.size();

    //store in varList the variables found in 'variables'
    parseVariables(varList, variables);

    //Generate two automata: one for the antecedent and one for the whole
    //formula
    auto fsms = codeGenerator::converter::generateAutomata(
        parsedFormula.first.first, parsedFormula.first.second);
   
    //parse the checker's name
    std::string checkerName = rapidxml::getAttributeValue(ch, "name", "");

    //generate the checker's source file
    if (generateCpp(fsms, varList, parsedFormula, checkerName) &&
    //generate the checker's header file
        generateHeader(fsms, varList, checkerName)) {
      std::cout << "Successfully generated files for checker " << checkerName
                << std::endl;
    } else {
      std::cout << "Could not generate files for checker " << checkerName
                << std::endl;
      return 1;
    }

    i++;
  }

  //generate include_checkers.hh
  if (!generateHeaderHandler(checkers)) {
    std::cout << "Could not generate header file for handler node" << std::endl;
    return 1;
  }

  //generate ver_env.cpp
  if (!generateHandler(checkers, nPhs, handlerName, migrateTo)) {
    delete[] nPhs;
    std::cout << "Could not generate handler node" << std::endl;
    return 1;
  }

  delete[] nPhs;
  return 0;
}

void parseCommandLineArguments(int argc, char *args[],
                               std::vector<std::string> &files,
                               std::string &outDirectory) {

  auto result = parse(argc, args);

  if (result.count("f")) {
    files = result["f"].as<std::vector<std::string>>();
  }
  if (result.count("o")) {
    outDirectory = result["o"].as<std::string>();
  }
  if (result.count("d")) {
    std::cout << "Adding files from directory: "
              << result["d"].as<std::string>() << "\n";
    for (const auto &entry :
         directory_iterator(result["d"].as<std::string>())) {
      if (entry.path().extension() == ".xml") {
        files.push_back(entry.path().u8string());
      }
    }
  }
  messageErrorIf(files.empty(), "No files found!");
}
