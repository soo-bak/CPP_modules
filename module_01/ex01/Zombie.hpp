#pragma once

#include <iostream>
#include <string>

class Zombie
{
  public:
    Zombie(const std::string& nameInput);
    ~Zombie();
    void announce();

  private:
    static const std::string _growl;
    std::string _name;
};
