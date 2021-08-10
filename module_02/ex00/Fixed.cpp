#include "Fixed.hpp"

const int Fixed::fractionalBitsNumber = 8;

Fixed::Fixed(void)
 : fixedPointValue(0) {
}

Fixed::Fixed(const Fixed& fixed)
  : fixedPointValue(fixed.fixedPointValue) {
}

Fixed::~Fixed(void) {
}

Fixed& Fixed::operator = (const Fixed& source) {

}
