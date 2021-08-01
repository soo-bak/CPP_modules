#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

class Phonebook {
  public:
    Phonebook();
    ~Phonebook();
    void GetCommand(const std::string& command);
    int GetResultValue(void);

  private:
    Contact _contacts[8];
    int _resultValue;
};
