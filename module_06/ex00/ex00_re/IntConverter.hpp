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
    virtual const std::string& getTypeName(void) const;

  private:

    static const std::string _typeName;

    int _value;
};
