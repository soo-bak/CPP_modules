#pragma once

#include "ATypeConverter.hpp"
#include "IntConverter.hpp"

class CharConverter : public ATypeConverter {

  public:

    CharConverter& operator = (const CharConverter& other);

    CharConverter(void);
    CharConverter(const std::string& literal);
    CharConverter(const CharConverter& other);
    virtual ~CharConverter();

    virtual void printValue(void) const;
    virtual void convert(void) const;

    const bool& getIsDisplayable(void) const;
    void setIsDisplayable(const bool& boolean);

  private:

    char _value;
    bool _isDisplayable;
};
