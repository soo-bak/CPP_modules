#include "Cat.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

Cat::Cat(void)
    : Animal("Cat") {
  std::cout << "Default constructor of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
  _brain = new Brain();
}

Cat::Cat(const Cat& cat) {
  std::cout << "Copy constructor of '" << ansiRed;
  std::cout << "Cat"<< ansiEnd << "' called. " << std::endl;
  setType(cat._type);
  if (cat._brain != NULL) {
    _brain = new Brain(cat.getBrain());
  } else {
    _brain = new Brain();
  }
}

Cat::~Cat(void) {
  std::cout << "Destructor of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
  delete _brain;
}

Cat& Cat::operator = (const Cat& other) {
  std::cout << "Assignation operator of '";
  std::cout << ansiRed << "Cat"<< ansiEnd << "' called. " << std::endl;
  if (this == &other) {
    return *this;
  }
  delete _brain;
  if (other._brain != NULL) {
    _brain = new Brain(other.getBrain());
  } else {
    _brain = new Brain();
  }
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"meow... meow...\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}

const Brain& Cat::getBrain(void) const {
  return *_brain;
}

void Cat::setBrain(const Brain& newBrain) {
  if (_brain != NULL) {
    delete _brain;
  }
  _brain = new Brain(newBrain);
  return ;
}
