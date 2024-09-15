#include <iostream>
#include <string>
#include <iomanip>

class Student {
  public: 
    Student() : name_("unknown"), student_id_("0") {}

    Student(const std::string& name, const std::string& student_id_) : name_(name), student_id_(student_id_) {}

    void set_name(const std::string& new_name) {
        name_ = new_name;
    }

    std::string get_name() const {
        return name_;
    }

    void set_student_id(const std::string& new_id) {
        student_id_ = new_id;
    }

    std::string get_student_id() const {
        return student_id_;
    }

  private:
    std::string student_id_;
    std::string name_;
};

class Window {
  public:
    void display(const Student& student) {
        std::cout << std::left << std::setw(15) << "name" << std::setw(10) << "student id\n";
        std::cout << std::string(25, '-') << '\n';

        std::cout << std::left << std::setw(15) << student.get_name() << std::setw(10) << student.get_student_id() << '\n';
    }
};

int main() {
    Student student_a("Michael James", "20030332");
    Window window;

    std::cout << "I generated a student class\n";
    std::cout << "----------------------------\n";

    std::cout << "Before modification:\n";
    window.display(student_a);

    student_a.set_name("Robert John");

    std::cout << "\nAfter modification:\n";
    window.display(student_a);

    std::cout << "----------------------------\n";
    return 0;
}