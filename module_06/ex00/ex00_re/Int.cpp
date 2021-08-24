#include "Int.hpp"

Int& Int::operator = (const Int& other) {
  AType::operator=(other);
  _value = other._value;
  return *this;
}

Int::Int(void)
    : AType(), _value(0) {
}

Int::Int(const std::string& string)
    : AType(string), _value(*string.begin()) {
}

Int::Int(const Int& other)
    : AType(other._literal), _value(other._value) {
}

Int::~Int(void) {
}

void Int::printValue(void) const {
  std::cout << "Int : ";
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

const bool& Int::getIsDisplayable(void) const {
  return _isDisplayable;
}

void Int::setIsDisplayable(const bool& boolean) {
  _isDisplayable = boolean;
  return ;
}
