#include "staff_management_system.h"

StaffManagementSystem::StaffManagementSystem() {
    staff_list_.load_staff_file(staff_file_name_);
}

void StaffManagementSystem::menu_navigate() {
    char option_number;

    while (true) {
        view_title();

        std::cin >> option_number;

        if (option_number == '1') {
            view_add_staffs();
        } else if (option_number == '2') {
            print_staffs();
        } else if (option_number == '3') {
            view_remove_staff();
        } else if (option_number == '4') {
            view_modify_staff();
        } else if (option_number == '5') {
            view_search_staff();
        } else if (option_number == '6') {
            sort_stafflist();
        } else if (option_number == '7') {
            clear_all_staffs();
        } else if (option_number == '0') {
            exit_application();
        } else {
            std::cout << "Input error, please input again: ";
        }

        wait_for_keypress();
    }
}

void StaffManagementSystem::view_title() {
    std::cout << "--------------------------------\n";
    std::cout << "------     1. Add a staff        ------\n";
    std::cout << "------     2. Print staff list     ------\n";
    std::cout << "------     3. Remove a staff        ------\n";
    std::cout << "------     4. Search a staff         ------\n";
    std::cout << "------     5. Modify a staff         ------\n";
    std::cout << "------     6. sort staff list       ------\n";
    std::cout << "------     7. Clear staff list    ------\n";
    std::cout << "------     0. Exit system       ------\n";
    std::cout << "------------------------------\n";
}

void StaffManagementSystem::view_input_prompt(Staff* new_staff) {
    char id[10];
    char name[15];
    char department;

    std::cout << "Please input a staff id: ";
    std::cin >> id;

    std::cout << "Please input a staff name: ";
    std::cin >> name;
    
    std::cout << "Please input the department (1: Employee, 2: Manager, 3: Boss): ";
    std::cin >> department;

    if (department == '1') {
        new_staff = new Employee(id, name);
    } else if (department == '2') {
        new_staff = new Manager(id, name);
    } else if (department == '3') {
        new_staff = new Boss(id, name);
    }
}

void StaffManagementSystem::view_add_staffs() {
    Staff* target_staff;
    int add_staffs_number;

    std::cout << "Please input staffs number: ";
    std::cin >> add_staffs_number;

    for (int i = 0; i < add_staffs_number; i++) {
        view_input_prompt(target_staff);

        int state_code = staff_list_.add_staffs(target_staff);
        if (state_code == 1) {
            std::cout << "Add staff successfully!\n"; 
        } else if (state_code == -1) {
            std::cout << "Fail to add a staff, staff list full\n";
        } else if (state_code == -2) {
            std::cout << "Fail to add a staff, duplicate staff\n";
        } 
    }
}

void StaffManagementSystem::print_staffs() {
    std::cout << std::left << std::setw(15) << "id" << std::setw(15) << "name" << std::setw(10) << "department\n";
    std::cout << std::string(50, '-') << '\n';
    
    for (int i = 0; i < staff_list_.num_staffs_; i++) {
        std::cout << std::left << std::setw(15) << staff_list_.staffs_ptr_[i]->get_id()
                << std::setw(15) << staff_list_.staffs_ptr_[i]->get_name() << std::setw(10)
                << staff_list_.staffs_ptr_[i]->get_department() << std::endl;
    }
}

void StaffManagementSystem::view_remove_staff() {
    char target_id[10];

    std::cout << "Please input id: ";
    std::cin >> target_id;

    bool state = staff_list_.remove_staff(target_id);
    if (state) {
        std::cout << "Remove staff successfully!\n";
    } else {
        std::cout << "Failed to remove staff, the staff not found\n";
    }
}

void StaffManagementSystem::view_modify_staff() {
    char target_id[10];

    std::cout << "Please input the id of the staff that you want to modify: ";
    std::cin >> target_id;

    int target_index = staff_list_.search_staff_by_id(target_id);
    if (target_index == staff_list_.num_staffs_) {
        std::cout << "Failed to modify staff, the staff not found\n";
    }

    Staff* modified_staff;

    view_input_prompt(modified_staff);

    bool state = staff_list_.modify_staff(modified_staff, target_id);
    if (state) {
        std::cout << "Modify staff successfully!\n";
    } 
}

void StaffManagementSystem::view_search_staff() {
    char search_method;

    std::cout << "Please input the search method (1: id, 2: name): ";
    std::cin >> search_method;

    int target_index = -1;
    if (search_method == '1') {
        char search_id[10];

        std::cout << "Plase input id: ";
        std::cin >> search_id;

        target_index = staff_list_.search_staff_by_id(search_id);
    } else if (search_method == '2') {
        char target_name[15];

        std::cout << "Plase input name: ";
        std::cin >> target_name;

        target_index = staff_list_.search_staff_by_name(target_name);
    }

    if (target_index != staff_list_.num_staffs_) {
        std::cout << "Search the staff successfully!\n";

        std::cout << std::left << std::setw(15) << "id" << std::setw(15) << "name" << std::setw(10) << "department\n";
        std::cout << std::string(50, '-') << '\n';

        std::cout << std::left << std::setw(15) << staff_list_.staffs_ptr_[target_index]->get_id()
            << std::setw(15) << staff_list_.staffs_ptr_[target_index]->get_name() << std::setw(10)
            << staff_list_.staffs_ptr_[target_index]->get_department() << std::endl;
    } else {
        std::cout << "Failed to search, the staff not found\n";
    }
}

void StaffManagementSystem::sort_stafflist() {
    for (int i = 0;)
}

void StaffManagementSystem::clear_all_staffs();

void StaffManagementSystem::exit_application();