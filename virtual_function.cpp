#include <iostream>
#include <string>

class Animal {
  public:
    explicit Animal(std::string name = "Unknown") : name_(name) {}

    virtual ~Animal() {}

    virtual void name() const {
        std::cout << "This animal's name: " << name_ << '\n';
    }

    virtual void say(const std::string& message = "hello") const {
        std::cout << message << '\n';
    }

  protected:
    std::string name_;
};

class Dog : public Animal {
  public:
    explicit Dog(std::string name = "Unknown dog") {}

    void name() const override {
        std::cout << "This dog's name: " << name_ << '\n';
    }

    void say(const std::string& message = "world") const override {
        std::cout << message << '\n';
    }
};

int main() {
    std::cout << "I have gererated virtual functions.\n";
    std::cout << "------------------------------\n";

    Animal* dog_ptr = new Dog("Dobernman");
    auto* animal_ptr = new Animal;

    animal_ptr->name();
    dog_ptr->name();

    Dog dog;
    Animal& animal = dog;

    dog.say();
    animal.say();

    delete animal_ptr;
    delete dog_ptr;

    std::cout << "------------------------------\n";

    return 0;
}