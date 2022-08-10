//#include "commandLineParser.hh"
#include "codeGenerator.hh"
#include "globals.hh"
#include "message.hh"
#include <iostream>

int main(int argc, char *args[]) {
  messageErrorIf(argc < 2, "Missing XML specification file, call as ./carmine "
                           "<specification.xml>");
  codeGenerator::generateVerEnv(args[1]);
  return 0;
}

// Unused for now
// void parseCommandLineArguments(int argc, char *args[],
//                               std::vector<std::string> &files,
//                               std::string &outDirectory) {
//
//  auto result = parse(argc, args);
//
//  if (result.count("f")) {
//    files = result["f"].as<std::vector<std::string>>();
//  }
//  if (result.count("o")) {
//    outDirectory = result["o"].as<std::string>();
//  }
//  if (result.count("d")) {
//    std::cout << "Adding files from directory: "
//              << result["d"].as<std::string>() << "\n";
//    for (const auto &entry :
//         directory_iterator(result["d"].as<std::string>())) {
//      if (entry.path().extension() == ".xml") {
//        files.push_back(entry.path().u8string());
//      }
//    }
//  }
//  messageErrorIf(files.empty(), "No files found!");
//}
