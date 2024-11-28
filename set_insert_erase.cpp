#include <ctime>
#include <cstdlib>
#include <iostream>
#include <set>

void display_set(const std::set<int>& basic_set) {
    for (std::set<int>::const_iterator it = basic_set.begin(); it != basic_set.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "I have gererated an example of set's insertion and erasure\n";
    std::cout << "------------------------------\n";

    std::set<int> basic_set;
    const int set_size = 10;

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < set_size; i++) {
        basic_set.insert(std::rand() % 100 + 1);
    }

    display_set(basic_set);

    basic_set.erase(basic_set.begin());
    display_set(basic_set);

    basic_set.erase(*basic_set.begin());
    display_set(basic_set);

    std::cout << "------------------------------\n";

    return 0;
}