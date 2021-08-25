#include <iostream>
#include <exception>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* P) {
  A* a = dynamic_cast<A*>(P);
  if (a != NULL) {
    std::cout << "A" << std::endl;
  }
  B* b = dynamic_cast<B*>(P);
  if (b != NULL) {
    std::cout << "B" << std::endl;
  }
  C* c = dynamic_cast<C*>(P);
  if (c != NULL) {
    std::cout << "C" << std::endl;
  }
  return ;
}

void identify(Base& P) {
  try {
    A& a = dynamic_cast<A&>(P);
    std::cout << "A" << std::endl;
    (void)a;
    return ;
  }
  catch (std::exception) {
  }
  try {
    B& b = dynamic_cast<B&>(P);
    std::cout << "B" << std::endl;
    (void)b;
    return ;
  }
  catch (std::exception) {
  }
  try {
    C& c = dynamic_cast<C&>(P);
    std::cout << "C" << std::endl;
    (void)c;
    return ;
  }
  catch (std::exception) {
  }
}
