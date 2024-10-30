#ifndef STAFF_LIST_H
#define STAFF_LIST_H

#include <fstream>

#include "staff.h"

class StaffList {
  public:
    StaffList();

    ~StaffList();

    static Staff* create_staff(std::string id, std::string name, const char department);

    int search_staff_by_name(const std::string target_name) const;

    int search_staff_by_id(const std::string target_id) const;

    bool add_staffs(Staff* new_staff);

    bool remove_staff(const std::string target_id);

    bool modify_staff(const Staff* modifed_staff, const std::string target_id);

    bool load_staff_file(std::string file_name);

    bool save_staff_file(std::string file_name);

    Staff** staffs_ptr_;
    int num_staffs_;
};

#endif  // STAFF_LIST_H