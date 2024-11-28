#include <ctime>
#include <cstdlib>
#include <iostream>
#include <set>

class DescendSort {
  public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    std::cout << "I have gererated an example of set custom sorting\n";
    std::cout << "------------------------------\n";

    std::set<int, DescendSort> basic_set;

    std::srand(static_cast<unsigned int>(std::time(0)));

    const int kSetSize = 10;
    for (int i = 0; i < kSetSize; i++) {
        basic_set.insert(std::rand() % 10 + 1);
    }

    for (std::set<int, DescendSort>::iterator it = basic_set.begin(); it != basic_set.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}