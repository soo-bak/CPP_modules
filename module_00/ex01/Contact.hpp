#pragma once

#include <string>
#include <iostream>

class Contact {
  public:
    Contact();
    ~Contact();
    void SetInformation();
    void SetContactIndex(const int& indexToAdd);
    void PrintFieldPrompt(int& arrayIterator);
    void PrintBasicInformation();

  private:
    std::string _information[5];
    int _contactIndex;
};

enum field {
  FirstName,
  LastName,
  NickName,
  PhoneNumber,
  DarkestSecret
};
