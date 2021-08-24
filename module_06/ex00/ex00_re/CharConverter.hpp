#pragma once

#include "ATypeConverter.hpp"
#include "IntConverter.hpp"
#include "FloatConverter.hpp"

class CharConverter : public ATypeConverter {

  public:

    CharConverter& operator = (const CharConverter& other);

    CharConverter(void);
    CharConverter(const std::string& literal);
    CharConverter(const int& integerNumber);
    CharConverter(const float& floatingNumber);
    CharConverter(const double& doubeNumber);
    CharConverter(const CharConverter& other);
    virtual ~CharConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;
    virtual const std::string& getTypeName(void) const;

  private:

    static const std::string _typeName;

    char _value;
    bool _isDisplayable;
};
