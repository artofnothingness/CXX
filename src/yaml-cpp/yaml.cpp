#include <yaml-cpp/yaml.h>
#include <iostream>
#include <cassert>


int main() {
  YAML::Node primes = YAML::Load("[2, 3, 5, 7, 11]");

  for (std::size_t i = 0; i < primes.size(); i++) {
    std::cout << primes[i].as<int>() << "\n";
  }

  for (YAML::const_iterator it = primes.begin(); it != primes.end(); ++it) {
    std::cout << it->as<int>() << "\n";
  }

  primes.push_back(13);
  assert(primes.size() == 6);

  YAML::Node lineup = YAML::Load("{1B: Prince Fielder, 2B: Rickie Weeks, LF: Ryan Braun}");
  for(YAML::const_iterator it=lineup.begin();it!=lineup.end();++it) {
    std::cout << "Playing at " << it->first.as<std::string>() << " is " << it->second.as<std::string>() << "\n";
  }

  lineup["RF"] = "Corey Hart";
  lineup["C"] = "Jonathan Lucroy";
  assert(lineup.size() == 5);

  YAML::Emitter out;
  out << "Hello, World!";
   
  std::cout << "Here's the output YAML:\n" << out.c_str(); // prints "Hello, World!"
}
