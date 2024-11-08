#include "file.hpp"

int main() {
    std::cout << "I generated an example that write the template class in separate files\n";
    std::cout << "------------------------------\n";

    File<int> file(0);

    file.run();

    std::cout << "------------------------------\n";

    return 0;
}