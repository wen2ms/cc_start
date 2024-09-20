#include <iostream>

int main(void) {
    int a[] = {1, 2, 3, 4, 5};

    std::cout << "------------------------------------------\n";
    std::cout << "Array's starting address is : " << a << '\n';
    std::cout << "Second element's address is : " << &a[1] << '\n';
    std::cout << "------------------------------------------\n";

    return 0;
}