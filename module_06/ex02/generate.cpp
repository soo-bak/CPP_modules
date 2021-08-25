#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

const std::string ansiPurple("\033[1;35m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

Base* generate(void) {
  Base* randomBase;
  std::srand(std::time(NULL));
  const int randomValue(std::rand());
  std::cout << "getnerated class is : ";
  if (randomValue % 3 == 1) {
    randomBase = new A();
    std::cout << ansiPurple << "A" << ansiEnd << std::endl;
  } else if (randomValue % 3 == 2) {
    randomBase = new B();
    std::cout << ansiGreen << "B" << ansiEnd << std::endl;
  } else {
    randomBase = new C();
    std::cout << ansiCyan << "C" << ansiEnd << std::endl;
  }
  return randomBase;
}
