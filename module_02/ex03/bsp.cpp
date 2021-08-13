#include "Fixed.hpp"
#include "Fixed.hpp"
#include "Point.hpp"

//cross (vector d12 X vector d13)
Fixed crossProduct(const Point& p1, const Point& p2,
                   const Point& p3) {
  Fixed result;
  result = ((p2.getX() - p1.getX()) * (p3.getY() - p1.getY()))
           - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
  return result;
}

// Binary Space Partitioning
bool bsp(const Point a, const Point b, const Point c,
         const Point point) {
  Fixed crossABP(crossProduct(a, b, point));
  Fixed crossBCP(crossProduct(b, c, point));
  Fixed crossCAP(crossProduct(c, a, point));

  if ((crossABP > 0) && (crossBCP > 0) && (crossCAP > 0)) {
    return true;
  } else if ((crossABP < 0) && (crossBCP < 0) && (crossCAP < 0)) {
    return true;
  } else {
    return false;
  }
}
