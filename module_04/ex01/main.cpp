#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiEnd("\033[0m");

int main() {
  Cat* catA = new Cat();
  {
    Cat catB;
    catB.getBrain()->setIdea(0, "new idea of cat B !");
    std::cout << "first idea of cat A : ";
    std::cout << catA->getBrain()->getIdea(0) << std::endl;
    std::cout << "first idea of cat B : ";
    std::cout << catB.getBrain()->getIdea(0) << std::endl;
    catB = *catA;
    std::cout << catB.getBrain()->getIdea(0) << std::endl;
  }
  return 0;
}
