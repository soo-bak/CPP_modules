#include "AType.hpp"

AType& AType::operator = (const AType& other) {
  if (this == &other) {
    return *this;
  }
  _literal = other._literal;
  _isConvertable = other._isConvertable;
  return *this;
}

AType::AType(const std::string& literal)
    : _literal(literal), _isConvertable(true) {

}

AType::AType(const AType& other)
    : _literal(other._literal),
      _isConvertable(other._isConvertable) {
}

AType::AType(void) {
}

AType::~AType(void) {
}

const std::string& AType::getLiteral(void) const {
  return _literal;
}

void AType::setLiteral(const std::string& newLiteralValue) {
  _literal = newLiteralValue;
  return ;
}

const bool& AType::getIsConvertable(void) const {
  return _isConvertable;
}

void AType::setIsConvertable(const bool& boolean) {
  _isConvertable = boolean;
  return ;
}
