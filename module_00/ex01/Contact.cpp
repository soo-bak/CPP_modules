#include "Contact.hpp"

std::string Contact::_fieldName[5] = {"First Name", "Last Name",
                                       "Nick Name", "Phone Number",
                                       "Darkest Secret"};

Contact::Contact() {
}

Contact::~Contact() {
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

void Contact::PrintInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++){
    std::cout << "  " << _fieldName[i] << " : " <<_information[i] << std::endl;
  }
  return ;
}

void Contact::SetContactIndex(const int& startZeroIndex) {
  std::stringstream indexStream;
  indexStream << (startZeroIndex + 1);
  const std::string startOneIndex = indexStream.str();
  _contactIndex = startOneIndex;
  return ;
}

void Contact::SetInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++) {
    PrintFieldPrompt(i);
    std::getline(std::cin, _information[i]);
  }
  return ;
}

std::string Contact::GetContactIndex() {
  return _contactIndex;
}

std::string *Contact::GetFieldName() {
  return _fieldName;
}
std::string *Contact::GetInformation() {
  return _information;
}


void Contact::PrintColumn(std::string content) {
  const int fieldWidth = 10;
  if (content.size() > fieldWidth) {
    const std::size_t truncatedIndex = fieldWidth - 1;
    content.at(truncatedIndex) = '.';
    const std::size_t truncatedSize = truncatedIndex + 1;
    content.resize(truncatedSize);
  }
  std::cout << std::setw(fieldWidth) << std::right << content << "|";
  return ;
}

void Contact::PrintFieldPrompt(const int& iterator) {
  std::cout << "  ADD contact's <" << _fieldName[iterator] << "> : ";
  return ;
}
