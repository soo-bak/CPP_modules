#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
  Phonebook Phonebook;
  std::string input;
  while (true) {
    std::cout << "input : ";
    getline(std::cin, input);
    const int commandValue = Phonebook.GetCommandValue(input);
    Phonebook.ExecuteCommand(commandValue);
  }
  return 0;
}
