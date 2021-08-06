#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

class Contact {
  public:
    Contact();
    ~Contact();
    void printList(const std::string index,
                   const std::string *information) const;
    void printInformation() const;
    void setContactIndex(const int& indexToAdd);
    void setInformation();
    const std::string& getContactIndex() const;
    const std::string *getFieldName() const;
    const std::string* getInformation() const;

  private:
    enum Field {
      FirstName,
      LastName,
      NickName,
      PhoneNumber,
      DarkestSecret
    };
    static const std::string _fieldName[5];
    static void _printColumn(std::string content);
    static void _printFieldPrompt(const int& arrayIterator);
    std::string _contactIndex;
    std::string _information[5];
};
