#include "CharConverter.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

CharConverter& CharConverter::operator = (const CharConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  _isDisplayable = other._isDisplayable;
  return *this;
}

CharConverter::CharConverter(void)
    : ATypeConverter(), _value(0),
      _isDisplayable(true) {
  _setTypeName("char");
}

CharConverter::CharConverter(const std::string& literal)
    : ATypeConverter(literal), _value(*literal.begin()),
      _isDisplayable(true) {
  _setTypeName("char");
}

CharConverter::CharConverter(const int& integerNumber)
    : ATypeConverter(), _value(0), _isDisplayable(true) {
  _setTypeName("char");
  _castToChar(integerNumber);
}

CharConverter::CharConverter(const float& floatingNumber)
    : ATypeConverter(), _value(0), _isDisplayable(true) {
  _setTypeName("char");
  _castToChar(floatingNumber);
}

CharConverter::CharConverter(const double& doubleNumber)
    : ATypeConverter(), _value(0), _isDisplayable(true) {
  _setTypeName("char");
  _castToChar(doubleNumber);
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
    std::cout << ansiRed << "Impossible" << ansiEnd;
  } else if (!_isDisplayable) {
    std::cout << ansiRed << "Non displayable" << ansiEnd;
  } else {
    std::cout << _value;
  }
  std::cout << std::endl;
  return ;
}

void CharConverter::convert(void) const {
  IntConverter intConverter(_value);
  intConverter.printValue();
  FloatConverter floatConverter(_value);
  floatConverter.printValue();
  DoubleConverter doubleConverter(_value);
  doubleConverter.printValue();
}

char CharConverter::_castToChar(const double& number) {
  char castedChar(0);
  if (number < std::numeric_limits<char>::min() ||
      number > std::numeric_limits<char>::max()) {
    _isConvertable = false;
  } else {
    castedChar = static_cast<char>(number);
    if (!isprint(castedChar)) {
      _isDisplayable = false;
    }
  }
  return castedChar;
}
