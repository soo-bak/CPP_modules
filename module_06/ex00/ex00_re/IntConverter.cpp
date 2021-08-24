#include "IntConverter.hpp"

IntConverter& IntConverter::operator = (const IntConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  return *this;
}

IntConverter::IntConverter(void)
    : ATypeConverter(), _value(0) {
}

IntConverter::IntConverter(const char& character)
    : ATypeConverter() {
  _value = static_cast<int>(character);
}

IntConverter::IntConverter(const std::string& literal)
    : ATypeConverter(literal), _value(atoi(literal.c_str())) {
}

IntConverter::IntConverter(const IntConverter& other)
    : ATypeConverter(other._literal), _value(other._value) {
}

IntConverter::~IntConverter(void) {
}

void IntConverter::printValue(void) const {
  std::cout << "int : ";
  if (!_isConvertable) {
    std::cout << "Impossible";
  } else {
    std::cout << _value;
  }
  std::cout << std::endl;
  return ;
}

void IntConverter::convert(void) const {

}
