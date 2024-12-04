#include "tvshow.h"

namespace tvshow {
TVShow::TVShow(std::string title, float rating, int release_year) : title_(title), rating_(rating), release_year_(release_year) {}

bool TVShow::operator==(const TVShow& other) const {
    return title_ == other.title_;
}

std::string& TVShow::title() {
    return title_;
}

float& TVShow::rating() {
    return rating_;
}
int& TVShow::release_year() {
    return release_year_;
}
}  // namespace tvshow