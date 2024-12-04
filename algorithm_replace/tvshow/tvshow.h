#ifndef TVSHOW_H
#define TVSHOW_H

#include <string>

namespace tvshow {
class TVShow {
  public:
    TVShow(std::string title = "", float rating = -1, int release_year = -1);

    bool operator==(const TVShow& other) const;

    std::string& title();
    float& rating();
    int& release_year();

  private:
    std::string title_;
    float rating_;
    int release_year_;
};
}

#endif  //TVSHOW_H

