#include <stdint.h>

#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
  uintptr_t returnPtr;
  returnPtr = reinterpret_cast<uintptr_t>(ptr);
  return returnPtr;
}
