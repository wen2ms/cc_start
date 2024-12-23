#include "student.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "utilities.h"
#include "crr_system_config.h"
#include "order.h"

Student::Student(std::string name, std::string password, int id) : Identity(name, password), id_(id) {
    init_computer_rooms();
}

void Student::run() {
    while (true) {
        std::system("clear");

        this->show_title();

        std::cout << "Please select your action: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                this->apply();
                break;
            case '2':
                this->view_mine();
                break;
            case '3':
                this->view_all();
                break;
            case '4':
                this->cancle();
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

void Student::apply() {
    std::cout << "The computer rooms are open from Monday to Friday!" << std::endl;
    std::cout << "Please enter your reservation time" << std::endl;

    std::cout << "1. Monday" << std::endl;
    std::cout << "2. Tuesday" << std::endl;
    std::cout << "3. Wednesday" << std::endl;
    std::cout << "4. Tursday" << std::endl;
    std::cout << "5. Friday" << std::endl;

    std::string date;
    while (true) {
        std::cin >> date;

        if (date.compare("5") <= 0 && date.compare("1") >= 0) {
            break;
        } else {
            std::cout << "Number invalid, please enter again..." << std::endl;
        }
    }

    std::cout << "Please enter your revervation interval" << std::endl;
    std::cout << "1. Mornning" << std::endl;
    std::cout << "2. Afternoon" << std::endl;

    std::string interval;
    while (true) {
        std::cin >> interval;

        if (interval == "1" || interval == "2") {
            break;
        } else {
            std::cout << "Number invalid, please enter again..." << std::endl;
        }
    }

    std::cout << "Please select computer room" << std::endl;
    for (std::vector<ComputerRoom>::iterator it = computer_rooms_.begin(); it != computer_rooms_.end(); ++it) {
        std::cout << "No." << it->room_id_ << " room  Capacity: " << it->capacity_ << std::endl;
    }

    std::string room_id;
    while (true) {
        std::cin >> room_id;

        if (room_id.compare(std::to_string(computer_rooms_.size())) <= 0 && room_id.compare("1") >= 0) {
            break;
        } else {
            std::cout << "Number invalid, please enter again..." << std::endl;
        }
    }

    std::cout << "Reservation successfully! Under review..." << std::endl;

    std::ofstream outfile(ORDER_DIR, std::ios::app);

    if (!outfile.is_open()) {
        std::cout << "Could not open " << ORDER_DIR << " for writing" << std::endl;
        return;
    }

    outfile << date << ',' << interval << ',' << id_ << ',' << name_ << ',' << room_id << ',' << OrderStatus::kReviewing << std::endl;
    outfile.close();
}

void Student::view_mine() {
    Order all_orders;
    std::vector<std::map<std::string, std::string>> all_records(all_orders.order_map_);

    if (all_records.empty()) {
        std::cout << "No reservation!" << std::endl;
        return;
    }

    std::vector<std::string> order_date_table = {"Monday", "Tuesday", "Wednesday", "Tursday", "Friday"};
    std::vector<std::string> order_status_table = {"failed", "canceled", "reviewing", "successful"};
    for (std::vector<std::map<std::string, std::string>>::iterator it = all_records.begin(); it != all_records.end(); ++it) {
        if (std::stoi(it->at("student id")) == id_) {
            std::cout << "Reservation time: " << order_date_table[std::stoi(it->at("date")) - 1];
            std::cout << "  Interval: " << (it->at("interval") == "1" ? "Morning" : "Afternoon");
            std::cout << "  Room Id: " << it->at("room id");
            std::cout << "  Status: " << order_status_table[std::stoi(it->at("status")) + 1] << std::endl;
        }
    }
}

void Student::view_all() {
    Order all_orders;
    std::vector<std::map<std::string, std::string>> all_records(all_orders.order_map_);

    if (all_records.empty()) {
        std::cout << "No reservation!" << std::endl;
        return;
    }

    std::vector<std::string> order_date_table = {"Monday", "Tuesday", "Wednesday", "Tursday", "Friday"};
    std::vector<std::string> order_status_table = {"failed", "canceled", "reviewing", "successful"};
    int order_index = 0;
    for (std::vector<std::map<std::string, std::string>>::iterator it = all_records.begin(); it != all_records.end(); ++it) {
        std::cout << ++order_index << ".";
        std::cout << "  Reservation time: " << order_date_table[std::stoi(it->at("date")) - 1];
        std::cout << "  Interval: " << (it->at("interval") == "1" ? "Morning" : "Afternoon");
        std::cout << "  Student Id: " << it->at("student id");
        std::cout << "  Student Name: " << it->at("student name");
        std::cout << "  Room Id: " << it->at("room id");
        std::cout << "  Status: " << order_status_table[std::stoi(it->at("status")) + 1] << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
    }
}

void Student::cancle() {
    Order all_orders;
    std::vector<std::map<std::string, std::string>> all_records(all_orders.order_map_);

    if (all_records.empty()) {
        std::cout << "No reservation!" << std::endl;
        return;
    }

    std::vector<std::string> order_date_table = {"Monday", "Tuesday", "Wednesday", "Tursday", "Friday"};
    std::cout << "Only canceled and successful orders can be deleted!" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

    std::vector<int> candidate_orders;
    int candidate_order_index = 0;
    for (std::vector<std::map<std::string, std::string>>::iterator it = all_records.begin(); it != all_records.end(); ++it) {
        if (std::stoi(it->at("student id")) == id_ && (it->at("status") == "1" || it->at("status") == "2")) {
            std::cout << ++candidate_order_index << ".";
            std::cout << "  Reservation time: " << order_date_table[std::stoi(it->at("date")) - 1];
            std::cout << "  Interval: " << (it->at("interval") == "1" ? "Morning" : "Afternoon");
            std::cout << "  Room Id: " << it->at("room id");
            std::cout << "  Status: " << (it->at("status") == "1" ? "reviewing" : "successful") << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;

            candidate_orders.push_back(it - all_records.begin());
        }
    }

    std::cout << "Please enter the orders id, 0 return: ";
    while (true) {
        std::string input_index;
        std::cin >> input_index;

        if (input_index == "0") {
            std::cout << "Return successfully!" << std::endl;
            break;
        } else if (input_index.compare("0") < 0 || input_index.compare(std::to_string(candidate_order_index)) > 0) {
            std::cout << "Number invalid, please enter again..." << std::endl;
            continue;
        }

        int real_index = candidate_orders[std::stoi(input_index) - 1];
        all_orders.order_map_[real_index]["status"] = std::to_string(OrderStatus::kCanceled);
        all_orders.update();
        std::cout << "Cancel successfully!" << std::endl;
        break;
    }
}

void Student::init_computer_rooms() {
    std::ifstream infile(COMPUTER_ROOM_DIR);

    if (!infile.is_open()) {
        std::cout << "Could not open " << COMPUTER_ROOM_DIR << " for reading" << std::endl;
        return;
    }

    ComputerRoom computer_room;
    while (infile >> computer_room.room_id_ && infile >> computer_room.capacity_) {
        computer_rooms_.push_back(computer_room);
    }

    infile.close();
}