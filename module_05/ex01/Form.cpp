#include "Form.hpp"

Form& Form::operator = (const Form& other) {
  if (this == &other) {
    return *this;
  }
  _isSigned = other.getIsSigned();
  return *this;
}

Form::Form(void)
    : _name("unknown"), _gradeToSign(150), _gradeToExcute(150),
      _isSigned(false) {
}

Form::Form(const Form& other)
    : _name(other.getName()), _gradeToSign(other.getGradeToSign()),
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
