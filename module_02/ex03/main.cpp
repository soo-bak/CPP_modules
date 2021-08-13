#include <iostream>

#include "Point.hpp"

const std::string colorRed("\033[1;31m");
const std::string colorCyan("\033[1;36m");
const std::string colorYellow("\033[1;33m");
const std::string colorEnd("\033[0m");

bool bsp(const Point a, const Point b, const Point c,
         const Point point);

int main() {
  {
    Point a(128, 2);
    Point b(481, 142);
    Point c(14, 164);

    Point point(250, 250);

    std::cout << colorRed;
    std::cout << "-------case 1---------" << std::endl;
    std::cout << colorEnd;
    if (bsp(a, b, c, point) == true) {
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
    std::cout << colorRed;
    std::cout << "----------------------" << std::endl;
    std::cout << colorEnd;
  }

  {
    Point a(67, 172);
    Point b(277, 94);
    Point c(314, 497);

    Point point(250, 250);

    std::cout << colorCyan;
    std::cout << "-------case 2---------" << std::endl;
    std::cout << colorEnd;
    if (bsp(a, b, c, point) == true) {
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
    std::cout << colorCyan;
    std::cout << "----------------------" << std::endl;
    std::cout << colorEnd;
  }

  {
    Point a(279, 81);
    Point b(296, 281);
    Point c(391, 473);

    Point point(250, 250);

    std::cout << colorYellow;
    std::cout << "-------case 3---------" << std::endl;
    std::cout << colorEnd;
    if (bsp(a, b, c, point) == true) {
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
    std::cout << colorYellow;
    std::cout << "----------------------" << std::endl;
    std::cout << colorEnd;
  }

  return 0;
}
