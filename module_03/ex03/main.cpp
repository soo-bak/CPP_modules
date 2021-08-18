#include <iostream>

#include "DiamondTrap.hpp"

int main() {
  DiamondTrap diamondTrap("D14M0ND-TP");

  diamondTrap.displayStatus();
  std::cout << std::endl;

  diamondTrap.attack("5H4D0W-TP");
  diamondTrap.displayStatus();
  std::cout << std::endl;

  diamondTrap.whoAmI();
  std::cout << std::endl;

  return 0;
}
