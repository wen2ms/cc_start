#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

#include "algorithm_find_config.h"

class Dog {
  public:
    Dog(std::string breed = "", int rating = -1) : breed_(breed), rating_(rating) {}

    bool operator==(const Dog& other_dog) const {
        return breed_ == other_dog.breed_;
    }

    std::string& breed() {
        return breed_;
    }

    int& rating() {
        return rating_;
    }

  private:
    std::string breed_;
    int rating_;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " Filename TargetBreed" << std::endl;
        return 1;
    }
    
    std::cout << "I generated an example of " << CMAKE_PROJECT_NAME << std::endl;
    std::cout << "------------------------------\n";

    const std::string kFileName(argv[1]);
    const std::string kTargetBreed(argv[2]);

    std::vector<Dog> dogs_list;

    std::ifstream in_file(kFileName);

    if (!in_file.is_open()) {
        std::cerr << "Could not open the file for reading" << std::endl;
        return 2;
    }

    std::string line;
    while (std::getline(in_file, line)) {
        std::istringstream string_stream(line);

        Dog temp_dog;

        std::getline(string_stream, temp_dog.breed(), ',');
        string_stream >> temp_dog.rating();

        dogs_list.push_back(temp_dog);
    }

    in_file.close();

    for (std::vector<Dog>::iterator it = dogs_list.begin(); it != dogs_list.end(); it++) {
        std::cout << it->breed() << ' ' << it->rating() << std::endl;
    }

    std::vector<Dog>::iterator target_iterator = std::find(dogs_list.begin(), dogs_list.end(), Dog(kTargetBreed));
    if (target_iterator == dogs_list.end()) {
        std::cout << "Not found " << kTargetBreed << std::endl;
    } else {
        std::cout << "Found successfully: " << target_iterator->breed() << ' ' << target_iterator->rating() << std::endl;
    }

    std::cout << "------------------------------\n";

    return 0;
}