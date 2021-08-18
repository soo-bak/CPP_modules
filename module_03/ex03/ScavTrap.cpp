#include "ScavTrap.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

ScavTrap::ScavTrap(void)
    : ClapTrap() {
  _trapType = "ScavTrap";
  _hitPoint = 100;
  _energyPoint = 50;
  _attackDamage = 20;
  _maxHitPoint = 100;
  _maxEnergyPoint = 50;
  std::cout << ansiItalic;
  std::cout << "ScavTrap <" << getName() << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ScavTrap::ScavTrap(const std::string& name)
  : ClapTrap(name) {
  _trapType = "ScavTrap";
  _hitPoint = 100;
  _energyPoint = 50;
  _attackDamage = 20;
  _maxHitPoint = 100;
  _maxEnergyPoint = 50;
  std::cout << ansiItalic;
  std::cout << "ScavTrap <" << getName() << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
  *this = scavTrap;
  std::cout << ansiItalic;
  std::cout << "ScavTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ScavTrap::~ScavTrap(void) {
  std::cout << ansiItalic;
  std::cout << "ScavTrap <" << getName() << "> is disappeared." << std::endl;
  std::cout << ansiEnd;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other) {
  if (this == &other) {
    return *this;
  }
  _name = other._name;
  _trapType = other._trapType;
  _hitPoint = other._hitPoint;
  _energyPoint = other._energyPoint;
  _attackDamage = other._attackDamage;
  _maxHitPoint = other._maxHitPoint;
  _maxEnergyPoint = other._maxEnergyPoint;
}

void ScavTrap::attack(const std::string& target) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << getName() << "> ";
  if (_isBroken()) {
    std::cout << "can't attack. It's broken" << std::endl;
    return ;
  }
  std::cout << "attacks <" << target << "> with bubble-gun, ";
  std::cout << "causing <" << _attackDamage << "> ";
  std::cout << "points of damage!" << std::endl;
  std::cout << "\"Yoo hoooooooooo!\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}

void ScavTrap::guardGate(void) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << getName() << "> ";
  std::cout << "entered in Gate keeper mode." << std::endl;
  std::cout << "\"Please don't shoot me, please don't shoot me!\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
