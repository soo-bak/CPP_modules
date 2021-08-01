#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::SetInformation(const std::string& input, const unsigned int& field) {
  this->_information[field] = input;
}
