#include <iostream>
#include <vector>

void print_vector(const std::vector<float>& vec);

void default_constructor() {
    std::vector<float> vec;

    for (int i = 0; i < 10; i++) {
        vec.push_back(i + 1);
    }

    print_vector(vec);
}

void iterator_constructor() {
    std::vector<float> orignal_vec;

    for (int i = 0; i < 10; i++) {
        orignal_vec.push_back(i + 1);
    }

    std::vector<float> iterative_vec(orignal_vec.begin() + 2, orignal_vec.end() - 3);
    print_vector(iterative_vec);
}

void items_construtor() {
    std::vector<float> vec(3, 1.0);

    print_vector(vec);
}

void vec_assign() {
    std::vector<float> origin_vec;

    for (int i = 0; i < 10; i++) {
        origin_vec.push_back(i + 1);
    }

    std::vector<float> operator_assign_vec;
    operator_assign_vec = origin_vec;
    print_vector(operator_assign_vec);

    std::vector<float> function_assign_vec;
    function_assign_vec.assign(origin_vec.begin(), origin_vec.end());
    print_vector(function_assign_vec);
}

void print_vector(const std::vector<float>& vec) {
    for (std::vector<float>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cout << "I have gererated an example of vector assignment.\n";
    std::cout << "------------------------------\n";

    default_constructor();

    iterator_constructor();

    items_construtor();

    vec_assign();

    std::cout << "------------------------------\n";

    return 0;
}