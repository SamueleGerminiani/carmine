#include "commandLineParser.hh"
cxxopts::ParseResult parse(int argc, char *argv[]) {

  try {
    cxxopts::Options options(argv[0], "");
    options.positional_help("[optional args]").show_positional_help();

    std::string file = "";

    options.allow_unrecognised_options().add_options()(
        "f, file", ".xml configuration file",
        cxxopts::value<std::vector<std::string>>(), "FILE")(
        "o, out_directory", "output directory", cxxopts::value<std::string>(),
        "DIRECTORY")("d, directory", "directory of .xml configurations files",
                     cxxopts::value<std::string>(),
                     "FILE")("help", "Show options");

    auto result = options.parse(argc, argv);

    if (result.count("help") ||
        (result.count("f") == 0 && result.count("d") == 0)) {
      std::cout << options.help({"", "Group"}) << std::endl;
      exit(0);
    }

    return result;

  } catch (const cxxopts::OptionException &e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    exit(1);
  }
}
