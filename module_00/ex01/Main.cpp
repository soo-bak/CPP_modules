#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
  Phonebook phonebook;
  while (true) {
    std::cout << "Enter the command : ";
    std::string input;
    std::getline(std::cin, input);
    const int command = phonebook.CheckCommand(input);
    phonebook.ExecuteCommand(command);
  }
  return 0;
}
