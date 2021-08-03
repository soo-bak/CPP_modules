#include "Contact.hpp"

Contact::Contact() {
  _fieldName[FirstName] = "First Name";
  _fieldName[LastName] = "Last Name";
  _fieldName[NickName] = "Nick Name";
  _fieldName[PhoneNumber] = "Phone Number";
  _fieldName[DarkestSecret] = "Darkest Secret";
}

Contact::~Contact() {
}

void Contact::SetInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++) {
    PrintFieldPrompt(i);
    std::getline(std::cin, _information[i]);
  }
}

void Contact::PrintFieldPrompt(const int& arrayIterator) {
  std::string fieldName;
  std::cout << "  ADD contact's <" << _fieldName[arrayIterator] << "> : ";
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
    std::cout << "  " << _fieldName[i] << " : " <<_information[i] << std::endl;
  }
}
