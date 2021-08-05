#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main () {
  Zombie stack("stack");
  stack.announce();
  Zombie *heap(newZombie("heap"));
  heap->announce();
  delete heap;
  return 0;
}
