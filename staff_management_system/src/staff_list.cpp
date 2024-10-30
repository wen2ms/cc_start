#include "staff_list.h"

StaffList::StaffList() : num_staffs_(0), staffs_ptr_(nullptr) {}

StaffList::~StaffList() {
    for (int i = 0; i < num_staffs_; i++) {
        delete staffs_ptr_[i];
    }

    delete[] staffs_ptr_;
    staffs_ptr_ = nullptr;
}

Staff* StaffList::create_staff(std::string id, std::string name, const char department) {
    if (department == '1') {
        return new Employee(id, name);
    } else if (department == '2') {
        return new Manager(id, name);
    } else if (department == '3') {
        return new Boss(id, name);
    }
}

int StaffList::search_staff_by_name(const std::string target_name) const {
    for (int i = 0; i < num_staffs_; i++) {
        if (staffs_ptr_[i]->get_name() == target_name) {
            return i;
        }
    }

    return num_staffs_;
}

int StaffList::search_staff_by_id(const std::string target_id) const {
    for (int i = 0; i < num_staffs_; i++) {
        if (staffs_ptr_[i]->get_id() == target_id) {
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

    delete[] staffs_ptr_;

    staffs_ptr_ = temp_staffs_ptr_;

    return true;
}

bool StaffList::remove_staff(const std::string target_id) {
    int target_staff_index;

    target_staff_index = search_staff_by_id(target_id);
    if (target_staff_index == num_staffs_) {
        return false;
    }

    Staff** temp_staffs_ptr_ = new Staff*[num_staffs_ - 1];

    for (int i = 0; i < target_staff_index; i++) {
        temp_staffs_ptr_[i] = staffs_ptr_[i];
    }
    for (int i = target_staff_index; i < num_staffs_ - 1; i++) {
        temp_staffs_ptr_[i] = staffs_ptr_[i + 1];
    }

    delete[] staffs_ptr_;

    staffs_ptr_ = temp_staffs_ptr_;

    num_staffs_ --;

    return true;
}

bool StaffList::modify_staff(const Staff* modifed_staff, const std::string target_id) {
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
    std::ifstream in_file(file_name);

    if (!in_file.is_open()) {
        std::cerr << "Could not open the file for reading\n";
        return false;
    }

    if (staffs_ptr_) {
        for (int i = 0; i < num_staffs_; i++) {
            delete staffs_ptr_[i];
        }
        delete[] staffs_ptr_;
        num_staffs_ = 0;
    }

    std::string temp_id;
    std::string temp_name;
    char temp_department;

    while (in_file >> temp_id && in_file >> temp_name && in_file >> temp_department) {
        num_staffs_++;
    }

    staffs_ptr_ = new Staff*[num_staffs_];
    if (!staffs_ptr_) {
        std::cerr << "Memory allocation failed\n";
        return false;
    }

    int i = 0;
    while (in_file >> temp_id && in_file >> temp_name && in_file >> temp_department) {
        staffs_ptr_[i++] = create_staff(temp_id, temp_name, temp_department);
    }

    in_file.close();
    return true;
}

bool StaffList::save_staff_file(std::string file_name) {
    std::ofstream out_file(file_name);

    if (!out_file.is_open()) {
        std::cerr << "Could not open the file for writing\n";
        return false;
    }

    for (int i = 0; i < num_staffs_; i++) {
        out_file << staffs_ptr_[i]->get_id() << ' ' << staffs_ptr_[i]->get_name() << ' ' 
                 << staffs_ptr_[i]->get_department() << '\n';
    }

    out_file.close();
    return true;
}
