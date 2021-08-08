#include <iostream>
#include <string>

#include "Replacer.hpp"

int main (int argc, char* argv[]) {
  if (argc != 4) {
    const std::string colorRed("\033[1;31m");
    const std::string colorEnd("\033[0m");
    std::cout << colorRed;
    std::cout << "<Error> Please check the arguments." << std::endl;
    std::cout << colorEnd;
    return -1;
  }
  Replacer replacer(argv[1], argv[2], argv[3]);
  replacer.makeReplacedFile();
  return 0;
}
