#pragma once

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat {

  public:

    class GradeTooHighException : public std::exception {
      public :
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public :
        virtual const char* what() const throw();
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

  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator << (std::ostream& outStream,
                           const Bureaucrat& object);
