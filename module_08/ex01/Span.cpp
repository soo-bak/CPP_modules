#include "Span.hpp"

Span& Span::operator = (const Span& other) {
  if (this == &other) {
    return *this;
  }
  _maxSize = other._maxSize;
  _elements = other._elements;
  return *this;
}

Span::Span(void)
    : _maxSize(0), _elements(0) {
}

Span::Span(const unsigned int& sizeInput)
    : _maxSize(sizeInput), _elements(0) {
}

Span::Span(const Span& other)
    : _maxSize(other._maxSize), _elements(other._elements) {
}

Span::~Span() {
}

void Span::addNumber(const int& newNumber) {
  if (_elements.size() >= _maxSize) {
    throw std::exception();
  }
  _elements.push_back(newNumber);
  return ;
}

void Span::addNumber(std::vector<int>::iterator start,
                     std::vector<int>::iterator end) {
  std::vector<int>::iterator i;
  i = start;
  int value(1);
  while (i < end) {
    addNumber(value);
    i++;
    value++;
  }
  return ;
}

void Span::addNumber(std::vector<int>::iterator start,
                     std::vector<int>::iterator end,
                     const int& newNumber) {
  std::vector<int>::iterator i;
  i = start;
  while (i < end) {
    addNumber(newNumber);
    i++;
  }
  return ;
}

std::vector<int> Span::getElements(void) const {
  return _elements;
}
