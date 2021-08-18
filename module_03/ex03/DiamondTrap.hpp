#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

  public:

    DiamondTrap(void);
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI(void);

  private:
    std::string _name;

};
