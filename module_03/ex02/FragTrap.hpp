#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

  public:

    FragTrap(void);
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& fragTrap);
    ~FragTrap(void);

    FragTrap& operator = (const FragTrap& other);

    virtual void attack(const std::string& target);
    void highFivesGuys(void);
};
