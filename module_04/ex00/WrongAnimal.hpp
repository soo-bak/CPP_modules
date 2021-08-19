#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
  public:
    WrongAnimal(void);
    WrongAnimal(const std::string& type);
    WrongAnimal(const WrongAnimal& wrongAnimal);
    ~WrongAnimal();

    WrongAnimal& operator = (const WrongAnimal& other);

    std::string getType(void) const;
    void setType(const std::string& type);
    void makeSound(void) const;

  protected:
    std::string _type;
};
