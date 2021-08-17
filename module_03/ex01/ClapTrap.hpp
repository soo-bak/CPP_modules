#pragma once

#include <iostream>
#include <string>

class ClapTrap {

  public:

    ClapTrap(void);
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap(const std::string& name, const unsigned int& hitPoint,
                   const unsigned int& energyPoint);
    ~ClapTrap(void);

    ClapTrap& operator = (const ClapTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void displayStatus(void) const;

  protected:

    std::string _name;
    unsigned int _hitPoint;
    unsigned int _energyPoint;

    bool _isBroken(void) const;
    void _initialize(const std::string& name,
                     const unsigned int& hitPoint,
                     const unsigned int& energyPoint);

  private:

    static const unsigned int _maxHitPoint;
    static const unsigned int _maxEnergyPoint;
    static const unsigned int _attackDamage;
};
