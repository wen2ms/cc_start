#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
class GreaterTarget {
  public:
    GreaterTarget(T threshold) : threshold_(threshold) {}

    bool operator()(const T& a) const {
        return a > threshold_;
    }

  private: 
    T threshold_;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " number threshold" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of replace_if\n";
    std::cout << "------------------------------\n";

    const int kInputSize = std::stoi(argv[1]);

    std::vector<int> input_vector;
    for (int i = 0; i < kInputSize; ++i) {
        input_vector.push_back(i + 1);
    } 

    std::for_each(input_vector.begin(), input_vector.end(), [](int item) {
        std::cout << item << ' ';
    });
    std::cout << std::endl;

    const int kThreshold = std::stoi(argv[2]);
    std::replace_if(input_vector.begin(), input_vector.end(), GreaterTarget(kThreshold), 0);

    std::for_each(input_vector.begin(), input_vector.end(), [](int item) {
        std::cout << item << ' ';
    });
    std::cout << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}