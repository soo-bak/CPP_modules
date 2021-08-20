#include "Ice.hpp"

Ice::Ice(void)
    : AMateria("ice") {
}

Ice::Ice(const Ice& other) {
  *this = other;
}

Ice::~Ice(void) {
}

Ice& Ice::operator = (const Ice& other) {
  if (this == &other) {
    return *this;
  }
  setType(other.getType());
}

AMateria* Ice::clone(void) const {
  AMateria* clonedMeteria = new Ice();
  return clonedMeteria;
}

void Ice::use(ICharacter& target) {
  // std::cout << "\"* shoots an ice bolt at " << target.getName() << ". *\"" << std::endl;
  return ;
}
