#include <iostream>

#include "ClapTrap.hpp"

int main() {
  {
    ClapTrap clapTrapA("A");
    clapTrapA.displayStatus();
    std::cout << std::endl;

    clapTrapA.attack("target");
    std::cout << std::endl;

    clapTrapA.takeDamage(0);
    clapTrapA.displayStatus();
    std::cout << std::endl;

    clapTrapA.takeDamage(1);
    clapTrapA.displayStatus();
    std::cout << std::endl;

    clapTrapA.takeDamage(8);
    clapTrapA.displayStatus();
    std::cout << std::endl;

    clapTrapA.takeDamage(10);
    clapTrapA.displayStatus();
    std::cout << std::endl;

    clapTrapA.takeDamage(5);
    clapTrapA.displayStatus();
    std::cout << std::endl;
  }

  {
    ClapTrap clapTrapB("B");

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
