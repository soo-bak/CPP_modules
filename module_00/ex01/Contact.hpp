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
    void PrintFieldPrompt(const int& arrayIterator);
    void PrintBasicInformation();
    void PrintColumn(std::string content);
    void PrintAllInformation();

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
