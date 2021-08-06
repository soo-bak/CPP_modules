#include "Phonebook.hpp"

Phonebook::Phonebook()
 : _registeredNumber(0), _indexToAdd(0), _selectedIndex(0) {
}

Phonebook::~Phonebook() {
}

void Phonebook::openPhonebook() {
  _checkPhonebookSize();
  std::cout << "Enter the command : ";
  std::string input;
  std::getline(std::cin, input).eof();
  if (std::cin.bad() || std::cin.eof())
    exit(0);
  const unsigned int command = _checkCommand(input);
  _executeCommand(command);
  return ;
}

void Phonebook::_checkPhonebookSize() {
  const int phonebookSize(8);
   if (_indexToAdd >= phonebookSize) {
     _indexToAdd = 0;
   }
   if (_registeredNumber > phonebookSize) {
     _registeredNumber = phonebookSize;
   }
   return ;
}

unsigned int Phonebook::_checkCommand(const std::string& input) {
  unsigned int command(0);
  if (input.compare("ADD") == 0) {
    command |= Add;
  } else if (input.compare("SEARCH") == 0) {
    command |= Search;
  } else if (input.compare("EXIT") == 0) {
    command |= Exit;
  } else if (input.empty()) {
    command |= Empty;
  } else {
    command |= Error;
  }
  return command;
}

void Phonebook::_executeCommand(const unsigned int& command) {
  if (command & Add) {
    _addContact();
  } else if (command & Search) {
    _searchContact();
  } else if (command & Exit) {
    exit(0);
  } else if (command & Error) {
    std::cout << "It's wrong command, try again." << std::endl;
  }
  return ;
}

void Phonebook::_addContact() {
  _checkPhonebookSize();
  _contact[_indexToAdd].setInformation();
  _contact[_indexToAdd].setContactIndex(_indexToAdd);
  _indexToAdd++;
  _registeredNumber++;
  return ;
}

void Phonebook::_searchContact() {
  if (_registeredNumber == 0) {
      std::cout << "No contacts are registered." << std::endl;
      return ;
  }
  _checkPhonebookSize();
  _displayContactList();
  _selectContact();
  _displayContactInformation();
  return ;
}

void Phonebook::_displayContactList() {
  _contact[0].printList("INDEX", _contact[0].getFieldName());
  for (int i = 0; i < _registeredNumber; i++) {
    const std::string contactIndex(_contact[i].getContactIndex());
    const std::string *information(_contact[i].getInformation());
    _contact[i].printList(contactIndex, information);
  }
  return ;
}

void Phonebook::_selectContact() {
  std::cout << "Select the index to detail information." << std::endl;
  std::string input;
  std::getline(std::cin, input);
  if (std::cin.bad() || std::cin.eof())
    exit(0);
  _selectedIndex = atoi(input.c_str());
  if (_selectedIndex > _registeredNumber || _selectedIndex < 1) {
    std::cout <<  "The index is invalid, try again." << std::endl;
    _selectContact();
  }
  return ;
}

void Phonebook::_displayContactInformation() {
  const int contactIndex(_selectedIndex - 1);
  _contact[contactIndex].printInformation();
  return ;
}
