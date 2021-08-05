#include "Phonebook.hpp"

Contact Phonebook::_contact[8] = {};
int Phonebook::_registeredNumber = 0;
int Phonebook::_indexToAdd = 0;
int Phonebook::_selectedIndex = 0;

Phonebook::Phonebook() {
}

Phonebook::~Phonebook() {
}

void Phonebook::OpenPhonebook() {
  CheckIndex();
  std::cout << "Enter the command : ";
  std::string input;
  std::getline(std::cin, input);
  const unsigned int command = CheckCommand(input);
  ExecuteCommand(command);
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

unsigned int Phonebook::CheckCommand(const std::string& input) {
  unsigned int command = 0;
  if (input.compare("ADD") == 0) {
    command |= Add;
  } else if (input.compare("SEARCH") == 0) {
    command |= Search;
  } else if (input.compare("EXIT") == 0) {
    command |= Exit;
  }
  return command;
}

void Phonebook::ExecuteCommand(const unsigned int& command) {
  if (command & Add) {
    AddContact();
  } else if (command & Search) {
    SearchContact();
  } else if (command & Exit) {
    exit(0);
  } else {
    std::cout << "It's wrong command, try again." << std::endl;
  }
  return ;
}

void Phonebook::AddContact() {
  CheckIndex();
  _contact[_indexToAdd].SetInformation();
  _contact[_indexToAdd].SetContactIndex(_indexToAdd);
  _indexToAdd++;
  _registeredNumber++;
  return ;
}

void Phonebook::SearchContact() {
  if (_registeredNumber == 0) {
      std::cout << "No contacts are registered." << std::endl;
      return ;
  }
  CheckIndex();
  DisplayContactList();
  SelectContact();
  DisplayContactInformation();
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
  _contact[contactIndex].PrintInformation();
  return ;
}
