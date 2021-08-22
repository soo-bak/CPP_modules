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
      _target("unknown") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequestForm",
           RobotomyRequestForm::_gradeToSign,
           RobotomyRequestForm::_gradeToExecute),
      _target(target ) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
  *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
  //TODO;
  return ;
}

const std::string& RobotomyRequestForm::getTarget(void) const {
  return _target;
}
