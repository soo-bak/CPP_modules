#pragma once

#include <iostream>
#include <string>

class ClapTrap {

  public:

    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& clapTrap);
    ~ClapTrap(void);

    ClapTrap& operator = (const ClapTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
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

static const std::string ansiItalic("\033[3;37m");
static const std::string ansiRed("\033[1;31m");
static const std::string ansiCyan("\033[1;36m");
static const std::string ansiEnd("\033[0m");
