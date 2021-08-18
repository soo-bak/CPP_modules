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

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void displayStatus(void) const;
    virtual std::string getName(void) const;
    virtual void setName(const std::string& name);

  protected:

    std::string _name;
    std::string _trapType;
    unsigned int _hitPoint;
    unsigned int _energyPoint;
    unsigned int _attackDamage;
    unsigned int _maxHitPoint;
    unsigned int _maxEnergyPoint;

    bool _isBroken(void) const;
};
