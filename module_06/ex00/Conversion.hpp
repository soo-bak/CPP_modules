#pragma once

#include <cctype>
#include <cstdlib>
#include <cmath>

#include <exception>

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

class Conversion {

  public:

    class NotMatchedTypeException : public std::exception {
      public:
        virtual const char* what(void) const throw();
    };
    enum {
      Char,
      Int,
      Float,
      Double,
      NaN,
      Inf,
      TypeListCount
    };

    Conversion& operator = (const Conversion& other);

    Conversion(void);
    Conversion(const std::string& string);
    Conversion(const Conversion& other);
    ~Conversion(void);

    const std::string& getLiteralValue(void) const;
    const unsigned int& getType(void) const;
    const char& getCharValue(void) const;
    const int& getIntValue(void) const;
    const float& getFloatValue(void) const;
    const double& getDoubleValue(void) const;

    void printConvertedValues(void) const;

  private:

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

    void _convertValues(void);

    std::string _literalValue;
    unsigned int _type;
    char _charValue;
    int _intValue;
    float _floatValue;
    double _doubleValue;
};
