#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

  public:

    DiamondTrap(void);
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& diamondTrap);
    ~DiamondTrap();

    DiamondTrap& operator = (const DiamondTrap& other);

    virtual void attack(const std::string& target);
    virtual std::string getName(void) const;
    virtual void setName(const std::string& name);

    void whoAmI(void);

  private:

    std::string _name;
};
