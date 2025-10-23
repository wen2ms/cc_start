#include <iostream>

class Animal {
  public:
    explicit Animal(int num) {
        std::cout << "num = " << num << '\n';
    }

    static int age_;
};

class Sheep : virtual public Animal {
  public:
    Sheep() : Animal(1) {}
};

class Camel : virtual public Animal {
  public:
    Camel() : Animal(2) {}
};

class Llama : public Sheep, public Camel {
  public:
    Llama() : Sheep(), Camel(), Animal(3) {}
};

int Animal::age_ = 0;

int main() {
    std::cout << "I have gererated a virtual inheritance.\n";
    std::cout << "------------------------------\n";

    Llama llama;
    std::cout << "Animal age: " << Llama::age_ << '\n';

    std::cout << "------------------------------\n";

    return 0;
}