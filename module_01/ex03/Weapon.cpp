#include "Weapon.hpp"

Weapon::Weapon(const std::string& typeInput)
  : _type(typeInput) {
}

Weapon::~Weapon(void) {
}

const std::string& Weapon::getType(void) {
  return _type;
}

void Weapon::setType(const std::string& typeInput) {
  _type = typeInput;
  return ;
}
