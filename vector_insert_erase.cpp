#include <iostream>
#include <cstdlib>
#include <vector>

void print_vector(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a vector size for command-line argument\n";
        return 1;
    }

    std::cout << "I have gererated an example of vector insertion and erasure.\n";
    std::cout << "------------------------------\n";

    std::vector<int> custom_vector;
    const int kVectorSize = std::atoi(argv[1]);

    for (int i = 0; i < kVectorSize; i++) {
        custom_vector.push_back(i + 1);
    }
    print_vector(custom_vector);

    for (int i = 0; i < kVectorSize / 2; i++) {
        custom_vector.erase(custom_vector.begin() + i + 1);
    }
    print_vector(custom_vector);

    for (int i = 0; i < kVectorSize / 2; i++) {
        custom_vector.insert(custom_vector.begin() + 2 * i + 1, 1, 2 * i + 2);
    }
    print_vector(custom_vector);

    for (int i = 0; i < kVectorSize - 1; i++) {
        custom_vector.pop_back();
    }
    print_vector(custom_vector);

    custom_vector.clear();
    print_vector(custom_vector);

    std::cout << "------------------------------\n";

    return 0;
}