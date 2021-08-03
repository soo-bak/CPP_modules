#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
  Phonebook phonebook;
  while (true) {
    std::string input;
    std::cin >> input;
    const int command = phonebook.CheckCommand(input);
    phonebook.ExecuteCommand(command);
  }
  return 0;
}
