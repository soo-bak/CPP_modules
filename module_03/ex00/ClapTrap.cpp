#include "ClapTrap.hpp"

const unsigned int ClapTrap::_maxHitPoint(10);
const unsigned int ClapTrap::_maxEnergyPoint(10);
const unsigned int ClapTrap::_attackDamage(0);

ClapTrap::ClapTrap(void)
    : _name("unknown"), _hitPoint(_maxHitPoint),
      _energyPoint(_maxEnergyPoint) {
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoint(_maxHitPoint),
      _energyPoint(_maxEnergyPoint) {
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
  *this = clapTrap;
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ClapTrap::~ClapTrap(void) {
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> is disappeared." << std::endl;
  std::cout << ansiEnd;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
  if (this == &other) {
    return *this;
  }
  _name = other._name;
  _hitPoint = other._hitPoint;
  _energyPoint = other._energyPoint;
  return *this;
}

void ClapTrap::attack(const std::string& target) {
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> ";
  if (_isBroken()) {
    std::cout << "can't attack. It's broken" << std::endl;
    return ;
  }
  std::cout << "attacks <" << target << ">, ";
  std::cout << "causing <" << _attackDamage << "> ";
  std::cout << "points of damage! " << std::endl;
  std::cout << ansiEnd;
  return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> ";
  if (_isBroken()) {
    std::cout << "is already broken." << std::endl;
  } else if (amount == 0) {
    std::cout << "is not damaged at all." << std::endl;
  } else {
    unsigned int validAmount(amount);
    if (validAmount >= _hitPoint) {
      validAmount = _hitPoint;
    }
    std::cout << "suffered <" << amount << "> ";
    std::cout << "points of damage! " << std::endl;
    _hitPoint -= validAmount;
    if (_isBroken()) {
      std::cout << "ClapTrap <" << _name << "> ";
      std::cout << "is broken." << std::endl;
    }
  }
  std::cout << ansiEnd;
  return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> ";
  if (_hitPoint == _maxHitPoint) {
    std::cout << "doesn't need to be repaired." << std::endl;
    return ;
  } else if (amount > _energyPoint) {
    std::cout << "doesn't have enough energy to repair <";
    std::cout << amount << "> points. ";
    unsigned int validAmount(_energyPoint);
    if (validAmount != 0) {
      if (validAmount >= (_maxHitPoint - _hitPoint)) {
        validAmount = (_maxHitPoint - _hitPoint);
        std::cout << "And do not need to be repaired <";
        std::cout << amount << ">, ";
      }
      std::cout << "Only <" << validAmount << "> points were repaired.";
      std::cout << std::endl;
      _hitPoint += validAmount;
      _energyPoint -= validAmount;
    }
  }
  std::cout << ansiEnd;
  return ;
}

bool ClapTrap::_isBroken(void) const {
  if (_hitPoint <= 0) {
    return true;
  } else {
    return false;
  }
}

void ClapTrap::displayStatus(void) const {
  std::cout << ansiItalic;
  std::cout << " B";
  std::cout << ansiEnd;
  std::cout << " [ ";
  std::cout << ansiRed;
  std::cout << "HP " << _hitPoint << "  ";
  std::cout << ansiCyan;
  std::cout << "EP " << _energyPoint;
  std::cout << ansiEnd;
  std::cout << " ]";
  std::cout << std::endl;
  return ;
}
