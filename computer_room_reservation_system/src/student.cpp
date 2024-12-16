#include "student.h"

#include <iostream>

Student::Student(std::string name, std::string password, int id) : Identity(name, password), id_(id) {}

void Student::run() {
    this->show_title();

    while (true) {
        std::cout << "Please select your action: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                // this->apply();
                break;
            case '2':
                // this->view_mine();
                break;
            case '3':
                // this->view_all();
                break;
            case '4':
                // this->cancle();
                break;
            case '0':
                std::cout << "Logout successful..." << std::endl;
                return;
            default:
                std::cout << "Number invalid, please enter again..." << std::endl;
                break;
        }
    }
}

 void Student::show_title() {
    std::cout << "Welcome student " << '\'' << name_ << '\'' << std::endl;
    std::cout << "              --------------------------------------------------               " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                1. Apply for reservation          |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                2. View my reservations           |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                3. View all reservations          |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                4. Cancle reservation             |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                0. Log out                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "              --------------------------------------------------               " << std::endl;
    std::cout << std::endl;   
 }