#include <iostream>

#include "competition_process_system.h"

int main() { 
    CompetitionProcessSystem cps_system;

    cps_system.show_title();

    char key;
    while (true) {
        std::cout << "Please select: ";

        std::cin >> key;

        switch (key) {
            case '1':
                cps_system.start();
                break;
            case '2':
                cps_system.load();
                break;
            case '3':
                cps_system.clear();
                break;
            case '0':
                std::cout << "Welcome next time..." << std::endl;
                return 0;
            default:
                std::cout << "Number invalid, please enter again..." << std::endl;
        }
    }

    return 0;
}