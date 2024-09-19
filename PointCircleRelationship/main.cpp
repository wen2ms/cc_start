#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Utilities.h"

int main() {
    std::cout << "I generated a relationship between point and circle relationship\n";
    std::cout << "--------------------------------\n";

    double px, py;
    std::cout << "Enter point coordinates (x, y): ";
    std::cin >> px >> py;
    Point p(px, py);

    double center_x, center_y, radius;
    std::cout << "Enter circle center coordinates (x, y) and radius: ";
    std::cin >> center_x >> center_y >> radius;
    Circle c(Point(center_x, center_y), radius);

    PointCircleRelationship relationship = compute_point_circle_relationship(c, p);

    switch (relationship) {
        case kInside:
            std::cout << "The point is inside the circle\n";
            break;
        case kOnCircumference:
            std::cout << "The point is on the circumference of the circle\n";
            break;
        case kOutside:
            std::cout << "The point is outside the circle\n";
            break;
    }

    std::cout << "--------------------------------\n";

    return 0;
}