#include <cmath>
#include <iostream>

class Shape {
  public:
    virtual ~Shape() {}

    virtual double cal_area() const = 0;
};

class Rectangle : public Shape {
  public:
    Rectangle(double width, double height) : width_(width), height_(height) {};

    double cal_area() const override {
        return width_ * height_;
    }

    double width_, height_;
};

class Circle : public Shape {
  public:
    Circle(double radius) : radius_(radius) {}

    double cal_area() const override {
        return M_PI * radius_ * radius_;
    }

  private:
    double radius_;
};

int main() {
    std::cout << "I generated a abstract class\n";
    std::cout << "---------------------------\n";

    Shape* rectangle = new Rectangle(3.0, 4.0);
    Shape* circle = new Circle(3.0);

    std::cout << "Area: " << rectangle->cal_area() << '\n';
    std::cout << "Area: " << circle->cal_area() << '\n';

    delete rectangle;
    delete circle;

    std::cout << "---------------------------\n";

    return 0;
}