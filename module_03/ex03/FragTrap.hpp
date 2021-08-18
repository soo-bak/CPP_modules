#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

  public:

    FragTrap(void);
    FragTrap(const std::string& name);
    ~FragTrap(void);

    virtual void attack(const std::string& target);
    void highFivesGuys(void);
};
