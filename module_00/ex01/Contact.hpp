#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

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
    std::string _contactIndex;
    std::string _information[5];
    std::string _fieldName[5];
};
