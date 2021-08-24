#pragma once

#include "ATypeConverter.hpp"
#include "CharConverter.hpp"
#include "IntConverter.hpp"

class DoubleConverter : public ATypeConverter {

  public:

    DoubleConverter& operator = (const DoubleConverter& other);

    DoubleConverter(void);
    DoubleConverter(const char& character);
    DoubleConverter(const int& integerNumber);
    DoubleConverter(const float& doubleNumber);
    DoubleConverter(const std::string& literal);
    DoubleConverter(const DoubleConverter& other);
    virtual ~DoubleConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;

  private:

    double _value;
};