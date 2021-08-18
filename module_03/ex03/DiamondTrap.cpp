#include "DiamondTrap.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

DiamondTrap::DiamondTrap(void) {
  std::cout << ansiItalic;
  std::cout << "DiamondTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name") {
  _name = name;
  _trapType = "DiamondTrap";
  _hitPoint = FragTrap::_maxHitPoint;
  _energyPoint = ScavTrap::_maxEnergyPoint;
  _attackDamage = FragTrap::_attackDamage;
  std::cout << ansiItalic;
  std::cout << "DiamondTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << ansiItalic;
  std::cout << "DiamondTrap <" << _name << "> disappeared." << std::endl;
  std::cout << ansiEnd;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
  return ;
}

void DiamondTrap::whoAmI(void) {
  std::cout << ansiItalic;
  std::cout << "DiamondTrap <" << _name << "> introduce himself." << std::endl;
  std::cout << "\"Hey, I'm " << _name;
  std::cout <<  " ...! and A.K.A. " << ClapTrap::_name;
  std::cout << "!!!\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}

std::string DiamondTrap::getName(void) const {
  return _name;
}

void DiamondTrap::setName(const std::string& name) {
  _name = name;
  return ;
}
