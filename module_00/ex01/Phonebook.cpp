#include "Phonebook.hpp"

Phonebook::Phonebook() {
}

Phonebook::~Phonebook() {
}

void Phonebook::ExecuteCommand(const std::string& command)
{
  if (command.compare("ADD") == 0) {
    std::cout << "it's ADD." << std::endl;
  } else if (command.compare("SEARCH") == 0) {
    std::cout << "it's SEARCH" << std::endl;
  } else if (command.compare("EXIT") == 0) {
    exit(0);
  }
}
