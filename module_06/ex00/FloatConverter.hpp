#pragma once

#include "ATypeConverter.hpp"
#include "CharConverter.hpp"
#include "IntConverter.hpp"
#include "DoubleConverter.hpp"

class FloatConverter : public ATypeConverter {

  public:
    enum {
      NegativeInfinity,
      PositiveInfinity,
      NotANumber,
      NotApplicable
    };

    FloatConverter& operator = (const FloatConverter& other);

    FloatConverter(void);
    FloatConverter(const char& character);
    FloatConverter(const int& integerNumber);
    FloatConverter(const double& doubleNumber,
                   const int& precision);
    FloatConverter(const std::string& literal);
    FloatConverter(const FloatConverter& other);
    virtual ~FloatConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;

    void setNonRepresentableValue(const unsigned int& value);

  private:

    float _value;
    int _precision;
    unsigned int _nonRepresentableValue;
};
