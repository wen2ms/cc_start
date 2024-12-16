#include "teacher.h"

#include <iostream>

Teacher::Teacher(std::string name, std::string password, int id) : Identity(name, password), id_(id) {}

void Teacher::run() {
    this->show_title();

    while (true) {
        std::cout << "Please select your action: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                // this->view_all();
                break;
            case '2':
                // this->review();
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

 void Teacher::show_title() {
    std::cout << "Welcome teacher " << '\'' << name_ << '\'' << std::endl;
    std::cout << "              --------------------------------------------------               " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                1. View all reservations          |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                2. review reservations            |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                0. Log out                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "              --------------------------------------------------               " << std::endl;
    std::cout << std::endl;   
 }