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
    void DisplayContactsList();
    void DisplayContactInformation();
    void AddContact();
    void CheckIndex();
    void SelectContact();

  private:
    Contact _contacts[8];
    int _contactsNumber;
    int _indexToAdd;
    int _selectedIndex;
};
