#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Dog {
  public:
    Dog(std::string name = "Unknown", int age = -1) : name_(name), age_(age) {}

    friend std::ostream& operator<<(std::ostream& out, const Dog& dog) {
        out << '(' << dog.name_ << ", " << dog.age_ << ')';
        return out;
    }

  private:
    std::string name_;
    int age_;
};

void read(const std::string& file_name, std::vector<Dog>& dogs) {
    std::ifstream in_file(file_name);

    if (!in_file.is_open()) {
        throw std::ios::failure("Could not open the file for reading\n");
    }

    std::string name;
    int age;
    while (in_file >> name && in_file >> age) {
        dogs.push_back(Dog(name, age));
    }

    in_file.close();
}

template <class ItemType>
void print_item(const ItemType& item) {
    std::cout << item << std::endl;
}

int main() {
    std::cout << "I generated a basic vector\n";
    std::cout << "---------------------------\n";

    const std::string kFileName = "dogs.txt";

    std::vector<Dog> dogs;
    
    read(kFileName, dogs);

    for (std::vector<Dog>::iterator it = dogs.begin(); it != dogs.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::for_each(dogs.begin(), dogs.end(), print_item<Dog>);

    std::cout << "---------------------------\n";

    return 0;
}