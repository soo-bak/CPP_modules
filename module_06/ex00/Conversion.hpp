#pragma once

#include <cctype>

#include <exception>

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
      TypeListCount
    };

    Conversion& operator = (const Conversion& other);

    Conversion(void);
    Conversion(const std::string& string);
    Conversion(const Conversion& other);
    ~Conversion(void);

    const std::string& getLiteralValue(void) const;
    const unsigned int& getType(void) const;

    unsigned int _findType(const std::string& strng);

  private:

    bool _isPointNumber(const std::string& string);
    bool _isSign(const char& character);
    bool _isDot(const char& character);
    bool _isFloatSuffix(const char& character);

    bool _isTypeChar(const std::string& string);
    bool _isTypeInt(const std::string& string);
    bool _isTypeFloat(const std::string& string);
    bool _isTypeDouble(const std::string& string);


    std::string _literalValue;
    unsigned int _type;
};
