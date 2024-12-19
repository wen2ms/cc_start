#include "administrator.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "utilities.h"
#include "crr_system_config.h"

Administrator::Administrator(std::string name, std::string password) : Identity(name, password) {}

void Administrator::run() {
    while (true) {
        std::system("clear");

        this->show_title();

        std::cout << "Please select your action: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                this->add_account();
                break;
            case '2':
                this->view_all_accounts();
                break;
            case '3':
                this->view_all_rooms();
                break;
            case '4':
                this->clear_all_accounts();
                break;
            case '0':
                std::cout << "Logout successful..." << std::endl;
                return;
            default:
                std::cout << "Number invalid, please enter again..." << std::endl;
                break;
        }

        utilities::wait_any_key();
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
    std::cout << "             |                0. Log out                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "              --------------------------------------------------               " << std::endl;
    std::cout << std::endl;   
}

void Administrator::add_account() {
    std::cout << "Enter the type of account to add" << std::endl;
    std::cout << "1. student" << std::endl;
    std::cout << "2. teacher" << std::endl;

    std::string key;
    std::cin >> key;

    if (key != "1" && key != "2") {
        std::cout << "Number invalid, please enter again..." << std::endl;
        return;
    }

    std::string input_name;
    std::string input_id;
    std::string input_password;

    std::string filename;

    if (key == "1") {
        std::cout << "Please input your student id: ";
        filename = STUDENT_DIR;
    } else if (key == "2") {
        std::cout << "Please input your teacher id: ";
        filename = TEACHER_DIR;
    }
    std::cin >> input_id;

    std::cin.ignore();
    std::cout << "Please input your name: ";
    std::getline(std::cin, input_name);

    std::cout << "Please input your password: ";
    std::cin >> input_password;

    std::ofstream outfile(filename, std::ios_base::app);
    if (!outfile.is_open()) {
        std::cout << "Could not open " << '\'' << filename << '\''  << " for writing" << std::endl;
        return;
    }

    outfile << input_id << ',' << input_name << ',' << input_password << std::endl;

    std::cout << "Add successfully!" << std::endl;

    outfile.close();
}

void Administrator::view_all_accounts() {

}

void Administrator::view_all_rooms() {

}

void Administrator::clear_all_accounts() {

}