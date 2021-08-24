#pragma once

#include "ATypeConverter.hpp"
#include "CharConverter.hpp"
#include "FloatConverter.hpp"

class IntConverter : public ATypeConverter {

  public:

    IntConverter& operator = (const IntConverter& other);

    IntConverter(void);
    IntConverter(const char& character);
    IntConverter(const std::string& literal);
    IntConverter(const IntConverter& other);
    virtual ~IntConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;

  private:

    int _value;
};
