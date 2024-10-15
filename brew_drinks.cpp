#include <iostream>

class Drink {
  public:
    virtual ~Drink() {};

    virtual void boil() const = 0;

    virtual void brew() const = 0;

    virtual void pour_into_cup() const = 0;

    virtual void add_ingredient() const = 0;

    virtual void start() const {
        boil();
        brew();
        pour_into_cup();
        add_ingredient();
    }
};

class Coffee : public Drink {
  public:
    void boil() const override {
        std::cout << "Boil water\n";
    }

    void brew() const override {
        std::cout << "Brew coffee\n";
    }

    void pour_into_cup() const override {
        std::cout << "Pour into cup\n";
    }

    void add_ingredient() const override {
        std::cout << "Add suger or milk\n";
    }
};

class Tea : public Drink {
  public:
    void boil() const override {
        std::cout << "Boil water\n";
    }

    void brew() const override {
        std::cout << "Brew tea\n";
    }

    void pour_into_cup() const override {
        std::cout << "Pour into cup\n";
    }

    void add_ingredient() const override {
        std::cout << "Add lemon\n";
    }
};

int main() {
    std::cout << "I generated an example of brewing drinks\n";
    std::cout << "---------------------------\n";

    Drink* coffee = new Coffee();
    Drink* tea = new Tea();

    coffee->start();

    std::cout << "-------\n";

    tea->start();

    delete coffee;
    delete tea;

    std::cout << "---------------------------\n";

    return 0;
}