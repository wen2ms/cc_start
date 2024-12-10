#include "competition_process_system.h"

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <random>
#include <numeric>

CompetitionProcessSystem::CompetitionProcessSystem(const std::string& filename) : filename_(filename) {}

void CompetitionProcessSystem::run() {
    show_title();

    char key;
    while (true) {
        std::cout << "Please select: ";

        std::cin >> key;

        switch (key) {
            case '1':
                start();
                break;
            case '2':
                history();
                break;
            case '3':
                clear();
                break;
            case '0':
                std::cout << "Welcome next time..." << std::endl;
                return;
            default:
                std::cout << "Number invalid, please enter again..." << std::endl;
        }
    }
}

void CompetitionProcessSystem::show_title() const {
    std::cout << "----------------------------------" << std::endl;
    std::cout << "--------- Welcome to CPS ---------" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "--------  1.Start Comeptition ----" << std::endl;
    std::cout << "--------  2.View History  --------" << std::endl;
    std::cout << "--------  3.Clear History --------" << std::endl;
    std::cout << "--------  0.Exit System  ---------" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

void CompetitionProcessSystem::start() {
    const int kPlayerNumber = 12;

    players_.clear();
    for (int i = 0; i < kPlayerNumber; ++i) {
        players_.push_back(Player(10001 + i, std::string(1, 'A' + i)));
    }

    const int kRoundNumber = players_.size() / 6;

    for (int i = 1; i <= kRoundNumber; ++i) {
        judge();

        std::cout << "The " << i << " round is being drawn..." << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "The order after the draw is as follows:" << std::endl;

        draw();

        std::cout << "----------------------" << std::endl;
        std::cout << "Please enter any key..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        
        std::cout << "-------- Round " << i << " Begins --------"<< std::endl;

        round();

        std::cout << "-------- Round " << i << " Over ----------"<< std::endl;
        std::cout << "Please enter any key..." << std::endl;
        std::cin.get();

        std::cout << "----- The players advanced in round " << i << " are as follws -----" << std::endl;

        print_players(players_.begin(), players_.end());

        std::cout << "Please enter any key..." << std::endl;
        std::cin.get();

        std::cout << "-------- This Competition Is Over --------" << std::endl;
        std::cout << "The History Saved..." << std::endl;

        save();

        std::cout << "Please enter any key..." << std::endl;
        std::cin.get();
    }
}

void CompetitionProcessSystem::judge() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    const int kJudgeNumber = 10;

    for (std::vector<Player>::iterator it = players_.begin(); it != players_.end(); ++it) {
        std::vector<int> scores;

        for (int j = 0; j < kJudgeNumber; ++j) {
            scores.push_back(std::rand() % 40 + 60);
        }

        int max = scores[0];
        int min = scores[0];
        for (int j = 0; j < kJudgeNumber; ++j) {
            int score = scores.at(j);
            if (max < score) {
                max = score;
            }

            if (min > score) {
                min = score;
            }
        }

        it->score_ = (std::accumulate(scores.begin(), scores.end(), 0.0) - max - min) / (kJudgeNumber - 2);
    }
}

void CompetitionProcessSystem::draw() {
    std::mt19937 random_generation(std::time(nullptr));

    std::shuffle(players_.begin(), players_.end(), random_generation);

    std::for_each(players_.begin(), players_.end(), [](const Player& item) {
        std::cout << item.id_ << ' ';
    });
    std::cout << std::endl;
}

void CompetitionProcessSystem::round() {
    if (players_.size() == 6) {
        auto player_sort = [](const Player& a, const Player& b) { return a.score_ > b.score_; };

        std::sort(players_.begin(), players_.end(), player_sort);

        std::cout << "First group rankings:" << std::endl;
        print_players(players_.begin(), players_.end());

        players_.resize(3);       
    } else {
        std::vector<Player> group1(players_.size() * 0.5), group2(players_.size() * 0.5);

        std::vector<Player>::iterator mid_position = players_.begin() + players_.size() * 0.5;

        std::copy(players_.begin(), mid_position, group1.begin());
        std::copy(mid_position, players_.end(), group2.begin());

        auto player_sort = [](const Player& a, const Player& b) { return a.score_ > b.score_; };

        std::sort(group1.begin(), group1.end(), player_sort);
        std::sort(group2.begin(), group2.end(), player_sort);

        std::cout << "First group rankings:" << std::endl;
        print_players(group1.begin(), group1.end());

        std::cout << "Second group rankings:" << std::endl;
        print_players(group2.begin(), group2.end());

        players_.resize(players_.size() * 0.5);
        std::merge(group1.begin(), group1.begin() + group1.size(), group2.begin(), group2.begin() + group2.size(), players_.begin(), player_sort);
    }
}

void CompetitionProcessSystem::save() const {
    std::ofstream outfile(filename_);

    if (!outfile.is_open()) {
        std::cerr << "Could not open " << filename_ << " for history" << std::endl;
        return;
    }
}

void CompetitionProcessSystem::history() const {
    std::ifstream infile(filename_);
    if (!infile.is_open()) {
        std::cerr << "Could not open " << filename_ << " for history" << std::endl;
        return;
    }

    const std::vector<std::string> kRank = {"Champion", "Second", "Third"};
    int number_competition = 1;

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream line_stream(line);

        std::cout << "------------------------------------------" << std::endl;
        std::cout << "  Competition" << number_competition++ << "\tId\tName\tScore" << std::endl;

        for (int i = 0; i < 3; ++i) {
            std::cout << "    " << kRank[i] << '\t';

            for (int j = 0; j < 3; ++j) {
                std::string cell;
                std::getline(line_stream, cell, ',');
                std::cout << cell << '\t';
            }
            std::cout << std::endl;
        }
    }

    infile.close();
}

void CompetitionProcessSystem::clear() const {
    std::ofstream outfile(filename_);

    if (!outfile.is_open()) {
        std::cout << "Could not open " << filename_ << "for clear" << std::endl;
        return;
    }

    outfile << "";

    outfile.close();
    std::cout << "Clear successfully..." << std::endl;
}

void CompetitionProcessSystem::print_players(const std::vector<Player>::iterator& begin, const std::vector<Player>::iterator& end) const {
    std::for_each(begin, end, [](const Player& player) {
        std::cout << "Id: " << player.id_ << " Name: player-" << player.name_ << " Score: " << player.score_ << std::endl;
    });      
}
