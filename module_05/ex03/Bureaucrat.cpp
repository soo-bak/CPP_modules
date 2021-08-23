#include "Bureaucrat.hpp"

const std::string ansiRed("\033[1;31m");
const std::string asniCyan("\033[1;36m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiEnd("\033[0m");

const int Bureaucrat::_highestGrade(1);
const int Bureaucrat::_lowestGrade(150);

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
  return "Bureaucrat::GradeTooLowException";
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
  if (this == &other) {
    return *this;
  }
  _grade = other._grade;
  return *this;
}

Bureaucrat::Bureaucrat(void)
    : _name("unknown"), _grade(_lowestGrade) {
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
    : _name(name), _grade(grade) {
  if (_grade < _highestGrade) {
    throw GradeTooHighException();
  }
  if (_grade > _lowestGrade) {
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

const int& Bureaucrat::getGrade(void) const {
  return _grade;
}

void Bureaucrat::increaseGrade(void) {
  if (_grade - 1 < _highestGrade) {
    throw GradeTooHighException();
  }
  _grade--;
  return ;
}

void Bureaucrat::decreaseGrade(void) {
  if (_grade + 1 > _lowestGrade) {
    throw GradeTooLowException();
  }
  _grade++;
  return ;
}

void Bureaucrat::signForm(Form& form) const {
  try {
    form.beSigned(*this);
    std::cout << "Bureaucrat " << asniCyan << getName() << ansiEnd;
    std::cout << " signs form " << ansiPurple << form.getName();
    std::cout << ansiEnd << std::endl;
  }
  catch (const std::exception& exception) {
    std::cout << "Bureaucrat " << asniCyan << getName() << ansiEnd;
    std::cout << "can not sign form " << ansiPurple << form.getName() << ansiEnd;
    std::cout << " because " << ansiRed << exception.what() << ansiEnd << std::endl;
  }
  return ;
}

void Bureaucrat::executeForm(const Form& form) const {
  try {
    form.execute(*this);
    std::cout << "Bureaucrat " << asniCyan << getName() << ansiEnd;
    std::cout << " execute form " << ansiPurple << form.getName();
    std::cout << ansiEnd << std::endl;
  }
  catch (const std::exception& exception) {
    std::cout << "Bureaucrat " << asniCyan << getName() << ansiEnd;
    std::cout << " can not execute form " << ansiPurple << form.getName() << ansiEnd;
    std::cout << " because " << ansiRed << exception.what() << ansiEnd << std::endl;
  }
}

std::ostream& operator << (std::ostream& outStream,
                           const Bureaucrat& object) {
  outStream << "Bureaucrat " << asniCyan << object.getName() << ansiEnd;
  outStream << " [grade : " << asniCyan << object.getGrade() << ansiEnd;
  outStream << "]" << std::endl;
  return outStream;
}
