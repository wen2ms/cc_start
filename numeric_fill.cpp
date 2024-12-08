#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of fill algorithm" << std::endl;
    std::cout << "-------------------" << std::endl;

    std::vector<float> float_numbers;
    const int kInputSize = std::stoi(argv[1]);

    for (int i = 0; i < kInputSize; ++i) {
        float_numbers.push_back(i + 1);
    }

    std::for_each(float_numbers.begin(), float_numbers.end(), [](float item) {
        std::cout << item << ' ';
    });
    std::cout << std::endl;

    std::fill(float_numbers.begin(), float_numbers.end(), 0.0);

    std::for_each(float_numbers.begin(), float_numbers.end(), [](float item) {
        std::cout << item << ' ';
    });
    std::cout << std::endl;


    std::cout << "-------------------" << std::endl;

    return 0;
}