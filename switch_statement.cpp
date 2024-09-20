#include <iostream>

int main(void) {
    int score = -1;

    std::cout << "------------\n";
    std::cout << "Please input a score for the movie: ";
    std::cin >> score;
    std::cout << "------------\n";

    switch (score) {
        case 1:
            std::cout << "very bad\n";
            break;
        case 2:
            std::cout << "bad\n";
            break;
        case 3:
            std::cout << "good\n";
            break;
        case 4:
            std::cout << "very good\n";
            break;
        case 5:
            std::cout << "perfect\n";
            break;
        default:
            std::cout << "Please input right score\n";
            break;
    }

    return 0;
}