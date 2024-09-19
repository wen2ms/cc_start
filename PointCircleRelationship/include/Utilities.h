#ifndef UTILITIES_H
#define UTILITIES_H

#include "Point.h"
#include "Circle.h"
#include "PointCircleRelationship.h"
#include <cmath>

double euclidean_distance(const Point& a, const Point& b);

PointCircleRelationship compute_point_circle_relationship(const Circle& circle, const Point& point);

#endif