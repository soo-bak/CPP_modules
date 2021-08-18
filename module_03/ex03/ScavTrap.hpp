#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

  public:

    ScavTrap(void);
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& scavTrap);
    ~ScavTrap(void);

    ScavTrap& operator = (const ScavTrap& other);

    virtual void attack(const std::string& target);

    void guardGate(void);
};
