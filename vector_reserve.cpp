#include <iostream>
#include <vector>

void check_expansion_times(std::vector<int>& vec, int reserve_size) {
    int* p = nullptr;
    int expansion_times = 0;

    for (int i = 0; i < reserve_size; i++) {
        vec.push_back(i + 1);

        if (p != &vec[0]) {
            p = &vec[0];
            expansion_times++;
        }
    }

    std::cout << "The vector expansion time: " << expansion_times << std::endl;
}

int main() {
    std::cout << "I have gererated an example of vector reserve.\n";
    std::cout << "------------------------------\n";
    
    std::vector<int> vec;
    const int kReserveSize = 10000;

    check_expansion_times(vec, kReserveSize);

    vec.clear();
    std::cout << "The capacity of the vector: " << vec.capacity() << std::endl;

    std::vector<int>().swap(vec);
    std::cout << "The capacity of the vector: " << vec.capacity() << std::endl;

    vec.reserve(kReserveSize);

    check_expansion_times(vec, kReserveSize);

    std::cout << "------------------------------\n";
    return 0;
}