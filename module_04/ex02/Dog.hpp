#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

  public:

    Dog(void);
    Dog(const Dog& dog);
    virtual ~Dog(void);

    Dog& operator = (const Dog& other);

    virtual void makeSound(void) const;
    const Brain& getBrain(void) const;
    void setBrain(const Brain& newBrain);

  private:

    Brain* _brain;
};
