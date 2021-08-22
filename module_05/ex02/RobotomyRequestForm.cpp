#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_gradeToSign(72);
const int RobotomyRequestForm::_gradeToExecute(45);

RobotomyRequestForm& RobotomyRequestForm::operator = (
    const RobotomyRequestForm& other) {
  Form::operator = (other);
  _target = other.getTarget();
  return *this;
}

RobotomyRequestForm::RobotomyRequestForm(void)
    : Form("RobotomyRequestForm",
           RobotomyRequestForm::_gradeToSign,
           RobotomyRequestForm::_gradeToExecute),
      _target("unknown"){
}
