#pragma once

#include <iostream>
#include <cmath>

class Fixed {
  public:
    static Fixed& min(Fixed& one, Fixed& two);
    static const Fixed& min(const Fixed& one, const Fixed& two);
    static Fixed& max(Fixed& one, Fixed& two);
    static const Fixed& max(const Fixed& one, const Fixed& two);

    Fixed(void);
    Fixed(const int& value);
    Fixed(const float& value);
    Fixed(const Fixed& fixed);
    ~Fixed(void);

    Fixed& operator = (const Fixed& other);

    bool operator > (const Fixed& other) const;
    bool operator < (const Fixed& other) const;
    bool operator >= (const Fixed& other) const;
    bool operator <= (const Fixed& other) const;
    bool operator == (const Fixed& other) const;
    bool operator != (const Fixed& other) const;

    const Fixed operator + (const Fixed& other) const;
    const Fixed operator - (const Fixed& other) const;
    const Fixed operator * (const Fixed& other) const;
    const Fixed operator / (const Fixed& other) const;

    Fixed& operator ++ (void);
    Fixed operator ++ (int);
    Fixed& operator -- (void);
    Fixed operator -- (int);

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
