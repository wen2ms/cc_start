#include "competition_process_system.h"

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <numeric>

CompetitionProcessSystem::CompetitionProcessSystem(const std::string& filename) : filename_(filename) {
    init();
}

void CompetitionProcessSystem::init() {
    players_id_.clear();
    players_.clear();

    for (int i = 0; i < kPlayerNumber; ++i) {
        players_id_.push_back(10001 + i);

        players_.insert(std::make_pair(10001 + i, Player(std::string(1, 'A' + i))));
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
    init();

    const int kRoundNumber = players_.size() / 6;

    std::cin.ignore();
    for (int i = 1; i <= kRoundNumber; ++i) {
        judge();

        std::cout << "The " << i << " round is being drawn..." << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "The order after the draw is as follows:" << std::endl;

        draw();

        std::cout << "----------------------" << std::endl;
        std::cout << "Please enter any key..." << std::endl;
        std::cin.get();
        
        std::cout << "-------- Round " << i << " Begins --------"<< std::endl;

        round();

        std::cout << "-------- Round " << i << " Over ----------"<< std::endl;
        std::cout << "Please enter any key..." << std::endl;
        std::cin.get();

        std::cout << "----- The players advanced in round " << i << " are as follws -----" << std::endl;

        print_players(players_id_.begin(), players_id_.end());

        std::cout << "Please enter any key..." << std::endl;
        std::cin.get();
    }

    std::cout << "-------- This Competition Is Over --------" << std::endl;
    std::cout << "Please enter any key..." << std::endl;
    std::cin.get();

    save();
}

void CompetitionProcessSystem::judge() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (std::vector<int>::iterator it = players_id_.begin(); it != players_id_.end(); ++it) {
        std::deque<int> scores;

        for (int j = 0; j < kJudgeNumber; ++j) {
            scores.push_back(std::rand() % 40 + 60);
        }

        std::sort(scores.begin(), scores.end(), std::greater<int>());

        scores.pop_back();
        scores.pop_front();

        players_[*it].score_ = std::accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
    }
}

void CompetitionProcessSystem::draw() {
    std::mt19937 random_generation(std::time(nullptr));

    std::shuffle(players_id_.begin(), players_id_.end(), random_generation);

    std::for_each(players_id_.begin(), players_id_.end(), [](int id) {
        std::cout << id << ' ';
    });
    std::cout << std::endl;
}

void CompetitionProcessSystem::round() {
    auto player_id_sort = [this](int a, int b) { return players_[a].score_ > players_[b].score_; };

    if (players_id_.size() == 6) {
        std::sort(players_id_.begin(), players_id_.end(), player_id_sort);

        std::cout << "First group rankings:" << std::endl;
        print_players(players_id_.begin(), players_id_.end());

        players_id_.resize(3);       
    } else {
        std::vector<int> group1(players_id_.size() * 0.5), group2(players_id_.size() * 0.5);

        std::vector<int>::iterator mid_position = players_id_.begin() + players_id_.size() * 0.5;

        std::copy(players_id_.begin(), mid_position, group1.begin());
        std::copy(mid_position, players_id_.end(), group2.begin());

        std::sort(group1.begin(), group1.end(), player_id_sort);
        std::sort(group2.begin(), group2.end(), player_id_sort);

        std::cout << "First group rankings:" << std::endl;
        print_players(group1.begin(), group1.end());

        std::cout << "Second group rankings:" << std::endl;
        print_players(group2.begin(), group2.end());

        players_id_.resize(players_.size() * 0.5);
        group1.resize(group1.size() * 0.5);
        group2.resize(group2.size() * 0.5);

        std::merge(group1.begin(), group1.begin() + group1.size(), group2.begin(), group2.begin() + group2.size(), players_id_.begin(), player_id_sort);
    }
}

void CompetitionProcessSystem::save() {
    std::ofstream outfile(filename_, std::ios::app);

    if (!outfile.is_open()) {
        std::cerr << "Could not open " << filename_ << " for history" << std::endl;
        return;
    }

    for (std::vector<int>::iterator it = players_id_.begin(); it != players_id_.end(); ++it) {
        outfile << *it << ',' << players_[*it].name_ << ',' << players_[*it].score_ << ',';
    }
    outfile << std::endl;

    outfile.close();

    std::cout << "The History Saved..." << std::endl;
}

void CompetitionProcessSystem::load() const {
    std::ifstream infile(filename_);
    if (!infile.is_open()) {
        std::cerr << "Could not open " << filename_ << " for history" << std::endl;
        return;
    }

    char head;
    infile >> head;

    if (infile.eof()) {
        std::cout << filename_ << " is empty" << std::endl;
        infile.close();
        return;
    }

    infile.putback(head);

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

void CompetitionProcessSystem::print_players(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
    for (std::vector<int>::const_iterator it = begin; it != end; ++it) {
        std::cout << "Id: " << *it << " Name: player-" << players_[*it].name_ << " Score: " << players_[*it].score_ << std::endl;
    }  
}
