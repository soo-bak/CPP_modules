#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Contact.hpp"

class Phonebook {
  public:
    Phonebook();
    ~Phonebook();
    void OpenPhonebook();

  private:
    enum Commands {
      Add = 1 << 0,
      Search = 1 << 1,
      Exit = 1 << 2
    };
    static Contact _contact[8];
    static int _registeredNumber;
    static int _indexToAdd;
    static int _selectedIndex;
    static unsigned int CheckCommand(const std::string& input);
    static void ExecuteCommand(const unsigned int& command);
    static void CheckIndex();
    static void AddContact();
    static void SearchContact();
    static void DisplayContactList();
    static void SelectContact();
    static void DisplayContactInformation();
};
