#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int randomNumber = std::rand() % 100 + 1; 
    int guessNumber = -1;
    int guessTimes = 0;

    std::cout << "------------------------------\n";
    std::cout << "I have gererated a random number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n";

    while (guessTimes < 5) {
        std::cout << "Enter your guess: ";
        std::cin >> guessNumber;

        if (guessNumber > randomNumber) {
            std::cout << "Your guess is too high. Try again.\n";
        } else if (guessNumber < randomNumber) {
            std::cout << "Your guess is too low. Try again.\n";
        } else  {
            std::cout << "Congratulations! You guessed the correct number!\n";
            break;
        }

        guessTimes ++;
    }

    if (guessTimes == 5)
        std::cout << "Guess tims exausted!\n";

    std::cout << "------------------------------\n";

    return 0;
}
