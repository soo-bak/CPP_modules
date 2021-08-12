#pragma once

#include <iostream>
#include <cmath>

class Fixed {
  public:
    Fixed(void);
    Fixed(const int& value);
    Fixed(const float& value);
    Fixed(const Fixed& fixed);
    ~Fixed(void);

    Fixed& operator = (const Fixed& other);

    Fixed operator + (const Fixed& fixed);
    Fixed operator - (const Fixed& fixed);
    Fixed operator * (const Fixed& fixed);
    Fixed operator / (const Fixed& fixed);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    static const int _fractionalBitsNumber;

    int _rawBits;
};

std::ostream& operator << (std::ostream& outStream,
                           const Fixed& object);
