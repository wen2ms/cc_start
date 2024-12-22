#include "administrator.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "utilities.h"
#include "crr_system_config.h"

Administrator::Administrator(std::string name, std::string password) : Identity(name, password) {
    init_students();
    init_teachers();
}

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
    int input_id;
    std::string input_password;

    std::string filename;

    if (key == "1") {
        std::cout << "Please input your student id: ";
        filename = STUDENT_DIR;
    } else if (key == "2") {
        std::cout << "Please input your teacher id: ";
        filename = TEACHER_DIR;
    }

    while (true) {
        std::cin >> input_id;
        if (key == "1") {
            std::vector<Student>::iterator target_it = std::find_if(students_.begin(), students_.end(), [=](const Student& other) {
                return input_id == other.id_;
            });

            if (target_it == students_.end()) {
                break;
            } else {
                std::cout << "The student id is repeated, please enter again: ";
            }
        } else if (key == "2") {
            std::vector<Teacher>::iterator target_it = std::find_if(teachers_.begin(), teachers_.end(), [=](const Teacher& other) {
                return input_id == other.id_;
            });

            if (target_it == teachers_.end()) {
                break;
            } else {
                std::cout << "The teacher id is repeated, please enter again: ";
            }
        }
    }

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

    if (key == "1") {
        students_.push_back(Student(input_name, input_password, input_id));
    } else if (key == "2") {
        teachers_.push_back(Teacher(input_name, input_password, input_id));
    }

    std::cout << "Add successfully!" << std::endl;

    outfile.close();
}

void Administrator::view_all_accounts() {

}

void Administrator::view_all_rooms() {

}

void Administrator::clear_all_accounts() {

}

void Administrator::init_students() {
    std::ifstream infile(STUDENT_DIR);

    if (!infile.is_open()) {
        std::cout << "Could not open " << STUDENT_DIR << " for reading" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream line_stream(line);

        std::string id, name, password;

        std::getline(line_stream, id, ',');
        std::getline(line_stream, name, ',');
        std::getline(line_stream, password, ',');

        students_.push_back(Student(name, password, std::stoi(id)));
    }

    infile.close();
}

void Administrator::init_teachers() {
    std::ifstream infile(TEACHER_DIR);

    if (!infile.is_open()) {
        std::cout << "Could not open " << TEACHER_DIR << " for reading" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream line_stream(line);

        std::string id, name, password;

        std::getline(line_stream, id, ',');
        std::getline(line_stream, name, ',');
        std::getline(line_stream, password, ',');

        teachers_.push_back(Teacher(name, password, std::stoi(id)));
    }

    infile.close();
}