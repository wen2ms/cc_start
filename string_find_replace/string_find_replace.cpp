#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::cout << "I generated a example that finds and replaces string\n";
    std::cout << "---------------------------\n";

    const std::string kFileName = "data.txt";

    std::ifstream in_file(kFileName);
    if (!in_file.is_open()) {
        std::cerr << "Could not open the file for reading\n";
        return 1;
    }

    std::string text;
    while (std::getline(in_file, text)) {
    }

    in_file.close();

    int index_by_find = text.find("every");
    int index_by_rfind = text.rfind("every");

    std::cout << index_by_find << std::endl;
    std::cout << index_by_rfind << std::endl;

    text.replace(index_by_find, 6, "single ");
    std::cout << text << std::endl;

    std::cout << "---------------------------\n";

    return 0;
}