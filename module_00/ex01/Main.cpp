#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
  Phonebook phonebook;
  while (true) {
    std::cout << "Please input the command : ";
    std::string input;
    // std::cin >> input;
    std::getline(std::cin, input);
    const int command = phonebook.CheckCommand(input);
    phonebook.ExecuteCommand(command);
  }
  return 0;
}
