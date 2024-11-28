#include <iostream>
#include <map>
#include <string>
#include <vector>

class Dog {
  public:
    Dog(std::string breed = "", int year = -1) : breed_(breed), year_(year) {}

    std::string breed_;
    int year_;
};

int main() {
    std::cout << "I have gererated an example of map find and count\n";
    std::cout << "------------------------------\n";

    std::vector<Dog> dogs_vector;
    dogs_vector.push_back(Dog("Doberman", 2));
    dogs_vector.push_back(Dog("French Bulldog", 1));
    dogs_vector.push_back(Dog("Labrador Retriever", 4));
    dogs_vector.push_back(Dog("Golden Retriever", 2));

    std::map<std::string, Dog> dogs_map;
    for (std::vector<Dog>::iterator it = dogs_vector.begin(); it != dogs_vector.end(); it++) {
        dogs_map.insert(std::make_pair(it->breed_, *it));
    }

    std::map<std::string, Dog>::iterator target_pos = dogs_map.find("Labrador Retriever");
    if (target_pos != dogs_map.end()) {
        std::cout << target_pos->second.breed_ << ' ' << target_pos->second.year_ << std::endl;
    }

    std::cout << "French Bulldog: " << dogs_map.count("French Bulldog") << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}