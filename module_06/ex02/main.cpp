#include <string>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* P);
void identify(Base& P);

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {

  std::cout << std::endl;
  std::cout << " [ " << ansiRed << "Generate random class" << ansiEnd << " ]" << std::endl;
  std::cout << "   ";
  Base* randomBase = generate();
  std::cout << std::endl;

  std::cout << " [ " << ansiRed << "Identifying by POINTER casting" << ansiEnd << " ]" << std::endl;
  std::cout << "   identified class is : ";
  identify(randomBase);
  std::cout << std::endl;

  std::cout << " [ " << ansiRed << "Identifying by REFERENCE casting" << ansiEnd << " ]" << std::endl;
  Base& reference = *randomBase;
  std::cout << "   identified class is : ";
  identify(reference);
  std::cout << std::endl;

  return 0;
}
