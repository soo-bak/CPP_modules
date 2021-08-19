#include "FragTrap.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

FragTrap::FragTrap(void)
    : ClapTrap() {
  _trapType = "FragTrap";
  _hitPoint = 100;
  _energyPoint = 100;
  _attackDamage = 30;
  _maxHitPoint = 100;
  _maxEnergyPoint = 100;
  std::cout << ansiItalic;
  std::cout << "FragTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
  _trapType = "FragTrap";
  _hitPoint = 100;
  _energyPoint = 100;
  _attackDamage = 30;
  _maxHitPoint = 100;
  _maxEnergyPoint = 100;
  std::cout << ansiItalic;
  std::cout << "FragTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

FragTrap::FragTrap(const FragTrap& fragTrap) {
  *this = fragTrap;
  std::cout << ansiItalic;
  std::cout << "FragTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

FragTrap::~FragTrap(void) {
  std::cout << ansiItalic;
  std::cout << "FragTrap <" << _name << "> is disappeared." << std::endl;
  std::cout << ansiEnd;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
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
  return *this;
}

void FragTrap::attack(const std::string& target) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << _name << "> ";
  if (_isBroken()) {
    std::cout << "can't attack. It's broken" << std::endl;
    return ;
  }
  std::cout << "attacks <" << target << "> with water-gun, ";
  std::cout << "causing <" << _attackDamage << "> ";
  std::cout << "points of damage! " << std::endl;
  std::cout << "\"Yeah? Well, hmph.\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}

void FragTrap::highFivesGuys(void) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << _name << "> ";
  std::cout << "offer a high five." << std::endl;
  std::cout << "\"Hey! Over here!, Over here!! I'm over heere!\"" << std::endl;
  std::cout << ansiEnd;
  return ;
}
