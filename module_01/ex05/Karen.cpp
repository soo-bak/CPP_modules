#include "Karen.hpp"

const std::string Karen::_validLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Karen::Karen(void) {
  _levelFunction[Debug] = &Karen::_debug;
  _levelFunction[Info] = &Karen::_info;
  _levelFunction[Warning] = &Karen::_warning;
  _levelFunction[Error] = &Karen::_error;
}

Karen::~Karen(void) {
}

void Karen::complain(std::string levelInput) {
  int levelValue(Debug);
  while ((levelValue <= Error) && (levelInput != _validLevels[levelValue])) {
    levelValue++;
  }
  switch (levelValue) {
    case Debug:
      (this->*_levelFunction[Debug])();
      break ;
    case Info:
      (this->*_levelFunction[Info])();
      break ;
    case Warning:
      (this->*_levelFunction[Warning])();
      break ;
    case Error:
      (this->*_levelFunction[Error])();
      break ;
    default:
      std::cout << "It is 'REAL' compile error, not karen's.";
      std::cout << "Maybe <"<< levelInput << "> is Invalid level." << std::endl;
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
