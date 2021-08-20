#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {

  public:

    Cure(void);
    Cure(const Cure& other);
    virtual ~Cure();

    Cure& operator = (const Cure& other);

    virtual AMateria* clone(void) const;
    virtual void use(ICharacter& target);
};
