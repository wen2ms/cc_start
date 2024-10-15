#include <iomanip>
#include <iostream>
#include <string>

const int kNameWidth = 15;
const int kIDWidth = 10;
const int kAgeWidth = 10;
const int kTotalScore = 10;

struct Student {
    std::string name;
    const int id;
    int total_score;
};

struct Teacher {
    std::string name;
    const int id;
    int age;
    Student students;
};

void display_teachers(const Teacher& teacher) {
    std::cout << std::left << std::setw(kNameWidth) << teacher.name << std::setw(kIDWidth) << teacher.id << std::setw(kAgeWidth)
              << teacher.age << std::setw(kNameWidth) << teacher.students.name << std::setw(kTotalScore)
              << teacher.students.total_score << '\n';
}

int main(void) {
    Teacher teachers[] = {{"Smith", 302, 44, {"Alice", 2000442, 450}},
                          {"John", 403, 32, {"Peter", 2000881, 300}},
                          {"Brown Lee", 603, 26, {"Guass Vasily", 2000001, 600}},
                          {"Mike Bilson", 306, 50, {"Jacob Harry", 2000002, 599}}};

    std::cout << "-----------------------------\n";
    std::cout << "I generated a teacher-student table.\n";

    std::cout << std::left << std::setw(kNameWidth) << "Teacher Name" << std::setw(kIDWidth) << "ID" << std::setw(kAgeWidth)
              << "Age" << std::setw(kNameWidth) << "Student Name" << std::setw(kTotalScore) << "Total Score\n";
    std::cout << std::left << std::string(2 * kNameWidth + kIDWidth + kAgeWidth + kTotalScore, '*') << '\n';

    for (const Teacher& teacher : teachers)
        display_teachers(teacher);

    std::cout << "-----------------------------\n";

    return 0;
}