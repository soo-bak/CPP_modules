#pragma once

#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {

  public:

    ShrubberyCreationForm(const std::string& target);
    virtual ~ShrubberyCreationForm(void);

    virtual void execute(const Bureaucrat& executor) const;

  private:
    static const int _gradeToSign;
    static const int _gradeToExecute;

    std::string _target;
    ShrubberyCreationForm(void);
};
