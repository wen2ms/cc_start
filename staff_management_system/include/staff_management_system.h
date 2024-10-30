#ifndef STAFF_MANAGEMENT_SYSTEM_H
#define STAFF_MANAGEMENT_SYSTEM_H

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "staff_list.h"

class StaffManagementSystem {
  public:
    StaffManagementSystem();

    void menu_navigate();

    void view_title();

    void view_input_prompt(Staff** new_staff);

    void view_add_staffs();

    void print_staffs();

    void view_remove_staff();

    void view_modify_staff();

    void view_search_staff();

    void view_sort_stafflist();

    void clear_all_staffs();

    void exit_application();

    void wait_for_keypress();

  private:
    std::string staff_file_name_;
    StaffList staff_list_;
};

#endif  // STAFF_MANAGEMENT_SYSTEM_H