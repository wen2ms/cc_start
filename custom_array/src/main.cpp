#include <iostream>
#include <string>
#include <fstream>

#include "card_box.hpp"

template <class Card>
void test_push_back(CardBox<Card>& box) {
    std::cout << "box: ";
    for (int i = 0; i < 5; i++) {
        box.push_back(i);
        std::cout << box[i] << ' ';
    }
    std::cout << '\n';
}

template <class Card>
void test_copy(const CardBox<Card>& box) {
    CardBox<Card> box_copy(10);
    std::cout << "The size of box_copy's elements: " << box_copy.get_cards_number() << '\n';
    box_copy = box;
    box_copy[0] = 1;
    std::cout << "The size of box_copy's elements: " << box_copy.get_cards_number() << '\n';

    std::cout << "box_copy: ";
    for (int i = 0; i < 5; i++) {
        std::cout << box_copy[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "box: ";
    for (int i = 0; i < 5; i++) {
        std::cout << box[i] << ' ';
    }
    std::cout << '\n';
}

template <class Card>
void test_remove(CardBox<Card>& box) {
    box.remove();

    int cards_number = box.get_cards_number();
    std::cout << "The size of box's elements: " << cards_number << '\n';

    for (int i = 0; i < cards_number; i++) {
        box.remove();
    }
    // box.remove();  // test index out of range.
}

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

template <class Card>
void test_dog_box(CardBox<Card>& box, std::string file_name) {
    std::ifstream in_file(file_name);

    if (!in_file.is_open()) {
        throw std::ios_base::failure("Could not open file for reading\n");
    }

    std::string name;
    int age;

    while (in_file >> name && in_file >> age) {
        box.push_back(Dog(name, age));
    }
    
    in_file.close();

    int dogs_number = box.get_cards_number();
    std::cout << "dog_box: ";
    for (int i = 0; i < dogs_number; i++) {
        std::cout << box[i] << ' ';
    }
    std::cout << '\n';
}


int main() {
    CardBox<int> box(5);

    test_push_back(box);

    test_copy(box);

    test_remove(box);

    CardBox<Dog> dog_box(5);
    const std::string file_name = "data/dogs.txt";

    test_dog_box(dog_box, file_name);

    return 0;
}