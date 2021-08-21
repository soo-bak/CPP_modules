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

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade)
    : _name(name), _grade(grade) {
  if (_grade < 1) {
    throw GradeTooHighException();
  }
  if (_grade > 150) {
    throw GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
}

Bureaucrat::~Bureaucrat(void) {
}

const std::string& Bureaucrat::getName(void) const {
  return _name;
}

const unsigned int& Bureaucrat::getGrade(void) const {
  return _grade;
}

void Bureaucrat::increaseGrade(void) {
  if (_grade - 1 < 1) {
    throw GradeTooHighException();
  }
  _grade--;
  return ;
}

void Bureaucrat::decreaseGrade(void) {
  if (_grade + 1 > 150) {
    throw GradeTooLowException();
  }
  _grade++;
  return ;
}
