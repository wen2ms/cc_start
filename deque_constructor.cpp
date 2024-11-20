#include <iostream>
#include <deque>

void print_deque(const std::deque<int>& deque) {
    for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "I have gererated an example of deque constructor.\n";
    std::cout << "------------------------------\n";

    std::deque<int> base_deque;
    const int kDequeSize = 10;

    for (int i = 0; i < kDequeSize; i++) {
        base_deque.push_front(i + 1);
    }
    print_deque(base_deque);

    std::deque<int> iterator_deque(base_deque.begin(), base_deque.end());
    print_deque(iterator_deque);

    std::deque<int> number_deque(10, 1);
    print_deque(number_deque);

    std::deque<int> copy_deque(base_deque);
    print_deque(copy_deque);

    std::cout << "------------------------------\n";

    return 0;
}