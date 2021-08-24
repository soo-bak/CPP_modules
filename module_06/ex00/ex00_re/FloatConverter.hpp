#pragma once

#include "ATypeConverter.hpp"
#include "CharConverter.hpp"
#include "IntConverter.hpp"

class FloatConverter : public ATypeConverter {

  public:

    FloatConverter& operator = (const FloatConverter& other);

    FloatConverter(void);
    FloatConverter(const char& character);
    FloatConverter(const std::string& literal);
    FloatConverter(const FloatConverter& other);
    virtual ~FloatConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;

  private:

    float _value;
};
