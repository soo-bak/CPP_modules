#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

  public:

    DiamondTrap(void);
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    virtual void attack(const std::string& target);
    void whoAmI(void);
    virtual std::string getName(void) const;
    virtual void setName(const std::string& name);

  private:

    std::string _name;
};
