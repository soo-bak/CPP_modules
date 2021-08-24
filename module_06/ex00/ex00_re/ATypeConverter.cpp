#include "ATypeConverter.hpp"

ATypeConverter& ATypeConverter::operator = (const ATypeConverter& other) {
  if (this == &other) {
    return *this;
  }
  _typeName = other._typeName;
  _isConvertable = other._isConvertable;
  return *this;
}

ATypeConverter::ATypeConverter(void) {
}

ATypeConverter::ATypeConverter(const std::string& typeName)
    : _typeName(typeName), _isConvertable(true) {
}

ATypeConverter::ATypeConverter(const ATypeConverter& other)
    : _typeName(other._typeName),
      _isConvertable(other._isConvertable) {
}


ATypeConverter::~ATypeConverter(void) {
}

const std::string& ATypeConverter::getTypeName(void) const {
  return _typeName;
}

void ATypeConverter::setTypeName(const std::string& newTypeName) {
  _typeName = newTypeName;
  return ;
}

const bool& ATypeConverter::getIsConvertable(void) const {
  return _isConvertable;
}

void ATypeConverter::setIsConvertable(const bool& boolean) {
  _isConvertable = boolean;
  return ;
}
