#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string.h>
#include <vector>

#include <iomanip>

// for convenience
using json = nlohmann::json;

int main() {

  json j = {{"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {{"everything", 42}}},
            {"list", {1, 0, 2}},
            {"object", {{"currency", "USD"}, {"value", 42.99}}}};

  // write prettified JSON to another file
  std::ofstream of("pretty.json");
  of << std::setw(4) << j << std::endl;

  std::ifstream i("pretty.json");
  json j_2;
  i >> j_2;

  int val = j["list"][0].get<int>();
  std::cout << val;
}
