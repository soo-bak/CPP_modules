#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string asniCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {
  std::cout << std::endl << ansiRed;
  std::cout << "-----------DEEP COPY TEST ABOUT CAT----------";
  std::cout << ansiEnd << std::endl;
  {
    Cat* catA = new Cat();
    std::cout << std::endl << asniCyan;
    std::cout << "Initial idea of cat A : " << ansiEnd;
    std::cout << catA->getBrain().getIdea(0) << std::endl;
    std::cout << std::endl;

    Brain brainA;
    brainA.setIdea(0, "GOOD IDEA");
    catA->setBrain(brainA);
    std::cout << std::endl << asniCyan;
    std::cout << "After copying, idea of cat A : " << ansiEnd;
    std::cout << catA->getBrain().getIdea(0) << std::endl;
    std::cout << std::endl;
    {
      std::cout << "---------new local----------------" << std::endl;
      Cat catB(*catA);
      std::cout << std::endl << asniCyan;
      std::cout << "Initial idea of cat B : " << ansiEnd;
      std::cout << catB.getBrain().getIdea(0) << std::endl;
      std::cout << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl << asniCyan;
    std::cout << "After cat B deleted, idea of cat A : " << ansiEnd;
    std::cout << catA->getBrain().getIdea(0) << std::endl;
    std::cout << std::endl;
    delete catA;
  }
  std::cout << std::endl << ansiRed;
  std::cout << "-----------DEEP COPY TEST ABOUT DOG----------";
  std::cout << ansiEnd << std::endl;
  {
    Dog* dogA = new Dog();
    std::cout << std::endl << asniCyan;
    std::cout << "Initial idea of dog A : " << ansiEnd;
    std::cout << dogA->getBrain().getIdea(0) << std::endl;
    std::cout << std::endl;

    Brain brainA;
    brainA.setIdea(0, "GOOD IDEA");
    dogA->setBrain(brainA);
    std::cout << std::endl << asniCyan;
    std::cout << "After copying, idea of dog A : " << ansiEnd;
    std::cout << dogA->getBrain().getIdea(0) << std::endl;
    std::cout << std::endl;
    {
      std::cout << "---------new local----------------" << std::endl;
      Dog dogB(*dogA);
      std::cout << std::endl << asniCyan;
      std::cout << "Initial idea of dog B : " << ansiEnd;
      std::cout << dogB.getBrain().getIdea(0) << std::endl;
      std::cout << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << std::endl << asniCyan;
    std::cout << "After dog B deleted, idea of dog A : " << ansiEnd;
    std::cout << dogA->getBrain().getIdea(0) << std::endl;
    std::cout << std::endl;
    delete dogA;
  }

  return 0;
}
