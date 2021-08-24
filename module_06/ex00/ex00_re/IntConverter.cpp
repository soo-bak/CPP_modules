#include "IntConverter.hpp"

IntConverter& IntConverter::operator = (const IntConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  return *this;
}

IntConverter::IntConverter(void)
    : ATypeConverter(), _value(0) {
  _setTypeName("int");
}

IntConverter::IntConverter(const char& character)
    : ATypeConverter(), _value(0) {
  _setTypeName("int");
  _value = static_cast<int>(character);
}

IntConverter::IntConverter(const float& floatigNumber)
    : ATypeConverter(), _value(0) {
  _setTypeName("int");
  _castToInt(floatigNumber);
}

IntConverter::IntConverter(const double& doubleNumber)
    : ATypeConverter(), _value(0) {
  _setTypeName("int");
  _castToInt(doubleNumber);
}

IntConverter::IntConverter(const std::string& literal)
    : ATypeConverter(literal), _value(atoi(literal.c_str())) {
  _setTypeName("int");
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
  CharConverter charConverter(_value);
  charConverter.printValue();
  FloatConverter floatConverter(_value);
  floatConverter.printValue();
  DoubleConverter doubleConverter(_value);
  doubleConverter.printValue();
  return ;
}

int IntConverter::_castToInt(const double& number) {
  int castedInt(0);
  if (number < std::numeric_limits<int>::min() ||
      number > std::numeric_limits<int>::max()) {
    _isConvertable = false;
  } else {
    castedInt = static_cast<int>(number);
  }
  return castedInt;
}
