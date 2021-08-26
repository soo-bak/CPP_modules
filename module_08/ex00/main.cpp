#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <exception>

#include "easyfind.hpp"

const std::string ansiRed("\033[1;31m");
const std::string ansiPurple("\033[1;35m");
const std::string ansiBlue("\033[1;34m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiGreen("\033[1;32m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {

  std::vector<int> intVector;
  intVector.push_back(1);
  intVector.push_back(2);
  intVector.push_back(3);
  intVector.push_back(4);
  intVector.push_back(42);
  intVector.push_back(1);
  intVector.push_back(2);

  const int targetValue(1);

  std::cout << std::endl;
  std::cout << " [ " << ansiPurple << "Value of Vector members" << ansiEnd << " ]" << std::endl;
  unsigned int index(0);
  for (std::vector<int>::iterator i = intVector.begin(); i < intVector.end(); i++) {
    std::cout << "   member [" << ansiYellow << index << ansiEnd << "]" << std::endl;
    std::cout << "           value : ";
    if (&(*easyfind(intVector, targetValue)) == &(*i)) {
      std::cout << ansiCyan << *i << ansiEnd << std::endl;
    } else {
      std::cout << *i << std::endl;
    }
    std::cout << "         address : ";
    if (&(*easyfind(intVector, targetValue)) == &(*i)) {
      std::cout << ansiCyan << &(*i) << ansiEnd <<std::endl;
    } else {
      std::cout << &(*i) << std::endl;
    }
    index++;
  }
  std::cout << std::endl;

  std::cout << " [ " << ansiPurple << "Value to find" << ansiEnd << " ]" << std::endl;
  std::cout << ansiCyan << "   " << targetValue << ansiEnd << std::endl;
  std::cout << std::endl;

  std::cout << " [ " << ansiPurple << "Function " << ansiEnd << "easyfind(vector, " << ansiCyan << targetValue << ansiEnd << ") " << ansiPurple << "excuted" << ansiEnd << " ]" << std::endl;
  if (easyfind(intVector, targetValue) != intVector.end()) {
    std::cout << "   result value : ";
    std::cout << ansiCyan << *easyfind(intVector, targetValue) << ansiEnd << std::endl;
    std::cout << "   result's address : ";
    std::cout << ansiCyan << &(*easyfind(intVector, targetValue)) << ansiEnd << std::endl;
  } else {
    std::cout << ansiRed << "   Not found" << ansiEnd << std::endl;
    std::cout << "   Vector's end address : " << ansiRed;
    std::cout << &(*intVector.end()) << ansiEnd <<std::endl;
    std::cout << "   easyfind's return value address : " << ansiRed;
    std::cout << &(*easyfind(intVector, targetValue)) << ansiEnd << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
