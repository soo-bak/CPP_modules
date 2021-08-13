#include <iostream>
#include <iomanip>

#include "Fixed.hpp"

const std::string colorRed("\033[1;31m");
const std::string colorCyan("\033[1;36m");
const std::string colorEnd("\033[0m");

int main() {

  {
    std::cout << colorCyan << "-----------------------------------";
    std::cout << colorEnd << std::endl;

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << std::setw(15) << "a : ";
    std::cout << a << std::endl;
    std::cout << std::setw(15) << "++a : ";
    std::cout << ++a << std::endl;
    std::cout << std::setw(15) << "a : ";
    std::cout << a << std::endl;
    std::cout << std::setw(15) << "a++ : ";
    std::cout << a++ << std::endl;
    std::cout << std::setw(15) << "a : ";
    std::cout << a << std::endl;

    std::cout << std::setw(15) << "b : ";
    std::cout << b << std::endl;

    std::cout << std::setw(15) << "max(a, b) : ";
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << std::setw(15) << "min(a, b) : ";
    std::cout << Fixed::min(a, b) << std::endl;

    std::cout << colorCyan << "-----------------------------------";
    std::cout << colorEnd << std::endl;
  }
  {
    std::cout << colorRed << "-----------------------------------";
    std::cout << colorEnd << std::endl;

    Fixed a(10);
    Fixed b(5.5f);
    Fixed c(10.0f);

    std::cout << std::setw(15) << "a : ";
    std::cout << a << std::endl;
    std::cout << std::setw(15) << "b : ";
    std::cout << b << std::endl;
    std::cout << std::setw(15) << "c : ";
    std::cout << c << std::endl;

    std::cout << std::setw(15) << "a > b : ";
    std::cout << (a > b) << std::endl;
    std::cout << std::setw(15) << "a < b : ";
    std::cout << (a < b) << std::endl;
    std::cout << std::setw(15) << "c >= a : ";
    std::cout << (c >= a) << std::endl;
    std::cout << std::setw(15) << "c <= a : ";
    std::cout << (c <= a) << std::endl;
    std::cout << std::setw(15) << "c == a : ";
    std::cout << (c == a) << std::endl;
    std::cout << std::setw(15) << "c != a : ";
    std::cout << (c != a) << std::endl;

    std::cout << colorRed << "-----------------------------------";
    std::cout << colorEnd << std::endl;
  }
  {
    std::cout << colorCyan << "-----------------------------------";
    std::cout << colorEnd << std::endl;

    Fixed a(10);
    Fixed b(2.5f);

    std::cout << std::setw(15) << "a : ";
    std::cout << a << std::endl;
    std::cout << std::setw(15) << "b : ";
    std::cout << b << std::endl;

    std::cout << std::setw(15) << "a + b : ";
    std::cout << a + b << std::endl;
    std::cout << std::setw(15) << "a - b : ";
    std::cout << a - b << std::endl;
    std::cout << std::setw(15) << "a * b : ";
    std::cout << a * b << std::endl;
    std::cout << std::setw(15) << "a / b : ";
    std::cout << a / b << std::endl;

    std::cout << colorCyan << "-----------------------------------";
    std::cout << colorEnd << std::endl;
  }


  return 0;
}
