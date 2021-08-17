#include <iostream>

#include "ClapTrap.hpp"

int main() {
  {
    ClapTrap clapTrap("CL4P-L3K");
    clapTrap.displayStatus();
    std::cout << std::endl;

    clapTrap.attack("5H4D0W-TP");
    std::cout << std::endl;

    clapTrap.takeDamage(0);
    clapTrap.displayStatus();
    std::cout << std::endl;

    clapTrap.takeDamage(1);
    clapTrap.displayStatus();
    std::cout << std::endl;

    clapTrap.takeDamage(8);
    clapTrap.displayStatus();
    std::cout << std::endl;

    clapTrap.takeDamage(10);
    clapTrap.displayStatus();
    std::cout << std::endl;

    clapTrap.takeDamage(5);
    clapTrap.displayStatus();
    std::cout << std::endl;
  }

  {
    ClapTrap clapTrapB("CL4P-L3K");

    clapTrapB.takeDamage(5);
    clapTrapB.displayStatus();
    std::cout << std::endl;

    clapTrapB.beRepaired(0);
    clapTrapB.displayStatus();
    std::cout << std::endl;

    clapTrapB.beRepaired(4);
    clapTrapB.displayStatus();
    std::cout << std::endl;

    clapTrapB.beRepaired(20);
    clapTrapB.displayStatus();
    std::cout << std::endl;

    clapTrapB.takeDamage(20);
    clapTrapB.displayStatus();
    std::cout << std::endl;

    clapTrapB.beRepaired(10);
    clapTrapB.displayStatus();
    std::cout << std::endl;
  }

  return 0;
}
