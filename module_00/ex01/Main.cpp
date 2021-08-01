#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
  Phonebook Phonebook;
  std::string command;
  while (true) {
    std::cout << "command : ";
    getline(std::cin, command);
    Phonebook.ExecuteCommand(command);
  }
  return 0;
}
