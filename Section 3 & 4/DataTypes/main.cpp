//
// Created by Vincent Allen on 2/3/23.
//
#include <iostream>

void four_twelve_quiz() {
    std::cout << "Enter -1 to exit." << '\n';
    std::cout << "Enter an character to get it's ASCII code: ";
    char ascii {};
    std::cin >> ascii;
    std::cout << "You entered " << ascii << " which has code " << static_cast<int>(ascii);

}

void print(int x) {
    std::cout << x << '\n';
}

int main() {
    print(static_cast<int>(5.5));

    for (char c = 0; c < 127; c++) {
        std::cout << c << " has value " << static_cast<int>(c) << '\n';
    }
    char ch {97};
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';

    four_twelve_quiz();

}