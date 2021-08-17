#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

  public:

    ScavTrap(void);
    ScavTrap(std::string& name);
    ~ScavTrap(void);

  private:

    static const unsigned int _maxHitPoint;
    static const unsigned int _maxEnergyPoint;
    static const unsigned int _attackDamage;

};
