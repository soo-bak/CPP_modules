#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string asniCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main () {

  try {
    Bureaucrat("Bob", 150);
  }
  catch (std::exception& exception){
    std::cout << exception.what() << std::endl;
  }
  return 0;
}
