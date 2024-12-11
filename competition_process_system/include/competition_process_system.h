#ifndef COMPETITION_PROCESS_SYSTEM
#define COMPETITION_PROCESS_SYSTEM

#include <string>
#include <vector>
#include <map>
#include <functional>

#include "player.h"
#include "cps_config.h"

class CompetitionProcessSystem {
  public:
    CompetitionProcessSystem(const std::string& filename = static_cast<std::string>(PROJECT_SOURCE_DIR) + "/history.csv");

    void init();

    void show_title() const;

    void start();

    void judge();

    void draw();

    void round();

    void save();

    void load() const;

    void clear() const;

    void print_players(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);

  private:
    std::string filename_;

    const int kPlayerNumber = 12;
    const int kJudgeNumber = 10;

    std::vector<int> players_id_;

    std::map<int, Player> players_;
};

#endif  // COMPETITION_PROCESS_SYSTEM