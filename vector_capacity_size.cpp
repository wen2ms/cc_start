#include <iostream>
#include <vector>

void print_vec(const std::vector<int>& vec);

void vec_resize() {
    std::vector<int> vec(10);

    if (vec.empty()) {
        std::cout << "The vector is empty\n";
    } else {
        std::cout << "The capacity of the vector: " << vec.capacity() << '\n';
        std::cout << "The size of the vector: " << vec.size() << '\n';
        print_vec(vec);

        vec.resize(5);
        print_vec(vec);

        vec.resize(10, 1);
        print_vec(vec);
    }  

}

void print_vec(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ' ';
    }
    std:: cout << '\n';
}

int main() {
    std::cout << "I have gererated an example of vector resizing.\n";
    std::cout << "------------------------------\n";

    vec_resize();

    std::cout << "------------------------------\n";

    return 0;
}