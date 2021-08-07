#pragma once

#include <string>

class Weapon {
  public:

  Weapon(const std::string& typeInput);
  ~Weapon(void);

  const std::string& getType(void);
  void setType(const std::string& typeInput);

  private:
    std::string _type;
};
