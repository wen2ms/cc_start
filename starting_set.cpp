#include <iostream>
#include <set>
#include <string>

class TVShow {
  public:
    TVShow(std::string name = "Unknown", float rating = -1, int release_date = 0)
        : name_(name), rating_(rating), release_date_(release_date) {}

    bool operator<(const TVShow& other) const {
        if (rating_ == other.rating_) {
            return release_date_ < other.release_date_;
        } else {
            return rating_ < other.rating_;
        }
    }

    bool operator==(const TVShow& other) const {
        return name_ == other.name_;
    }

    std::string name_;
    float rating_;
    int release_date_;
};

void print_set(const std::set<TVShow>& shows_set) {
    for (std::set<TVShow>::const_iterator it = shows_set.begin(); it != shows_set.end(); it++) {
        std::cout << it->name_ << ' ' << it->rating_ << ' ' << it->release_date_ << "  ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "I have gererated an example of starting set\n";
    std::cout << "------------------------------\n";

    std::set<TVShow> shows_set = {{"Game of Thrones", 9.3, 2011},
                                  {"Sherlock", 9.1, 2010},
                                  {"Friends", 8.9, 1994},
                                  {"Frieren", 8.9, 2023},
                                  {"Arcane", 9.0, 2021}};
    
    shows_set.insert(TVShow("One Piece", 9.0, 1999));

    std::cout << "Before swap:" << std::endl;
    print_set(shows_set);

    std::set<TVShow> empty_set;
    empty_set.swap(shows_set);

    std::cout << "After swap:" << std::endl;
    if (shows_set.empty()) {
        print_set(shows_set);
        std::cout << "The size of the shows set: " << shows_set.size() << std::endl;
    }

    std::cout << "------------------------------\n";

    return 0;
}