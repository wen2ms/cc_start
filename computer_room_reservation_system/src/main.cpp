#include <iostream>

#include "crr_system.h"
#include "crr_system_config.h"
#include "utilities.h"

int main() {
    CRRSystem crr_system;

    while (true) {
        std::system("clear");

        crr_system.show_title();
        std::cout << "Please select your identity: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                crr_system.login_in(STUDENT_DIR, kStudent);
                break;
            case '2':
                crr_system.login_in(TEACHER_DIR, kTeacher);
                break;
            case '3':
                crr_system.login_in(ADMINISTRATOR_DIR, kAdministrator);
                break;
            case '0':
                std::cout << "Welcome next time..." << std::endl;
                return 0;
            default:
                std::cout << "Number invalid, please enter again..." << std::endl;
                break;
        }

        utilities::wait_any_key();
    }

    return 0;
}