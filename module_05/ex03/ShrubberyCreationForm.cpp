#include "ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::_gradeToSign(145);
const int ShrubberyCreationForm::_gradeToExecute(137);
const std::string ShrubberyCreationForm::_shrubberyAscii[16] = {
  "                * *",
  "           *    *  * ",
  "      *  *    *     *  * ",
  "     *     *    *  *    *",
  " * *   *    *    *    *   *",
  " *     *  *    * * *  *    *",
  " *   *     * *#   # *   *",
  "  *      #.  #: #  * *    *",
  " *   * *  #. ##        *",
  "   *        ###",
  "              ##",
  "              ##.",
  "              .##:",
  "              ;###",
  "            ,####.",
  "           .######. "
};

ShrubberyCreationForm& ShrubberyCreationForm::operator = (
    const ShrubberyCreationForm& other) {
  Form::operator = (other);
  _target = other.getTarget();
  return *this;
}

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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
  *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
  Form::execute(executor);
  const std::string fileName(getTarget() + "_shrubbery");
  std::ofstream outFileStream(fileName.c_str());
  for (size_t i = 0; i < _shrubberyAscii->size(); i++) {
    outFileStream << _shrubberyAscii[i] << std::endl;
  }
  return ;
}

const std::string& ShrubberyCreationForm::getTarget(void) const {
  return _target;
}
