#include "RobotomyRequestForm.hpp"

const std::string ansiGreen("\033[1;32m");
const std::string ansiEnd("\033[0m");

const int RobotomyRequestForm::_gradeToSign(72);
const int RobotomyRequestForm::_gradeToExecute(45);

RobotomyRequestForm& RobotomyRequestForm::operator = (
    const RobotomyRequestForm& other) {
  Form::operator = (other);
  _target = other.getTarget();
  return *this;
}

RobotomyRequestForm::RobotomyRequestForm(void)
    : Form("robotomy request",
           RobotomyRequestForm::_gradeToSign,
           RobotomyRequestForm::_gradeToExecute),
      _target("unknown") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("robotomy request",
           RobotomyRequestForm::_gradeToSign,
           RobotomyRequestForm::_gradeToExecute),
      _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
  *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
  Form::execute(executor);
  std::cout << "drilling.... drilling.... drlllllllll.... " << std::endl;
  std::srand(std::time(NULL));
  if (std::rand() % 2) {
    std::cout << "[Robotomization " << ansiGreen << "success" << ansiEnd;
    std::cout << "] target " << ansiGreen << getTarget() << ansiEnd;
    std::cout << " is successfully robotomized" << std::endl;
  } else {
    std::cout << "[Robotomization " << ansiGreen << "failure" << ansiEnd;
    std::cout << "] target " << ansiGreen << getTarget() << ansiEnd;
    std::cout << " failed to be robotomized" << std::endl;
  }
  return ;
}

const std::string& RobotomyRequestForm::getTarget(void) const {
  return _target;
}
