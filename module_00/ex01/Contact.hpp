#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

enum field {
  FirstName,
  LastName,
  NickName,
  PhoneNumber,
  DarkestSecret
};

class Contact {
  public:
    Contact();
    ~Contact();
    void SetInformation();
    void SetContactIndex(const int& indexToAdd);
    void PrintFieldPrompt(const int& arrayIterator);
    void PrintBasicInformation(const std::string index,
                               const std::string *information);
    void PrintColumn(std::string content);
    void PrintAllInformation();
    std::string GetContactIndex();
    std::string *GetInformation();
    std::string *GetFieldName();

  private:
    std::string _information[5];
    std::string _contactIndex;
    std::string _fieldName[5];
};
