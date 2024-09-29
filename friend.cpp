#include <iostream>
#include <string>

class Human;
class Dog;

class Cat {
  public:
    Cat(): name_("Unknown") {}

    Cat(std::string name) : name_(name) {}

    void get_human_name(Human& human);

  private:
    std::string name_;
};

class Human {
  public:
    friend class Dog;

    Human() : name_("Unknown") {}

    Human(std::string name) : name_(name) {}

    friend void get_partners_name(Human& human, Dog& dog);

    friend void Cat::get_human_name(Human& human);
    
  private:
    std::string name_;
};

class Dog {
  public: 
    Dog() : name_("Unknown") {}

    Dog(std::string name) : name_(name) {}

    void get_human_name(Human& human) {
        std::cout << "Human name: " << human.name_ << '\n';
    }

    friend void get_partners_name(Human& human, Dog& dog);

  private:
    std::string name_;
};

void get_partners_name(Human& human, Dog& dog) {
  std::cout << "Human name: " << human.name_ << " Dog name: " << dog.name_ << '\n';
}

void Cat::get_human_name(Human& human) {
  std::cout << "Human name: " << human.name_ << '\n';
}

int main() {
    std::cout << "I generated an example of friend\n";
    std::cout << "--------------------------\n";

    Human doctor("jack");
    Dog dobermann("Mat");
    Cat cat("dog");

    get_partners_name(doctor, dobermann);

    dobermann.get_human_name(doctor);

    cat.get_human_name(doctor);

    std::cout << "--------------------------\n";

    return 0;
}