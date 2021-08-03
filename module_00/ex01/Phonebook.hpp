#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

class Phonebook {
  public:
    Phonebook();
    ~Phonebook();
    unsigned int CheckCommand(const std::string& input);
    void ExecuteCommand(const unsigned int& command);
    void DisplayContactList();
    void DisplayContactInformation();
    void AddContact();
    void CheckIndex();
    void SelectContact();

  private:
    Contact _contact[8];
    int _registeredNumber;
    int _indexToAdd;
    int _selectedIndex;
};
