#include "Intern.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiEnd("\033[0m");

const std::string Intern::_validFormName[3] = {
  "shrubbery creation",
  "robotomy request",
  "presidential pardon"
};

const char* Intern::NotExistingFormException::what(void) const throw() {
  return "Intern::NotExistingFormException";
}

Intern::Intern(void) {
}

Intern::~Intern(void) {
}

Form* Intern::makeForm(const std::string& formName,
                       const std::string& target) const {
  int formIndex;
  for (formIndex = ShrubberyCreation;
       formIndex < FormListNumbers; formIndex++) {
    if (formName.compare(_validFormName[formIndex]) == 0) {
      break ;
    }
  }
  Form* createdForm(NULL);
  switch (formIndex) {
    case ShrubberyCreation:
      createdForm = new ShrubberyCreationForm(target);
      break ;
    case RobotomyRequest:
      createdForm = new RobotomyRequestForm(target);
      break ;
    case PresidentialPardon:
      createdForm = new PresidentialPardonForm(target);
      break ;
    default:
      std::cout << "There is no form named " << ansiRed << formName;
      std::cout << ansiEnd << "..." << std::endl;
      throw NotExistingFormException();
  }
  std::cout << "Intern creates " << ansiPurple << formName;
  std::cout << ansiEnd << std::endl;
  return createdForm;
}
