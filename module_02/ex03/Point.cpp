#include "Point.hpp"

Point::Point(void)
    : _x(0), _y(0) {
}

Point::Point(const Point& point)
    : _x(point._x), _y(point._y) {
}

Point::Point(const float& x, const float& y)
    : _x(x), _y(y) {
}

Point::~Point(void) {
}

Point& Point::operator = (const Point& other) {
  if (this == &other) {
    return *this;
  }
}

const Fixed& Point::getX(void) {
  return _x;
}

const Fixed& Point::getY(void) {
  return _y;
}
