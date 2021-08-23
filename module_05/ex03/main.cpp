#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string asniCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main () {

  Bureaucrat jinchoi("jinchoi", 1);
  Intern someRandomIntern;

  while (true) {
    Form* form;
    try {
      std::string formName;
      std::cout << "Enter the form's name for Intern : ";
      std::getline(std::cin, formName);
      form = someRandomIntern.makeForm(formName, "randomTarget");
    }
    catch (const std::exception& exception) {
      std::cout << exception.what() << std::endl;
      continue ;
    }
    jinchoi.signForm(*form);
    jinchoi.executeForm(*form);
    delete form;
  }
  return 0;
}
