#include <iostream>

class Animal {
  public:
    static int age_;
};

class Sheep : virtual public Animal {};

class Camel : virtual public Animal {};

class Llama : public Sheep, public Camel {};

int Animal::age_ = 0;

int main() {
    std::cout << "I have gererated a virtual inheritance.\n";
    std::cout << "------------------------------\n";

    std::cout << "Animal age: " << Llama::age_ << '\n';

    std::cout << "------------------------------\n";

    return 0;
}