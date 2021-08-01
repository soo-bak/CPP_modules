#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

int main() {
  Phonebook Phonebook;
  std::string command;
  while (true) {
    std::cout << "command : ";
    getline(std::cin, command);
    Phonebook.GetCommand(command);
  }
  return 0;
}
