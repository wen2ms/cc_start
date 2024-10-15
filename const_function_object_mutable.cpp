#include <iostream>

class Dog {
  public:
    Dog(int dog_id) : dog_id_(dog_id), age_(0) {}

    int get_dog_id() const {
        return dog_id_;
    }

    int get_age() const {
        age_++;

        return age_;
    }

    void set_age(int age) {
        age_ = age;
    }

  private:
    int dog_id_;
    mutable int age_;
};

int main() {
    std::cout << "---------------------------------------\n";
    std::cout << "I generated an example of const functions and const object.\n";

    const Dog mon(007);

    std::cout << "Initial age: " << mon.get_age() << '\n';

    std::cout << "Second age: " << mon.get_age() << '\n';

    // mon.set_age(); // Error: Cannot call non-const member function on a const object

    std::cout << "---------------------------------------\n";

    return 0;
}