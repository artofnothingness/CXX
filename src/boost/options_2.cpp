#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char *argv[]) {
  opt::options_description desc("All options");

  int oranges_var = 0;
  desc.add_options()("oranges,o", opt::value<int>(&oranges_var)->required(), "oranges that you have")
                    ("name", opt::value<std::string>(), "your name")
                    ("help", "produce help message")
                    ("apples,a", opt::value<int>()->default_value(10), "apples that you have");

  opt::variables_map vm;

  opt::store(opt::parse_command_line(argc, argv, desc), vm);

  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
  }
  try {
    opt::store(opt::parse_config_file<char>("apples_oranges.cfg", desc), vm);
  } catch (const opt::reading_file &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  try {
    opt::notify(vm);
  } catch (const opt::required_option &e) {
    std::cout << "Error: " << e.what() << std::endl;
    return 2;
  }

  if (vm.count("name")) {
    std::cout << "Hi," << vm["name"].as<std::string>() << "!\n";
  }
  std::cout << "Fruits count: " << vm["apples"].as<int>() + vm["oranges"].as<int>() << std::endl;
}
