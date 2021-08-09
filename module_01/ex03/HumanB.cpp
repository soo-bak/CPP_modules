#include "HumanB.hpp"

HumanB::HumanB(std::string nameInput)
 : _name(nameInput) {
}

HumanB::~HumanB(void) {
}

void HumanB::attack(void) {
  std::cout << _name << " attacks with his ";
  std::cout << _weapon->getType() << std::endl;
  return ;
}

void HumanB::setWeapon(Weapon& weaponInput) {
  _weapon = &weaponInput;
  return ;
}
