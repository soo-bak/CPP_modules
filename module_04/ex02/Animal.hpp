#pragma once

#include <string>
#include <iostream>

class Animal {
  public:
    Animal(void);
    Animal(const std::string& type);
    Animal(const Animal& animal);
    virtual ~Animal();

    Animal& operator = (const Animal& other);

    std::string getType(void) const;
    void setType(const std::string& type);
    virtual void makeSound(void) const = 0;

  protected:
    std::string _type;
};
