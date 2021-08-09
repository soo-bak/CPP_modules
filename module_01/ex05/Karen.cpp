#include "Karen.hpp"

const std::string Karen::_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Karen::Karen(void)
 : _levelFunction(NULL) {
}

Karen::~Karen(void) {
}

void Karen::complain(std::string levelInput) {
  _setLevelFunction(levelInput);
  (this->*_levelFunction)();
  return ;
}

void Karen::_setLevelFunction(std::string& levelInput) {
  Levels levels(static_cast<Levels>(levelInput[0]));
  switch (levels) {
    case Debug:
      _levelFunction = &Karen::_debug;
      break ;
    case Info:
      _levelFunction = &Karen::_info;
      break ;
    case Warning:
      _levelFunction = &Karen::_warning;
      break ;
    case Error:
      _levelFunction = &Karen::_error;
      break ;
    default:
      std::cout << levelInput << " is invalid." << std::endl;
      exit(0);
  }
  return ;
}

void Karen::_debug(void) {
  std::cout << "I love to get extra bacon for my ";
  std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
  std::cout << "I just love it!" << std::endl;
  return ;
}

void Karen::_info(void) {
  std::cout << "I cannot believe adding extra bacon cost more money. ";
  std::cout << "You don't put enough! ";
  std::cout << "If you did I would not have to ask for it!" << std::endl;
  return ;
}

void Karen::_warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free. ";
  std::cout << "I've been coming here for years ";
  std::cout << "and you just started working here last month." << std::endl;
  return ;
}

void Karen::_error(void) {
  std::cout << "This is unacceptable, I want to speak to the manager now.";
  std::cout << std::endl;
  return ;
}
