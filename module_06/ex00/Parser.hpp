#pragma once

#include <string>

#include "CharConverter.hpp"
#include "IntConverter.hpp"

class Parser {

  public:

    enum ValidType {
      CharType,
      IntType,
      FloatType,
      DoubleType,
      ValidTypesNumber
    };

    class NotMatchedTypeException : public std::exception {
      public:
       virtual const char* what(void) const throw();
    };

    Parser& operator = (const Parser& other);

    Parser(void);
    Parser(const Parser& other);
    ~Parser();

    static ATypeConverter* acquireType(const std::string& string);
    static void printOtherTypeValue(const ATypeConverter& type);

  private:

    static unsigned int _detectType(const std::string& string);
    static bool _isTypeChar(const std::string& string);
    static bool _isTypeInt(const std::string& string);
    static bool _isTypeFloat(const std::string& string);
    static bool _isTypeDouble(const std::string& string);
    static bool _isPointNumber(const std::string& string);
    static bool _isNaN(const std::string& string);
    static bool _isInf(const std::string& string);
    static bool _isSign(const char& character);
    static bool _isDot(const char& character);
    static bool _isFloatSuffix(const char& character);
};
