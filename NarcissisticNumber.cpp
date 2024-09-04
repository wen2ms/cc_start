#include <iostream>
#include <cmath>

bool is_narcissistic(int number) {
    int sum = 0;
    int original_number = number;
    int numberDigits = 3;

    while (number > 0) {
        int digit = number % 10;
        sum += std::pow(digit, 3);
        number /=  10;
    }
    return original_number == sum;
}

int main(void) {
    int narcissistic_number[900];

    std::cout << "--------------------------------\n";
    std::cout << "Three-digit Narcissistic numbers are: ";

    for (int number = 100; number < 1000; number ++) {
        if (is_narcissistic(number)) {
            narcissistic_number[number-100] = number;
            std::cout << number << ' ';
        }
    } 

    std::cout << "\n--------------------------------\n";         

    return 0;
}