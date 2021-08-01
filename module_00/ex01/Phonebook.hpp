#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

class Phonebook {
  public:
    Phonebook();
    ~Phonebook();
    void ExecuteCommand(const std::string& command);
    unsigned int GetContactsNumber();
    unsigned int SetContactsNumber();

  private:
    Contact _contacts[8];
    unsigned int _contactsNumber;
};
