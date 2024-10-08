#include <iostream>
#include <string>

class Animal {
  public:
    Animal(std::string name = "Unknown") : name_(name) {}

    virtual ~Animal() {}

    virtual void get_name() const {
        std::cout << "This animal's name: " << name_ << '\n';
    }

    std::string name_;
};

class Dog : public Animal {
  public:
    Dog(std::string name = "Unknown dog") : Animal(name) {}

    void get_name() const override {
        std::cout << "This dog's name: " << name_ << '\n';
    }
};

int main() {
    std::cout << "I have gererated virtual functions.\n";
    std::cout << "------------------------------\n";

    Animal* dog_ptr = new Dog("Dobernman");
    Animal* animal_ptr = new Animal();

    animal_ptr->get_name();
    dog_ptr->get_name();

    delete animal_ptr;
    delete dog_ptr;

    std::cout << "------------------------------\n";

    return 0;
}