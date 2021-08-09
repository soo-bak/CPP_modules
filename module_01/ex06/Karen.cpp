#include "Karen.hpp"

const std::string colorStart("\033[1;31m");
const std::string colorEnd("\033[0m");

const std::string Karen::_validLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Karen::Karen(void) {
  _levelFunctions[Debug] = &Karen::_debug;
  _levelFunctions[Info] = &Karen::_info;
  _levelFunctions[Warning] = &Karen::_warning;
  _levelFunctions[Error] = &Karen::_error;
}

Karen::~Karen(void) {
}

void Karen::filter(std::string level) {
  int levelValue(Debug);
  while ((levelValue <= Error) && (level != _validLevels[levelValue])) {
    levelValue++;
  }
  switch (levelValue) {
    case Debug:
      _debug();
      std::cout << std::endl;
    case Info:
      _info();
      std::cout << std::endl;
    case Warning:
      _warning();
      std::cout << std::endl;
    case Error:
      _error();
      std::cout << std::endl;
      break ;
    default:
      std::cout << colorStart;
      std::cout << "[ Probably complaining about insignificant problems ]";
      std::cout << std::endl;
      std::cout << colorEnd;
  }
  return ;
}

void Karen::complain(std::string level) {
  for (int i = Debug; i <= Error; i++) {
    if (_validLevels[i].compare(level) == 0) {
      (this->*_levelFunctions[i])();
    }
  }
  return ;
}

void Karen::_debug(void) {
  std::cout << colorStart << "[ DEBUG ]" << colorEnd << std::endl;
  std::cout << "I love to get extra bacon for my ";
  std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
  std::cout << "I just love it!" << std::endl;
  return ;
}

void Karen::_info(void) {
  std::cout << colorStart << "[ INFO ]" << colorEnd << std::endl;
  std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
  std::cout << "You don't put enough!" << std::endl;
  std::cout << "If you did I would not have to ask for it!" << std::endl;
  return ;
}

void Karen::_warning(void) {
  std::cout << colorStart << "[ WARNING ]" << colorEnd << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
  std::cout << "I've been coming here for years ";
  std::cout << "and you just started working here last month." << std::endl;
  return ;
}

void Karen::_error(void) {
  std::cout << colorStart << "[ ERROR ]" << colorEnd << std::endl;
  std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
  return ;
}
