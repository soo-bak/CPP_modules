#include "Karen.hpp"

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
      _displayLevelInformation(levelValue);
      levelValue++;
    case Info:
      _displayLevelInformation(levelValue);
      levelValue++;
    case Warning:
      _displayLevelInformation(levelValue);
      levelValue++;
    case Error:
      _displayLevelInformation(levelValue);
      break ;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]";
      std::cout << std::endl;
  }
}

void Karen::_displayLevelInformation(int levelValue) {
  std::cout << "[ " << _validLevels[levelValue] << " ]" << std::endl;
  (this->*_levelFunctions[levelValue])();
  std::cout << std::endl;
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
  std::cout << "I love to get extra bacon for my ";
  std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
  std::cout << "I just love it!" << std::endl;
  return ;
}

void Karen::_info(void) {
  std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
  std::cout << "You don't put enough!" << std::endl;
  std::cout << "If you did I would not have to ask for it!" << std::endl;
  return ;
}

void Karen::_warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
  std::cout << "I've been coming here for years ";
  std::cout << "and you just started working here last month." << std::endl;
  return ;
}

void Karen::_error(void) {
  std::cout << "This is unacceptable, ";
  std::cout << "I want to speak to the manager now." << std::endl;
  return ;
}
