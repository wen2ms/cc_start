#include "teacher.h"

#include <cstdlib>
#include <iostream>

#include "utilities.h"
#include "order.h"

Teacher::Teacher(std::string name, std::string password, int id) : Identity(name, password), id_(id) {}

void Teacher::run() {
    while (true) {
        std::system("clear");

        this->show_title();

        std::cout << "Please select your action: "; 

        char key;

        std::cin >> key;

        switch (key) {
            case '1':
                this->view_all();
                break;
            case '2':
                this->review();
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

void Teacher::view_all() {
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

void Teacher::review() {
    Order all_orders;
    std::vector<std::map<std::string, std::string>> all_records(all_orders.order_map_);

    std::vector<std::string> order_date_table = {"Monday", "Tuesday", "Wednesday", "Tursday", "Friday"};
    std::cout << "---------------------------------------------------" << std::endl;

    std::vector<int> candidate_orders;
    int candidate_order_index = 0;
    for (std::vector<std::map<std::string, std::string>>::iterator it = all_records.begin(); it != all_records.end(); ++it) {
        if (it->at("status") == "1") {
            std::cout << ++candidate_order_index << ".";
            std::cout << "  Reservation time: " << order_date_table[std::stoi(it->at("date")) - 1];
            std::cout << "  Interval: " << (it->at("interval") == "1" ? "Morning" : "Afternoon");
            std::cout << "  Room Id: " << it->at("room id");
            std::cout << "  Status: " << "reviewing" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;

            candidate_orders.push_back(it - all_records.begin());
        }
    }

    if (candidate_order_index == 0) {
        std::cout << "No reviewing reservation!" << std::endl;
        return;
    }

    std::cout << "Please enter the review orders id, 0 return: ";
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

        std::cout << "Please enter the audit result" << std::endl;
        std::cout << "1. successful  2. failed" << std::endl;

        while (true) {
            std::string review_result;
            std::cin >> review_result;

            if (review_result != "1" && review_result != "2") {
                std::cout << "Number invalid, please enter again..." << std::endl;
            } else {
                int real_index = candidate_orders[std::stoi(input_index) - 1];
                if (review_result == "2") {
                    all_orders.order_map_[real_index]["status"] = std::to_string(OrderStatus::kFailed);
                } else {
                    all_orders.order_map_[real_index]["status"] = std::to_string(OrderStatus::kSuccessful);
                }
                all_orders.update();
                std::cout << "Review completed!" << std::endl;
                break;
            }
        }

        break;
    } 
}
