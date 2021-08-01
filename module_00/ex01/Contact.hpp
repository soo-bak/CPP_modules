#pragma once

#include <string>

class Contact {
  private:
    std::string _information[5];

  public:
    Contact();
    ~Contact();
};

enum field {
  FirstName,
  LastName,
  NickName,
  PhoneNumber,
  DarkestSecret
};
