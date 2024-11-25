#include <cstring>
#include <fstream>
#include <iostream>

struct Dog {
    char name[50];
    int age;
    char gender;
};

int main() {
    std::cout << "I generated an example of binary file operation\n";
    std::cout << "------------------------------\n";

    Dog dog;
    std::strcpy(dog.name, "Doberman");
    dog.age = 5;
    dog.gender = 'F';

    std::string filename = "dog.dat";

    std::ofstream out_file(filename, std::ios::binary);
    if (out_file.is_open()) {
        out_file.write(reinterpret_cast<const char*>(&dog), sizeof(Dog));
        out_file.close();

        std::cout << "Object written successfully\n";
    } else {
        std::cerr << "Could not open the file for writing\n";
    }

    Dog new_dog;

    std::ifstream in_file(filename, std::ios::binary);
    if (in_file.is_open()) {
        in_file.read(reinterpret_cast<char*>(&new_dog), sizeof(Dog));
        in_file.close();

        std::cout << "Object read successfully\n";
    } else {
        std::cerr << "Could not open the file for reading\n";
    }

    std::cout << "Name: " << new_dog.name << "\n";
    std::cout << "Age: " << new_dog.age << "\n";
    std::cout << "Gender: " << new_dog.gender << "\n";

    std::cout << "------------------------------\n";

    return 0;
}