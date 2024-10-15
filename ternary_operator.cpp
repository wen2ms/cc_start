#include <iostream>

int main(void) {
    int x, y, z;

    std::cout << "---------------------------\n";
    std::cout << "max function: z = max(x, y)\n";
    std::cout << "this function takes two integers as input and returns the larger one.\n";
    std::cout << "---------------------------\n";
    std::cin >> x >> y;

    std::cout << "z = " << (x > y ? x : y) << std::endl;

    return 0;
}
