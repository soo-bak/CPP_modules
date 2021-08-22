#include "Form.hpp"

const int Form::_highestGrade(1);
const int Form::_lowestGrade(150);

const char* Form::GradeTooHighException::what(void) const throw() {

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

std::ostream& operator << (std::ostream& outStream,
                           const Form& object) {
  // outStream <<
}
