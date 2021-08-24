#include "Char.hpp"

Char& Char::operator = (const Char& other) {
  AType::operator=(other);
  _value = other._value;
  _isDisplayable = other._isDisplayable;
  return *this;
}

Char::Char(void)
    : AType(), _value(0),
      _isDisplayable(true) {
}

Char::Char(const std::string& string)
    : AType("char"), _value(*string.begin()),
      _isDisplayable(true) {
}

Char::Char(const Char& other)
    : AType(other._typeName), _value(other._value),
      _isDisplayable(other._isDisplayable){
}

Char::~Char(void) {
}

void Char::printValue(void) const {
  std::cout << "char : ";
  if (!_isConvertable) {
    std::cout << "Impossible";
  } else if (!_isDisplayable) {
    std::cout << "Non displayable";
  } else {
    std::cout << _value;
  }
  std::cout << std::endl;
  return ;
}

const bool& Char::getIsDisplayable(void) const {
  return _isDisplayable;
}

void Char::setIsDisplayable(const bool& boolean) {
  _isDisplayable = boolean;
  return ;
}
