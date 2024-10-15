#include <iostream>
#include <string>

class Person {
  public:
    Person(const std::string& person_name, int person_age) : name_(person_name), age_(person_age) {
        std::cout << "Constructor called: " << "name: " << name_ << "\tage: " << age_ << '\n';
    }

    ~Person() {
        std::cout << "Destructor called.\n";
    }

  private:
    std::string name_;
    int age_;
};

int main() {
    std::cout << "I generated an example of constructor and destructor example.\n";
    std::cout << "------------------------------\n";

    Person* person = new Person("Anna Emily", 28);

    delete person;

    std::cout << "------------------------------\n";

    return 0;
}