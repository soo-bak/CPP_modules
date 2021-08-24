#pragma once

#include <iostream>
#include <string>

class AType {

  public:

    AType& operator = (const AType& other);

    AType(const std::string& literal);
    AType(const AType& other);
    virtual ~AType();

    virtual void printValue(void) const = 0;

    const std::string& getLiteral(void) const;
    void setLiteral(const std::string& newLiteral);
    const bool& getIsConvertable(void) const;
    void setIsConvertable(const bool& boolean);

  protected:
    std::string _literal;
    bool _isConvertable;

  private:
    AType(void);
};
