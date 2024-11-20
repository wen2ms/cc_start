#include <iostream>
#include <deque>

void print_deque(const std::deque<int>& deque) {
    for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "I have gererated an example of deque insertion and erasure.\n";
    std::cout << "------------------------------\n";

    std::deque<int> base_deque;
    const int kDequeSize = 10;

    for (int i = 0; i < kDequeSize; i++) {
        base_deque.push_front(i + 1);
    }
    print_deque(base_deque);

    for (int i = 0; i < kDequeSize / 2; i++) {
        base_deque.pop_front();
    }
    print_deque(base_deque);

    base_deque.insert(base_deque.end(), 0);
    print_deque(base_deque);

    base_deque.insert(base_deque.end(), 1, -1);
    print_deque(base_deque);

    base_deque.erase(base_deque.end() - 2, base_deque.end());
    print_deque(base_deque);

    std::cout << "------------------------------\n";

    return 0;
}