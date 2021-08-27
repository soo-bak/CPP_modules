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

unsigned long Span::shortestSpan(void) {
  if (_elements.size() <= 1) {
    throw std::exception();
  }
  std::sort(_elements.begin(), _elements.end());
  std::vector<unsigned long> spans;
  for (unsigned int i = 0; i < _elements.size(); i++) {
    unsigned long span;
    span = _elements[i + 1] - _elements[i];
    spans.push_back(span);
  }
  const unsigned long shortestSpan = *std::min_element(spans.begin(), spans.end());
  if (shortestSpan == 0) {
    throw std::exception();
  }
  return shortestSpan;
}

unsigned long Span::longestSpan(void) {
  if (_elements.size() <= 1) {
    throw std::exception();
  }
  int max;
  max = *std::max_element(_elements.begin(), _elements.end());
  int min;
  min = *std::min_element(_elements.begin(), _elements.end());
  const unsigned long longestSpan(max - min);
  if (longestSpan == 0) {
    throw std::exception();
  }
  return longestSpan;
}

std::vector<int> Span::getElements(void) const {
  return _elements;
}
