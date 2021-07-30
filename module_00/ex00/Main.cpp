#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

// int main(int argc, char* argv[]) {
//   if (argc == 1) {
//     std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
//   } else {
//     for (int i = 1; i < argc; i++) {
//       int length = strlen(argv[i]);
//       for (int j = 0; j < length; j++) {
//         char upperCase = toupper(argv[i][j]);
//         std::cout << upperCase;
//       }
//     }
//   }
//   std::cout << std::endl;
//   return 0;
// }

int main(int argc, char *argv[]) {
    if (argc == 1) {
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
      for (int i = 1; i < argc; i++) {
        std::string message;
        message = argv[i];
        for (std::string::iterator j = message.begin(); j < message.end(); j++) {
          *j = toupper(*j);
          std::cout << *j;
        }
      }
    }
  std::cout << std::endl;
  return 0;
}
