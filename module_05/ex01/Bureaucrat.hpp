#pragma once

#include <exception>
#include <string>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {

  public:

    class GradeTooHighException : public std::exception {
      public :
        virtual const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
      public :
        virtual const char* what(void) const throw();
    };

    Bureaucrat& operator = (const Bureaucrat& other);

    Bureaucrat(void);
    Bureaucrat(const std::string& name, const int& grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat(void);

    const std::string& getName(void) const;
    const int& getGrade(void) const;
    void increaseGrade(void);
    void decreaseGrade(void);
    void signForm(Form& form) const;

  private:

    static const int _highestGrade;
    static const int _lowestGrade;

    const std::string _name;
    int _grade;
};

std::ostream& operator << (std::ostream& outStream,
                           const Bureaucrat& object);
