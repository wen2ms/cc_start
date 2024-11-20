#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <random>
#include <string>
#include <vector>

class Player {
  public:
    Player(std::string name = "Unknown", int judges_number = 0) : name_(name), scores_(judges_number), final_scores_(0) {
        for (int i = 0; i < scores_.size(); i++) {
            scores_[i] = std::rand() % 10 + 1;
        }
    }

    friend std::ostream& operator<< (std::ostream& out, const Player& player) {
        out << player.name_ << ' ';
        for (std::deque<int>::const_iterator it = player.scores_.begin(); it != player.scores_.end(); it++) {
            out << *it << ' ';
        }
        out << "   " << player.final_scores_;  

        return out;
    }

    void judges_score() {
        std::deque<int> scores_copy(scores_);

        std::sort(scores_copy.begin(), scores_copy.end());

        scores_copy.pop_front();
        scores_copy.pop_back();

        float sum = 0;
        for (std::deque<int>::const_iterator it = scores_copy.begin(); it != scores_copy.end(); it++ ) {
            sum += *it;
        }
        
        final_scores_ = sum / scores_copy.size();
    }

  private:
    std::string name_;
    std::deque<int> scores_;
    float final_scores_;
};

void print_players_vector(const std::vector<Player>& players_vector) {
    for (std::vector<Player>::const_iterator it = players_vector.begin(); it != players_vector.end(); it++) {
        std::cout << *it << std::endl;
    }
}

int main() {
    std::cout << "This is a judges-scoring program.\n";
    std::cout << "------------------------------\n";

    const int kPlayersNumber = 5;
    const int kJudgesNumber = 10;

    std::vector<Player> players_vector;
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int i = 0; i < kPlayersNumber; i++) {
        std::string player_name(1, 'A' + i);

        players_vector.push_back(Player(player_name, kJudgesNumber));
    }
    print_players_vector(players_vector);

    std::cout << "Judges scored" << std::endl;

    for (std::vector<Player>::iterator it = players_vector.begin(); it != players_vector.end(); it++) {
        (*it).judges_score();
    }
    print_players_vector(players_vector);


    std::cout << "------------------------------\n";

    return 0;
}