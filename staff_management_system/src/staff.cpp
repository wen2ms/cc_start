#include "staff.h"

Staff::Staff(const char* id, const char* name, const char department) {
    std::strcpy(id_, id);
    std::strcpy(name_, name);
    department_ = department;
}

Employee::Employee(const char* id, const char* name, const char department) : Staff(id, name, department) {}

void Employee::perform_duty() const {
    std::cout << "Employee do employee stuff\n";
}

Manager::Manager(const char* id, const char* name, const char department) : Staff(id, name, department) {}

void Manager::perform_duty() const {
    std::cout << "Manager distributes the boss's tasks\n";
}

Boss::Boss(const char* id, const char* name, const char department) : Staff(id, name, department) {}

void Boss::perform_duty() const {
    std::cout << "Boss do nothing\n";
}