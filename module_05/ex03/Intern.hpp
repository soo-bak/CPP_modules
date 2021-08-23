#pragma once

#include <string>
#include <exception>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Form;

class Intern {

  public:

    enum {
      ShrubberyCreation,
      RobotomyRequest,
      PresidentialPardon,
      FormListNumbers
    };
    class NotExistingFormException : public std::exception {
      public:
        virtual const char* what(void) const throw();
    };

    Intern& operator = (const Intern& other);
    Intern(void);
    Intern(const Intern& other);
    ~Intern(void);

    Form* makeForm(const std::string& formName,
                   const std::string& target) const;

  private:
    static const std::string _validFormName[3];
};
