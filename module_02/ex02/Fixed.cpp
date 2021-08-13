#include "Fixed.hpp"

const int Fixed::_fractionalBitsNumber = 8;

Fixed& Fixed::min(Fixed& one, Fixed& two) {
  return (one <= two ? one : two);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two) {
  return (one <= two ? one : two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two) {
  return (one >= two ? one : two);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two) {
  return (one >= two ? one : two);
}

Fixed::Fixed(void)
    : _rawBits(0) {
}

Fixed::Fixed(const int& value)
    : _rawBits(value << _fractionalBitsNumber) {
}

Fixed::Fixed(const float& value) {
  const int scailingFactor(1 << _fractionalBitsNumber);
  _rawBits = static_cast<int>(roundf(value * scailingFactor));
}

Fixed::Fixed(const Fixed& fixed) {
  *this = fixed;
}

Fixed::~Fixed(void) {
}

Fixed& Fixed::operator = (const Fixed& other) {
  if (this == &other) {
    return *this;
  }
  _rawBits = other._rawBits;
  return *this;
}

bool Fixed::operator > (const Fixed& other) const {
  return _rawBits > other._rawBits;
}

bool Fixed::operator < (const Fixed& other) const {
  return _rawBits < other._rawBits;
}

bool Fixed::operator >= (const Fixed& other) const {
  return !(_rawBits < other._rawBits);
}

bool Fixed::operator <= (const Fixed& other) const {
  return !(_rawBits > other._rawBits);
}

bool Fixed::operator == (const Fixed& other) const {
  return _rawBits == other._rawBits;
}

bool Fixed::operator != (const Fixed& other) const {
  return !(_rawBits == other._rawBits);
}

const Fixed Fixed::operator + (const Fixed& other) const {
  Fixed result(*this);
  result._rawBits += other._rawBits;
  return result;
}

const Fixed Fixed::operator - (const Fixed& other) const {
  Fixed result(*this);
  result._rawBits -= other._rawBits;
  return result;
}

const Fixed Fixed::operator * (const Fixed& other) const {
  Fixed result(*this);
  long long temp(result._rawBits);
  temp *= other._rawBits;
  const int scailingFactor(1 << _fractionalBitsNumber);
  temp /= scailingFactor;
  result._rawBits = static_cast<int>(temp);
  return result;
}

const Fixed Fixed::operator / (const Fixed& other) const {
  Fixed result(*this);
  if (other._rawBits == 0) {
    result._rawBits = 0;
  } else {
    long long temp(result._rawBits);
    const int scailingFactor(1 << _fractionalBitsNumber);
    temp *= scailingFactor;
    temp /= other._rawBits;
    result._rawBits = static_cast<int>(temp);
  }
  return result;
}

Fixed& Fixed::operator ++ (void) {
  ++_rawBits;
  return *this;
}

Fixed Fixed::operator ++ (int) {
  Fixed temp(*this);
  ++(*this);
  return temp;
}

Fixed& Fixed::operator -- (void) {
  --_rawBits;
  return *this;
}

Fixed Fixed::operator -- (int) {
  Fixed temp(*this);
  --(*this);
  return temp;
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
