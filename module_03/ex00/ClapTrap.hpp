#pragma once

#include <iostream>
#include <string>

class ClapTrap {

  public:

    ClapTrap(void);
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& clapTrap);
    ~ClapTrap(void);

    ClapTrap& operator = (const ClapTrap& other);

    void attack(const std::string& target);
    void takeDamage(const unsigned int& amount);
    void beRepaired(const unsigned int& amount);
    void displayStatus(void) const;

  private:

    static const unsigned int _maxHitPoint;
    static const unsigned int _maxEnergyPoint;
    static const unsigned int _attackDamage;

    std::string _name;
    unsigned int _hitPoint;
    unsigned int _energyPoint;

    bool _isBroken(void) const;
};
