#include <iostream>

class Point {
  public:
    Point(double x = 0, double y = 0) : x_(x), y_(y) {} 

    Point operator+(const Point& point) {
        return Point(x_ + point.x_, y_ + point.y_);
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << '(' << point.x_ << ", " << point.y_ << ')';
        return out;
    }

    double x_, y_;
};

int main() {
    std::cout << "I generated an example of operator overloading.\n";
    std::cout << "----------------------\n";

    Point point1(0, 0), point2(1, 1);

    std::cout << "Point1 + Point2 = " << point1 + point2 << '\n';

    std::cout << "----------------------\n";

    return 0;
}