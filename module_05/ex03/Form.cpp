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

const char* Form::ExecutingNotSignedFormException::what(void) const throw() {
  return "Form::ExecutingNotSignedFormException";
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
      _gradeToExecute(_lowestGrade),
      _isSigned(false) {
}

Form::Form(const std::string& name, const int& gradeToSign,
           const int& gradeToExecute)
    : _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _isSigned(false) {
  if (_gradeToSign < _highestGrade || _gradeToExecute < _highestGrade) {
    throw GradeTooHighException();
  }
  if (_gradeToSign > _lowestGrade || _gradeToExecute > _lowestGrade) {
    throw GradeTooLowException();
  }
}

Form::Form(const Form& other)
    : _name(other.getName()),
      _gradeToSign(other.getGradeToSign()),
      _gradeToExecute(other.getGradeToExecute()),
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

const int& Form::getGradeToExecute(void) const {
  return _gradeToExecute;
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
    throw GradeTooLowException();
  }
  setIsSigned(true);
  return ;
}

void Form::execute(const Bureaucrat& executor) const {
  if (getIsSigned() == false) {
    throw ExecutingNotSignedFormException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw GradeTooLowException();
  }
  return ;
}

std::ostream& operator << (std::ostream& outStream,
                           const Form& object) {
  outStream << "Form " << ansiPurple << object.getName() << ansiEnd;
  outStream << " [required grade to sign " << ansiPurple;
  outStream << object.getGradeToSign() << ansiEnd;
  outStream << " required grade to execute " << ansiPurple;
  outStream << object.getGradeToExecute() << ansiEnd << "]" << std::endl;
  return outStream;
}
