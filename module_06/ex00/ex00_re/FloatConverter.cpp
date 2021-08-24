#include "FloatConverter.hpp"

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
    : ATypeConverter() {
  _setTypeName("float");
  _value = static_cast<float>(character);
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
    std::cout << "Impossible";
  } else {
    std::cout << _value;
  }
  std::cout << std::endl;
  return ;
}

void FloatConverter::convert(void) const {
  CharConverter charConverter(_value);
  charConverter.printValue();
}
