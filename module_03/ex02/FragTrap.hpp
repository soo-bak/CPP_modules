#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

  public:

    FragTrap(void);
    FragTrap(const std::string& name);
    ~FragTrap(void);

    void attack(const std::string& target);
    void highFivesGuys(void);
};
