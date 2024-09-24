#include <iostream>

class Dog {
  public:
    Dog() {
        age_ ++;
    }

    static int get_age() {
        return age_;
    }

  private:
    static int age_;
};

int Dog::age_ = 0;

int main() {
    std::cout << "I generated an example of static member\n";
    std::cout << "----------------------\n";

    Dog joy, pee;

    std::cout << "This dog's age is " << joy.get_age() << '\n'; 

    Dog nic;

    std::cout << "This dog's age is " << Dog::get_age() << '\n';
  
    std::cout << "----------------------\n";

    return 0;
} 