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

CharConverter::CharConverter(const std::string& literal)
    : ATypeConverter(literal), _value(*literal.begin()),
      _isDisplayable(true) {
}

CharConverter::CharConverter(const int& integerNumber)
    : ATypeConverter(), _value(0), _isDisplayable(true) {
  if (integerNumber < 0 || integerNumber > 127) {
    _isConvertable = false;
  } else {
    _value = static_cast<char>(integerNumber);
    if (!isprint(_value)) {
      _isDisplayable = false;
    }
  }
}

CharConverter::CharConverter(const CharConverter& other)
    : ATypeConverter(other._literal), _value(other._value),
      _isDisplayable(other._isDisplayable) {
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

void CharConverter::convert(void) const {
  IntConverter intConverter(_value);
  intConverter.printValue();
}

const bool& CharConverter::getIsDisplayable(void) const {
  return _isDisplayable;
}

void CharConverter::setIsDisplayable(const bool& boolean) {
  _isDisplayable = boolean;
  return ;
}
