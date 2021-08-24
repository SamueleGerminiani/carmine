#include "codeGenerator.hh"
#include "commandLineParser.hh"
#include "xmlUtils.hh"
#include <filesystem>
using namespace std::filesystem;

strHandler parseSpecifications(const std::string &pathToSpec) {
  strHandler tmpHandler;
  // Parse xml file
  rapidxml::file<> *_xmlFile;
  rapidxml::xml_document<> *_doc;

  // find root node
  try {
    _xmlFile = new rapidxml::file<>(pathToSpec.c_str());
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
  tmpHandler._name = rapidxml::getAttributeValue(root, "name", "");
  tmpHandler._migrateTo = rapidxml::getAttributeValue(root, "migrateTo", "");
  rapidxml::XmlNodeList checkers;

  // the checkers in the current machine handler
  rapidxml::getNodesFromName(root, "checker", checkers);

  for (auto &ch : checkers) {
    strChecker tmpChecker;
    // parse the checker's name
    tmpChecker._name = rapidxml::getAttributeValue(ch, "name", "");
    tmpChecker._LTLformula = rapidxml::getAttributeValue(ch, "LTLformula", "");
    rapidxml::XmlNodeList variables;
    rapidxml::getNodesFromName(ch, "variable", variables);
    for (auto &var : variables) {
      strVariable tmpVariable;
      tmpVariable._decl = rapidxml::getAttributeValue(var, "decl", "");
      rapidxml::XmlNodeList list;
      rapidxml::getNodesFromName(var, "msgType", list);
      tmpVariable._msgType = list[0]->value();
      list.clear();
      rapidxml::getNodesFromName(var, "rosTopic", list);
      tmpVariable._rosTopic = list[0]->value();
      list.clear();
      rapidxml::getNodesFromName(var, "msgField", list);
      tmpVariable._msgField = list[0]->value();
      splitNameType(tmpVariable._name, tmpVariable._type, tmpVariable._decl);
      tmpChecker._variables.push_back(tmpVariable);
    }
    tmpHandler._checkers.push_back(tmpChecker);
  }

  return tmpHandler;
}

int main(int argc, char *args[]) {

  if (argc < 2) {
    std::cout << "Missing XML specification file, call as ./carmine "
                 "<specification.xml>"
              << std::endl;
    return 0;
  }
  strHandler spec = parseSpecifications(args[1]);

  // Each item in the array is the number o placeholders generated for each
  // checker formula
  int *nPhs = new int[spec._checkers.size()];
  int i = 0;
  // Parse each checker and generate code
  for (auto &ch : spec._checkers) {

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
    if (generateCpp(fsms, ch._variables, parsedFormula, ch._name) &&
        // generate the checker's header file
        generateHeader(fsms, ch._variables, ch._name)) {
      std::cout << "Successfully generated files for checker " << ch._name
                << std::endl;
    } else {
      std::cout << "Could not generate files for checker " << ch._name
                << std::endl;
      return 1;
    }

    i++;
  }

  // generate include_checkers.hh
  if (!generateHeaderHandler(spec._checkers)) {
    std::cout << "Could not generate header file for handler node" << std::endl;
    return 1;
  }

  // generate ver_env.cpp
  if (!generateHandler(spec._checkers, nPhs, spec._name, spec._migrateTo)) {
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
