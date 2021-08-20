#include "Cure.hpp"

Cure::Cure(void)
    : AMeteria("cure") {
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
}

AMeteria* Cure::clone(void) const {
  AMeteria* clonedMeteria = new Cure();
  return clonedMeteria;
}

void Cure::use(ICharacter& target) {
  // std::cout << "\"* heals " << target.getName() << "'s wounds. *\"" << std::endl;
  return ;
}
