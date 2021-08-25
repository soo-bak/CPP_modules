#include <iostream>
#include <exception>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

const std::string ansiPurple("\033[1;35m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

void identify(Base* P) {
  A* a = dynamic_cast<A*>(P);
  if (a != NULL) {
    std::cout << ansiPurple << "A" << ansiEnd << std::endl;
  }
  B* b = dynamic_cast<B*>(P);
  if (b != NULL) {
    std::cout << ansiGreen << "B" << ansiEnd << std::endl;
  }
  C* c = dynamic_cast<C*>(P);
  if (c != NULL) {
    std::cout << ansiCyan << "C" << ansiEnd << std::endl;
  }
  return ;
}

void identify(Base& P) {
  try {
    A& a = dynamic_cast<A&>(P);
    std::cout << ansiPurple << "A" << ansiEnd << std::endl;
    (void)a;
    return ;
  }
  catch (std::exception) {
  }
  try {
    B& b = dynamic_cast<B&>(P);
    std::cout << ansiGreen << "B" << ansiEnd << std::endl;
    (void)b;
    return ;
  }
  catch (std::exception) {
  }
  try {
    C& c = dynamic_cast<C&>(P);
    std::cout << ansiCyan << "C" << ansiEnd << std::endl;
    (void)c;
    return ;
  }
  catch (std::exception) {
  }
}
