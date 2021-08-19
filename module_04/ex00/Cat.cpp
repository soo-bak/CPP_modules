#include "Cat.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

Cat::Cat(void)
    : Animal("Cat") {
  std::cout << "Default constructor of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Cat::~Cat(void) {
  std::cout << "Destructor of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

void Cat::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"meow... meow...\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
