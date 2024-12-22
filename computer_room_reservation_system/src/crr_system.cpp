#include "crr_system.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "administrator.h"
#include "teacher.h"
#include "student.h"
#include "utilities.h"

CRRSystem::CRRSystem() {}

void CRRSystem::show_title() {
    std::cout << "-------------- Welcome to Computer Room Reservation System(CRRS) --------------" << std::endl;
    std::cout << std::endl;
    std::cout << "              --------------------------------------------------              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                1. Student                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                2. Teacher                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                3. Administrator                  |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                0. Exit                           |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "              --------------------------------------------------              " << std::endl;
    std::cout << std::endl;   
}

void CRRSystem::login_in(const std::string& filename, IdentifyType type) {
    std::ifstream infile(filename);

    if (!infile.is_open()) {
        std::cout << "Could not open " << "\'" << filename << "\'" << std::endl;
        return; 
    }

    std::string input_name;
    std::string input_password;
    std::string input_id;

    if (type == kStudent) {
        std::cout << "Please input your student id: ";
        std::cin >> input_id;
    } else if (type == kTeacher) {
        std::cout << "Please input your teacher id: ";
        std::cin >> input_id;
    }

    std::cin.ignore();
    std::cout << "Please input your name: ";
    std::getline(std::cin, input_name);

    std::cout << "Please input your password: ";
    std::cin >> input_password;

    Identity* somebody = nullptr;

    std::string line;
    if (type == kStudent) {
        while (std::getline(infile, line)) {
            std::istringstream line_stream(line);

            std::string target_id;
            std::string target_name;
            std::string target_password;

            std::getline(line_stream, target_id, ',');
            std::getline(line_stream, target_name, ',');
            std::getline(line_stream, target_password, ',');

            if (target_id == input_id && target_name == input_name && target_password == input_password) {
                std::cout << "Student verification passed!" << std::endl;

                somebody = new Student(input_name, input_password, std::stoi(target_id));

                utilities::wait_any_key();

                somebody->run();

                delete somebody;
                somebody = nullptr;
                
                return;
            }
        }
    } else if (type == kTeacher) {
        while (std::getline(infile, line)) {
            std::istringstream line_stream(line);

            std::string target_id;
            std::string target_name;
            std::string target_password;

            std::getline(line_stream, target_id, ',');
            std::getline(line_stream, target_name, ',');
            std::getline(line_stream, target_password, ',');

            if (target_id == input_id && target_name == input_name && target_password == input_password) {
                std::cout << "Teacher verification passed!" << std::endl;

                somebody = new Teacher(input_name, input_password, std::stoi(input_id));

                utilities::wait_any_key();

                somebody->run();

                delete somebody;
                somebody = nullptr;
                
                return;
            }
        }
    } else {
        while (std::getline(infile, line)) {
            std::istringstream line_stream(line);

            std::string target_name;
            std::string target_password;

            std::getline(line_stream, target_name, ',');
            std::getline(line_stream, target_password, ',');

            if (target_name == input_name && target_password == input_password) {
                std::cout << "Administrator verification passed!" << std::endl;

                somebody = new Administrator(input_name, input_password);

                utilities::wait_any_key();

                somebody->run();

                delete somebody;
                somebody = nullptr;
                
                return;
            }
        }
    }

    std::cout << "Verification failed!" << std::endl;
    return;
}