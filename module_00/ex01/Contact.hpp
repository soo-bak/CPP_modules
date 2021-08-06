#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

class Contact {
  public:
    Contact(void);
    ~Contact(void);
    void printList(const std::string index,
                   const std::string *information) const;
    void printInformation(void) const;
    void setContactIndex(const int& indexToAdd);
    void setInformation(void);
    const std::string& getContactIndex(void) const;
    const std::string *getFieldName(void) const;
    const std::string* getInformation(void) const;

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
