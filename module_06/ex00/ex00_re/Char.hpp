#pragma once

#include "AType.hpp"

class Char : public AType {

  public:

    Char& operator = (const Char& other);

    Char(void);
    Char(const std::string& string);
    Char(const Char& other);
    virtual ~Char();

    virtual void printValue(void) const;

    const bool& getIsConvertable(void) const;
    const bool& getIsDisplayable(void) const;
    void setIsConvertable(const bool& boolean);
    void setIsDisplayable(const bool& boolean);
  private:


    char _value;
    bool _isDisplayable;
};
