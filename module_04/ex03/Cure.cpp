#include "Cure.hpp"

Cure::Cure(void)
    : AMateria("cure") {
}

Cure::Cure(const Cure& other) {
  *this = other;
}

Cure::~Cure(void) {
}

Cure& Cure::operator = (const Cure& other) {
  if (this == &other) {
    return *this;
  }
  setType(other.getType());
  return *this;
}

AMateria* Cure::clone(void) const {
  AMateria* clonedMateria = new Cure();
  return clonedMateria;
}

void Cure::use(ICharacter& target) {
  std::cout << "\"* heals " << target.getName() << "'s wounds. *\"" << std::endl;
  return ;
}
