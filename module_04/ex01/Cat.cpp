#include "Cat.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

Cat::Cat(void)
    : Animal("Cat") {
  std::cout << "Default constructor of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Cat::Cat(const Cat& cat) {
  *this = cat;
  std::cout << "Copy constructor of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
}

Cat::~Cat(void) {
  std::cout << "Destructor of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
  std::cout << "Assignation operator of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
  if (this == &other) {
    return *this;
  }
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"meow... meow...\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
