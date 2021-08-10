#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main () {
  randomChump("stack");

  Zombie *heap(newZombie("heap"));
  heap->announce();
  delete heap;
  return 0;
}
