#include "Zombie.hpp"

const std::string Zombie::_growl = "BraiiiiiiinnnzzzZ...";

Zombie::Zombie(const std::string& nameInput)
 : _name(nameInput) {
}

Zombie::~Zombie(void) {
  const std::string colorStart("\033[1;31m");
  const std::string colorEnd("\033[0m");
  std::cout << colorStart;
  std::cout << _name << " returned to the ground." << std::endl;
  std::cout << colorEnd;
}

void Zombie::announce(void) {
  std::cout << "<" << _name << "> " << _growl << std::endl;
  return ;
}
