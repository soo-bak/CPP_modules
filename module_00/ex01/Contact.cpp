#include "Contact.hpp"

const std::string Contact::_fieldName[5] = {"First Name", "Last Name",
                                            "Nick Name", "Phone Number",
                                            "Darkest Secret"};

const std::string* Contact::getFieldNameArray() {
  return _fieldName;
}

Contact::Contact() {
}

Contact::~Contact() {
}

const std::string Contact::getContactIndex() const {
  return _contactIndex;
}

const std::string* Contact::getInformationArray() const{
  return _information;
}

void Contact::printInformation() const {
  for (int i = FirstName; i <= DarkestSecret; i++){
    std::cout << "  " << _fieldName[i] << " : " <<_information[i] << std::endl;
  }
  return ;
}

void Contact::setContactIndex(const int& startZeroIndex) {
  std::stringstream indexStream;
  indexStream << (startZeroIndex + 1);
  const std::string startOneIndex(indexStream.str());
  _contactIndex = startOneIndex;
  return ;
}

void Contact::makeInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++) {
    _printFieldPrompt(i);
    std::getline(std::cin, _information[i]);
    if (std::cin.bad() || std::cin.eof())
      return ;
  }
  return ;
}

void Contact::_printFieldPrompt(const int& iterator){
  std::cout << "  Enter contact's <" << _fieldName[iterator] << "> : ";
  return ;
}
