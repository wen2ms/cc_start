#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
  public:
    Player();

    Player(std::string name);

    std::string name_;
    float score_;
};

#endif  // PLAYER_H