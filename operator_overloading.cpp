#include <iostream>

class Point {
  public:
    Point(double x = 0, double y = 0) : x_(x), y_(y) {} 

    Point operator+(const Point& point) {
        return Point(x_ + point.x_, y_ + point.y_);
    }

    Point& operator++() {
        x_ ++;
        y_ ++;
        return *this;
    }

    Point operator++(int) {
        Point temp = *this;

        x_ ++;
        y_ ++;
        
        return temp;
    }

    bool operator==(const Point& point) {
        return (x_ == point.x_ && y_ == point.y_) ? true : false;
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
    std::cout << "Point1 ++ = " << point1 ++ << "   ++ Point1 = " << ++ point1 << '\n';
    
    Point point3(2, 2);

    if (point1 == point3) {
        std::cout << "Point1 and Point3 are equal\n";
    } else {
        std::cout << "Point1 and Point3 are not equal\n";
    }

    std::cout << "----------------------\n";

    return 0;
}