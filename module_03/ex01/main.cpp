#include <iostream>

#include "ScavTrap.hpp"

int main() {
  ScavTrap scavTrap("SC4V-TP");

  scavTrap.displayStatus();
  std::cout << std::endl;

  scavTrap.attack("5H4D0W-TP");
  scavTrap.displayStatus();
  std::cout << std::endl;

  scavTrap.takeDamage(42);
  scavTrap.displayStatus();
  std::cout << std::endl;

  scavTrap.takeDamage(84);
  scavTrap.displayStatus();
  std::cout << std::endl;

  scavTrap.beRepaired(48);
  scavTrap.displayStatus();
  std::cout << std::endl;

  scavTrap.beRepaired(3);
  scavTrap.displayStatus();
  std::cout << std::endl;

  scavTrap.guardGate();
  std::cout << std::endl;

  return 0;
}
