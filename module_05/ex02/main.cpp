#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string asniCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main () {

  ShrubberyCreationForm shrubber("Spaghetti");
  RobotomyRequestForm robotomy("Robster");
  PresidentialPardonForm presidential("Pizza");

  try {
    while (true) {
      std::string name;
      int grade;
      std::cout << "Enter the bureaucrat's name : ";
      std::cin >> name;
      std::cout << "Enter the bureaucrat's grade : ";
      std::cin >> grade;
      Bureaucrat bureaucrat(name, grade);
      std::cout << std::endl << bureaucrat << std::endl;
      std::string command;
      std::cout << "Eneter the command for signing" << std::endl;
      std::cout << "(s: ShrubberyCreation / r: RobotomyRequest / p: PresidentialPardon)" << std::endl;
      std::cin >> command;
      std::cout << std::endl;
      if (command.compare("s") == 0) {
        bureaucrat.signForm(shrubber);
      } else if (command.compare("r") == 0) {
        bureaucrat.signForm(robotomy);
      } else if (command.compare("p") == 0) {
        bureaucrat.signForm(presidential);
      } else {
        std::cout << std::endl;
        continue ;
      }
      std::cout << std::endl;
      std::cout << "Eneter the command for executing" << std::endl;
      std::cout << "(s: ShrubberyCreation / r: RobotomyRequest / p: PresidentialPardon)" << std::endl;
      std::cin >> command;
      std::cout << std::endl;
      if (command.compare("s") == 0) {
        bureaucrat.executeForm(shrubber);
      } else if (command.compare("r") == 0) {
        bureaucrat.executeForm(robotomy);
      } else if (command.compare("p") == 0) {
        bureaucrat.executeForm(presidential);
      }
      std::cout << std::endl;
    }
  }
  catch (const std::exception& exception) {
    std::cout << exception.what() << std::endl;
  }

  return 0;
}
