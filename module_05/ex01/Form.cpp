#include "Form.hpp"

const std::string ansiPurple("\033[1;35m");
const std::string ansiEnd("\033[0m");

const int Form::_highestGrade(1);
const int Form::_lowestGrade(150);

const char* Form::GradeTooHighException::what(void) const throw() {
  return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what(void) const throw() {
  return "Form::GradeTooLowException";
}

Form& Form::operator = (const Form& other) {
  if (this == &other) {
    return *this;
  }
  _isSigned = other.getIsSigned();
  return *this;
}

Form::Form(void)
    : _name("unknown"),
      _gradeToSign(_lowestGrade),
      _gradeToExcute(_lowestGrade),
      _isSigned(false) {
}

Form::Form(const std::string& name, const int& gradeToSign,
           const int& gradeToExcute)
    : _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExcute(gradeToExcute),
      _isSigned(false) {
  if (_gradeToSign < _highestGrade || _gradeToExcute < _highestGrade) {
    throw GradeTooHighException();
  }
  if (_gradeToSign > _lowestGrade || _gradeToExcute > _lowestGrade) {
    throw GradeTooLowException();
  }
}

Form::Form(const Form& other)
    : _name(other.getName()),
      _gradeToSign(other.getGradeToSign()),
      _gradeToExcute(other.getGradeToExcute()),
      _isSigned(other.getIsSigned()) {
}

Form::~Form(void) {
}

const std::string& Form::getName(void) const {
  return _name;
}

const int& Form::getGradeToSign(void) const {
  return _gradeToSign;
}

const int& Form::getGradeToExcute(void) const {
  return _gradeToExcute;
}

const bool& Form::getIsSigned(void) const {
  return _isSigned;
}

void Form::setIsSigned(const bool& newIsSigned) {
  _isSigned = newIsSigned;
  return ;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > getGradeToSign()) {
    throw Form::GradeTooLowException();
  }
  setIsSigned(true);
}

std::ostream& operator << (std::ostream& outStream,
                           const Form& object) {
  outStream << "Form " << ansiPurple << object.getName() << ansiEnd;
  outStream << " [required grade to sign : " << ansiPurple;
  outStream << object.getGradeToSign() << ansiEnd;
  outStream << " required grade to excute : " << ansiPurple;
  outStream << object.getGradeToExcute() << ansiEnd << "]" << std::endl;
  return outStream;
}
