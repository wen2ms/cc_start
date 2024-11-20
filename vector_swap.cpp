#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << ' ';
    } 
    std::cout << '\n';   
}

int main() {
    std::cout << "I have gererated an example of vector swap.\n";
    std::cout << "------------------------------\n";

    std::vector<int> vec;

    for (int i = 0; i < 10000; i++) {
        vec.push_back(i + 1); 
    }

    std::cout << "The size of vector: " << vec.size() << '\n';
    std::cout << "The capacity of vector: " << vec.capacity() << '\n';

    vec.resize(10);

    print_vector(vec);

    std::cout << "The size of vector: " << vec.size() << '\n';
    std::cout << "The capacity of vector: " << vec.capacity() << '\n';

    std::vector<int>(vec).swap(vec);

    std::cout << "The size of vector: " << vec.size() << '\n';
    std::cout << "The capacity of vector: " << vec.capacity() << '\n';

    std::cout << "------------------------------\n";

    return 0;
}