#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << "Size TargetNumber" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of stl binary search\n";
    std::cout << "------------------------------\n";

    const int kInputSize = std::stoi(argv[1]);

    std::set<int> input_set;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < kInputSize; i++) {
        input_set.insert(std::rand() % 100);
    }

    for (std::set<int>::iterator it = input_set.begin(); it != input_set.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    const int kTargetNumber =  std::stoi(argv[2]);
    if (std::binary_search(input_set.begin(), input_set.end(), kTargetNumber)) {
        std::cout << "Found Successfully" << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    std::cout << "------------------------------\n";

    return 0;
}