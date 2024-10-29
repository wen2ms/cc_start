#include "staff_list.h"

const int kStaffNum = 50;

StaffList::StaffList() {
   staffs_ptr_ = new Staff*[kStaffNum];
}

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
        if (staffs_ptr_[i]->get_name() == target_name) {
            return i;
        }
    }
}

int StaffList::search_staff_by_id(const char target_id[10]) const {
    for (int i = 0; i < num_staffs_; i++) {
        if (staffs_ptr_[i]->get_id() == target_id) {
            return i;
        }
    }
}
    
int StaffList::add_staffs(Staff* new_staff) {
    if (num_staffs_ == kStaffNum) {
        return -1;
    } else if (search_staff_by_id(new_staff->get_id()) != num_staffs_) {
        return -2;
    }

    staffs_ptr_[num_staffs_++] = new_staff;
    
    return 1;
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

    delete staffs_ptr_[-- num_staffs_];

    return true;
}

bool StaffList::modify_staff(const Staff* modifed_staff, const char target_id[10]) {
    int target_staff_index;

    target_staff_index = search_staff_by_id(target_id);
    if (target_staff_index == num_staffs_) {
        return false;
    }

    delete staffs_ptr_[target_staff_index];
    staffs_ptr_[target_staff_index] = create_staff(modifed_staff->get_id(), modifed_staff->get_name(), modifed_staff->get_department());

    return true;
}

bool StaffList::load_staff_file(std::string file_name) {
    std::ifstream in_file(file_name, std::ios::binary);

    if (!in_file.is_open()) {
        std::cerr << "Could not open the file for reading\n";
        return false;
    }

    if (!staffs_ptr_) {
        for (int i = 0; i < num_staffs_; i++) {
            delete staffs_ptr_[i];
        }
        delete[] staffs_ptr_;
    }

    int num_staffs;
    in_file.read(reinterpret_cast<char*>(&num_staffs), sizeof(num_staffs)); 

    staffs_ptr_ = new Staff*[num_staffs];
    if (!staffs_ptr_) {
        std::cerr << "Memory allocation failed\n";
        return false;   
    }

    for (int i = 0; i < num_staffs; i++) {
        in_file.read(reinterpret_cast<char*>(staffs_ptr_[i]), sizeof(Staff));

        if (staffs_ptr_[i]->get_department() == '1') {
            staffs_ptr_[i] = new Employee(staffs_ptr_[i]->get_id(), staffs_ptr_[i]->get_name());
        } else if (staffs_ptr_[i]->get_department() == '2') {
            staffs_ptr_[i] = new Manager(staffs_ptr_[i]->get_id(), staffs_ptr_[i]->get_name());
        } else if (staffs_ptr_[i]->get_department() == '3') {
            staffs_ptr_[i] = new Boss(staffs_ptr_[i]->get_id(), staffs_ptr_[i]->get_name());
        }

        in_file.read(reinterpret_cast<char*>(&staffs_ptr_[i]), sizeof(Staff));
    }

    num_staffs_ = num_staffs;

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

    for (int i = 0; i < num_staffs_; i++) {
        out_file.write(reinterpret_cast<char*>(staffs_ptr_[i]), sizeof(Staff));
    }

    out_file.close();
    return true;
}
