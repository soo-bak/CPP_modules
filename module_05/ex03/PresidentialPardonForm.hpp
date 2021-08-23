#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form {

  public:

    virtual PresidentialPardonForm& operator = (
        const PresidentialPardonForm& other);

    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm(void);

    virtual void execute(const Bureaucrat& executor) const;
    const std::string& getTarget(void) const;

  private:
    static const int _gradeToSign;
    static const int _gradeToExecute;

    std::string _target;
    PresidentialPardonForm(void);
};
