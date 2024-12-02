#include "utilities.h"

double euclidean_distance(const Point& a, const Point& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

PointCircleRelationship compute_point_circle_relationship(const Circle& circle, const Point& point) {
    double distance = euclidean_distance(circle.center, point);

    if (distance < circle.radius - 1e-9) {
        return kInside;
    } else if (std::abs(distance - circle.radius) < 1e-9) {
        return kOnCircumference;
    } else {
        return kOutside;
    }
}