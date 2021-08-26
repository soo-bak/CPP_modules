#pragma once

#include <iostream>

template <typename T>
void iter(T* array, const unsigned int& length,
          void (*f)(const T&)) {
  for (unsigned int i = 0; i < length; i++) {
    (*f)(array[i]);
  }
  return ;
}

template <typename T>
void testPrint(const T& value) {
  std::cout << value << std::endl;
  return ;
}
