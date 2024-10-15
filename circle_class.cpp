#include <cstdlib>
#include <iostream>

const double kPI = 3.1415926;

class Circle {
  public:
    int radius_;

    double calculate_perimeter(void) {
        return 2 * kPI * radius_;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide a radius as command-line argument\n";
        return 1;
    }

    Circle circle;

    circle.radius_ = std::atoi(argv[1]);

    std::cout << "I generated a circle class\n";
    std::cout << "---------------------------\n";

    std::cout << "The perimeter of a circle: " << circle.calculate_perimeter() << '\n';

    std::cout << "---------------------------\n";

    return 0;
}