#include <iostream>
#include <string>
#include <list>

class TVShow {
  public:
    TVShow(std::string name = "Unknown", float ranking = -1): name_(name), ranking_(ranking) {}

    std::string name_;
    float ranking_;
};

void print_list(const std::list<TVShow>& shows_list) {
    for (std::list<TVShow>::const_iterator it = shows_list.begin(); it != shows_list.end(); it++) {
        std::cout << it->name_ << ' ' << it->ranking_ << "  ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "I have gererated an example of list reverse and sorting.\n";
    std::cout << "------------------------------\n";

    std::list<TVShow> shows_list;

    shows_list.push_back(TVShow("Game of Thrones", 9.3));
    shows_list.push_back(TVShow("Sherlock", 9.1));
    shows_list.push_back(TVShow("Friends", 8.9));
    shows_list.push_back(TVShow("Frieren", 8.8));
    shows_list.push_back(TVShow("Arcane", 8.5));

    std::cout << "Before sorting: " << std::endl;
    print_list(shows_list);

    shows_list.sort([](const TVShow& a, const TVShow& b) {
        return a.ranking_ < b.ranking_;
    });

    std::cout << "After sorting: " << std::endl;
    print_list(shows_list);

    shows_list.reverse();

    std::cout << "Reserved:" << std::endl;
    print_list(shows_list);

    std::cout << "------------------------------\n";

    return 0;
}