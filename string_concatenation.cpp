#include <iostream>
#include <string>


int main() {
    std::cout << "I generated a string concatenation\n";
    std::cout << "---------------------------------\n";

    std::string base_word("Achieve");

    std::cout << base_word + " a dream\n";

    std::string noun = "Argument";

    std::cout << base_word.append(noun, 4) << std::endl;

    std::cout << std::string().append(base_word.c_str(), 7) << std::endl;

    std::cout << "---------------------------------\n";

    return 0;
}