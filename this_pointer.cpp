#include <iostream>

class Dog {
  public: 
    Dog(int age) : age_(age) {}

    Dog dog_age_increment() {
        this->age_ ++;

        return *this;
    }

    int age_;
};

int main() {
    std::cout << "I generated an example of this pointer.\n";
    std::cout << "------------------------\n";

    Dog mars(10);

    mars.dog_age_increment().dog_age_increment().dog_age_increment();

    std::cout << "Age: " << mars.age_ << '\n';

    std::cout << "------------------------\n";

    return 0;
}