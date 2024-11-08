#include <iostream>
#include <string>

template <class NameType, class AgeType>
class Dog;

template <class NameType, class AgeType>
void display_age(const Dog<NameType, AgeType>& dog) {
    std::cout << "The dog is " << dog.age_ << " years old" << std::endl;
}

template <class NameType, class AgeType>
class Dog {
  public:
    Dog(NameType name, AgeType age) : name_(name), age_(age) {}

    friend void display_name(const Dog<NameType, AgeType>& dog) {
        std::cout << "The dog is " << dog.name_ << std::endl;
    }

    friend void display_age<>(const Dog<NameType, AgeType>& dog);

  private:
    NameType name_;
    AgeType age_;
};

int main() {
    std::cout << "I generated an example of template class and friend\n";
    std::cout << "-----------------------------\n";
    
    Dog<int, std::string> dog(0, "fifteen");

    display_name(dog);

    display_age(dog);

    std::cout << "-----------------------------\n";

    return 0;
}