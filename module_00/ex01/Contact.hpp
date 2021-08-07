#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

class Contact {
  public:
    enum Field {
      FirstName,
      LastName,
      NickName,
      PhoneNumber,
      DarkestSecret
    };

    static const std::string* getFieldNameArray(void);

    Contact(void);
    ~Contact(void);

    const std::string getContactIndex(void) const;
    const std::string* getInformationArray(void) const;
    void printInformation(void) const;
    void setContactIndex(const int& startZeroIndex);
    void makeInformation(void);

  private:
    static void _printFieldPrompt(const int& fieldIterator);
    static const std::string _fieldName[5];

    std::string _information[5];
    std::string _contactIndex;
};
