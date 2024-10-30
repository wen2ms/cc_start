#include "staff.h"

Staff::Staff(std::string id, std::string name, const char department) : id_(id), name_(name), department_(department) {}

Employee::Employee(std::string id, std::string name, const char department) : Staff(id, name, department) {}

void Employee::perform_duty() const {
    std::cout << "Employee do employee stuff\n";
}

Manager::Manager(std::string id, std::string name, const char department) : Staff(id, name, department) {}

void Manager::perform_duty() const {
    std::cout << "Manager distributes the boss's tasks\n";
}

Boss::Boss(std::string id, std::string name, const char department) : Staff(id, name, department) {}

void Boss::perform_duty() const {
    std::cout << "Boss do nothing\n";
}