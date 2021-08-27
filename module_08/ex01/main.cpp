#include <exception>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Span.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {
  const unsigned int testSize = 10000;
  Span testSpan(testSize);

  std::vector<int>::iterator begin;
  begin = testSpan.getElements().begin();
  std::vector<int>::iterator end;
  end = begin + testSize;

  testSpan.addNumber(begin, end - 1);
  // testSpan.addNumber(begin, end - 1, 1);
  testSpan.addNumber(42);

  for (unsigned int i = 0; i < testSpan.getElements().size(); i++) {
    std::cout << testSpan.getElements().at(i) << std::endl;
  }

  return 0;
}
