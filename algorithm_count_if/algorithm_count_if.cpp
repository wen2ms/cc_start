#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <fstream>

class App {
  public:
    App(std::string app_name = "", int rank = -1) : app_name_(app_name), rank_(rank) {}

    bool operator==(const App& other_app) const {
        return app_name_ == other_app.app_name_;
    }

    std::string app_name_;
    int rank_;
};

class CountTargetCompany {
  public:
    CountTargetCompany(std::string target_company) : target_company_(target_company) {}

    bool operator()(const App& app) const {
        if (app.app_name_.find(target_company_) == std::string::npos) {
            return false;
        } else {
            return true;
        }
    }

  private:
    std::string target_company_;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << "Filename TargetAppName" << std::endl;
        return 1;
    }

    std::cout << "I generated an example of stl count_if" << std::endl;
    std::cout << "------------------------------\n";

    const std::string kFileName = argv[1];

    std::ifstream infile(kFileName);

    if (!infile.is_open()) {
        std::cout << "Could not open " << kFileName << " for reading" << std::endl;
        return 2;
    }

    std::list<App> input_list;

    std::string line;
    while (std::getline(infile, line)) {
        int comma_position = line.find(',');

        std::string app_name = line.substr(0, comma_position);
        int rank = std::stoi(line.substr(comma_position + 1));
        
        input_list.push_back(App(app_name, rank));
    }

    for (std::list<App>::iterator it = input_list.begin(); it != input_list.end(); it++) {
        std::cout << it->app_name_ << ' ' << it->rank_ << std::endl;
    }

    const std::string kTargetAppName = argv[2];
    int target_counts = std::count(input_list.begin(), input_list.end(), App(kTargetAppName));
    int target_counts_if = std::count_if(input_list.begin(), input_list.end(), CountTargetCompany(kTargetAppName));

    std::cout << kTargetAppName << " Counts: " << target_counts << std::endl;
    std::cout << kTargetAppName << " CountsIf: " << target_counts_if << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}