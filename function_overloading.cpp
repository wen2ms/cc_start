#include <cstdlib>
#include <iostream>
#include <string>

void display(std::string message) {
    std::cout << "Message" << '\n';
}

void display(const std::string& message) {
    std::cout << "Message: " << message << '\n';
}

void display(const std::string& message, int repeat_times) {
    for (int i = 0; i < repeat_times; i++)
        std::cout << "Message" << i + 1 << ": " << message << '\n';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide a string as a command-line argument\n";
        return 1;
    }

    std::cout << "I generated a function overloading example\n";
    std::cout << "-------------------------------------------\n";

    std::string message = argv[1];

    if (argc == 2) {
        // Ambiguity
        // display(message);
    } else if (argc == 3) {
        display(message, std::atoi(argv[2]));
    }

    std::cout << "-------------------------------------------\n";

    return 0;
}