#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <random>
#include <deque>
#include <functional>

void print_deuqe_item(int item) {
    std::cout << item << ' ';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of stl sort algorithm\n";
    std::cout << "------------------------------\n";

    const int kInputSize = std::stoi(argv[1]);

    std::deque<int> input_deque;
    for (int i = 0; i < kInputSize; i++) {
        input_deque.push_back(i + 1);
    }

    std::mt19937 random_generation(std::time(nullptr));
    std::shuffle(input_deque.begin(), input_deque.end(), random_generation);
    
    std::cout << "Input deque: ";
    std::for_each(input_deque.begin(), input_deque.end(), print_deuqe_item);
    std::cout << std::endl;

    std::sort(input_deque.begin(), input_deque.end(), std::greater<int>());

    std::cout << "Descending order deque: ";
    std::for_each(input_deque.begin(), input_deque.end(), print_deuqe_item);
    std::cout << std::endl;

    std::deque<int> duplicate_deque(input_deque);
    std::deque<int> merged_deque;
    
    merged_deque.resize(input_deque.size() + duplicate_deque.size());
    std::merge(input_deque.begin(), input_deque.end(), duplicate_deque.begin(), duplicate_deque.end(), merged_deque.begin(), std::greater<int>());

    std::cout << "Merged deque: ";
    std::for_each(merged_deque.begin(), merged_deque.end(), print_deuqe_item);
    std::cout << std::endl;

    std::reverse(merged_deque.begin(), merged_deque.end());

    std::cout << "Reversed deque: ";
    std::for_each(merged_deque.begin(), merged_deque.end(), print_deuqe_item);
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}