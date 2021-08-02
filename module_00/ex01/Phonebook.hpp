#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

class Phonebook {
  public:
    Phonebook();
    ~Phonebook();
    unsigned int GetCommandValue(const std::string& input);
    void ExecuteCommand(const unsigned int& commandValue);
    void DisplayContactList();
    void AddNewContact();
    void CheckIndexToAdd();
    int GetContactsNumber();

  private:
    Contact _contacts[8];
    int _contactsNumber;
    int _indexToAdd;
};
