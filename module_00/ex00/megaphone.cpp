#include <iostream>
#include <string>

const std::string Noise = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

std::string MakeUpperMessage(char *input) {
  std::string message(input);
  for (std::string::iterator i = message.begin(); i < message.end(); i++) {
    *i = toupper(*i);
  }
  return message;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
      std::cout << Noise;
    } else {
      for (int i = 1; i < argc; i++) {
        std::cout << MakeUpperMessage(argv[i]);
      }
    }
  std::cout << std::endl;
  return 0;
}
