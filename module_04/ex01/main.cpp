#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiEnd("\033[0m");

int main() {
  {
    Cat* catA = new Cat();
    Cat* catB = new Cat();

    catA->getBrain()->setIdea(0, "IDEA CAT A");
    std::cout << catA->getBrain()->getIdea(0) << std::endl;
    std::cout << catB->getBrain()->getIdea(0) << std::endl;
  }
  return 0;
}
