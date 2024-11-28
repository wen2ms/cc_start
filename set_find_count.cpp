#include <iostream>
#include <set>
#include <string>

int main() {
    std::cout << "I have gererated an example of set's find and count\n";
    std::cout << "------------------------------\n";

    std::set<std::string> tv_series;

    tv_series.insert("Friends");
    tv_series.insert("Frieren");
    tv_series.insert("Sherlock");
    tv_series.insert("Arcane");

    for (std::set<std::string>::iterator it = tv_series.begin(); it != tv_series.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    std::set<std::string>::iterator target_pos = tv_series.find("Sherlock");
    if (target_pos != tv_series.end()) {
        std::cout << "Find " << *target_pos << " successfully!" << std::endl;
    }
    
    target_pos = tv_series.find("Game of Thrones");
    if (target_pos == tv_series.end()){
        std::cout << "Find failed!" << std::endl;
    }

    std::cout << "Sherlock counts: " << tv_series.count("Sherlock") << std::endl;

    std::cout << "------------------------------\n";

    return 0;
}