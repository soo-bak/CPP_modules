#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
  public:

    HumanA(std::string nameInput, Weapon& weaponInput);
    ~HumanA(void);

    void attack(void);

  private:
    std::string _name;
    Weapon& _weapon;
};
