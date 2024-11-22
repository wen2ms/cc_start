#include <iostream>
#include <queue>
#include <string>

class Dog {
  public:
    Dog(std::string breed = "unknown", int age = -1) : breed_(breed), age_(age) {}

    std::string get_breed() const {
        return breed_;
    }

    int get_age() const {
        return age_;
    }

  private:
    std::string breed_;
    int age_;
};

int main() {
    std::cout << "I have gererated an example of queue\n";
    std::cout << "------------------------------\n";

    std::queue<Dog> queue_dogs;

    queue_dogs.push(Dog("Doberman", 1));
    queue_dogs.push(Dog("French bulldog", 0));
    queue_dogs.push(Dog("Labrador", 3));

    while (!queue_dogs.empty()) {
        std::cout << "The back: " << queue_dogs.back().get_breed() << ' ' << queue_dogs.back().get_age() << std::string(2, ' ');
        std::cout << "The front: " << queue_dogs.front().get_breed() << ' ' << queue_dogs.front().get_age() << std::endl;

        queue_dogs.pop();
    }

    std::cout << "------------------------------\n";

    return 0;
}