#pragma once

#include "ATypeConverter.hpp"
#include "IntConverter.hpp"
#include "FloatConverter.hpp"
#include "DoubleConverter.hpp"

class CharConverter : public ATypeConverter {

  public:

    CharConverter& operator = (const CharConverter& other);

    CharConverter(void);
    CharConverter(const std::string& literal);
    CharConverter(const int& integerNumber);
    CharConverter(const float& floatingNumber);
    CharConverter(const double& doubleNumber);
    CharConverter(const CharConverter& other);
    virtual ~CharConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;

  private:

    char _castToChar(const double& number);

    char _value;
    bool _isDisplayable;
};
