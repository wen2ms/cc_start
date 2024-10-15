#include <iostream>

int main(void) {
    std::cout << "-----------------------------------\n";
    std::cout << "I generated the mutiplication table.\n";

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << '*' << i << '=' << j * i << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "-----------------------------------\n";

    return 0;
}