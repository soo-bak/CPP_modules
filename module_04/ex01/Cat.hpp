#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

  public:

    Cat(void);
    Cat(const Cat& cat);
    virtual ~Cat(void);

    Cat& operator = (const Cat& other);

    virtual void makeSound(void) const;
    Brain* getBrain(void) const;
    void setBrain(const Brain*& newBrain);

  private:

    Brain* _brain;
};
