#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const {
  return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what(void) const {
  return "GradeTooLowException";
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
  if (this == &other) {
    return *this;
  }
  _grade = other._grade;
  return *this;
}

Bureaucrat::Bureaucrat(void)
    : _name("unknown"), _grade(150) {
}

Bureaucrat::~Bureaucrat(void) {
}
