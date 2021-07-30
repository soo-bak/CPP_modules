#include <iostream>

int main(int argc, char* argv[]) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      std::cout << argv[argc] << std::endl;
    }
  } else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }
  return 0;
}
