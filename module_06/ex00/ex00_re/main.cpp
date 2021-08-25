#include <exception>
#include <iostream>

#include "Parser.hpp"
#include "CharConverter.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << ansiRed;
    std::cout << "Please execute in the appropriate foramt" << std::endl;
    std::cout << ansiEnd;
    return -1;
  }
  std::string input(argv[1]);
  ATypeConverter* type;
  try {
    type = Parser::acquireType(input);
  }
  catch (const std::exception& exception) {
    std::cout << ansiRed;
    std::cout << exception.what() << std::endl;
    std::cout << ansiEnd;
    return -1;
  }
  std::cout << "[ " << ansiCyan << "Acquired type " << ansiEnd;
  std::cout << ansiYellow << type->getTypeName();
  std::cout << ansiEnd << " ]" << std::endl;
  type->printValue();
  std::cout << std::endl;
  std::cout << "[ " << ansiCyan << "Converted other types";
  std::cout << ansiEnd << " ]" << std::endl;
  type->convert();
  delete type;
  return 0;
}
