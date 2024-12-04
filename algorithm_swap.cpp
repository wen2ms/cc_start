#include <algorithm>
#include <iostream>
#include <vector>

class IntPointer {
  public:
    IntPointer(int value) : data_(new int(value)) {}

    ~IntPointer() {
        delete data_;
    }

    IntPointer(const IntPointer& other) : data_(new int(*other.data_)) {}

    IntPointer& operator=(const IntPointer& other) {
        if (this != &other) {
            delete data_;
            data_ = new int(*other.data_);
        }
        return *this;
    }

    void swap(IntPointer& other) {
        std::swap(data_, other.data_);
    }

    int* data_;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of swap algorithm\n";
    std::cout << "------------------------------\n";

    std::vector<IntPointer> natural_numbers;
    std::vector<IntPointer> positive_integers;

    const int kInputSize = std::stoi(argv[1]);
    for (int i = 0; i < kInputSize; ++i) {
        natural_numbers.push_back(i);
        positive_integers.push_back(i + 1);
    }

    auto print_int = [](const IntPointer& integer) { std::cout << *integer.data_ << ' '; };

    std::cout << "Before swapping" << std::endl;
    std::for_each(natural_numbers.begin(), natural_numbers.end(), print_int);
    std::cout << std::endl;

    std::for_each(positive_integers.begin(), positive_integers.end(), print_int);
    std::cout << std::endl;

    natural_numbers.swap(positive_integers);

    std::cout << "After swapping" << std::endl;
    std::for_each(natural_numbers.begin(), natural_numbers.end(), print_int);
    std::cout << std::endl;

    std::for_each(positive_integers.begin(), positive_integers.end(), print_int);
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}