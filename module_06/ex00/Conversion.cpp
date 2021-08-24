#include "Conversion.hpp"

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
    : _literalValue(other.getLiteralValue()) {
}

Conversion::Conversion(const std::string& string)
    : _literalValue(string) {
  try {
    _type = _findType(_literalValue);
  }
  catch (std::exception& exception) {
    std::cout << exception.what() << std::endl;
  }
  std::string test;
  if (_type == Char) {
    test = "char";
  } else if (_type == Int) {
    test = "int";
  } else if (_type == Float) {
    test = "float";
  } else if (_type == Double) {
    test = "double";
  } else {
    test = "???????";
  }
  std::cout << "[ " << test << " ]" << std::endl;
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
  std::cout << string << std::endl;
  if (_isPointNumber(string) &&
      _isFloatSuffix(*(string.end() - 1))) {
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

unsigned int Conversion::_findType(const std::string& string) {
  if (_isTypeChar(string)) {
    return Char;
  } else if (_isTypeInt(string)) {
    return Int;
  } else if (_isTypeFloat(string)) {
    return Float;
  } else if (_isTypeDouble(string)) {
    return Double;
  } else {
    throw NotMatchedTypeException();
  }
  return TypeListCount;
}
