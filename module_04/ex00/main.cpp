#include "Animal.hpp"

int main() {
  const Animal* meta = new Animal();

  meta->makeSound();

  delete meta;
  return 0;
}
