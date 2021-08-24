#include "CharConverter.hpp"

CharConverter& CharConverter::operator = (const CharConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  _isDisplayable = other._isDisplayable;
  return *this;
}

CharConverter::CharConverter(void)
    : ATypeConverter(), _value(0),
      _isDisplayable(true) {
}

CharConverter::CharConverter(const std::string& string)
    : ATypeConverter("char"), _value(*string.begin()),
      _isDisplayable(true) {
}

CharConverter::CharConverter(const CharConverter& other)
    : ATypeConverter(other._typeName), _value(other._value),
      _isDisplayable(other._isDisplayable){
}

CharConverter::~CharConverter(void) {
}

void CharConverter::printValue(void) const {
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

const bool& CharConverter::getIsDisplayable(void) const {
  return _isDisplayable;
}

void CharConverter::setIsDisplayable(const bool& boolean) {
  _isDisplayable = boolean;
  return ;
}
