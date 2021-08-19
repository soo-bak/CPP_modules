#include "WrongAnimal.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiEnd("\033[0m");

WrongAnimal::WrongAnimal(void)
    : _type("Unknown") {
  std::cout << "Default constructor of '";
  std::cout << ansiPurple << "WrongAnimal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type)
    : _type(type) {
  std::cout << "Constructor of '";
  std::cout << ansiPurple << "WrongAnimal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) {
  *this = animal;
  std::cout << "Copy constructor of '";
  std::cout << ansiPurple << "WrongAnimal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "Destructor of '";
  std::cout << ansiPurple << "WrongAnimal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
  std::cout << "Assignation operator called." << std::endl;
  if (this == &other) {
    return *this;
  }
  setType(other._type);
  return *this;
}

std::string WrongAnimal::getType(void) const {
  return _type;
}

void WrongAnimal::setType(const std::string& type) {
  _type = type;
  return ;
}

void WrongAnimal::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"Unknown wrong animal sound...\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
