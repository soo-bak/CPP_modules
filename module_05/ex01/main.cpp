#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    std::cout << std::endl;

    Bureaucrat bureaucrat(nameInput, gradeInput);
    std::cout << asniCyan << "Bureaucrat appeard! " << ansiEnd << std::endl;
    std::cout << bureaucrat << std::endl;

    std::cout << " Eneter the Form's name : ";
    std::cin >> nameInput;
    int signGradeInput;
    std::cout << " Eneter the Form's grade to sign : ";
    std::cin >> signGradeInput;
    int executeGradeInput;
    std::cout << " Eneter the Form's grade to execute : ";
    std::cin >> executeGradeInput;
    std::cout << std::endl;

    Form form(nameInput, signGradeInput, executeGradeInput);
    std::cout << ansiPurple << "Form is made! " << ansiEnd << std::endl;
    std::cout << form << std::endl;

    while (true) {
      std::string command;
      std::cout << " Eneter the command" << std::endl;
      std::cout << " (i to increase grade, d to decrease grade, s to sign the form) : ";
      std::cin >> command;
      if (command.compare("i") == 0) {
        std::cout << std::endl;
        bureaucrat.increaseGrade();
        std::cout << bureaucrat << std::endl;
      } else if (command.compare("d") == 0) {
        std::cout << std::endl;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;
      } else if (command.compare("s") == 0) {
        std::cout << std::endl;
        bureaucrat.signForm(form);
        std::cout << std::endl;
      }
    }
  }

  catch (std::exception& exception){
    std::cout << exception.what() << std::endl;
  }

  return 0;
}
