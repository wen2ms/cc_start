#include <iostream>

int main(void) {
    int a = 10;
    int b = 20;

    const int *ptr1 = &a;
    ptr1 = &b;
    // *ptr1 = 30;  // Error

    int *const ptr2 = &a;
    *ptr2 = 40;
    // ptr2 = &b;   // Error

    const int *const ptr3 = &a;
    // *ptr3 = 50;  // Error
    // ptr = &b;    // Error

    std::cout << "---------------------------------------\n";

    std::cout << "I distinguished the relationship between constand pointer.\n";
    std::cout << "ptr1 points: " << *ptr1 << std::endl;
    std::cout << "ptr2 points: " << *ptr2 << std::endl;
    std::cout << "ptr3 points: " << *ptr3 << std::endl;

    std::cout << "---------------------------------------\n";
}