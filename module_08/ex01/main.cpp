#include <exception>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Span.hpp"

int main() {
  const unsigned int testSize = 10000;
  Span testSpan(testSize);

  std::vector<int>::iterator begin;
  begin = testSpan.getElements().begin();
  std::vector<int>::iterator end;
  end = begin + testSize;

  testSpan.addNumber(begin, end - 1);
  testSpan.addNumber(10042);

  // testSpan.addNumber(5);
  // testSpan.addNumber(3);
  // testSpan.addNumber(17);
  // testSpan.addNumber(9);
  // testSpan.addNumber(11);

  for (unsigned int i = 0; i < testSpan.getElements().size(); i++) {
    std::cout << "Element [" << i << "] : ";
    std::cout << testSpan.getElements().at(i) << std::endl;
  }

  std::cout << "Shortest span : " << testSpan.shortestSpan() << std::endl;
  std::cout << "Longest span : " << testSpan.longestSpan() << std::endl;

  return 0;
}
