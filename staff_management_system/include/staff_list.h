#ifndef STAFF_LIST_H
#define STAFF_LIST_H

#include <fstream>

#include "staff.h"

class StaffList {
  public:
    StaffList();

    ~StaffList();

    static Staff* create_staff(const char* id, const char* name, const char department);

    int search_staff_by_name(const char target_name[15]) const;

    int search_staff_by_id(const char target_id[10]) const;

    int add_staffs(Staff* new_staff);

    bool remove_staff(const char target_id[10]);

    bool modify_staff(const Staff* modifed_staff, const char target_id[10]);

    bool load_staff_file(std::string file_name);

    bool save_staff_file(std::string file_name);

    Staff** staffs_ptr_;
    int num_staffs_;
};

#endif  // STAFF_LIST_H