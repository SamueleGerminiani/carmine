#include "codeGenerator.hh"
#include "commandLineParser.hh"
#include "odenCore.hh"
#include "parserUtils.hh"
#include <cmath>
#include <experimental/filesystem>
#include <numeric>

static void parseCommandLineArguments(int argc, char *args[],
                                      std::vector<std::string> &files,
                                      std::string &outDirectory);

int main(int argc, char *args[]) {

	if(argc < 3){
		std::cout<<"Missing parameters, call as ./carmine <formula> <checker name>"<<std::endl;
		return 0;
	}

  // set default output directory
  std::string outDirectory = ".";
  std::vector<std::string> files;

  // parseCommandLineArguments(argc, args, files, outDirectory);

  // Proposition test
  //  std::string formula="G(a U b)";
  std::string formula = args[1];
  std::string checkerName = args[2];
  std::string declarations = "int currPos; bool start; int tcur;";
  //  oden::Proposition *p=oden::parseProposition(formula,declarations);
  //  std::cout << oden::prop2String(*p) << "\n";
  auto res = oden::parseLTLformula(formula, declarations);
  for (auto p : res.second) {
    std::cout << p.first << ":" << oden::prop2String(*p.second) << "\n";
  }
  std::cout << res.first << "\n";

  for (auto p : res.second) {
	  delete p.second;
  }
  auto automata = codeGenerator::converter::generateAutomata(res.first);

  std::ofstream outfile;
  outfile.open ("../output/"+checkerName+".cpp");
  outfile<<"//Checker for "<<args[1]<<std::endl;
  codeGenerator::converter::generateChecker(automata,checkerName, outfile);
  outfile.close();

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
    for (const auto &entry : std::experimental::filesystem::directory_iterator(
             result["d"].as<std::string>())) {
      if (entry.path().extension() == ".xml") {
        files.push_back(entry.path().u8string());
      }
    }
  }
  messageErrorIf(files.empty(), "No files found!");
}
