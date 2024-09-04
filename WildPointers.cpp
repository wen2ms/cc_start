#include <iostream>

int main(void) {
    int *ptr = (int *)0x1002;

    std::cout << *ptr << std::endl;

    return 0;
}