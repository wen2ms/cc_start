#include <iostream>
#include <string>

class Dog {
  public:
    std::string scientific_name_;

    Dog() : scientific_name_("unknown") {}

    Dog(const std::string& scientific_name) : scientific_name_(scientific_name) {}

    Dog(const Dog& dog) : scientific_name_(dog.scientific_name_) {
        std::cout << "copy constructor called\n";
    } 
};

void get_breed(Dog dog) {
    std::cout << "The dog breed: " << dog.scientific_name_ << '\n';
}

Dog create_dog(const std::string& scientific_name) {
    Dog dog(scientific_name);

    return dog;    
}

int main() {
    std::cout << "I generated an example of copy constructor.\n";
    std::cout << "---------------------\n";

    Dog nancy("French Bulldog");

    Dog bibabo = nancy;

    get_breed(bibabo);

    Dog chip = create_dog("Dobermann");

    std::cout << "---------------------\n";

    return 0;
}