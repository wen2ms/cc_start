#include <iostream>
#include <cstdlib>

int main(int agrc, char* argv[]) {
    if (agrc < 2) {
        std::cout << "Please provide an array of integers as command-line arguments\n";
        return 0;
    }

    std::cout << "I generated a example about new\n";
    std::cout << "---------------------------------\n";

    const int kN = agrc - 1;
    int* singleElement = new int(kN);
    std::cout << "Single Element: " << *singleElement << '\n';

    int* arrayElement = new int[kN];

    for (int i = 0; i < kN; i ++) {
        arrayElement[i] = std::atoi(argv[i+1]);
    }
    
    std::cout << "Array: ";
    for (int i = 0; i < kN; i ++) {
        std::cout << arrayElement[i] << ' ';
    }
    std::cout << '\n';

    delete singleElement;
    delete[] arrayElement;

    std::cout << "---------------------------------\n";

    return 0;
}