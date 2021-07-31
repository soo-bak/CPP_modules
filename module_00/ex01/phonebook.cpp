#include "phonebook.hpp"

int main() {
  std::string input;
  while (true) {
    std::cout << "input : ";
    getline(std::cin, input);
    if (input.compare("ADD") == 0)
      std::cout << "it's ADD." << std::endl;
    else if (input.compare("SEARCH") == 0)
      std::cout << "it's SEARCH." << std::endl;
    else if (input.compare("EXIT") == 0)
      std::cout << "it's EXIT." << std::endl;
    else
      continue ;
  }
  return 0;
}
