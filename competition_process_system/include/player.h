#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
  public:
    Player();

    Player(int id, std::string name);

    int id_;
    std::string name_;
    float score_;
};

#endif  // PLAYER_H