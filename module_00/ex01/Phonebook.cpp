#include "Phonebook.hpp"

enum Commands {
  Add = 1 << 0,
  Search = 1 << 1,
  Exit = 1 << 2
};

Phonebook::Phonebook() {
  _contactsNumber = 0;
  _indexToAdd = 0;
  _selectedIndex = 0;
}

Phonebook::~Phonebook() {
}

unsigned int Phonebook::CheckCommand(const std::string& input) {
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

void Phonebook::ExecuteCommand(const unsigned int& command) {
  CheckIndex();
  if (command & Add) {
    AddContact();
  } else if (command & Search) {
    DisplayContactsList();
    SelectContact();
    DisplayContactInformation();
  } else if (command & Exit) {
    exit(0);
  } else {
    std::cout << "It's wrong command, try again." << std::endl;
  }
}

void Phonebook::CheckIndex() {
  const int maximumContactNumber = 8;
   if (_indexToAdd >= maximumContactNumber) {
     _indexToAdd = 0;
   }
   if (_contactsNumber > maximumContactNumber) {
     _contactsNumber = maximumContactNumber;
   }
}

void Phonebook::AddContact() {
  _contacts[_indexToAdd].SetInformation();
  _contacts[_indexToAdd].SetContactIndex(_indexToAdd);
  _indexToAdd++;
  _contactsNumber++;
}

void Phonebook::DisplayContactsList() {
  for (int i = 0; i < _contactsNumber; i++) {
    _contacts[i].PrintBasicInformation();
  }
}

void Phonebook::SelectContact() {
  std::cout << "Select the index to detail information." << std::endl;
  std::string input;
  std::getline(std::cin, input);
  _selectedIndex = atoi(input.c_str());
  if (_selectedIndex > _contactsNumber || _selectedIndex < 1) {
    std::cout <<  "The index is invalid, try agin." << std::endl;
    SelectContact();
  }
}

void Phonebook::DisplayContactInformation() {
  const int contactIndex = _selectedIndex - 1;
  _contacts[contactIndex].PrintAllInformation();
}
