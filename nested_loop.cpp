#include <iostream>

int main(void) {
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }

    return 0;
}