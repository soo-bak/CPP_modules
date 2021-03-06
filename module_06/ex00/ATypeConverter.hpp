#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>

class ATypeConverter {

  public:

    ATypeConverter& operator = (const ATypeConverter& other);

    ATypeConverter(void);
    ATypeConverter(const std::string& literal);
    ATypeConverter(const ATypeConverter& other);
    virtual ~ATypeConverter();

    virtual void printValue(void) const = 0;
    virtual void convert(void) const = 0;

    const std::string& getTypeName(void) const;
    void setIsConvertable(const bool& boolean);

  protected:

    void _setTypeName(const std::string& typeName);

    std::string _literal;
    std::string _typeName;
    bool _isConvertable;
};
