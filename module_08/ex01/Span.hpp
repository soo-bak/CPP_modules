#pragma once

#include <vector>
#include <algorithm>
#include <exception>

class Span {
  public:

    Span& operator = (const Span& other);

    Span(void);
    Span(const unsigned int& size);
    Span(const Span& other);
    ~Span();

    void addNumber(const int& newNumber);

  private:
    unsigned int _size;
    std::vector<int> _numbers;
};
