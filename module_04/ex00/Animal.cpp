#include "Animal.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

Animal::Animal(void)
    : _type("Unknown") {
  std::cout << "Default constructor of '";
  std::cout << ansiRed << "Animal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Animal::Animal(const std::string& type)
    : _type(type) {
 std::cout << "Constructor of '";
  std::cout << ansiRed << "Animal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Animal::Animal(const Animal& animal) {
  *this = animal;
  std::cout << "Copy constructor of '";
  std::cout << ansiRed << "Animal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Animal::~Animal(void) {
  std::cout << "Destructor of '";
  std::cout << ansiRed << "Animal"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
  std::cout << "Assignation operator called." << std::endl;
  if (this == &other) {
    return *this;
  }
  setType(other._type);
  return *this;

}
std::string Animal::getType(void) const {
  return _type;
}

void Animal::setType(const std::string& type) {
  _type = type;
  return ;
}

void Animal::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"Unknown animal sound...\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
