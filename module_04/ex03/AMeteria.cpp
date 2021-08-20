#include "AMeteria.hpp"

AMeteria::AMeteria(void)
    : _type("unknown") {
}

AMeteria::AMeteria(const std::string& type)
    : _type(type) {
}

AMeteria::AMeteria(const AMeteria& other) {
  setType(other.getType());
}

AMeteria::~AMeteria(void) {
}

void AMeteria::use(ICharacter& target) {
  // std::cout << "\"*cast some magic to " << target << ". *\"" << std::endl;
}

const std::string& AMeteria::getType(void) const {
  return _type;
}

void AMeteria::setType(const std::string& newType) {
  _type = newType;
  return ;
}
