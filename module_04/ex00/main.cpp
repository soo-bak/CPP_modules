#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiEnd("\033[0m");

int main() {
  {
    std::cout << "------------------------------------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl;

    std::cout << ansiBlue << "dog->getType()" << ansiEnd << " : ";
    std::cout << dog->getType() << std::endl;
    std::cout << ansiRed << "cat->getType()" << ansiEnd << " : ";
    std::cout << cat->getType() << std::endl;
    std::cout << std::endl;

    std::cout << ansiPurple << "meta->makeSound()" << ansiEnd << " : ";
    meta->makeSound();
    std::cout << ansiBlue << "dog->makeSound()" << ansiEnd << " : ";
    dog->makeSound();
    std::cout << ansiRed << "cat->makeSound()" << ansiEnd << " : ";
    cat->makeSound();
    std::cout << std::endl;

    delete meta;
    delete dog;
    delete cat;
  }

  {
    std::cout << "------------------------------------" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << std::endl;

    std::cout << ansiRed << "wrongCat->getType()" << ansiEnd << " : ";
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << std::endl;

    std::cout << ansiPurple << "wrongMeta->makeSound()" << ansiEnd << " : ";
    wrongMeta->makeSound();
    std::cout << ansiRed << "wrongCat->makeSound()" << ansiEnd << " : ";
    wrongCat->makeSound();
    std::cout << std::endl;

    delete wrongMeta;
    delete wrongCat;
  }

  return 0;
}
