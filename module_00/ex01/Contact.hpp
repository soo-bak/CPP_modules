#pragma once

#include <string>

class Contact {
  public:
    Contact();
    ~Contact();
    void SetInformation(const std::string& input, const unsigned int& field);

  private:
    std::string _information[5];
};

enum field {
  FirstName,
  LastName,
  NickName,
  PhoneNumber,
  DarkestSecret
};
