#include "AType.hpp"

AType& AType::operator = (const AType& other) {
  if (this == &other) {
    return *this;
  }
  _typeName = other._typeName;
  _isConvertable = other._isConvertable;
  return *this;
}

AType::AType(void) {
}

AType::AType(const std::string& typeName)
    : _typeName(typeName), _isConvertable(true) {
}

AType::AType(const AType& other)
    : _typeName(other._typeName),
      _isConvertable(other._isConvertable) {
}


AType::~AType(void) {
}

const std::string& AType::getTypeName(void) const {
  return _typeName;
}

void AType::setTypeName(const std::string& newTypeName) {
  _typeName = newTypeName;
  return ;
}

const bool& AType::getIsConvertable(void) const {
  return _isConvertable;
}

void AType::setIsConvertable(const bool& boolean) {
  _isConvertable = boolean;
  return ;
}
