#include "staff.h"

Staff::Staff(const char* id = "unknown", const char* name = "unknown", const char department = '0') {
    std::strcpy(id_, id);
    std::strcpy(id_, id);
    department_ = department;
}

Employee::Employee(const char* id, const char* name, const char department = '1') : Staff(id, name, department) {}

void Employee::perform_duty() const {
    std::cout << "Employee do employee stuff\n";
}

Manager::Manager(const char* id, const char* name, const char department = '2') : Staff(id, name, department) {}

void Manager::perform_duty() const {
    std::cout << "Manager distributes the boss's tasks\n";
}

Boss::Boss(const char* id, const char* name, const char department = '3') : Staff(id, name, department) {}

void Boss::perform_duty() const {
    std::cout << "Boss do nothing\n";
}