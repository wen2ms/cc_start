#include <iostream>
#include <string>
#include <list>

class Dog {
  public:
    Dog(std::string breed = "Unknown", int age = -1) : breed_(breed), age_(age) {}

    std::string breed_;
    int age_;
};

void print_items_list(const std::list<Dog>& dog_list) {
    for (std::list<Dog>::const_iterator it = dog_list.begin(); it != dog_list.end(); it++) {
        std::cout << it->breed_ << ' ' << it->age_ << std::endl;
    }
}

int main() {
    std::cout << "I have gererated an example of list's insertion and erasure.\n";
    std::cout << "------------------------------\n";

    std::list<Dog> dog_list;

    dog_list.push_back(Dog("Labrador", 5));
    dog_list.push_back(Dog("French Bulldog", 1));
    dog_list.push_back(Dog("Doberman", 2));
    dog_list.push_back(Dog("Golden Retriever", 2));

    std::list<Dog> old_dog_list(dog_list);
    for (std::list<Dog>::iterator it = old_dog_list.begin(); it != old_dog_list.end();) {
        if (it->age_ <= 3) {
            it = old_dog_list.erase(it);
        } else {
            it++;
        }
    }

    print_items_list(old_dog_list);

    std::list<Dog> young_dog_list;

    std::list<Dog>::iterator dog_list_iterator = dog_list.begin();
    dog_list_iterator++;

    young_dog_list.insert(young_dog_list.begin(), dog_list_iterator, dog_list.end());

    print_items_list(young_dog_list);

    std::cout << "------------------------------\n";

    return 0;
}