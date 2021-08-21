#pragma once

#include <exception>
#include <string>

class Bureaucrat {

  public:

    class GradeTooHighException : public std::exception {
      public :
        const char* what() const;
    };
    class GradeTooLowException : public std::exception {
      public :
        const char* what() const;
    };

    Bureaucrat& operator = (const Bureaucrat& other);

    Bureaucrat(void);
    Bureaucrat(const std::string& name, const unsigned int& grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat(void);

    const std::string& getName(void) const;
    const unsigned int& getGrade(void) const;
    void increaseGrade(void);
    void decreaseGrade(void);

  private:
    const std::string _name;
    unsigned int _grade;
};
