/*
 *
 *     Write a Fraction class that has a constructor that takes a numerator and a denominator.
 *     If the user passes in a denominator of 0, throw an exception of type std::runtime_error
 *     (included in the stdexcept header). In your main program, ask the user to enter two integers.
 *     If the Fraction is valid, print the fraction. If the Fraction is invalid, catch a std::exception,
 *     and tell the user that they entered an invalid fraction.
 */

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int m_numerator{};
    int m_denominator{};
public:
    Fraction(int numerator, int denominator) : m_numerator{numerator}, m_denominator{denominator} {
        if (denominator == 0) {
            throw std::runtime_error("Entered a denominator of 0");
        }
    }

    friend std::ostream &operator<<(std::ostream &out, Fraction &fraction) {
        std::cout << fraction.m_numerator << "/" << fraction.m_denominator;
        return out;
    }
};

int main() {
    try {
        std::cout << "Enter 2 integers to make a fraction: ";
        int num1{};
        int num2{};

        std::cin >> num1;
        std::cin >> num2;

        Fraction fraction{num1, num2};

        std::cout << "Your fraction: " << fraction;
    } catch (std::runtime_error &error) {
        std::cout << "You entered an invalid fraction!";
    }
    return 0;
}
