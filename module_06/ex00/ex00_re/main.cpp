#include <exception>
#include <iostream>

#include "Convertor.hpp"
#include "Char.hpp"

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
  AType* type;
  try {
    type = Convertor::acquireType(input);
    type->printValue();
  }
  catch (const std::exception& exception) {
    std::cout << ansiRed;
    std::cout << exception.what() << std::endl;
    std::cout << ansiEnd;
  }
  return 0;
}
