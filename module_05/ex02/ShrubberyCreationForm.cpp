#include "ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::_gradeToSign(145);
const int ShrubberyCreationForm::_gradeToExecute(137);

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form("ShrubberyCreationForm",
           ShrubberyCreationForm::_gradeToSign,
           ShrubberyCreationForm::_gradeToExecute),
      _target("unknown") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("ShrubberyCreationForm",
           ShrubberyCreationForm::_gradeToSign,
           ShrubberyCreationForm::_gradeToExecute),
      _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
  Form::execute(executor);

}
