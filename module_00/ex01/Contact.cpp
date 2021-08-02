#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::SetInformation() {
  for (int i = FirstName; i < DarkestSecret; i++) {
    PrintFieldPrompt(i);
    getline(std::cin, this->_information[i]);
  }
}

void Contact::PrintFieldPrompt(int& arrayIterator) {
  std::string fieldName;
  if (arrayIterator == FirstName) {
    fieldName = "First Name : ";
  } else if (arrayIterator == LastName) {
    fieldName = "Last Name : ";
  } else if (arrayIterator == NickName) {
    fieldName = "Nick Name : ";
  } else if (arrayIterator == PhoneNumber) {
    fieldName = "Phone Number : ";
  } else if (arrayIterator == DarkestSecret) {
    fieldName = "DarkestSecret : ";
  } else {
    fieldName = "Field name error";
  }
  std::cout << fieldName;
}

void Contact::SetContactIndex(const int& indexToAdd) {
  this->_contactIndex = indexToAdd;
}

void Contact::PrintBasicInformation() {
  for (int i = FirstName; i < PhoneNumber; i++) {
    std::cout << _information[i] << std::endl;
  }
}
