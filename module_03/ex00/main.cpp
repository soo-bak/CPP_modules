#include <iostream>

#include "ClapTrap.hpp"



int main() {
  ClapTrap clapTrapA;
  ClapTrap clapTrapB("B");

  clapTrapB.attack("target");
  clapTrapB.displayStatus();
  clapTrapB.takeDamage(0);
  clapTrapB.displayStatus();
  clapTrapB.takeDamage(1);
  clapTrapB.displayStatus();
  clapTrapB.takeDamage(8);
  clapTrapB.displayStatus();
  clapTrapB.takeDamage(10);
  clapTrapB.displayStatus();
  clapTrapB.takeDamage(10);
  clapTrapB.displayStatus();

  return 0;
}
