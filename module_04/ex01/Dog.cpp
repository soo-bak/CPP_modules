#include "Dog.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiEnd("\033[0m");

Dog::Dog(void)
    : Animal("Dog") {
  std::cout << "Default constructor of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "Destructor of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

void Dog::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"bow wow! bow wow!\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
