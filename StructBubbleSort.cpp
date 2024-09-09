#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

struct Student {
    std::string name;
    int score;
    int age; 
};

void initialize_students(Student students[], int num_students) {
    std::string names[] = {"James", "Michael", "Robert", "John", "David",
                           "William", "Richard", "Joseph", "Thomas", "Chirstopher"};

    for (int i = 0; i < num_students; i ++) {
        students[i].name = names[i];
        students[i].score = std::rand() % 101;
        students[i].age = std::rand() % 30 + 18;
    }
}

void bubble_sort(Student students[], int num_students) {
    for (int i = 0; i < num_students - 1; i ++) {
        for (int j = 0; j < num_students - i - 1; j ++) {
            if (students[j].score < students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void print_students(const Student students[], int num_students) {
    std::cout << std::left << std::setw(15) << "Name"
              << std::setw(10) << "Score"
              << std::setw(5) << "Age" << '\n';
    std::cout << std::left << std::string(30, '*') << '\n';

    for (int i = 0; i < num_students; i ++) {
        std::cout << std::left << std::setw(15) << students[i].name
                  << std::setw(10) << students[i].score
                  << std::setw(5) << students[i].age << '\n';
    }
}

int main(void) {
    std:srand(static_cast<unsigned int>(std::time(0)));

    const int kNumStudents = 10;
    Student students[kNumStudents];

    std::cout << "---------------------------------\n";
    std::cout << "I generated a struct bubble sort\n";

    initialize_students(students, kNumStudents);

    std::cout << "Before sort by score:\n";
    print_students(students, kNumStudents);

    bubble_sort(students, kNumStudents);

    std::cout << "\nAfter sort by score:\n";
    print_students(students, kNumStudents);

    std::cout << "---------------------------------\n";

    return 0;
}

