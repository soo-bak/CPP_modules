#include "Phonebook.hpp"

enum Commands {
  Add = 1 << 0,
  Search = 1 << 1,
  Exit = 1 << 2
};

Phonebook::Phonebook() {
}

Phonebook::~Phonebook() {
}

unsigned int Phonebook::GetCommandValue(const std::string& input) {
  unsigned int returnValue = 0;
  if (input.compare("ADD") == 0) {
    returnValue |= Add;
  } else if (input.compare("SEARCH") == 0) {
    returnValue |= Search;
  } else if (input.compare("EXIT") == 0) {
    returnValue |= Exit;
  }
  return returnValue;
}

void Phonebook::ExecuteCommand(const unsigned int& commandValue)
{
  if (commandValue & Add) {
    std::cout << "It's ADD." << std::endl;
  } else if (commandValue & Search) {
    std::cout << "It's SEARCH." << std::endl;
  } else if (commandValue & Exit) {
    exit(0);
  }
}
