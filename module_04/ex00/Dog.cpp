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

Dog::Dog(const Dog& dog) {
  *this = dog;
  std::cout << "Copy constructor of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
}

Dog::~Dog(void) {
  std::cout << "Destructor of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
  std::cout << "Assignation operator of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
  if (this == &other) {
    return *this;
  }
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"bow wow! bow wow!\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
