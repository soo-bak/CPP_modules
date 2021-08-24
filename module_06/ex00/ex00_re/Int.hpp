#pragma once

#include "AType.hpp"

class Int : public AType {

  public:

    Int& operator = (const Int& other);

    Int(void);
    Int(const std::string& string);
    Int(const Int& other);
    virtual ~Int();

    virtual void printValue(void) const;

  private:

    int _value;
};
