#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class TVShow {
  public:
    TVShow(std::string title = "", float rating = -1, int release_year = -1)
        : title_(title), rating_(rating), release_year_(release_year) {}

    std::string title_;
    float rating_;
    int release_year_;
};

std::map<std::string, TVShow> load_file() {
    const std::string kFileName = "tvshows.txt";

    std::map<std::string, TVShow> shows_map;

    std::ifstream in_file(kFileName);

    if (!in_file.is_open()) {
        throw std::runtime_error("Can not open the file for reading");
    }

    std::string line;
    while (std::getline(in_file, line)) {
        std::istringstream stringstream(line);

        std::string title;
        float rating;
        int release_year;

        std::getline(stringstream, title, ',');

        stringstream >> rating;

        stringstream.ignore();

        stringstream >> release_year;

        shows_map.insert(std::make_pair(title, TVShow(title, rating, release_year)));
    }

    in_file.close();

    return shows_map;
}

int main() {
    std::cout << "I generated a starting map\n";
    std::cout << "---------------------------\n";

    std::map<std::string, TVShow> shows_map;

    try {
        shows_map = load_file();

        for (std::map<std::string, TVShow>::iterator it = shows_map.begin(); it != shows_map.end(); it++) {
            std::cout << "Key: " << it->first << std::endl;

            std::cout << "Title: " << it->second.title_ << ", Rating: " << it->second.rating_
                      << ", Release Year: " << it->second.release_year_ << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------\n";

    return 0;
}