#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Contact.hpp"

class Phonebook {

  enum Commands {
  Add = 1 << 0,
  Search = 1 << 1,
  Exit = 1 << 2
  };

  public:
    Phonebook();
    ~Phonebook();
    unsigned int CheckCommand(const std::string& input);
    void ExecuteCommand(const unsigned int& command);
    void CheckIndex();
    void AddContact();
    void DisplayContactList();
    void SelectContact();
    void DisplayContactInformation();

  private:
    Contact _contact[8];
    int _registeredNumber;
    int _indexToAdd;
    int _selectedIndex;
};
