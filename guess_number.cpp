#include <cstdlib>
#include <ctime>
#include <iostream>

const int kMaxTimes = 6;

int main(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int random_number = std::rand() % 100 + 1;
    int guess_number = -1;
    int guess_times = 0;

    std::cout << "------------------------------\n";
    std::cout << "I have gererated a random number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n";

    while (guess_times < kMaxTimes) {
        std::cout << "Enter your guess: ";
        std::cin >> guess_number;

        if (guess_number > random_number) {
            std::cout << "Your guess is too high. Try again.\n";
        } else if (guess_number < random_number) {
            std::cout << "Your guess is too low. Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number!\n";
            break;
        }

        guess_times++;
    }

    if (guess_times == kMaxTimes)
        std::cout << "Guess tims exausted!\n";

    std::cout << "------------------------------\n";

    return 0;
}
