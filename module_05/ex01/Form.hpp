#pragma once

#include <iostream>
#include <string>

class Form {

  public:
    Form& operator = (const Form& other);

    Form(void);
    Form(const Form& other);
    ~Form(void);

    const std::string& getName(void) const;
    const int& getGradeToSign(void) const;
    const int& getGradeToExcute(void) const;

    const bool& getIsSigned(void) const;
    void setIsSigned(const bool& newIsSigned);

  private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExcute;

    bool _isSigned;
};

std::ostream& operator << (std::ostream& outStream,
                           const Form& object);
