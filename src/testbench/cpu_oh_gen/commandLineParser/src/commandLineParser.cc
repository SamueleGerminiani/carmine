#include "commandLineParser.hh"
cxxopts::ParseResult parse(int argc, char *argv[]) {

  try {
    cxxopts::Options options(argv[0], "");
    options.positional_help("[optional args]").show_positional_help();

    std::string file = "";

    options.allow_unrecognised_options().add_options()( "targetNode", "targetNode", cxxopts::value<std::string>())("help", "Show options");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help({"", "Group"}) << std::endl;
      exit(0);
    }

    return result;

  } catch (const cxxopts::OptionException &e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    exit(1);
  }
}
