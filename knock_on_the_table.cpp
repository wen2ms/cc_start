#include <iostream>

int main(void) {
    std::cout << "--------------------------\n";
    std::cout << "Let's play the knock on the table game!";
    for (int number = 1; number < 100; number++) {
        if (number % 7 == 0 || number % 10 == 7 || number / 10 == 7)
            std::cout << "Knock on the table!\n";
        else
            std::cout << number << '\n';
    }
    std::cout << "\n--------------------------\n";

    return 0;
}
