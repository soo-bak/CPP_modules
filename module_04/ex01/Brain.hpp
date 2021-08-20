#pragma once

#include <string>
#include <iostream>
#include <typeinfo>

class Brain {
  public:

    static const int ideasLength = 100;

    Brain(void);
    Brain(const Brain& brain);
    ~Brain(void);

    Brain& operator = (const Brain& other);

    std::string getIdea(size_t index) const;

  private:
    std::string _ideas[ideasLength];
};
