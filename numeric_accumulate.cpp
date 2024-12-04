#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of accumulate algorithm\n";
    std::cout << "------------------------------\n";

    const int kInputSize = std::stoi(argv[1]);

    std::vector<int> positive_integers;
    for (int i = 0; i < kInputSize; i++) {
        positive_integers.push_back(i + 1);
    }

    auto print_interger = [](int x) { std::cout << x << ' '; }; 
    
    for (std::vector<int>::iterator i = positive_integers.begin(); i != positive_integers.end(); ++i) {
        print_interger(*i);
    }
    std::cout << std::endl;

    int total = std::accumulate(positive_integers.begin(), positive_integers.end(), 0);

    std::cout << "The total is " << total << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}