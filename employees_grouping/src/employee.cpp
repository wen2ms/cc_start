#include "employee.h"

Employee::Employee(std::string name, int salary) : name_(name), salary_(salary) {}

std::string Employee::get_name() const {
    return name_;
}

int Employee::get_salary() const {
    return salary_;
} 