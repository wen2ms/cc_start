#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class PrintNumber {
  public:
    void operator()(const int element) const {
        std::cout << element << ' ';
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of set union\n";
    std::cout << "------------------------------\n";

    const int kInputSize = std::stoi(argv[1]);
    std::vector<int> input_numbers1;
    std::vector<int> input_numbers2;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < kInputSize; ++i) {
        input_numbers1.push_back(std::rand() % 10);
        input_numbers2.push_back(std::rand() % 10);
    }

    std::sort(input_numbers1.begin(), input_numbers1.end());
    std::sort(input_numbers2.begin(), input_numbers2.end());

    std::for_each(input_numbers1.begin(), input_numbers1.end(), PrintNumber());
    std::cout << std::endl;

    std::for_each(input_numbers2.begin(), input_numbers2.end(), PrintNumber());
    std::cout << std::endl;

    std::vector<int> output_numbers;
    output_numbers.resize(input_numbers1.size() + input_numbers2.size());

    std::vector<int>::iterator end_position = std::set_union(input_numbers1.begin(), input_numbers1.end(), input_numbers2.begin(),
                                                             input_numbers2.end(), output_numbers.begin());

    std::for_each(output_numbers.begin(), end_position, PrintNumber());
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}