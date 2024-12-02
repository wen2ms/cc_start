#ifndef UTILITIES_H
#define UTILITIES_H

#include <cmath>

#include "circle.h"
#include "point.h"
#include "point_circle_relationship.h"

double euclidean_distance(const Point& a, const Point& b);

PointCircleRelationship compute_point_circle_relationship(const Circle& circle, const Point& point);

#endif