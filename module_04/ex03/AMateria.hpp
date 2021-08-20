#pragma once

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {

  public:

    AMateria(void);
    AMateria(const std::string& type);
    AMateria(const AMateria& other);
    virtual ~AMateria();

    AMateria& operator = (const AMateria& other);

    virtual AMateria* clone(void) const = 0;
    virtual void use(ICharacter& target);

    const std::string& getType(void) const;
    void setType(const std::string& newType);

  protected:
    std::string _type;
};
