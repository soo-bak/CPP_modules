#include <string>

#include "iter.hpp"

int main() {

  char test[5] = {'a', 'b', 'c', 'd', 'e'};
  // int test[5] = {1, 2, 3, 4, 5};
  // float test[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
  // double test[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
  // std::string test[5] = {"ABC", "DEF", "GHI", "JKL", "MNO"};

  iter(test, 5, testPrint);
  return 0;
}
