#pragma once

#include <string>
#include <iostream>

class ICharacter;

class AMateria {

  public:

    AMateria(void);
    AMateria(const std::string& type);
    AMateria(const AMateria& other);
   ~AMateria();

   AMateria& operator = (const AMateria& other) = delete;

  virtual AMateria* clone(void) const = 0;
  virtual void use(ICharacter& target);

  const std::string& getType(void) const;
  void setType(const std::string& newType);


  protected:
    std::string _type;
};
