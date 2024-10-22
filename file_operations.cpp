#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::cout << "I generated an example of fstream\n";
    std::cout << "--------------------------\n";

    std::string filename = "example.md";

    std::ofstream out_file(filename);
    if (out_file.is_open()) {
        out_file << "### example\n";
        out_file << "\n- This is a test file\n";
        out_file << "\n- File I/O using fstream\n";
        out_file.close();

        std::cout << "File written successfully\n";
    } else {
        std::cerr << "Uable to open file for writing\n";
        return 1;
    }

    std::ifstream in_file(filename);
    if (in_file.is_open()) {
        std::string line;
        while (std::getline(in_file, line)) {
            std::cout << line << '\n';
        }

        in_file.close();
    } else {
        std::cerr << "Uable to open file for reading\n";
        return 1;
    }

    std::cout << "--------------------------\n";

    return 0;
}