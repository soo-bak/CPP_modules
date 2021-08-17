#include <iostream>

#include "ScavTrap.hpp"

int main() {
  ScavTrap a("nvnvn");

  a.attack("asdf");
  a.displayStatus();
  a.takeDamage(100);
  a.displayStatus();
  a.beRepaired(49);
  a.displayStatus();

}
