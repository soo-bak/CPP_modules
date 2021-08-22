#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form {

  public:

    virtual RobotomyRequestForm& operator = (
        const RobotomyRequestForm& other);

    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm(void);

    virtual void execute(const Bureaucrat& executor) const;
    const std::string& getTarget(void) const;

  private:
    static const int _gradeToSign;
    static const int _gradeToExecute;

    std::string _target;
    RobotomyRequestForm(void);
};
