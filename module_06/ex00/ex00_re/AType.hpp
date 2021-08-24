#pragma once

#include <iostream>
#include <string>

class AType {

  public:

    AType& operator = (const AType& other);

    AType(void);
    AType(const std::string& literal);
    AType(const AType& other);
    virtual ~AType();

    virtual void printValue(void) const = 0;

    const std::string& getTypeName(void) const;
    void setTypeName(const std::string& newLiteral);
    const bool& getIsConvertable(void) const;
    void setIsConvertable(const bool& boolean);

  protected:
    std::string _typeName;
    bool _isConvertable;
};
