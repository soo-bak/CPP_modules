#include "Brain.hpp"

const std::string ansiItalic("\033[3;37m");
const std::string ansiYellow("\033[1;34m");
const std::string ansiEnd("\033[0m");

Brain::Brain(void) {
  std::cout << "Default constructor of '" << ansiYellow;
  std::cout << "Brain"<< ansiEnd << "' called." << std::endl;
}

Brain::~Brain(void) {
  std::cout << "Destructor of '" << ansiYellow;
  std::cout << "Brain"<< ansiEnd << "' called." << std::endl;
}

std::string Brain::getIdea(size_t index) const {
  return _ideas[index];
}
