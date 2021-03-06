#include "ClapTrap.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiRed("\033[1;31m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

ClapTrap::ClapTrap(void)
    : _name("unknown"), _trapType("ClapTrap"), _hitPoint(10),
      _energyPoint(10), _attackDamage(0),
      _maxHitPoint(10), _maxEnergyPoint(10)  {
  std::cout << ansiItalic;
  std::cout << "ClapTrap <" << _name << "> appeared." << std::endl;
  std::cout << ansiEnd;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _trapType("ClapTrap"), _hitPoint(10),
      _energyPoint(10), _attackDamage(0),
      _maxHitPoint(10), _maxEnergyPoint(10) {
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
  _trapType = other._trapType;
  _hitPoint = other._hitPoint;
  _energyPoint = other._energyPoint;
  _attackDamage = other._attackDamage;
  _maxHitPoint = other._maxHitPoint;
  _maxEnergyPoint = other._maxEnergyPoint;
  return *this;
}

void ClapTrap::attack(const std::string& target) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << _name << "> ";
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
  std::cout << _trapType << " <" << _name << "> ";
  if (_isBroken()) {
    std::cout << "is already broken." << std::endl;
  } else if (amount == 0) {
    std::cout << "is attacked, but not damaged at all." << std::endl;
  } else {
    unsigned int validAmount(amount);
    if (amount >= _hitPoint) {
      validAmount = _hitPoint;
    }
    std::cout << "suffered <" << amount << "> ";
    std::cout << "points of damage! " << std::endl;
    _hitPoint -= validAmount;
    if (_isBroken()) {
      std::cout << _trapType << " <" << _name << "> ";
      std::cout << "is broken." << std::endl;
    }
  }
  std::cout << ansiEnd;
  return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << ansiItalic;
  std::cout << _trapType << " <" << _name << "> ";
  if (_hitPoint == _maxHitPoint) {
    std::cout << "doesn't need to be repaired." << std::endl;
    return ;
  } else if (amount == 0) {
    std::cout << "want to be repaired, but nothing happend." << std::endl;
    return ;
  } else {
    unsigned int validAmount(amount);
    if (amount > _energyPoint) {
      std::cout << "doesn't have enough energy to repair <";
      std::cout << amount << "> points. <" << _name << "> ";
      validAmount = _energyPoint;
    }
    if (validAmount > (_maxHitPoint - _hitPoint)) {
      std::cout << "do not need to be repaired <";
      std::cout << amount << ">, ";
      validAmount = (_maxHitPoint - _hitPoint);
      std::cout << "only <" << validAmount << "> points were repaired.";
      std::cout << std::endl;
      _hitPoint += validAmount;
      _energyPoint -= validAmount;
    } else {
      std:: cout << "is repaired by <" << validAmount << "> points." << std::endl;
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
  std::cout << " " << ansiItalic << getName() << ansiEnd << " [ ";
  std::cout << ansiRed << "HP " << _hitPoint << "  ";
  std::cout << ansiCyan << "EP " << _energyPoint << ansiEnd;
  std::cout << " ]" << std::endl;
  return ;
}

std::string ClapTrap::getName(void) const {
  return _name;
}

void ClapTrap::setName(const std::string& name) {
  _name = name;
  return ;
}
