#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
  public:

    HumanB(std::string nameInput);
    ~HumanB(void);

    void setWeapon(Weapon& weaponInput);
    void attack(void);

  private:
    std::string _name;
    Weapon*  _weapon;
};
