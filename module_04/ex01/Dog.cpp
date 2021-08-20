#include "Dog.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiEnd("\033[0m");

Dog::Dog(void)
    : Animal("Dog") {
  std::cout << "Default constructor of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
  _brain = new Brain();
}

Dog::Dog(const Dog& dog) {
  std::cout << "Copy constructor of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
  if (dog._brain != NULL) {
    _brain = new Brain(dog.getBrain());
  } else {
    _brain = new Brain();
  }
}

Dog::~Dog(void) {
  std::cout << "Destructor of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. ";
  std::cout << "[type : " << getType() << "]" << std::endl;
  delete _brain;
}

Dog& Dog::operator = (const Dog& other) {
  std::cout << "Assignation operator of '";
  std::cout << ansiBlue << "Dog"<< ansiEnd << "' called. " << std::endl;
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

void Dog::makeSound(void) const {
  std::cout << ansiItalic;
  std::cout << "\"bow wow! bow wow!\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}

const Brain& Dog::getBrain(void) const {
  return *_brain;
}

void Dog::setBrain(const Brain& newBrain) {
  if (_brain != NULL) {
    delete _brain;
  }
  _brain = new Brain(newBrain);
  return ;
}
