#include <iostream>
#include <string>

void testScope(std::string* pointer){
  const std::string colorStart("\033[1;31m");
  const std::string colorEnd("\033[0m");
  std::cout << colorStart;
  std::cout << "<Pointer>   address[" << &pointer << "]";
  std::cout << " dereferencing value[" << *pointer << "]" << std::endl;
  std::cout << colorEnd;
}

void testScope(std::string& reference){
  const std::string colorStart("\033[1;31m");
  const std::string colorEnd("\033[0m");
  std::cout << colorStart;
  std::cout << "<Reference> address[" << &reference << "]";
  std::cout << " dereferencing value[" << reference << "]" << std::endl;
  std::cout << colorEnd;
}

int main () {
  std::string brain = "HI THIS IS BRAIN";
  std::string* stringPTR(&brain);
  std::string& stringREF(brain);
  std::cout << "<Origin>    address[" << &brain << "]" << std::endl;
  std::cout << "<Pointer>   address[" << &stringPTR << "]";
  std::cout << " dereferencing value[" << *stringPTR << "]" << std::endl;
  std::cout << "<Reference> address[" << &stringREF << "]";
  std::cout << " dereferencing value[" << stringREF << "]" << std::endl;
  testScope(stringPTR);
  testScope(stringREF);
  return 0;
}
