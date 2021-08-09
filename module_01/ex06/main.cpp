#include <string>

#include "Karen.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    return -1;
  }
  const std::string argumentInput(argv[1]);
  Karen karen;
  karen.filter(argumentInput);
}
