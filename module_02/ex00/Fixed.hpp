#pragma once

#include <iostream>

class Fixed {
  public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed& fixed);

    Fixed& operator = (const Fixed& source);

    int getRawBits(void) const;
    void setRawBits(int const raw);


  private:
    static const int _fractionalBitsNumber;
    int _rawBits;
};
