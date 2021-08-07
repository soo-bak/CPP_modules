#include <iostream>
#include <string>

std::string mekeUppermessage(char* input) {
  std::string message(input);
  for (std::string::iterator i = message.begin(); i < message.end(); i++) {
    *i = toupper(*i);
  }
  return message;
}

int main(int argc, char* argv[]) {
  const std::string noise = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  if (argc == 1) {
    std::cout << noise;
  } else {
    for (int i = 1; i < argc; i++) {
      std::cout << mekeUppermessage(argv[i]);
    }
  }
  std::cout << std::endl;
  return 0;
}
