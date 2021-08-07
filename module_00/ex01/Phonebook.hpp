#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Contact.hpp"

class Phonebook {
  public:
    Phonebook(void);
    ~Phonebook(void);

    void openPhonebook(void);

  private:
    enum Commands {
      Add = 1 << 0,
      Search = 1 << 1,
      Exit = 1 << 2,
      Empty = 1 << 3,
      Error = 1 << 4
    };

    static unsigned int _makeCommandValue(const std::string& input);

    Contact _contact[8];
    int _columnWidth;
    int _phonebookSize;
    int _registeredNumber;
    int _indexToAdd;
    int _selectedIndex;

    const std::string _makeTruncatedString(std::string& stringInput) const;
    void _displayContactList(void) const;
    void _displayContactInformation(void) const;
    void _executeCommand(const unsigned int& commandValue);
    void _addContact(void);
    void _searchContact(void);
    void _selectContact(void);
};
