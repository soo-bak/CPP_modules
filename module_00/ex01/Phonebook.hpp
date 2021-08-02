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
    void ExecuteCommand(const unsigned int& command);
    unsigned int GetContactsNumber();
    unsigned int SetContactsNumber();

  private:
    Contact _contacts[8];
    unsigned int _contactsNumber;
};
