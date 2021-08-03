#include "Phonebook.hpp"

enum Commands {
  Add = 1 << 0,
  Search = 1 << 1,
  Exit = 1 << 2
};

Phonebook::Phonebook() {
  _contactsNumber = 0;
  _indexToAdd = 0;
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

void Phonebook::ExecuteCommand(const unsigned int& commandValue) {
  if (commandValue & Add) {
    CheckIndexToAdd();
    AddNewContact();
  } else if (commandValue & Search) {
    DisplayContactList();
  } else if (commandValue & Exit) {
    exit(0);
  } else {
    return ;
  }
}

void Phonebook::CheckIndexToAdd() {
  const int maximuContactNumber = 8;
   if (_indexToAdd > maximuContactNumber) {
     _indexToAdd = 0;
     _contactsNumber = maximuContactNumber;
   }
}

void Phonebook::AddNewContact() {
  _contacts[_indexToAdd].SetInformation();
  _contacts[_indexToAdd].SetContactIndex(_indexToAdd);
  _indexToAdd++;
  _contactsNumber++;
}

void Phonebook::DisplayContactList() {
  for (int i = 0; i < _contactsNumber; i++) {
    _contacts[i].PrintBasicInformation();
  }
}
