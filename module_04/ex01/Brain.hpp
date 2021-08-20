#pragma once

#include <string>
#include <iostream>

class Brain {
  public:

    static const int ideasLength = 100;

    Brain(void);
    Brain(const Brain& brain);
    ~Brain(void);

    Brain& operator = (const Brain& other);

    std::string getIdea(size_t index) const;
    void setIdea(size_t index, const std::string& newIdea);

  private:
    std::string _ideas[ideasLength];
};
