#include <iostream>
#include <list>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << "Number" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of adjacent_find_if\n";
    std::cout << "------------------------------\n";

    const int kInputSize = std::stoi(argv[1]);
    std::list<int> input_list;

    for (int i = 0; i < kInputSize; i++) {
        input_list.push_back(i);
        input_list.push_front(i);
    }

    for (std::list<int>::iterator it = input_list.begin(); it != input_list.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::list<int>::iterator adjacent_iterator = std::adjacent_find(input_list.begin(), input_list.end());
    if (adjacent_iterator == input_list.end()) {
        std::cout << "Not Adjacent Found" << std::endl;
    } else {
        std::cout << "Found Successfully, the adjacent is " << *adjacent_iterator << std::endl;
    }

    std::cout << "------------------------------\n";

    return 0;
}