#include <iostream>
#include <vector>

class Square {
  public:
    int operator()(int x) {
        number_calls_++;

        return x * x;
    }

    int number_calls_;
};

void print_square(Square square, const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << square(*it) << ' ';
    }
    std::cout << std::endl;

    std::cout << "The number of calls: " << square.number_calls_ << std::endl;
}

int main() {
    std::cout << "I have gererated an example of function object\n";
    std::cout << "------------------------------\n";

    std::vector<int> vec = {1, 2, 3, 4};

    print_square(Square(), vec);

    std::cout << "------------------------------\n";

    return 0;
}