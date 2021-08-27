#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span {
  public:

    Span& operator = (const Span& other);

    Span(void);
    Span(const unsigned int& maxSize);
    Span(const Span& other);
    ~Span();

    void addNumber(const int& newNumber);
    void addNumber(std::vector<int>::iterator start,
                   std::vector<int>::iterator end);
    void addNumber(std::vector<int>::iterator start,
                   std::vector<int>::iterator end,
                   const int& newNumber);
    std::vector<int> getElements(void) const;

  private:
    unsigned int _maxSize;
    std::vector<int> _elements;
};
