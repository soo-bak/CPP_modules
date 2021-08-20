#pragma once

#include "AMeteria.hpp"

class Cure : public AMeteria {

  public:

    Cure(void);
    Cure(const Cure& other);
    ~Cure();

    Cure& operator = (const Cure& other);

    virtual AMeteria* clone(void) const;
    virtual void use(ICharacter& target);
};
