#ifndef COMPETITION_PROCESS_SYSTEM
#define COMPETITION_PROCESS_SYSTEM

#include <string>
#include <vector>

#include "player.h"
#include "cps_config.h"

class CompetitionProcessSystem {
  public:
    CompetitionProcessSystem(const std::string& filename = static_cast<std::string>(PROJECT_SOURCE_DIR) + "/history.csv");

    void show_title() const;

    void start();

    void judge();

    void draw();

    void round();

    void save() const;

    void load() const;

    void clear() const;

    void print_players(const std::vector<Player>::iterator& begin, const std::vector<Player>::iterator& end) const;

  private:
    const std::string filename_;
    std::vector<Player> players_;
};

#endif  // COMPETITION_PROCESS_SYSTEM