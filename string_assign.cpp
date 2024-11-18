#include <iostream>
#include <string>

int find_bravo(const std::string& sentence) {
    int index = 0;
    for (std::string::const_iterator it = sentence.begin(); it != sentence.end(); it++, index++) {
        if (*it == 'o') {
            return index;
        }
    }

    return -1;
}

int main() {
    std::cout << "I wrote several uses of string assignment\n";
    std::cout << "-----------------------------\n";

    // std::string str_char_assignment = 'C';  // Error, no matching constructor.
    std::string str_char_assignment;
    str_char_assignment = 'C';
    std::cout << str_char_assignment << std::endl;

    char c_type_str[] = "Bravo! Lisa";
    std::string str_assign;
    str_assign.assign(c_type_str);
    std::cout << str_assign << std::endl;

    str_assign.assign(c_type_str, find_bravo(c_type_str) + 1);
    std::cout << str_assign << std::endl;

    str_assign.assign(3, '*');
    std::cout << str_assign << std::endl;

    std::cout << "-----------------------------\n";

    return 0;
}
