#include "PresidentialPardonForm.hpp"

const std::string ansiGreen("\033[1;32m");
const std::string ansiEnd("\033[0m");

const int PresidentialPardonForm::_gradeToSign(25);
const int PresidentialPardonForm::_gradeToExecute(5);

PresidentialPardonForm& PresidentialPardonForm::operator = (
    const PresidentialPardonForm& other) {
  Form::operator = (other);
  _target = other.getTarget();
  return *this;
}

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form("presidential pardon",
           PresidentialPardonForm::_gradeToSign,
           PresidentialPardonForm::_gradeToExecute),
      _target("unknown") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("presidential pardon",
           PresidentialPardonForm::_gradeToSign,
           PresidentialPardonForm::_gradeToExecute),
      _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
  *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
  Form::execute(executor);
  std::cout << "target " << ansiGreen << getTarget() << ansiEnd;
  std::cout << " has been pardoned by Zafold Beeblebrox" << std::endl;
  return ;
}

const std::string& PresidentialPardonForm::getTarget(void) const {
  return _target;
}
