#include "Brain.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiYellow("\033[1;34m");
const std::string ansiEnd("\033[0m");

Brain::Brain(void) {
  std::cout << "Default constructor of '" << ansiYellow;
  std::cout << "Brain"<< ansiEnd << "' called." << std::endl;
}

Brain::Brain(const Brain& brain) {
  *this = brain;
  std::cout << "Copy constructor of '" << ansiYellow;
  std::cout << "Brain"<< ansiEnd << "' called." << std::endl;
}

Brain::~Brain(void) {
  std::cout << "Destructor of '" << ansiYellow;
  std::cout << "Brain"<< ansiEnd << "' called." << std::endl;
}

Brain& Brain::operator = (const Brain& other) {
   std::cout << "Assignation operator of '" << ansiYellow;
   std::cout << "Brain"<< ansiEnd << "' called." << std::endl;
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < ideasLength; i++) {
    setIdea(i, other.getIdea(i));
  }
  return *this;
}

void Brain::setIdea(size_t index, const std::string& newIdea) {
  _ideas[index] = newIdea;
  return ;
}

std::string Brain::getIdea(size_t index) const {
  return _ideas[index];
}
