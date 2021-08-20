#include "AMateria.hpp"

AMateria::AMateria(void)
    : _type("unknown") {
}

AMateria::AMateria(const std::string& type)
    : _type(type) {
}

AMateria::AMateria(const AMateria& other) {
  setType(other.getType());
}

AMateria::~AMateria(void) {
}

AMateria& AMateria::operator = (const AMateria& other) {
  if (_type == other.getType()) {
    *this = other;
  }
  return *this;
}

void AMateria::use(ICharacter& target) {
  std::cout << "\"*cast some magic to " << target.getName() << ". *\"" << std::endl;
}

const std::string& AMateria::getType(void) const {
  return _type;
}

void AMateria::setType(const std::string& newType) {
  _type = newType;
  return ;
}
