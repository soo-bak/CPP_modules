#pragma once

#include <string>

#include "Char.hpp"

class Convertor {

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

    Convertor& operator = (const Convertor& other);

    Convertor(void);
    ~Convertor();

    static AType* acquireType(const std::string& string);

  private:
    static unsigned int detectType(const std::string& string);
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
    static unsigned int _detectType(const std::string& strng);
};
