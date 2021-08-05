#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
  Zombie *returnVariable = new Zombie(name);
  return returnVariable;
}
