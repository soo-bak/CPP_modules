#include <iostream>

#include "ScavTrap.hpp"

int main() {
  ScavTrap scavTrap("SC4V-TP");

  scavTrap.attack("5H4D0W-TP");
  scavTrap.displayStatus();
  scavTrap.takeDamage(2);
  scavTrap.displayStatus();
  scavTrap.beRepaired(49);
  scavTrap.displayStatus();
  scavTrap.guardGate();
  return 0;
}
