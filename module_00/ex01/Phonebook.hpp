#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Contact.hpp"

class Phonebook {
  public:
    Phonebook();
    ~Phonebook();
    void openPhonebook();

  private:
    enum Commands {
      Add = 1 << 0,
      Search = 1 << 1,
      Exit = 1 << 2,
      Empty = 1 << 3,
      Error = 1 << 4
    };
    static unsigned int _checkCommand(const std::string& input);
    void _executeCommand(const unsigned int& command);
    void _checkPhonebookSize();
    void _addContact();
    void _searchContact();
    void _displayContactList();
    void _selectContact();
    void _displayContactInformation();
    Contact _contact[8];
    int _registeredNumber;
    int _indexToAdd;
    int _selectedIndex;
};
