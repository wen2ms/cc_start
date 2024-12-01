#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>

#include "department.h"
#include "employee.h"

int main() {
    std::cout << "I have gererated an example of employees grouping\n";
    std::cout << "------------------------------\n";

    std::vector<Employee> employees_list;
    const int kEmployeeNumber = 10;

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < kEmployeeNumber; i++) {
        std::string name(1, 'A' + i);
        int salary = std::rand() % 10000 + 5000;

        employees_list.push_back(Employee(name, salary));
    }

    std::multimap<Department, Employee> employees_map;

    for (std::vector<Employee>::iterator it = employees_list.begin(); it != employees_list.end(); it++) {
        Department department = static_cast<Department>(std::rand() % 3);

        employees_map.insert(std::make_pair(department, *it));
    }

    std::vector<std::string> departments_list = {"Planning", "Art", "Department"};
    for (std::multimap<Department, Employee>::iterator it = employees_map.begin(); it != employees_map.end(); it++) {
        std::cout << departments_list[it->first] << ' ' << it->second.get_name() << ' ' << it->second.get_salary() << std::endl;
    }

    std::map<Department, Employee>::iterator planning_iterator = employees_map.find(kPlanning);
    int planning_number = employees_map.count(kPlanning);

    std::cout << "------Planning------" << std::endl;
    for (int i = 0; i < planning_number; i++) {
        std::cout << departments_list[planning_iterator->first] << ' ' << planning_iterator->second.get_name() << ' '
                  << planning_iterator->second.get_salary() << std::endl;

        planning_iterator++;
    }

    std::cout << "------------------------------\n";

    return 0;
}