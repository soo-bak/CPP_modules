#include <iostream>

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string asniCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {
  std::cout << ansiRed;
  std::cout << "-----------SUBJECT TEST CASE----------" << std::endl;
  std::cout << ansiEnd;
  {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
  }
  std::cout << ansiRed;
  std::cout << "-----------UDEFINED MATERIA TEST CASE----------" << std::endl;
  std::cout << ansiEnd;
  {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("TEST");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
  }
  std::cout << ansiRed;
  std::cout << "-----------EQUIP COUNT TEST CASE----------" << std::endl;
  std::cout << ansiEnd;
  {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    for (int i = 0; i < 4; i++) {
      std::cout << "[check]" << std::endl;
      me->equip(tmp);
    }
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
  }
  return 0;
}
