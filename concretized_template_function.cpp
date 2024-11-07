#include <iostream>
#include <string>

class Dog {
  public:
    Dog(std::string name = "Unkown", int age = -1) : name_(name), age_(age) {}

    std::string name_;
    int age_;
};

template <class T>
bool equal_to(const T& a, const T& b) {
    return (a == b ? true : false);
}

template <>
bool equal_to(const Dog& a, const Dog& b) {
    return (a.name_ == b.name_ ? true : false) ;
}

int main() {
    std::cout << "I generated an example of concretized template functions\n";
    std::cout << "---------------------------------------\n";

    Dog dobermann("juicy", 8);
    Dog bulldog("juicy", 10);

    if (equal_to(dobermann, bulldog)) {
        std::cout << "Dobermann is equal to bulldog\n";
    } else {
        std::cout << "Dobermann is not equal to bulldog\n";
    }

    std::cout << "---------------------------------------\n";

    return 0;
}
