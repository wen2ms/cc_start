#include <iostream>

class Cube {
  public:
    Cube() : height_(0), width_(0), length_(0) {}

    Cube(double height, double width, double length) : height_(height), width_(width), length_(length) {}

    double get_height() const {
        return height_;
    }

    double get_width() const {
        return width_;
    } 

    double get_length() const {
        return length_;
    }

    bool is_same(Cube& cube) const {
        if (height_ == cube.get_height() && width_ == cube.get_width() && length_ == cube.get_length()) {
            return true;
        }
        
        return false;
    }              

    double calculate_area() const {
        return 2 * (height_ * width_ + height_ * length_ + width_ * length_); 
    }

    double calculate_volume() const {
        return height_ * width_ * length_;
    }

  private:
    double height_, width_, length_;
};

int main() {
    double height, width, length;

    std::cout << "I generated a cube class\n";
    std::cout << "--------------------------\n";

    std::cout << "Please input the first cube(height, width, length): ";
    std::cin >> height >> width >> length;

    Cube cube_a(height, width, length);

    std::cout << "Please input the second cube(height, width, length): ";
    std::cin >> height >> width >> length;
       
    Cube cube_b(height, width, length);

    if (cube_a.is_same(cube_b)) {
        std::cout << "The two cubes are same\n";
    } else {
        std::cout << "The two cubes are not same\n";
    }

    std::cout << "--------------------------\n";

    return 0;
}