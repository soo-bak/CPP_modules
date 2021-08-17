#include "ScavTrap.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

const unsigned int ScavTrap::_maxHitPoint(100);
const unsigned int ScavTrap::_maxEnergyPoint(50);
const unsigned int ScavTrap::_attackDamage(20);

ScavTrap::ScavTrap(void)
    : ClapTrap("unknown", _maxHitPoint, _maxEnergyPoint) {
  std::cout << ansiItalic;
  std::cout << "ScavTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ScavTrap::~ScavTrap(void) {
}
