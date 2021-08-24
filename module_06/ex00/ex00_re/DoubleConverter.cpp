#include "DoubleConverter.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

DoubleConverter& DoubleConverter::operator = (const DoubleConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  return *this;
}

DoubleConverter::DoubleConverter(void)
    : ATypeConverter(), _value(0) {
  _setTypeName("double");
}

DoubleConverter::DoubleConverter(const char& character)
    : ATypeConverter(), _value(0) {
  _setTypeName("double");
  _value = static_cast<double>(character);
}

DoubleConverter::DoubleConverter(const int& integerNumber)
    : ATypeConverter(), _value(0) {
  _setTypeName("double");
  _value = static_cast<double>(integerNumber);
}

DoubleConverter::DoubleConverter(const float& floatingNumber)
    : ATypeConverter(), _value(0) {
  _setTypeName("double");
  _value = static_cast<double>(floatingNumber);
}

DoubleConverter::DoubleConverter(const std::string& literal)
    : ATypeConverter(literal), _value(atoi(literal.c_str())) {
}

DoubleConverter::DoubleConverter(const DoubleConverter& other)
    : ATypeConverter(other._literal), _value(other._value) {
}

DoubleConverter::~DoubleConverter(void) {
}

void DoubleConverter::printValue(void) const {
  std::cout << "double : ";
  if (!_isConvertable) {
    std::cout << ansiRed << "Impossible" << ansiEnd;
  } else {
    std::cout << _value;
  }
  std::cout << std::endl;
  return ;
}

void DoubleConverter::convert(void) const {
  CharConverter charConverter(_value);
  charConverter.printValue();
  IntConverter intConverter(_value);
  intConverter.printValue();
  FloatConverter floatConverter(_value);
  floatConverter.printValue();
}
