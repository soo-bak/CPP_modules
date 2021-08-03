#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Contact {
  public:
    void PrintColumn(std::string content);
    void PrintFieldPrompt(const int& arrayIterator);
    void SetInformation();
    void SetContactIndex(const int& indexToAdd);
    void PrintBasicInformation(const std::string index,
                               const std::string *information);
    void PrintAllInformation();
    Contact();
    ~Contact();
    std::string *GetFieldName();
    std::string GetContactIndex();
    std::string *GetInformation();

  private:
    std::string _fieldName[5];
    std::string _contactIndex;
    std::string _information[5];
};
