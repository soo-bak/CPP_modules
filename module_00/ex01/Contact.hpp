#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Contact {
  public:
    Contact();
    ~Contact();
    void PrintBasicInformation(const std::string index,
                               const std::string *information);
    void PrintInformation();
    void SetContactIndex(const int& indexToAdd);
    void SetInformation();
    std::string GetContactIndex();
    std::string *GetFieldName();
    std::string *GetInformation();

  private:
    enum field {
      FirstName,
      LastName,
      NickName,
      PhoneNumber,
      DarkestSecret
    };
    static std::string _fieldName[5];
    static void PrintColumn(std::string content);
    static void PrintFieldPrompt(const int& arrayIterator);
    std::string _contactIndex;
    std::string _information[5];
};
