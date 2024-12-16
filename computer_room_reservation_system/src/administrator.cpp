#include "administrator.h"

#include <iostream>

Administrator::Administrator(std::string name, std::string password) : Identity(name, password) {}

void Administrator::run() {
    this->show_title();

    while (true) {
        std::cout << "Please select your action: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                // this->add_account();
                break;
            case '2':
                // this->view_all_accounts();
                break;
            case '3':
                // this->view_all_rooms();
                break;
            case '4':
                // this->clear_all_accounts();
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

void Administrator::show_title() {
    std::cout << "Welcome administrator " << '\'' << name_ << '\'' << std::endl;
    std::cout << "              --------------------------------------------------               " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                1. Add account                    |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                2. View all accounts              |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                3. View computer rooms            |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                4. Clear reservation              |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                5. Log out                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "              --------------------------------------------------               " << std::endl;
    std::cout << std::endl;   
}