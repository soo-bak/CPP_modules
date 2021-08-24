#pragma once

#include <iostream>
#include <string>

class ATypeConverter {

  public:

    ATypeConverter& operator = (const ATypeConverter& other);

    ATypeConverter(void);
    ATypeConverter(const std::string& literal);
    ATypeConverter(const ATypeConverter& other);
    virtual ~ATypeConverter();

    virtual void printValue(void) const = 0;

    const std::string& getTypeName(void) const;
    void setTypeName(const std::string& newLiteral);
    const bool& getIsConvertable(void) const;
    void setIsConvertable(const bool& boolean);

  protected:

    std::string _typeName;
    bool _isConvertable;
};
