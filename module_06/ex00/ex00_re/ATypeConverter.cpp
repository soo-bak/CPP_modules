#include "ATypeConverter.hpp"

ATypeConverter& ATypeConverter::operator = (const ATypeConverter& other) {
  if (this == &other) {
    return *this;
  }
  _literal = other._literal;
  _typeName = other._typeName;
  _isConvertable = other._isConvertable;
  return *this;
}

ATypeConverter::ATypeConverter(void)
    : _literal(""), _typeName("unknwon"),
      _isConvertable(true) {
}

ATypeConverter::ATypeConverter(const std::string& literal)
    : _literal(literal), _typeName("unknwon"),
      _isConvertable(true) {
}

ATypeConverter::ATypeConverter(const ATypeConverter& other)
    : _literal(other._literal),
      _typeName(other._typeName),
      _isConvertable(other._isConvertable) {
}

ATypeConverter::~ATypeConverter(void) {
}

const std::string& ATypeConverter::getTypeName(void) const {
  return _typeName;
}

void ATypeConverter::_setTypeName(const std::string& typeName) {
  _typeName = typeName;
}
