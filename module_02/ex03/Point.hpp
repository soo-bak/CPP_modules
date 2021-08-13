#pragma once

#include "Fixed.hpp"

class Point {
  public:
    Point(void);
    Point(const Point& point);
    Point(const float& x, const float& y);
    ~Point(void);

    Point& operator = (const Point& other);

    const Fixed& getX(void) const;
    const Fixed& getY(void) const;

  private:
    const Fixed _x;
    const Fixed _y;
};
