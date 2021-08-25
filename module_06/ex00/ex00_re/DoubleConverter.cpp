#include "DoubleConverter.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

DoubleConverter& DoubleConverter::operator = (const DoubleConverter& other) {
  ATypeConverter::operator = (other);
  _value = other._value;
  return *this;
}

DoubleConverter::DoubleConverter(void)
    : ATypeConverter(), _value(0), _precision(0),
      _nonRepresentableValue(NotApplicable) {
  _setTypeName("double");
}

DoubleConverter::DoubleConverter(const char& character)
    : ATypeConverter(), _value(0), _precision(1),
      _nonRepresentableValue(NotApplicable) {
  _setTypeName("double");
  _value = static_cast<double>(character);
}

DoubleConverter::DoubleConverter(const int& integerNumber)
    : ATypeConverter(), _value(0), _precision(1),
      _nonRepresentableValue(NotApplicable) {
  _setTypeName("double");
  _value = static_cast<double>(integerNumber);
}

DoubleConverter::DoubleConverter(const float& floatingNumber,
                                 const int& precision)
    : ATypeConverter(), _value(0), _precision(precision),
      _nonRepresentableValue(NotApplicable) {
  _setTypeName("double");
  _value = static_cast<double>(floatingNumber);
}

DoubleConverter::DoubleConverter(const std::string& literal)
    : ATypeConverter(literal), _value(0),
      _precision(literal.length() - literal.find('.') - 1),
      _nonRepresentableValue(NotApplicable) {
  _setTypeName("double");
  if (!literal.compare("-inf")) {
    _nonRepresentableValue = NegativeInfinity;
    _value = -INFINITY;
  } else if (!literal.compare("+inf") || !literal.compare("inf")) {
    _nonRepresentableValue = PositiveInfinity;
    _value = INFINITY;
  } else if (!literal.compare("nan")) {
    _nonRepresentableValue = NotANumber;
    _value = NAN;
  } else {
    _value = atof(literal.c_str());
  }
}

DoubleConverter::DoubleConverter(const DoubleConverter& other)
    : ATypeConverter(other._literal), _value(other._value) {
}

DoubleConverter::~DoubleConverter(void) {
}

void DoubleConverter::printValue(void) const {
  std::cout << "  double : ";
  if (_nonRepresentableValue == NegativeInfinity) {
    std::cout << "-inf";
  } else if (_nonRepresentableValue == PositiveInfinity) {
    std::cout << "+inf";
  } else if (_nonRepresentableValue == NotANumber) {
    std::cout << "nan" ;
  } else {
    std::cout << std::fixed << std::setprecision(_precision);
    std::cout << _value;
  }
  std::cout << std::endl;
  return ;
}

void DoubleConverter::convert(void) const {
  CharConverter charConverter(_value);
  IntConverter intConverter(_value);
  FloatConverter floatConverter(_value, _precision);
  if (_nonRepresentableValue != NotApplicable) {
    charConverter.setIsConvertable(false);
    intConverter.setIsConvertable(false);
    for (unsigned int i = NegativeInfinity; i < NotApplicable; i++) {
      if (_nonRepresentableValue == i) {
        floatConverter.setNonRepresentableValue(i);
        floatConverter.setIsConvertable(true);
        break ;
      }
    }
  }
  charConverter.printValue();
  intConverter.printValue();
  floatConverter.printValue();
  return ;
}
