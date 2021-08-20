#include "WrongCat.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

WrongCat::WrongCat(void)
    : WrongAnimal("WrongCat") {
  std::cout << "Default constructor of '";
  std::cout << ansiRed << "WrongCat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) {
  *this = wrongCat;
  std::cout << "Copy constructor of '";
  std::cout << ansiRed << "WrongCat"<< ansiEnd << "' called. ";
}

WrongCat::~WrongCat(void) {
  std::cout << "Destructor of '";
  std::cout << ansiRed << "WrongCat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
  std::cout << "Assignation operator of '";
  std::cout << ansiRed << "WrongCat"<< ansiEnd << "' called. ";
  if (this == &other) {
    return *this;
  }
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"meow... meow...\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
