#include <ctime>
#include <cstdlib>
#include <iostream>
#include <map>

class Point {
  public:
    Point() {}

    Point(int x, int y, int value) : postion_(x, y), value_(value) {}

    std::pair<int, int> postion_;
    int value_;
};

class CustomSort {
  public:
    bool operator()(std::pair<int, int> p1, std::pair<int, int> p2) const {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        } else {
            return p1.second < p2.second;
        }
    }
};

int main() {
    std::cout << "I have gererated an example of map find and count\n";
    std::cout << "------------------------------\n";

    std::map<std::pair<int, int>, Point, CustomSort> points_map;

    std::srand(static_cast<unsigned int>(std::time(0)));
    
    const int kMapSize = 5;
    for (int i = 0; i < kMapSize; i++) {
        int x = std::rand() % 10;
        int y = std::rand() % 10;
        int value = std::rand() % 255;

        Point point(x, y, value);
        points_map.insert(std::make_pair(point.postion_, point));
    }

    for (std::map<std::pair<int, int>, Point, CustomSort>::iterator it = points_map.begin(); it != points_map.end(); it++) {
        std::cout << '(' << it->second.postion_.first << ' ' << it->second.postion_.second << ' ' << it->second.value_ << ") ";
    }
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}