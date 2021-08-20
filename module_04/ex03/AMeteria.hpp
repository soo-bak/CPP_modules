#pragma once

#include <string>
#include <iostream>

class ICharacter;

class AMeteria {

  public:

    AMeteria(void);
    AMeteria(const std::string& type);
    AMeteria(const AMeteria& other);
   ~AMeteria();

   AMeteria& operator = (const AMeteria& other) = delete;

  virtual AMeteria* clone(void) const = 0;
  virtual void use(ICharacter& target);

  const std::string& getType(void) const;
  void setType(const std::string& newType);


  protected:
    std::string _type;
};
