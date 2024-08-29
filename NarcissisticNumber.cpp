#include <iostream>
#include <cmath>

bool isNarcissistic(int number) {
    int sum = 0;
    int originalNumber = number;
    int numberDigits = 3;

    while (number > 0) {
        int digit = number % 10;
        sum += std::pow(digit, 3);
        number /=  10;
    }
    return originalNumber == sum;
}

int main(void) {
    int narcissisticNumber[900];

    std::cout << "--------------------------------\n";
    std::cout << "Three-digit Narcissistic numbers are: ";

    for (int number = 100; number < 1000; number ++) {
        if (isNarcissistic(number)) {
            narcissisticNumber[number-100] = number;
            std::cout << number << ' ';
        }
    } 

    std::cout << "\n--------------------------------\n";         

    return 0;
}