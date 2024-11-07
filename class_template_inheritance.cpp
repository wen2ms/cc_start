#include <iostream>
#include <string>
#include <typeinfo>

template <class ResourceType>
class Dog {
  public:
    Dog(ResourceType src_name) : src_name_(src_name) {}
    
    ResourceType src_name_;
};

template <class ResourceType>
class Cerberus : public Dog<ResourceType> {
  public:
    Cerberus(ResourceType src_name) : Dog<ResourceType>(src_name) {}

    void fire_attack() {
        std::cout << "Type name is " << typeid(ResourceType).name() << std::endl;
    }
};

int main() {
    std::cout << "I generated an example of class template inheritance\n";
    std::cout << "------------------------------\n";

    Cerberus<std::string> cerberus("./cerberus.mp4");

    cerberus.fire_attack();

    std::cout << "------------------------------\n";

    return 0;
}