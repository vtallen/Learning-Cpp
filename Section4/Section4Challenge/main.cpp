#include <iostream>

int main() {
    int favoriteNumber;

    std::cout << "What is your favorite number? :: ";
    std::cin >> favoriteNumber;
    std::cout << favoriteNumber << " is my favorite number too!" << std::endl;
    std::cout << "No really, " << favoriteNumber << " is my favorite number";
    return 0;
}
