#include <iostream>

#include "crr_system.h"

int main() {
    CRRSystem crr_system;

    Identity* someone = new Student("name", "password", 123);

    crr_system.show_title();
    while (true) {
        std::cout << "Please select your identity: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                someone->run();
                break;
            case '2':
                // Teacher Logic
                break;
            case '3':
                // Administrator Logic
                break;
            case '0':
                std::cout << "Welcome next time..." << std::endl;
                return 0;
            default:
                std::cout << "Number invalid, please enter again..." << std::endl;
                break;
        }
    }

    return 0;
}