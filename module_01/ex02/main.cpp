#include <iostream>
#include <string>

int main () {
  std::string brain = "HI THIS IS BRAIN";
  std::string *stringPTR = &brain;
  std::string &stringREF = brain;
  std::cout << "Pointer : " << stringPTR << std::endl;
  std::cout << "Reference : " << &stringREF << std::endl;
  return 0;
}
