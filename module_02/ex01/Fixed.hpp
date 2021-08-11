#include <iostream>
#include <cmath>

class Fixed {
  public:
    Fixed(void);
    Fixed(const Fixed& fixed);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed& operator = (const Fixed& source);

  private:
    static const int _fractionalBitsNumber;

    int _fixedPointValue;
};
