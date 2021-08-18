#include "FragTrap.hpp"

#include <iostream>

int main() {
  FragTrap fragTrap("FR49-TP");

  fragTrap.displayStatus();
  std::cout << std::endl;

  fragTrap.attack("5H4D0W-TP");
  fragTrap.displayStatus();
  std::cout << std::endl;

  fragTrap.takeDamage(42);
  fragTrap.displayStatus();
  std::cout << std::endl;

  fragTrap.takeDamage(84);
  fragTrap.displayStatus();
  std::cout << std::endl;

  fragTrap.beRepaired(48);
  fragTrap.displayStatus();
  std::cout << std::endl;

  fragTrap.beRepaired(123);
  fragTrap.displayStatus();
  std::cout << std::endl;

  fragTrap.highFivesGuys();
  std::cout << std::endl;

  return 0;
}
