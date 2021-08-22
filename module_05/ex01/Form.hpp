#pragma once

#include <iostream>
#include <string>

class Form {

  public:

    class GradeTooHighException : public std::exception {
      public :
        virtual const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
      public :
        virtual const char* what(void) const throw();
    };

    Form& operator = (const Form& other);

    Form(void);
    Form(const std::string& name, const int& gradeToSign,
         const int& gradeToExcute);
    Form(const Form& other);
    ~Form(void);

    const std::string& getName(void) const;
    const int& getGradeToSign(void) const;
    const int& getGradeToExcute(void) const;

    const bool& getIsSigned(void) const;
    void setIsSigned(const bool& newIsSigned);

  private:

    static const int _highestGrade;
    static const int _lowestGrade;

    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExcute;


    bool _isSigned;
};

std::ostream& operator << (std::ostream& outStream,
                           const Form& object);
