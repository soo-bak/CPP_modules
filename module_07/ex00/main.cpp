#include <iostream>
#include <string>

#include "whatever.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {

  char a('A');
  char b('B');

  // int a(24);
  // int b(42);

  // float a(24.24f);
  // float b(42.42f);

  // double a(24.2424);
  // double b(42.4242);

  // std::string a("ABCD");
  // std::string b("EFGH");

  std::cout << std::endl;
  std::cout << " [ " << ansiRed << "Intial value" << ansiEnd << " ]" << std::endl;
  std::cout << "   a : " << ansiPurple << a << ansiEnd << std::endl;
  std::cout << "   b : " << ansiCyan << b << ansiEnd << std::endl;
  std::cout << std::endl;
  ::swap(a,b);
  std::cout << " [ " << ansiGreen << "swap(a, b)" << ansiEnd << " ]" << std::endl;
  std::cout << "   a : " << ansiCyan << a << ansiEnd << std::endl;
  std::cout << "   b : " << ansiPurple << b << ansiEnd << std::endl;
  std::cout << std::endl;
  std::cout << " [ " << ansiGreen << "min(a, b)" << ansiEnd << " ]" << std::endl;
  std::cout << "   result : " << ansiPurple << ::min(a, b) << ansiEnd << std::endl;
  std::cout << std::endl;
  std::cout << " [ " << ansiGreen << "max(a, b)" << ansiEnd << " ]" << std::endl;
  std::cout << "   result : " << ansiCyan << ::max(a, b) << ansiEnd << std::endl;
  std::cout << std::endl;

  return 0;
}
