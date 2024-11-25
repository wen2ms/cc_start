#include <iostream>
#include <list>
#include <string>

class TVShow {
  public:
    TVShow(std::string name = "Unknown", float rating = -1, int realase_date = 0)
        : name_(name), rating_(rating), release_date_(realase_date) {}

    std::string name_;
    float rating_;
    int release_date_;
};

void print_list(const std::list<TVShow>& shows_list) {
    for (std::list<TVShow>::const_iterator it = shows_list.begin(); it != shows_list.end(); it++) {
        std::cout << it->name_ << ' ' << it->rating_ << "  ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "I have gererated an example of list reverse and sorting.\n";
    std::cout << "------------------------------\n";

    std::list<TVShow> shows_list;

    shows_list.push_back(TVShow("Game of Thrones", 9.3, 2011));
    shows_list.push_back(TVShow("Sherlock", 9.1, 2010));
    shows_list.push_back(TVShow("Friends", 8.9, 1994));
    shows_list.push_back(TVShow("Frieren", 8.9, 2023));
    shows_list.push_back(TVShow("Arcane", 9.0, 2021));

    std::cout << "Before sorting: " << std::endl;
    print_list(shows_list);

    shows_list.sort([](const TVShow& a, const TVShow& b) {
        if (a.rating_ == b.rating_) {
            return a.release_date_ < b.release_date_;
        } 

        return a.rating_ < b.rating_;
    });

    std::cout << "After sorting: " << std::endl;
    print_list(shows_list);

    shows_list.reverse();

    std::cout << "Reserved:" << std::endl;
    print_list(shows_list);

    std::cout << "------------------------------\n";

    return 0;
}