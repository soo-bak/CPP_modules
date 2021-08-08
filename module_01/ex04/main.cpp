#include <iostream>
#include <string>

#include "Replacer.hpp"

int main (int argc, char* argv[]) {
  if (argc != 4) {
    std::cout << "Please check the arguments." << std::endl;
    return -1;
  }
  Replacer replacer(argv[1], argv[2], argv[3]);
  replacer.makeReplacedFile();
  return 0;
}
