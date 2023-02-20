#include <iostream>
#include <random>

namespace constants {
    constexpr int minNumber {1};
    constexpr int maxNumber {100};
}

namespace Random {
    std::random_device rd;
    std::seed_seq ss {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    std::mt19937 mt {ss};

    std::uniform_int_distribution distribution {constants::minNumber, constants::maxNumber};

    int getRandom() {
        return distribution(mt);
    }
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getGuess(int guessNum) {
    int guess{};

    bool gettingGuess {true};
    while (gettingGuess) {
        std::cout << "Guess #" << guessNum << ": ";
        std::cin >> guess;

        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Invalid input, try again." << '\n';
        } else {
            ignoreLine();
            if (guess < constants::minNumber || guess > constants::maxNumber) {
                std::cout << "That is not a valid guess, try again." << '\n';
            } else {
                break;
            }
        }
    }

    return guess;
}

int main() {
    start:
    std::cout << "I'm thinking of a number between 1 and 100. You have 7 tries to guess" << '\n';

    int randomNumber = Random::getRandom();

    int guessNum {1};
    while (guessNum <= 7) {
        int guess {getGuess(guessNum)};


        if (guess == randomNumber) {
            std::cout << "Correct! You win!" << '\n';
            break;
        } else {
            std::cout << ((guess > randomNumber) ? "Your guess is too high." : "Your guess is too low.") << '\n';
            if (guessNum == 7) {
                std::cout << "You lose, the correct number was " << randomNumber << '\n';
            }
        }
        ++guessNum;
    }

    std::cout << "Would you like to play again? (y/n): ";
    char again {};
    std::cin >> again;

    if (toupper(again) == 'Y') {
        goto start;
    }

    return 0;
}
