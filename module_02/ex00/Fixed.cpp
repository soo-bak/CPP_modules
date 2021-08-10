#include "Fixed.hpp"

const int Fixed::_fractionalBitsNumber = 8;

Fixed::Fixed(void)
    : _fixedPointValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& source) {
  if (this == &source) {
    return *this;
  }
  std::cout << "Assignation operator called" << std::endl;
  _fixedPointValue = source.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
  _fixedPointValue = raw;
  return ;
}
