#include "Contact.hpp"

enum field {
  FirstName,
  LastName,
  NickName,
  PhoneNumber,
  DarkestSecret
};

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
  return ;
}

void Contact::SetContactIndex(const int& indexToAdd) {
  std::stringstream ss;
  ss << (indexToAdd + 1);
  ss >> _contactIndex;
  return ;
}

void Contact::PrintFieldPrompt(const int& arrayIterator) {
  std::cout << "  ADD contact's <" << _fieldName[arrayIterator] << "> : ";
  return ;
}

void Contact::PrintBasicInformation(const std::string index,
                                    const std::string *information) {
  std::cout << "|";
  PrintColumn(index);
  for (int i = FirstName; i < PhoneNumber; i++) {
    PrintColumn(information[i]);
  }
  std::cout << std::endl;
  return ;
}

void Contact::PrintColumn(std::string content) {
  const int fieldWidth = 10;
  if (content.size() > fieldWidth) {
    const std::size_t truncatedIndex = fieldWidth - 1;
    content.at(truncatedIndex) = '.';
    const std::size_t truncatedSize = truncatedIndex + 1;
    content.resize(truncatedSize);
  }
  std::cout << std::setw(fieldWidth) << std::right;
  std::cout << content << "|";
  return ;
}

void Contact::PrintAllInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++){
    std::cout << "  " << _fieldName[i] << " : " <<_information[i] << std::endl;
  }
  return ;
}

std::string Contact::GetContactIndex() {
  return _contactIndex;
}

std::string *Contact::GetInformation() {
  return _information;
}

std::string *Contact::GetFieldName() {
  return _fieldName;
}
