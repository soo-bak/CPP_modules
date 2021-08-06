#include "Contact.hpp"

const std::string Contact::_fieldName[5] = {"First Name", "Last Name",
                                            "Nick Name", "Phone Number",
                                            "Darkest Secret"};

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::printList(const std::string index,
                        const std::string *information) const {
  std::cout << "|";
  _printColumn(index);
  for (int i = FirstName; i < PhoneNumber; i++) {
    _printColumn(information[i]);
  }
  std::cout << std::endl;
  return ;
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

void Contact::setInformation() {
  for (int i = FirstName; i <= DarkestSecret; i++) {
    _printFieldPrompt(i);
    std::getline(std::cin, _information[i]);
    if (std::cin.bad() || std::cin.eof())
      return ;
  }
  return ;
}

const std::string& Contact::getContactIndex() const {
  return _contactIndex;
}

const std::string *Contact::getFieldName() const {
  return _fieldName;
}
const std::string* Contact::getInformation() const {
  return _information;
}

void Contact::_printColumn(std::string content) {
  const int fieldWidth(10);
  if (content.size() > fieldWidth) {
    const std::size_t truncatedIndex(fieldWidth - 1);
    content.at(truncatedIndex) = '.';
    const std::size_t truncatedSize(truncatedIndex + 1);
    content.resize(truncatedSize);
  }
  std::cout << std::setw(fieldWidth) << std::right << content << "|";
  return ;
}

void Contact::_printFieldPrompt(const int& iterator) {
  std::cout << "  ADD contact's <" << _fieldName[iterator] << "> : ";
  return ;
}
