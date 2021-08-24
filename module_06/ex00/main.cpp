#include <string>
#include <exception>
#include <iostream>

#include "Conversion.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string asniCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main (int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << ansiRed;
    std::cout << "Please execute in the appropriate foramt" << std::endl;
    std::cout << ansiEnd;
    return 0;
  }
  std::string stringInput = argv[1];
  try {
  Conversion converter(stringInput);

  }
  catch (std::exception& exception) {
    std::cout << exception.what() << std::endl;
  }

  return 0;
}
