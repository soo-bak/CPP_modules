#include <iostream>
#include <iomanip>
#include <string>


const std::string g_colorRed("\033[1;31m");
const std::string g_colorPurple("\033[1;35m");
const std::string g_colorEnd("\033[0m");

void testScope(std::string* pointer){
  std::cout << g_colorPurple;
  std::cout << std::setw(16) << std::left;
  std::cout << "<arg Pointer>" << "address[" << &pointer << "]";
  std::cout << g_colorEnd;
  std::cout << " : " << *pointer << std::endl;
}

void testScope(std::string& reference){
  std::cout << std::setw(16) << std::left;
  std::cout << "<arg Reference>" << "address[" << &reference << "]";
  std::cout << " : " << reference << std::endl;
}

int main () {

  std::string brain = "HI THIS IS BRAIN";
  std::string* stringPTR(&brain);
  std::string& stringREF(brain);
  std::cout << std::setw(16) << std::left;
  std::cout << "<Origin>" << "address[" << &brain << "]";
  std::cout << " : " << brain << std::endl;
  std::cout << g_colorRed;
  std::cout << std::setw(16) << std::left;
  std::cout << "<Pointer>" << "address[" << &stringPTR << "]";
  std::cout << g_colorEnd;
  std::cout << " : " << *stringPTR << std::endl;
  std::cout << std::setw(16) << std::left;
  std::cout << "<Reference>" << "address[" << &stringREF << "]";
  std::cout << " : " << stringREF << std::endl;
  testScope(stringPTR);
  testScope(stringREF);
  return 0;
}
