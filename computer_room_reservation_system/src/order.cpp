#include "order.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <string>

#include "crr_system_config.h"

Order::Order() {
    std::ifstream infile(ORDER_DIR);

    if (!infile.is_open()) {
        std::cout << "Could not open " << ORDER_DIR << std::endl;
        return;
    }

    std::string line;
    std::getline(infile, line);
    std::istringstream line_stream(line);

    std::queue<std::string> labels;
    std::string label;
    while (std::getline(line_stream, label, ',')) {
        labels.push(label);
    }

    while (std::getline(infile, line)) {
        std::istringstream line_stream(line);
        std::map<std::string, std::string> record;

        std::string value;
        std::queue<std::string> attributes(labels);
        while (std::getline(line_stream, value, ',')) {
            record.insert(std::make_pair(attributes.front(), value));
            attributes.pop();
        }

        order_map_.push_back(record);
    }
}

void Order::update() {
    std::ofstream outfile(ORDER_DIR);

    if (!outfile.is_open()) {
        std::cout << "Could not open " << ORDER_DIR << std::endl;
        return;
    }

    outfile << "date,interval,student id,student name,room id,status" << std::endl;

    for (std::vector<std::map<std::string, std::string>>::iterator it = order_map_.begin(); it != order_map_.end(); ++it) {
        outfile << it->at("date") << "," << it->at("interval") << "," << it->at("student id") << "," << it->at("student name")
                << "," << it->at("room id") << "," << it->at("status") << std::endl;
    }

    outfile.close();
}