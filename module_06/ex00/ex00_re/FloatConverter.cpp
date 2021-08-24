#include "FloatConverter.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

FloatConverter& FloatConverter::operator = (const FloatConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  return *this;
}

FloatConverter::FloatConverter(void)
    : ATypeConverter(), _value(0) {
  _setTypeName("float");
}

FloatConverter::FloatConverter(const char& character)
    : ATypeConverter(), _value(0) {
  _setTypeName("float");
  _value = static_cast<float>(character);
}

FloatConverter::FloatConverter(const int& integerNumber)
    : ATypeConverter(), _value(0) {
  _setTypeName("float");
  _value = static_cast<float>(integerNumber);
}

FloatConverter::FloatConverter(const double& doubleNumber)
    : ATypeConverter(), _value(0) {
  _setTypeName("float");
  if (doubleNumber < std::numeric_limits<float>::min() ||
      doubleNumber > std::numeric_limits<float>::max()) {
    _isConvertable = false;
  } else {
    _value = static_cast<float>(doubleNumber);
  }
}

FloatConverter::FloatConverter(const std::string& literal)
    : ATypeConverter(literal), _value(atoi(literal.c_str())) {
}

FloatConverter::FloatConverter(const FloatConverter& other)
    : ATypeConverter(other._literal), _value(other._value) {
}

FloatConverter::~FloatConverter(void) {
}

void FloatConverter::printValue(void) const {
  std::cout << "float : ";
  if (!_isConvertable) {
    std::cout << ansiRed << "Impossible" << ansiEnd;
  } else {
    std::cout << _value;
  }
  std::cout << std::endl;
  return ;
}

void FloatConverter::convert(void) const {
  CharConverter charConverter(_value);
  charConverter.printValue();
  IntConverter intConverter(_value);
  intConverter.printValue();
  DoubleConverter doubleConverter(_value);
  doubleConverter.printValue();
}
