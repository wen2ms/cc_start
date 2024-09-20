#include <iostream>
#include <iomanip>
#include <string>

struct Dog {
    std::string scientific_name;
    int age;
    char gender;
};

int main(void) {

    Dog picky;

    picky.scientific_name = "Dobermann";
    picky.age = 1;
    picky.gender = 'M';

    Dog lucy = {"Teddy", 3, 'F'};

    const int kNameWidth = 20;
    const int kAgeWidth = 5;
    const int kGenderWidth = 5;

    std::cout << "--------------------------------\n";
    std::cout << "I defined a struct of dog.\n";
    std::cout << std::left << std::setw(kNameWidth) << "Scientific Name"
              << std::setw(kAgeWidth) << "Age"
              << std::setw(kGenderWidth) << "Gender\n";

    std::cout << std::left << std::setw(kNameWidth) << picky.scientific_name
              << std::setw(kAgeWidth) << picky.age
              << std::setw(kGenderWidth) << picky.gender << '\n';

    std::cout << std::left << std::setw(kNameWidth) << lucy.scientific_name
              << std::setw(kAgeWidth) << lucy.age
              << std::setw(kGenderWidth) << lucy.gender << '\n';

    std::cout << "--------------------------------\n";

    return 0;
}