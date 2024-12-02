#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class TVShow {
  public:
    TVShow(std::string title = "", float rating = -1, int realase_date = 0)
        : title_(title), rating_(rating), release_date_(realase_date) {}

    std::string title_;
    float rating_;
    int release_date_;
};

class RatingFilter {
  public:
    RatingFilter(float rating) : rating_filter_(rating) {}

    bool operator()(const TVShow& item) const {
        return item.rating_ >= rating_filter_;
    }

  private:
    float rating_filter_;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << "Filename TargetRating" << std::endl;
        return 1;
    }

    std::cout << "I generated a find_if algorithm\n";
    std::cout << "---------------------------\n";

    const std::string kFileName(argv[1]);
    const float kTargetRating = std::stof(argv[2]);

    std::ifstream infile(kFileName);

    if (!infile.is_open()) {
        std::cout << "Could not open " << kFileName << " for reading" << std::endl;
        return 2;
    }

    std::vector<TVShow> input_vector;

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream string_stream(line);

        TVShow temp_tvshow;

        std::getline(string_stream, temp_tvshow.title_, ',');

        string_stream >> temp_tvshow.rating_;

        string_stream.ignore();
        string_stream >> temp_tvshow.release_date_;

        input_vector.push_back(temp_tvshow);
    }

    infile.close();

    for (std::vector<TVShow>::iterator it = input_vector.begin(); it != input_vector.end(); it++) {
        std::cout << it->title_ << ' ' << it->rating_ << ' ' << it->release_date_ << std::endl;
    }

    std::vector<TVShow>::iterator target_iterator =
        std::find_if(input_vector.begin(), input_vector.end(), RatingFilter(kTargetRating));
    if (target_iterator == input_vector.end()) {
        std::cout << " Not Found" << std::endl;
    } else {
        std::cout << "Found successfully: " << target_iterator->title_ << ' ' << target_iterator->rating_ << ' '
                  << target_iterator->release_date_ << std::endl;
    }

    std::cout << "---------------------------\n";

    return 0;
}