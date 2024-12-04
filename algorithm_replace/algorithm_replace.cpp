#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "algorithm_replace_config.h"
#include "tvshow.h"

int main(int argc, char* argv[]) {
    std::cout << "I generated a replace algorithm\n";
    std::cout << "---------------------------\n";

    const std::string kFilename = TVSHOWS_TXT_PATH;

    std::ifstream infile(kFilename);
    if (!infile.is_open()) {
        std::cout << "Could not open " << kFilename << std::endl;
        return 2;
    }

    std::list<tvshow::TVShow> input_tvshows;

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream line_stream(line);
        std::vector<std::string> line_separate_comma;

        std::string cell;
        while (std::getline(line_stream, cell, ',')) {
            line_separate_comma.push_back(cell);
        }

        tvshow::TVShow temp_show;
        temp_show.title() = line_separate_comma[0];
        temp_show.rating() = std::stof(line_separate_comma[1]);
        temp_show.release_year() = std::stoi(line_separate_comma[2]);

        input_tvshows.push_back(temp_show);
    }

    infile.close();

    std::for_each(input_tvshows.begin(), input_tvshows.end(), [](tvshow::TVShow& show) {
        std::cout << show.title() << ' ' << show.rating() << ' ' << show.release_year() << std::endl;
    });

    tvshow::TVShow target;

    std::cout << "Input the tvshow title you want to replace: " << std::endl;
    std::cin >> target.title();

    std::list<tvshow::TVShow >::iterator target_position = std::find(input_tvshows.begin(), input_tvshows.end(), target);
    if (target_position == input_tvshows.end()) {
        std::cout << "Not found" << std::endl;
    } else {
        tvshow::TVShow substitute;

        std::cout << "Input title rating release-year: ";
        std::cin >> substitute.title() >> substitute.rating() >> substitute.release_year();

        std::replace(input_tvshows.begin(), input_tvshows.end(), target, substitute);
    }

    std::for_each(input_tvshows.begin(), input_tvshows.end(), [](tvshow::TVShow& show) {
        std::cout << show.title() << ' ' << show.rating() << ' ' << show.release_year() << std::endl;
    });

    std::ofstream outfile(kFilename);

    std::for_each(input_tvshows.begin(), input_tvshows.end(), [&](tvshow::TVShow& show) {
        outfile << show.title() << ',' << show.rating() << ',' << show.release_year() << std::endl;
    });

    outfile.close();

    std::cout << "---------------------------\n";

    return 0;
}