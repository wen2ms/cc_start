#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>

int main() {
    std::cout << "I generated an example of starting pair\n";
    std::cout << "----------------------\n";

    std::list<std::pair<int, int>> points_list;

    std::srand(static_cast<unsigned int>(std::time(0)));

    const int list_size = 5;
    for (int i = 0; i < list_size; i++) {
        points_list.push_back(std::make_pair(std::rand() % 10 + 1, std::rand() % 10 + 1));
    }

    for (std::list<std::pair<int, int>>::iterator it = points_list.begin(); it != points_list.end(); it++) {
        std::cout << '(' << it->first << ',' << it->second << ") ";
    }
    std::cout << std::endl;

    std::cout << "----------------------\n";

    return 0;
}