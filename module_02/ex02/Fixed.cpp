#include "Fixed.hpp"

const int Fixed::_fractionalBitsNumber = 8;

Fixed::Fixed(void)
    : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int& value)
    : _rawBits(value << _fractionalBitsNumber) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float& value) {
  std::cout << "Float constructor called" << std::endl;
  const int scailingFactor(1 << _fractionalBitsNumber);
  _rawBits = static_cast<int>(roundf(value * scailingFactor));
}

Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other) {
  std::cout << "Assignation operator called" << std::endl;
  if (this == &other) {
    return *this;
  }
  _rawBits = other.getRawBits();
  return *this;
}

Fixed Fixed::operator + (const Fixed& fixed) {
  Fixed result;
  result._rawBits = (this->_rawBits + fixed._rawBits);
  return result;
}

Fixed Fixed::operator - (const Fixed& fixed) {
  Fixed result;
  result._rawBits = (this->_rawBits - fixed._rawBits);
}

Fixed Fixed::operator * (const Fixed& fixed) {


}

Fixed Fixed::operator / (const Fixed& fixed) {

}

float Fixed::toFloat(void) const {
  const int scailingFactor(1 << _fractionalBitsNumber);
  return (static_cast<float>(_rawBits) / scailingFactor);
}

int Fixed::toInt(void) const {
  return _rawBits >> _fractionalBitsNumber;
}

int Fixed::getRawBits(void) const {
  return _rawBits;
}

void Fixed::setRawBits(int const raw) {
  _rawBits = raw;
  return ;
}

std::ostream& operator << (std::ostream& outStream,
                           const Fixed& object) {
  outStream << object.toFloat();
  return outStream;
}
