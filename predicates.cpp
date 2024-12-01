#include <iostream>
#include <vector>
#include <algorithm>

class TVShow {
  public:
    TVShow(std::string title = "", int release_year = 0) : title_(title), release_year_(release_year) {}

    std::string title_;
    int release_year_;
};

class LessThan {
  public:
    bool operator()(const TVShow& tvshow) const {
        return tvshow.release_year_ < 2000;
    }
};

class DescendingOrder {
  public: 
    bool operator()(const TVShow& a, const TVShow& b) const {
        return a.release_year_ > b.release_year_;
    }
};

void print_tvshows_vector(std::vector<TVShow>::iterator start, std::vector<TVShow>::iterator end) {
    for (; start != end; start++) {
        std::cout << start->title_ << ' ' << start->release_year_ << "  ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "I generated an example of predicates\n";
    std::cout << "----------------------\n";

    std::vector<TVShow> tvshows_vector;

    tvshows_vector.push_back(TVShow("Friends", 1994));
    tvshows_vector.push_back(TVShow("Frieren", 2023));
    tvshows_vector.push_back(TVShow("Sherlock", 2010));
    tvshows_vector.push_back(TVShow("Game of Thrones", 2011));
    tvshows_vector.push_back(TVShow("Arcane", 2021));

    std::sort(tvshows_vector.begin(), tvshows_vector.end(), DescendingOrder());

    print_tvshows_vector(tvshows_vector.begin(), tvshows_vector.end());

    std::vector<TVShow>::iterator lt_2000 = std::find_if(tvshows_vector.begin(), tvshows_vector.end(), LessThan());

    print_tvshows_vector(tvshows_vector.begin(), lt_2000);

    std::cout << "----------------------\n";

    return 0;
}