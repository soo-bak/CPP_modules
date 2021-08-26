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
  Span testSpan(5);

  testSpan.addNumber(1);
  testSpan.addNumber(2);
  testSpan.addNumber(3);
  testSpan.addNumber(4);
  testSpan.addNumber(5);


  return 0;
}
