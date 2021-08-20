#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {

  public:

    Ice(void);
    Ice(const Ice& other);
    virtual ~Ice();

    Ice& operator = (const Ice& other);

    virtual AMateria* clone(void) const;
    virtual void use(ICharacter& target);
};
