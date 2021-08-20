#pragma once

#include <string>

#include "AMeteria.hpp"

class ICharacter {

  public:

    virtual ~ICharacter() {};
    virtual const std::string getName(void) const = 0;
    virtual void equip(AMeteria* meteria) = 0;
    virtual void unequip(int index) = 0;
    virtual void use(int index, ICharacter& target) = 0;
};
