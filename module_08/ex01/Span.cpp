#include "Span.hpp"

Span& Span::operator = (const Span& other) {
  if (this == &other) {
    return *this;
  }
  _size = other._size;
  _numbers = other._numbers;
  return *this;
}

Span::Span(void)
    : _size(0), _numbers(0) {
}

Span::Span(const unsigned int& sizeInput)
    : _size(sizeInput), _numbers(0) {
}

Span::Span(const Span& other)
    : _size(other._size), _numbers(other._numbers) {
}

Span::~Span() {
}

void Span::addNumber(const int& newNumber) {
  if (_numbers.size() >= _size) {
    throw std::exception();
  }
  _numbers.push_back(newNumber);
  return ;
}
