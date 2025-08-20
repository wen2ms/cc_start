#include <cstdlib>
#include <iostream>
#include <stack>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a size for the command-line argument";
        return 1;
    }

    std::cout << "I have gererated an example of stack\n";
    std::cout << "------------------------------\n";

    std::stack<int> basic_stack;
    const int kStackSize = std::atoi(argv[1]);

    for (int i = 0; i < kStackSize; i++) {
        basic_stack.push(i + 1);
    }

    std::cout << "The stack size: " << basic_stack.size() << '\n';

    std::cout << "The top element of the stack: ";
    while (!basic_stack.empty()) {
        std::cout << basic_stack.top() << ' ';

        basic_stack.pop();
    }
    std::cout << '\n';

    // segmentation fault
    // basic_stack.pop();

    std::cout << "------------------------------\n";

    return 0;
}