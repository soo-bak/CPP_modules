#pragma once

#include "ATypeConverter.hpp"

class CharConverter : public ATypeConverter {

  public:

    CharConverter& operator = (const CharConverter& other);

    CharConverter(void);
    CharConverter(const std::string& string);
    CharConverter(const CharConverter& other);
    virtual ~CharConverter();

    virtual void printValue(void) const;

    const bool& getIsDisplayable(void) const;
    void setIsDisplayable(const bool& boolean);

  private:

    char _value;
    bool _isDisplayable;
};
