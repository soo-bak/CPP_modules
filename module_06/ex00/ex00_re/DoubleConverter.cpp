#include "DoubleConverter.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

DoubleConverter& DoubleConverter::operator = (const DoubleConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  return *this;
}

DoubleConverter::DoubleConverter(void)
    : ATypeConverter(), _value(0), _precision(0) {
  _setTypeName("double");
}

DoubleConverter::DoubleConverter(const char& character)
    : ATypeConverter(), _value(0), _precision(1) {
  _setTypeName("double");
  _value = static_cast<double>(character);
}

DoubleConverter::DoubleConverter(const int& integerNumber)
    : ATypeConverter(), _value(0), _precision(1) {
  _setTypeName("double");
  _value = static_cast<double>(integerNumber);
}

DoubleConverter::DoubleConverter(const float& floatingNumber,
                                 const int& precision)
    : ATypeConverter(), _value(0), _precision(precision) {
  _setTypeName("double");
  _value = static_cast<double>(floatingNumber);
}

DoubleConverter::DoubleConverter(const std::string& literal)
    : ATypeConverter(literal), _value(0),
      _precision(literal.length() - literal.find('.') - 1) {
  _value = static_cast<float>(atof(literal.c_str()));
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
    std::cout << std::fixed << std::setprecision(_precision);
    std::cout <<_value;
  }
  std::cout << std::endl;
  return ;
}

void DoubleConverter::convert(void) const {
  CharConverter charConverter(_value);
  charConverter.printValue();
  IntConverter intConverter(_value);
  intConverter.printValue();
  FloatConverter floatConverter(_value, _precision);
  floatConverter.printValue();
}
