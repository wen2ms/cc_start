#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "I generated a example of nested vector\n";
    std::cout << "--------------------------------\n";

    std::vector<std::vector<std::string>> string_matrix;

    std::vector<std::string> string_vector1;
    std::vector<std::string> string_vector2;
    std::vector<std::string> string_vector3;

    for (int i = 0; i < 3; i++) {
        string_vector1.push_back(std::string(3, '*'));
        string_vector2.push_back("***");

        const char* temp_string = "***";
        string_vector3.push_back(temp_string);
    }

    string_matrix.push_back(string_vector1);
    string_matrix.push_back(string_vector2);
    string_matrix.push_back(string_vector3);

    for (std::vector<std::vector<std::string>>::iterator i = string_matrix.begin(); i != string_matrix.end(); i++) {
        for (std::vector<std::string>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            std::cout << *j << ' '; 
        }
        std::cout << '\n';
    }

    std::cout << "--------------------------------\n";

    return 0;
}