#include "Phonebook.hpp"
#include "Contact.hpp"

int main() {
  Phonebook phonebook;
  while (!std::cin.bad() && !std::cin.eof()) {
    phonebook.openPhonebook();
  }
  return 0;
}
