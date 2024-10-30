#include "staff_list.h"

StaffList::StaffList() : num_staffs_(0), staffs_ptr_(nullptr) {}

StaffList::~StaffList() {
    for (int i = 0; i < num_staffs_; i++) {
        delete staffs_ptr_[i];
    }

    delete[] staffs_ptr_;
}

Staff* StaffList::create_staff(const char* id, const char* name, const char department) {
    if (department == '1') {
        return new Employee(id, name);
    } else if (department == '2') {
        return new Manager(id, name);
    } else if (department == '3') {
        return new Boss(id, name);
    }
}

int StaffList::search_staff_by_name(const char target_name[15]) const {
    for (int i = 0; i < num_staffs_; i++) {
        if (std::strcmp(staffs_ptr_[i]->get_name(), target_name) == 0) {
            return i;
        }
    }

    return num_staffs_;
}

int StaffList::search_staff_by_id(const char target_id[10]) const {
    for (int i = 0; i < num_staffs_; i++) {
        if (std::strcmp(staffs_ptr_[i]->get_id(), target_id) == 0) {
            return i;
        }
    }

    return num_staffs_;
}

bool StaffList::add_staffs(Staff* new_staff) {
    if (search_staff_by_id(new_staff->get_id()) != num_staffs_) {
        return false;
    }

    Staff** temp_staffs_ptr_ = new Staff*[num_staffs_ + 1];

    for (int i = 0; i < num_staffs_; i++) {
        temp_staffs_ptr_[i] = staffs_ptr_[i];
    }
    temp_staffs_ptr_[num_staffs_++] = new_staff;

    staffs_ptr_ = temp_staffs_ptr_;

    return true;
}

bool StaffList::remove_staff(const char target_id[10]) {
    int target_staff_index;

    target_staff_index = search_staff_by_id(target_id);
    if (target_staff_index == num_staffs_) {
        return false;
    }

    for (int i = target_staff_index; i < num_staffs_; i++) {
        staffs_ptr_[i] = staffs_ptr_[i + 1];
    }

    delete staffs_ptr_[--num_staffs_];

    return true;
}

bool StaffList::modify_staff(const Staff* modifed_staff, const char target_id[10]) {
    int target_staff_index;

    target_staff_index = search_staff_by_id(target_id);
    if (target_staff_index == num_staffs_) {
        return false;
    }

    delete staffs_ptr_[target_staff_index];
    staffs_ptr_[target_staff_index] =
        create_staff(modifed_staff->get_id(), modifed_staff->get_name(), modifed_staff->get_department());

    return true;
}

bool StaffList::load_staff_file(std::string file_name) {
    std::ifstream in_file(file_name, std::ios::binary);

    if (!in_file.is_open()) {
        std::cerr << "Could not open the file for reading\n";
        return false;
    }

    if (staffs_ptr_) {
        for (int i = 0; i < num_staffs_; i++) {
            delete staffs_ptr_[i];
        }
        delete[] staffs_ptr_;
    }

    in_file.read(reinterpret_cast<char*>(&num_staffs_), sizeof(num_staffs_));

    staffs_ptr_ = new Staff*[num_staffs_];
    if (!staffs_ptr_) {
        std::cerr << "Memory allocation failed\n";
        return false;
    }

    char temp_id[10];
    char temp_name[15];
    char temp_department;
    for (int i = 0; i < num_staffs_; i++) {
        in_file.read(temp_id, sizeof(temp_id));
        in_file.read(temp_name, sizeof(temp_name));
        in_file.read(&temp_department, sizeof(temp_department));

        if (temp_department == '1') {
            staffs_ptr_[i] = new Employee(temp_id, temp_name);
        } else if (temp_department == '2') {
            staffs_ptr_[i] = new Manager(temp_id, temp_name);
        } else if (temp_department == '3') {
            staffs_ptr_[i] = new Boss(temp_id, temp_name);
        }
    }

    in_file.close();
    return true;
}

bool StaffList::save_staff_file(std::string file_name) {
    std::ofstream out_file(file_name, std::ios::binary);

    if (!out_file.is_open()) {
        std::cerr << "Could not open the file for writing\n";
        return false;
    }

    out_file.write(reinterpret_cast<char*>(&num_staffs_), sizeof(num_staffs_));

    char temp_id[10];
    char temp_name[15];
    char temp_department;
    for (int i = 0; i < num_staffs_; i++) {
        std::strcpy(temp_id, staffs_ptr_[i]->get_id());
        std::strcpy(temp_name, staffs_ptr_[i]->get_name());
        temp_department = staffs_ptr_[i]->get_department();

        out_file.write(temp_id, sizeof(temp_id));
        out_file.write(temp_name, sizeof(temp_name));
        out_file.write(&temp_department, sizeof(temp_department));
    }

    out_file.close();
    return true;
}
