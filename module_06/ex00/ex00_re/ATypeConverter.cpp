#include "ATypeConverter.hpp"

ATypeConverter& ATypeConverter::operator = (const ATypeConverter& other) {
  if (this == &other) {
    return *this;
  }
  _literal = other._literal;
  _isConvertable = other._isConvertable;
  return *this;
}

ATypeConverter::ATypeConverter(void) {
}

ATypeConverter::ATypeConverter(const std::string& literal)
    : _literal(literal), _isConvertable(true) {
}

ATypeConverter::ATypeConverter(const ATypeConverter& other)
    : _literal(other._literal),
      _isConvertable(other._isConvertable) {
}


ATypeConverter::~ATypeConverter(void) {
}

const std::string& ATypeConverter::getLiteral(void) const {
  return _literal;
}

void ATypeConverter::setLiteral(const std::string& newTypeName) {
  _literal = newTypeName;
  return ;
}

const bool& ATypeConverter::getIsConvertable(void) const {
  return _isConvertable;
}

void ATypeConverter::setIsConvertable(const bool& boolean) {
  _isConvertable = boolean;
  return ;
}
