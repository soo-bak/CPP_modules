#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::SetInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++) {
    PrintFieldPrompt(i);
    std::getline(std::cin, _information[i]);
    // std::cin >> _information[i];
  }
}

void Contact::PrintFieldPrompt(const int& arrayIterator) {
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
    fieldName = "Darkest Secret : ";
  } else {
    fieldName = "Field name error";
  }
  std::cout << fieldName;
}

void Contact::SetContactIndex(const int& indexToAdd) {
  std::stringstream ss;
  ss << (indexToAdd + 1);
  ss >> _contactIndex;
}

void Contact::PrintBasicInformation() {
  std::cout << "|";
  PrintColumn(_contactIndex);
  for (int i = FirstName; i < PhoneNumber; i++) {
    PrintColumn(_information[i]);
  }
  std::cout << std::endl;
}

void Contact::PrintColumn(std::string content) {
  const int fieldWidth = 10;
  if (content.size() > fieldWidth) {
    const std::size_t truncatedIndex = fieldWidth - 1;
    content.at(truncatedIndex) = '.';
    const std::size_t truncatedSize = truncatedIndex + 1;
    content.resize(truncatedSize);
  }
  std::stringstream contentStream;
  contentStream << content;
  std::cout << std::setw(fieldWidth) << std::right;
  std::cout << contentStream.str() << "|";
}

void Contact::PrintAllInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++){
    std::cout << _information[i] << std::endl;
  }
}
