#include "Parser.hpp"

const char* Parser::NotMatchedTypeException::what(void) const throw() {
  return "Parser::NotMatchedTypeException";
}

Parser::Parser(void) {
}

Parser::~Parser(void) {
}

ATypeConverter* Parser::acquireType(const std::string& string) {
  const unsigned int typeEnum(_detectType(string));

  ATypeConverter* returnType(NULL);
  switch (typeEnum) {
    case CharType:
      returnType = new CharConverter(string);
    break;
    case IntType:
      returnType = new IntConverter(string);
  default:
    break;
  }
  return returnType;
}

unsigned int Parser::_detectType(const std::string& string) {
  if (_isTypeChar(string)) {
    return CharType;
  } else if (_isTypeInt(string)) {
    return IntType;
  } else if (_isTypeFloat(string)) {
    return FloatType;
  } else if (_isTypeDouble(string)) {
    return DoubleType;
  } else {
    throw NotMatchedTypeException();
  }
}

bool Parser::_isPointNumber(const std::string& string) {
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

bool Parser::_isSign(const char& character) {
 if (character == '+' || character == '-')  {
   return true;
 }
 return false;
}

bool Parser::_isDot(const char& character) {
  if (character == '.') {
    return true;
  }
  return false;
}

bool Parser::_isFloatSuffix(const char& character) {
  if (character == 'f') {
    return true;
  }
  return false;
}

bool Parser::_isTypeChar(const std::string& string) {
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

bool Parser::_isTypeInt(const std::string& string) {
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

bool Parser::_isTypeFloat(const std::string& string) {
  if (_isPointNumber(string) &&
      _isFloatSuffix(*(string.end() - 1)) &&
      !_isDot(*(string.end() - 2))) {
    return true;
  }
  return false;
}

bool Parser::_isTypeDouble(const std::string& string) {
  if (_isPointNumber(string) &&
      isdigit(*(string.end() - 1))) {
    return true;
  }
  return false;
}

bool Parser::_isNaN(const std::string& string) {
  if (string.compare("nan") == 0) {
    return true;
  }
  return false;
}

bool Parser::_isInf(const std::string& string) {
  if (string.compare("+inf") == 0 || string.compare("-inf") == 0 ||
      string.compare("+inff") == 0 || string.compare("-inff") == 0) {
    return true;
  }
  return false;
}
