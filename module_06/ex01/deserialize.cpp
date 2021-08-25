#include <stdint.h>

#include "Data.hpp"

Data* deserialize(uintptr_t raw) {
  Data* returnPtr;
  returnPtr = reinterpret_cast<Data*>(raw);
  return returnPtr;
}
