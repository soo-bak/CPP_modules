#pragma once

#include <iostream>
#include <string>

class Zombie
{
  public:
    Zombie();
    Zombie(const std::string& nameInput);
    ~Zombie();
    void announce();
    void setName(const std::string& nameInput);

  private:
    static const std::string _growl;
    std::string _name;
};
