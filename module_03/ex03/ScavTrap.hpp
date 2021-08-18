#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

  public:

    ScavTrap(void);
    ScavTrap(const std::string& name);
    ~ScavTrap(void);

    virtual void attack(const std::string& target);
    void guardGate(void);
};
