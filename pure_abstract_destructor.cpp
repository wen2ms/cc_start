#include <iostream>

class Animal {
  public:
    virtual ~Animal() = 0;
};

Animal::~Animal() {
    std::cout << "Base class destructor called\n";
}

class Dog : public Animal {
  public:
    Dog(int age = 0) {
        age_ = new int(age);
    }

    virtual ~Dog() {
        std::cout << "Derived class destructor called\n";
        delete age_;
    }

  private:
    int* age_;
};

int main() {
    std::cout << "I generated an example of pure abstact destructor\n";
    std::cout << "----------------------\n";

    Animal* dog = new Dog();

    delete dog;

    std::cout << "----------------------\n";

    return 0;
}