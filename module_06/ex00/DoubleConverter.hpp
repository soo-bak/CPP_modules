#pragma once

#include <cmath>

#include "ATypeConverter.hpp"
#include "CharConverter.hpp"
#include "IntConverter.hpp"
#include "FloatConverter.hpp"

class DoubleConverter : public ATypeConverter {

  public:
    enum {
      NegativeInfinity,
      PositiveInfinity,
      NotANumber,
      NotApplicable
    };

    DoubleConverter& operator = (const DoubleConverter& other);

    DoubleConverter(void);
    DoubleConverter(const char& character);
    DoubleConverter(const int& integerNumber);
    DoubleConverter(const float& floatingNumber,
                    const int& precision);
    DoubleConverter(const std::string& literal);
    DoubleConverter(const DoubleConverter& other);
    virtual ~DoubleConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;

  private:

    double _value;
    int _precision;
    unsigned int _nonRepresentableValue;
};
