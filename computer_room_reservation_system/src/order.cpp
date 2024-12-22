#include "order.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <queue>

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

}