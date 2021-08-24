#include <exception>
#include <iostream>

#include "Parser.hpp"
#include "CharConverter.hpp"

const std::string ansiRed("\033[1;31m");
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
    type->printValue();
    std::cout << std::endl;
  }
  catch (const std::exception& exception) {
    std::cout << ansiRed;
    std::cout << exception.what() << std::endl;
    std::cout << ansiEnd;
  }
  delete type;
  return 0;
}
