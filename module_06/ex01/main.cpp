#include <iostream>
#include <stdint.h>

#include "Data.hpp"

uintptr_t serialized(Data* ptr);
Data* deserialized(uintptr_t raw);

const std::string ansiRed("\033[1;31m");
const std::string ansiYellow("\033[1;33m");
const std::string ansiCyan("\033[1;36m");
const std::string ansiEnd("\033[0m");

int main() {
  Data initialData;
  initialData.dataName = "Initial";
  initialData.value = 42;
  std::cout << std::endl;
  std::cout << "[ " << ansiRed << "Initial Data structure" << ansiEnd << " ]";
  std::cout << std::endl;
  std::cout << "   address : ";
  std::cout << ansiCyan << &initialData << ansiEnd << std::endl;
  std::cout << "   name : ";
  std::cout << ansiYellow << initialData.dataName << ansiEnd << std::endl;
  std::cout << "   value : ";
  std::cout << ansiYellow << initialData.value << ansiEnd << std::endl;
  std::cout << std::endl;

  uintptr_t serializedIntPtr;
  serializedIntPtr = serialized(&initialData);

  std::cout << "[ " << ansiRed << "Serialized int type pointer" << ansiEnd << " ]";
  std::cout << std::endl;
  std::cout << "   pointer value in decimal integer : ";
  std::cout << serializedIntPtr << std::endl;
  std::cout << "   pointer value in hexadecimal : ";
  std::cout << std::showbase << std::hex;
  std::cout << ansiCyan << serializedIntPtr << ansiEnd << std::endl;
  std::cout << std::dec;
  std::cout << std::endl;

  Data* deserializedDataPtr;
  deserializedDataPtr = deserialized(serializedIntPtr);
  std::cout << "[ " << ansiRed << "Deserialized Data type pointer" << ansiEnd << " ]";
  std::cout << std::endl;
  std::cout << "   pointer value : ";
  std::cout << ansiCyan << deserializedDataPtr << ansiEnd << std::endl;
  std::cout << std::endl;

  std::cout << "[ " << ansiRed << "Referencing pointer" << ansiEnd << " ]";
  std::cout << std::endl;
  std::cout << "   name : ";
  std::cout << ansiYellow << deserializedDataPtr->dataName << ansiEnd << std::endl;
  std::cout << "   value : ";
  std::cout << ansiYellow << deserializedDataPtr->value << ansiEnd << std::endl;
  std::cout << std::endl;

  return 0;
}
