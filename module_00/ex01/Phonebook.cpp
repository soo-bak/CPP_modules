#include "Phonebook.hpp"

enum Commands {
  Add = 1 << 0,
  Search = 1 << 1,
  Exit = 1 << 2
};

Phonebook::Phonebook() {
  _registeredNumber = 0;
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
    return ;
  } else if (command & Search) {
    if (_registeredNumber == 0) {
      std::cout << "No contacts are registered." << std::endl;
      return ;
    } else {
      DisplayContactList();
      SelectContact();
      DisplayContactInformation();
    }
    return ;
  } else if (command & Exit) {
    exit(0);
  } else {
    std::cout << "It's wrong command, try again." << std::endl;
    return ;
  }
}

void Phonebook::CheckIndex() {
  const int maximumContactNumber = 8;
   if (_indexToAdd >= maximumContactNumber) {
     _indexToAdd = 0;
   }
   if (_registeredNumber > maximumContactNumber) {
     _registeredNumber = maximumContactNumber;
   }
   return ;
}

void Phonebook::AddContact() {
  _contact[_indexToAdd].SetInformation();
  _contact[_indexToAdd].SetContactIndex(_indexToAdd);
  _indexToAdd++;
  _registeredNumber++;
  return ;
}

void Phonebook::DisplayContactList() {
  _contact[0].PrintBasicInformation("INDEX", _contact[0].GetFieldName());
  for (int i = 0; i < _registeredNumber; i++) {
    const std::string contactIndex = _contact[i].GetContactIndex();
    const std::string *information = _contact[i].GetInformation();
    _contact[i].PrintBasicInformation(contactIndex, information);
  }
  return ;
}

void Phonebook::SelectContact() {
  std::cout << "Select the index to detail information." << std::endl;
  std::string input;
  std::getline(std::cin, input);
  _selectedIndex = atoi(input.c_str());
  if (_selectedIndex > _registeredNumber || _selectedIndex < 1) {
    std::cout <<  "The index is invalid, try again." << std::endl;
    SelectContact();
  }
  return ;
}

void Phonebook::DisplayContactInformation() {
  const int contactIndex = _selectedIndex - 1;
  _contact[contactIndex].PrintAllInformation();
  return ;
}
