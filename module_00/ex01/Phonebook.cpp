#include "Phonebook.hpp"

Phonebook::Phonebook() {
}

Phonebook::~Phonebook() {
}

void Phonebook::GetCommand(const std::string& command)
{
  if (command.compare("ADD") == 0) {
    std::cout << "it's ADD." << std::endl;
    this->_resultValue = 1;
  } else if (command.compare("SEARCH") == 0) {
    std::cout << "it's SEARCH" << std::endl;
    this->_resultValue = 1;
  } else if (command.compare("EXIT") == 0) {
    exit(0);
  } else {
    this->_resultValue = 0;
  }
}


int Phonebook::GetResultValue() {
  return _resultValue;
}
