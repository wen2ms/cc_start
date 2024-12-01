#include <algorithm>
#include <iostream>
#include <functional>
#include <list>
#include <vector>

int main() {
    std::cout << "I generated an example of build-in functors\n";
    std::cout << "------------------------------\n";

    std::list<int> val_vector;
    const int kValsNumber = 10;

    for (int i = 0; i < kValsNumber; i++) {
        val_vector.push_back(i + 1);
    }

    std::list<int> plus_val_vector;
    for (int i = 0; i < kValsNumber - 1; i++) {
        std::plus<int> build_in_plus;
        plus_val_vector.push_back(build_in_plus(i + 1, i + 2));
    }

    val_vector.sort(std::greater<int>());
    plus_val_vector.sort(std::greater<int>());

    std::for_each(val_vector.begin(), val_vector.end(), [](int i) {
        std::cout << i << ' ';
    });
    std::cout << std::endl;

    std::for_each(plus_val_vector.begin(), plus_val_vector.end(), [](int i) {
        std::cout << i << ' ';
    });
    std::cout << std::endl;

    std::vector<bool> bool_vector({true, false, true, false});
    std::vector<bool> not_bool_vector(bool_vector.size());

    std::transform(bool_vector.begin(), bool_vector.end(), not_bool_vector.begin(), std::logical_not<bool>());

    for (int i = 0; i < not_bool_vector.size(); i++) {
        std::cout << not_bool_vector[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}