#include <iostream>
#include <algorithm>
#include <vector>

class PrintVector {
  public:
    void operator()(const int item) {
        std::cout << item << ' ';
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " Number" << std::endl;
        return 1;
    }

    std::cout << "I have gererated an example of for_each and transform.\n";
    std::cout << "------------------------------\n";

    std::vector<int> input_vector;
    const int kDefaultSize = std::stoi(argv[1]);

    for (int i = 0; i < kDefaultSize; i++) {
        input_vector.push_back(i + 1);
    }

    std::for_each(input_vector.begin(), input_vector.end(), PrintVector());
    std::cout << std::endl;

    std::vector<int> destination_vector;
    destination_vector.resize(input_vector.size());

    std::transform(input_vector.begin(), input_vector.end(), destination_vector.begin(), [](const int item) {
        std::cout << item << ' ';
        return item;
    });
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}