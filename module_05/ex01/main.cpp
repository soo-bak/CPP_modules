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
    std::string nameInput;
    std::cout << " Eneter the Bureaucrat's name : ";
    std::cin >> nameInput;
    int gradeInput;
    std::cout << " Eneter the Bureaucrat's grade : ";
    std::cin >> gradeInput;

    Bureaucrat test(nameInput, gradeInput);
    std::cout << asniCyan << "Bureaucrat appeard! " << ansiEnd << std::endl;
    std::cout << test << std::endl;

    while (true) {
      std::string command;
      std::cout << " Eneter the command(i to increase grade, d to decrease grade) : ";
      std::cin >> command;
      if (command.compare("i") == 0) {
        test.increaseGrade();
      } else if (command.compare("d") == 0) {
        test.decreaseGrade();
      }
      std::cout << test << std::endl;
    }
  }

  catch (std::exception& exception){
    std::cout << exception.what() << std::endl;
  }

  return 0;
}
