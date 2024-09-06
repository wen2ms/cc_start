#include <iostream>
#include <iomanip>
#include <string>

const int kNameWidth = 15;
const int kIDWidth = 5;
const int kTotalScore = 5;

struct Student {
    std::string name;
    const int total_score;
};

struct Teacher {
    std::string name;
    const int ID;
    const Student students[3];
};

void display_title(void) {
    std::cout << std::left << std::setw(kNameWidth) << "Teacher Name"
              << std::setw(kIDWidth) << "ID"
              << std::setw(kNameWidth) << "Student Name"
              << std::setw(kTotalScore) << "Total Score\n";
    std::cout << std::left << std::string(2*kNameWidth + kIDWidth + kTotalScore, '*') << '\n';
}

void display_teacher(const Teacher& teacher) {
    for (const Student& student : teacher.students) {
        std::cout << std::left << std::setw(kNameWidth) << teacher.name
                  << std::setw(kIDWidth) << teacher.ID
                  << std::setw(kNameWidth) << student.name
                  << std::setw(kTotalScore) << student.total_score << std::endl;
    }
}

int main(void) {
    Teacher teachers[3] = {
        {"Mr. Smith", 101, {{"Peter", 85}, {"Bob", 90}, {"Charlie", 92}}},
        {"Ms. Johnson", 102, {{"James", 85}, {"Bob", 90}, {"Patricia", 92}}},
        {"Dr. Lee", 103, {{"Alice", 85}, {"Michael", 90}, {"Charlie", 92}}}
    };

    std::cout << "-----------------------------\n";
    std::cout << "I generated a teacher-student table.\n";

    display_title();
    for (const Teacher& teacher : teachers) {
        display_teacher(teacher);
    }
    
    std::cout << "-----------------------------\n";

    return 0;
}