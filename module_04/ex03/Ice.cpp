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
  return *this;
}

AMateria* Ice::clone(void) const {
  AMateria* clonedMateria = new Ice();
  return clonedMateria;
}

void Ice::use(ICharacter& target) {
  std::cout << "\"* shoots an ice bolt at " << target.getName() << ". *\"" << std::endl;
  return ;
}
