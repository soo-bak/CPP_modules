#include "Conversion.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiEnd("\033[0m");

const char* Conversion::NotMatchedTypeException::what(void) const throw() {
  return "Conversion::NotMatchedTypeException";
}

Conversion& Conversion::operator = (const Conversion& other) {
  if (this == &other) {
    return *this;
  }
  _literalValue = other.getLiteralValue();
  _type = other.getType();
  return *this;
}

Conversion::Conversion(const Conversion& other)
    : _literalValue(other.getLiteralValue()),
      _type(other.getType()) {
}

Conversion::Conversion(const std::string& string)
    : _literalValue(string) {
  _type = _detectType(_literalValue);
  _convertValues();
}

Conversion::Conversion(void)
    : _literalValue(""), _type(TypeListCount) {
}

Conversion::~Conversion(void) {
}

const std::string& Conversion::getLiteralValue(void) const {
  return _literalValue;
}

const unsigned int& Conversion::getType(void) const {
  return _type;
}

const char& Conversion::getCharValue(void) const {
  return _charValue;
}

const int& Conversion::getIntValue(void) const {
  return _intValue;
}

const float& Conversion::getFloatValue(void) const {
  return _floatValue;
}

const double& Conversion::getDoubleValue(void) const {
  return _doubleValue;
}

void Conversion::printConvertedValues(void) const {
  std::cout << "Char : " << _charValue << std::endl;
  std::cout << "Int : " << _intValue << std::endl;
  std::cout << "Float : " << _floatValue << std::endl;
  std::cout << "Double : " << _doubleValue << std::endl;
}

bool Conversion::_isPointNumber(const std::string& string) {
  if (!isdigit(*string.begin()) && !_isSign(*string.begin())) {
    return false;
  }
  int dotCounts(0);
  for (std::string::const_iterator i = string.begin() + 1;
       i < string.end() - 1; i++) {
    if (!isdigit(*i) && !_isDot(*i)) {
      return false;
    }
    if (_isDot(*i)) {
        dotCounts++;
    }
  }
  if (dotCounts != 1) {
    return false;
  }
  return true;
}

bool Conversion::_isSign(const char& character) {
 if (character == '+' || character == '-')  {
   return true;
 }
 return false;
}

bool Conversion::_isDot(const char& character) {
  if (character == '.') {
    return true;
  }
  return false;
}

bool Conversion::_isFloatSuffix(const char& character) {
  if (character == 'f') {
    return true;
  }
  return false;
}

bool Conversion::_isTypeChar(const std::string& string) {
  if (string.length() != 1) {
    return false;
  }
  // !iscntrl(asciiValue)
  const int asciiValue(string.at(0));
  if (!isdigit(asciiValue)) {
    return true;
  }
  return false;
}

bool Conversion::_isTypeInt(const std::string& string) {
  if (!isdigit(*string.begin()) &&
      !_isSign(*string.begin())) {
    return false;
  }
  for (std::string::const_iterator i = string.begin() + 1;
       i < string.end(); i++) {
    if (!isdigit(*i)) {
      return false;
    }
  }
  return true;
}

bool Conversion::_isTypeFloat(const std::string& string) {
  if (_isPointNumber(string) &&
      _isFloatSuffix(*(string.end() - 1)) &&
      !_isDot(*(string.end() - 2))) {
    return true;
  }
  return false;
}

bool Conversion::_isTypeDouble(const std::string& string) {
  if (_isPointNumber(string) &&
      isdigit(*(string.end() - 1))) {
    return true;
  }
  return false;
}

bool Conversion::_isNaN(const std::string& string) {
  if (string.compare("nan") == 0) {
    return true;
  }
  return false;
}

bool Conversion::_isInf(const std::string& string) {
  if (string.compare("+inf") == 0 || string.compare("-inf") == 0 ||
      string.compare("+inff") == 0 || string.compare("-inff") == 0) {
    return true;
  }
  return false;
}

unsigned int Conversion::_detectType(const std::string& string) {
  if (_isTypeChar(string)) {
    return Char;
  } else if (_isTypeInt(string)) {
    return Int;
  } else if (_isTypeFloat(string)) {
    return Float;
  } else if (_isTypeDouble(string)) {
    return Double;
  } else if (_isNaN(string)) {
    return NaN;
  } else if (_isInf(string)) {
    return Inf;
  } else {
    throw NotMatchedTypeException();
  }
  return TypeListCount;
}

void Conversion::_convertValues(void) {
  switch (_type) {
    case Char:
      _charValue = _literalValue.at(0);
      _intValue = static_cast<int>(_charValue);
      _floatValue = static_cast<float>(_charValue);
      _doubleValue = static_cast<double>(_charValue);
      break ;
    case Int:
      _intValue = atoi(_literalValue.c_str());
      _charValue = static_cast<char>(_intValue);
      _floatValue = static_cast<float>(_intValue);
      _doubleValue = static_cast<double>(_intValue);
      break ;
    case Float:
      _floatValue = static_cast<float>(atof(_literalValue.c_str()));
      _charValue = static_cast<char>(_floatValue);
      _intValue = static_cast<int>(_floatValue);
      _doubleValue = static_cast<double>(_floatValue);
      break ;
    case Double:
      _doubleValue = atof(_literalValue.c_str());
      _charValue = static_cast<char>(_doubleValue);
      _intValue = static_cast<int>(_doubleValue);
      _floatValue = static_cast<float>(_doubleValue);
      break ;
    case NaN:
      _charValue = NAN;
      _intValue = NAN;
      _floatValue = NAN;
      _doubleValue = NAN;
      break ;
    default:
      throw NotMatchedTypeException();
      break ;
  }
  return ;
}
