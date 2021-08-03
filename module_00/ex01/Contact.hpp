#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Contact {
  public:
    Contact();
    ~Contact();
    void SetInformation();
    void SetContactIndex(const int& indexToAdd);
    void PrintFieldPrompt(int& arrayIterator);
    void PrintBasicInformation();
    void PrintColumn(const std::string& content);

  private:
    std::string _information[5];
    std::string _contactIndex;
};

enum field {
  FirstName,
  LastName,
  NickName,
  PhoneNumber,
  DarkestSecret
};
