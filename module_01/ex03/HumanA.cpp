#include "HumanA.hpp"

HumanA::HumanA(std::string nameInput, Weapon& weaponInput)
  : _name(nameInput), _weapon(weaponInput) {
}

HumanA::~HumanA(void) {
}

void HumanA::attack(void) {
  std::cout << _name << " attacks with his ";
  std::cout << _weapon.getType() << std::endl;
  return ;
}
