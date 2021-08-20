#pragma once

#include "Animal.hpp"

class Cat : public Animal {
  public:
    Cat(void);
    Cat(const Cat& cat);
    virtual ~Cat(void);

    Cat& operator = (const Cat& other);

    virtual void makeSound(void) const;
};
