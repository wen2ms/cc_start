#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle {
  public:
    Point center;
    double radius;

    Circle(Point center = Point(), double radius = 0.0);
};

#endif