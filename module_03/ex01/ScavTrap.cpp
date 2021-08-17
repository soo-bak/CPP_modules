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
  std::cout << "ScavTrap <" << _name << "> appeared." << std::endl;
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
  std::cout << "ScavTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ScavTrap::~ScavTrap(void) {
  std::cout << ansiItalic;
  std::cout << "ScavTrap <" << _name << "> is disappeared." << std::endl;
  std::cout << ansiEnd;
}

void ScavTrap::attack(const std::string& target) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << _name << "> ";
  if (_isBroken()) {
    std::cout << "can't attack. It's broken" << std::endl;
    return ;
  }
  std::cout << "scav attacks <" << target << ">, ";
  std::cout << "causing <" << _attackDamage << "> ";
  std::cout << "points of damage! ";
  std::cout << "Yoo hoooooooooo!" << std::endl;
  std::cout << ansiEnd;
  return ;
}

void ScavTrap::guardGate(void) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << _name << "> ";
  std::cout << "entered in Gate keeper mode." << std::endl;
  std::cout << ansiEnd;
  return ;
}
