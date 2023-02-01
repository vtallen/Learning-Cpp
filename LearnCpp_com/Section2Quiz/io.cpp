#include <iostream>

int read_number() {
    int number {};
    std::cout << "Enter a number: ";
    std::cin >> number;

    return number;
}

void write_number(int number) {
    std::cout << "The sum of these numbers is " << number << std::endl;
}