#pragma once

#include "AMeteria.hpp"

class Ice : public AMeteria {

  public:

    Ice(void);
    Ice(const Ice& other);
    ~Ice();

    Ice& operator = (const Ice& other);

    virtual AMeteria* clone(void) const;
    virtual void use(ICharacter& target);
};
