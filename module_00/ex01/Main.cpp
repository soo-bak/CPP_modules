#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
  Phonebook Phonebook;
  while (true) {
    std::cout << "input : ";
    std::string input;
    getline(std::cin, input);
    const int commandValue = Phonebook.GetCommandValue(input);
    Phonebook.ExecuteCommand(commandValue);
  }
  return 0;
}
