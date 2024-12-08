#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class App {
  public:
    App(std::string app_name = "", int rank = -1) : app_name_(app_name), rank_(rank) {}

    bool operator<(const App& other) const {
        return rank_ < other.rank_;
    }

    bool operator==(const App& other) const {
        return rank_ == other.rank_;
    }

    std::string app_name_;
    int rank_;
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " filename1 filename2 filename3" << std::endl;
        return 1;
    }

    std::cout << "I generated a set intersection algorithm\n";
    std::cout << "---------------------------\n";

    const std::vector<std::string> kFilenames = {argv[1], argv[2], argv[3]};

    std::vector<std::ifstream*> infiles;

    for (std::vector<std::string>::const_iterator it = kFilenames.begin(); it != kFilenames.end(); ++it) {
        std::ifstream* temp_infile = new std::ifstream(*it);

        if (!temp_infile->is_open()) {
            std::cout << "Could not open " << *it << " for reading" << std::endl;
            return 2;
        } else {
            infiles.push_back(temp_infile);
        }
    }

    std::vector<std::set<App>> apps;

    for (std::vector<std::ifstream*>::iterator it = infiles.begin(); it != infiles.end(); ++it) {
        std::set<App> cell;

        std::string line;
        while (std::getline(**it, line)) {
            std::istringstream line_stream(line);

            App temp_app;

            std::getline(line_stream, temp_app.app_name_, ',');
            line_stream >> temp_app.rank_;

            cell.insert(temp_app);
        }

        apps.push_back(cell);

        (*it)->close();
    }

    for (std::vector<std::set<App>>::iterator i = apps.begin(); i != apps.end(); ++i) {
        for (std::set<App>::iterator j = i->begin(); j != i->end(); ++j) {
            std::cout << j->app_name_ << ' ' << j->rank_ << "  ";
        }
        std::cout << std::endl;
    }

    std::set<App> intersection = apps[0];
    for (std::vector<std::set<App>>::iterator i = apps.begin() + 1; i != apps.end(); ++i) {
        std::set<App> current_interection;

        std::set_intersection(intersection.begin(), intersection.end(), i->begin(), i->end(),
                              std::inserter(current_interection, current_interection.begin()));

        intersection = current_interection;

        for (std::set<App>::iterator k = intersection.begin(); k != intersection.end(); ++k) {
            std::cout << k->app_name_ << ' ' << k->rank_ << "  ";
        }
        std::cout << std::endl;
    }

    for (std::vector<std::ifstream*>::iterator it = infiles.begin(); it != infiles.end(); ++it) {
        delete *it;
        *it = nullptr;
    }

    std::cout << "---------------------------\n";

    return 0;
}