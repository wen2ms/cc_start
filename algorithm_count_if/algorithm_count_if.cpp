#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

class App {
  public:
    explicit App(std::string app_name = "", int rank = -1) : app_name_(app_name), rank_(rank) {}

    bool operator==(const App& other_app) const {
        return app_name_ == other_app.app_name_;
    }

    std::string app_name_;
    int rank_;
};

class CountTargetCompany {
  public:
    explicit CountTargetCompany(const std::string& target_company) : target_company_(target_company) {}

    bool operator()(const App& app) const {
        return app.app_name_.find(target_company_) != std::string::npos;
    }

  private:
    std::string target_company_;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << "Filename TargetAppName" << '\n';
        return 1;
    }

    std::cout << "I generated an example of stl count_if" << '\n';
    std::cout << "------------------------------\n";

    const std::string kFileName = argv[1];

    std::ifstream infile(kFileName);

    if (!infile.is_open()) {
        std::cout << "Could not open " << kFileName << " for reading" << '\n';
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

    for (const auto& [app_name, rank] : input_list) {
        std::cout << app_name << ' ' << rank << '\n';
    }

    const std::string kTargetAppName = argv[2];
    int target_counts = std::count(input_list.begin(), input_list.end(), App(kTargetAppName));
    int target_counts_if = std::count_if(input_list.begin(), input_list.end(), CountTargetCompany(kTargetAppName));

    std::cout << kTargetAppName << " Counts: " << target_counts << '\n';
    std::cout << kTargetAppName << " CountsIf: " << target_counts_if << '\n';

    std::cout << "------------------------------\n";

    return 0;
}